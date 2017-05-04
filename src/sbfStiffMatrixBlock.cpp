#include "sbfStiffMatrixBlock.h"
#include "sbfMatrixIterator.h"
#include "sbfMesh.h"
#include "sbfElement.h"
#include "sbfAdditions.h"
#include "sbfthreadpool.hpp"
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <array>

template <int dim>
sbfStiffMatrixBlock<dim>::sbfStiffMatrixBlock (sbfMesh *mesh,
                                                sbfPropertiesSet *propSet,
                                                MatrixType type , bool makeReport) :
    sbfStiffMatrix ( mesh, propSet, type )
{
    init();
    if ( !mesh_ ) throw std::runtime_error ( "nullptr in mesh" );
    updateIndexesFromMesh(makeReport);
}

template <int dim>
sbfStiffMatrixBlock<dim>::~sbfStiffMatrixBlock()
{
    clean();
}

template <int dim>
void sbfStiffMatrixBlock<dim>::init()
{
    numNodes_ = 0;
    numBlocks_ = 0;
    numBlocksAlter_ = 0;
    data_ = nullptr;
    indJ_ = nullptr;
    shiftInd_ = nullptr;
    indJAlter_ = nullptr;
    shiftIndAlter_ = nullptr;
    ptrDataAlter_ = nullptr;
    columnsIndsPtrs_.clear();
    columnsIndsPtrsAlter_.clear();
}

template <int dim>
void sbfStiffMatrixBlock<dim>::clean()
{
    if ( data_ != nullptr )
    {delete [] data_; data_ = nullptr;}
    if ( indJ_ != nullptr )
    {delete [] indJ_; indJ_ = nullptr;}
    if ( shiftInd_ != nullptr )
    {delete [] shiftInd_; shiftInd_ = nullptr;}
    if ( indJAlter_ != nullptr )
    {delete [] indJAlter_; indJAlter_ = nullptr;}
    if ( shiftIndAlter_ != nullptr )
    {delete [] shiftIndAlter_; shiftIndAlter_ = nullptr;}
    if ( ptrDataAlter_ != nullptr )
    {delete [] ptrDataAlter_; ptrDataAlter_ = nullptr;}
    columnsIndsPtrs_.clear();
    columnsIndsPtrsAlter_.clear();
}

template <int dim>
void sbfStiffMatrixBlock<dim>::allocate()
{
    clean();
    data_ = new double [blockSize_ * numBlocks_];
    null();
    indJ_ = new size_t [numBlocks_];
    //+1 to allow unique iteration through rows,
    //i.e. from shiftInd_[ct] to shiftInd_[ct+1]
    shiftInd_ = new size_t [numNodes_ + 1];
    if ( numBlocksAlter_ > 0 ) {
        indJAlter_ = new size_t [numBlocksAlter_];
        shiftIndAlter_ = new size_t [numNodes_ + 1];
        ptrDataAlter_ = new double * [numBlocksAlter_];
        for ( size_t ct = 0; ct < numBlocksAlter_; ++ct ) ptrDataAlter_[ct] = nullptr;
    }
    columnsIndsPtrs_.resize ( numNodes_ );
    columnsIndsPtrsAlter_.resize ( numNodes_ );
}

template <int dim>
void sbfStiffMatrixBlock<dim>::setNumBlocksNodes (size_t numBlocks, size_t numNodes, size_t numBlocksAlter )
{
    clean();
    numBlocks_ = numBlocks;
    numBlocksAlter_ = numBlocksAlter;
    numNodes_ = numNodes;
    allocate();
}

template <int dim>
void sbfStiffMatrixBlock<dim>::updateIndexesFromMesh ( unsigned int *begin, unsigned int *end, bool makeReport )
{
    if ( makeReport ) report.createNewProgress ( "Update stiff indexes" );
    std::vector<std::set<unsigned int>> indexes;
    numNodes_ = mesh_->numNodes();
    indexes.resize ( numNodes_ );
    sbfThreadPool pool ( sbfNumThreads );
    std::array<std::mutex, sbfNumThreads> indexesPartLocks;
    std::array<std::future<int>, sbfNumThreads> futures;
    auto computer = [&] ( int computorID, int numComputors, int numAllRows ) -> int {
        unsigned int *localStart = begin + ( end - begin ) * computorID / numComputors ;
        unsigned int *localStop = begin + ( end - begin ) * ( computorID + 1 ) / numComputors;
        if ( localStop > end ) localStop = end;
        for ( unsigned int *ind = localStart; ind < localStop; ++ind )
        {
            std::vector<int> nodeIDs = mesh_->elemPtr ( *ind )->indexes();
            for ( auto node1 : nodeIDs ) {
                std::unique_lock<std::mutex> lock ( indexesPartLocks[node1 * numComputors / numAllRows] );
                indexes[node1].insert ( nodeIDs.begin(), nodeIDs.end() );
            }
        }
        return 0;
    };
    for ( int ct = 1; ct < sbfNumThreads; ++ct )
        futures[ct] = pool.enqueue ( computer, ct, sbfNumThreads, numNodes_ );
    computer ( 0, sbfNumThreads, numNodes_ );
    for ( int ct = 1; ct < sbfNumThreads; ++ct )
        futures[ct].get();
    size_t indLength = 0;
    for ( auto &row : indexes ) indLength += row.size();

    if ( type_ & MatrixType::FULL_MATRIX ) {
        setNumBlocksNodes ( indLength, numNodes_, 0 );
        int count = 0;
        int ct = 0;
        shiftInd_[count++] = ct;
        for ( auto &row : indexes ) {
            for ( auto nodeID : row )
                indJ_[ct++] = nodeID;
            shiftInd_[count++] = ct;
        }
    }//MatrixType::FULL_MATRIX
    else if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) {
        size_t numBeforeDiagonal = 0, numAfterDiagonal = 0;
        size_t size = indexes.size();
        for ( size_t ct = 0; ct < size; ++ct ) {
            auto &row = indexes[ct];
            for ( auto &id : row ) {
                if ( id < ct ) ++numBeforeDiagonal;
                else if ( id > ct ) ++numAfterDiagonal;
            }
        }
        //TODO is it true?
        assert ( numBeforeDiagonal == numAfterDiagonal );
        assert ( numBeforeDiagonal == ( indLength - numNodes_ ) / 2 );
        if ( type_ & UP_TREANGLE_MATRIX ) numBlocksAlter_ = numBeforeDiagonal;
        else numBlocksAlter_ = numAfterDiagonal;
        numBlocks_ = indLength - numBlocksAlter_;
        setNumBlocksNodes ( numBlocks_, numNodes_, numBlocksAlter_ );
        int countNorm = 0;
        int ctNorm = 0;
        int countAlter = 0;
        int ctAlter = 0;
        shiftInd_[countNorm++] = ctNorm;
        shiftIndAlter_[countAlter++] = ctAlter;
        size = static_cast<int> ( indexes.size() );
        for ( size_t ct = 0; ct < size; ++ct ) {
            auto &row = indexes[ct];
            for ( auto nodeID : row ) {
                if ( type_ & UP_TREANGLE_MATRIX ) {
                    if ( nodeID >= ct ) indJ_[ctNorm++] = nodeID;
                    else {indJAlter_[ctAlter] = nodeID; ptrDataAlter_[ctAlter] = nullptr; ctAlter++;}
                }
                else {
                    if ( nodeID <= ct ) indJ_[ctNorm++] = nodeID;
                    else {indJAlter_[ctAlter] = nodeID; ptrDataAlter_[ctAlter] = nullptr; ctAlter++;}
                }
            }
            shiftInd_[countNorm++] = ctNorm;
            shiftIndAlter_[countAlter++] = ctAlter;
        }
        updataAlterPtr();
    }//type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX
    else
        throw std::runtime_error ( "Not supported matrix type" );
    try {
        updateColumnsIndsPtrs();
    }
    catch ( std::exception &e ) {
        std::string err = "Cought exception during update of stiffness matrix columns indexing.";
        report.error ( err );
        throw std::runtime_error ( err );
    }
    if ( makeReport ) report.finalizeProgress();
}

template <int dim>
void sbfStiffMatrixBlock<dim>::updateIndexesFromMesh (unsigned int startElemIndex, unsigned int stopElemIndex, bool makeReport )
{
    std::vector<unsigned int> indexes;
    indexes.resize ( stopElemIndex - startElemIndex );
    for ( unsigned int ct = startElemIndex; ct < stopElemIndex; ++ct ) indexes[ct] = ct;
    updateIndexesFromMesh ( indexes.data(), indexes.data() + indexes.size(), makeReport );
}

template <int dim>
void sbfStiffMatrixBlock<dim>::updateIndexesFromMesh(bool makeReport)
{
    updateIndexesFromMesh ( 0, mesh_->numElements(), makeReport );
}

template <int dim>
void sbfStiffMatrixBlock<dim>::updataAlterPtr()
{
    if ( ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) && numBlocksAlter_ > 0 ) {
        int count = 0;
        for ( size_t ctIndI = 0; ctIndI < numNodes_; ctIndI++ ) {
            for ( size_t shift = shiftIndAlter_[ctIndI]; shift < shiftIndAlter_[ctIndI + 1]; shift++ )
                ptrDataAlter_[count++] = blockPtr ( indJAlter_[shift], ctIndI );
        }
    }
}

template <int dim>
double *sbfStiffMatrixBlock<dim>::blockPtr ( unsigned int indI, unsigned int indJ )
{
    //Search in regular storage ONLY
    size_t shift = shiftInd_[indI];
    double *base = data_ + shift * blockSize_;
    size_t searchLength = shiftInd_[indI + 1] - shift;
    for ( size_t ct = 0; ct < searchLength; ct++ ) { //Search through row indI for column indJ
        if ( indJ_[shift + ct] == indJ )
            return base;
        base += blockSize_;
    }

    return nullptr;
}

template <int dim>
void sbfStiffMatrixBlock<dim>::updateColumnsIndsPtrs()
{
    for ( auto &col : columnsIndsPtrs_ ) col.clear();
    for ( auto &col : columnsIndsPtrsAlter_ ) col.clear();
    for ( size_t indI = 0; indI < numNodes_; ++indI ) {
        size_t shift = shiftInd_[indI];
        double *base = data_ + shift * blockSize_;
        size_t searchLength = shiftInd_[indI + 1] - shift;
        for ( size_t ct = 0; ct < searchLength; ct++ ) {
            columnsIndsPtrs_[indJ_[shift + ct]].push_back ( std::make_pair ( indI, base ) );
            base += blockSize_;
        }
    }
    if ( ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) &&
         numBlocksAlter_ > 0 ) {
        size_t count = 0;
        for ( size_t indI = 0; indI < numNodes_; indI++ ) {
            for ( size_t shift = shiftIndAlter_[indI]; shift < shiftIndAlter_[indI + 1]; shift++ )
                columnsIndsPtrsAlter_[indJAlter_[shift]].push_back (
                    std::make_pair ( indI, ptrDataAlter_[count++] )
                );
        }
    }
}

//template <int dim>
//void sbfStiffMatrixBlock<dim>::compute ( int startID, int stopID )
//{

//}

template <int dim>
void sbfStiffMatrixBlock<dim>::null()
{
    const size_t length = numBlocks_ * blockSize_;
    for ( size_t ct = 0; ct < length; ct++ ) data_[ct] = 0.0;
}

template <int dim>
sbfMatrixIterator *sbfStiffMatrixBlock<dim>::createIterator()
{
    return new sbfStiffMatrixBlockIterator<dim> ( this );
}

template <int dim>
bool sbfStiffMatrixBlock<dim>::isValid()
{
    CreateSmartAndRawPtr ( sbfMatrixIterator, createIterator(), iter );

    const int numNodes = mesh_->numNodes();
    //Check diagonal elements
    for ( int ctNode = 0; ctNode < numNodes; ++ctNode ) {
        double *data = iter->diagonal ( ctNode );
        for ( int ct = 0; ct < blockDim_; ct++ )
            if (
                data[ct * ( blockDim_ + 1 )] < 0 ||
                !std::isnormal ( data[ct * ( blockDim_ + 1 )] )
            )
                return false;
    }
    return true;
}

template <int dim>
void sbfStiffMatrixBlock<dim>::read_stream ( std::ifstream &in )
{
    in.read ( reinterpret_cast<char *> ( &type_ ), sizeof ( type_ ) );
    in.read ( reinterpret_cast<char *> ( &numNodes_ ), sizeof ( numNodes_ ) );
    in.read ( reinterpret_cast<char *> ( &numBlocks_ ), sizeof ( numBlocks_ ) );

    if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX )
        in.read ( reinterpret_cast<char *> ( &numBlocksAlter_ ), sizeof ( numBlocksAlter_ ) );

    if ( type_ & FULL_MATRIX )
        setNumBlocksNodes ( numBlocks_, numNodes_ );
    if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX )
        setNumBlocksNodes ( numBlocks_, numNodes_, numBlocksAlter_ );

    in.read ( reinterpret_cast<char *> ( indJ_ ), numBlocks_ * sizeof ( indJ_[0] ) );
    in.read ( reinterpret_cast<char *> ( shiftInd_ ), ( numNodes_ + 1 ) *sizeof ( shiftInd_[0] ) );
    in.read ( reinterpret_cast<char *> ( data_ ), numBlocks_ * blockSize_ * sizeof ( data_[0] ) );
    if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) { //Alternate information
        in.read ( reinterpret_cast<char *> ( indJAlter_ ), numBlocksAlter_ * sizeof ( indJAlter_[0] ) );
        in.read ( reinterpret_cast<char *> ( shiftIndAlter_ ), ( numNodes_ + 1 ) *sizeof ( shiftIndAlter_[0] ) );
        std::vector<int> shiftPtrDataAlter;
        shiftPtrDataAlter.resize ( numBlocksAlter_ );
        in.read ( reinterpret_cast<char *> ( & ( shiftPtrDataAlter[0] ) ), numBlocksAlter_ * sizeof ( shiftPtrDataAlter[0] ) );
        for ( size_t ct = 0; ct < numBlocksAlter_; ct++ )
            ptrDataAlter_[ct] = data_ + shiftPtrDataAlter[ct];
    }//Alternate information
}

template <int dim>
void sbfStiffMatrixBlock<dim>::write_stream ( std::ofstream &out ) const
{
    out.write ( reinterpret_cast<const char *> ( &type_ ), sizeof ( type_ ) );
    out.write ( reinterpret_cast<const char *> ( &numNodes_ ), sizeof ( numNodes_ ) );
    out.write ( reinterpret_cast<const char *> ( &numBlocks_ ), sizeof ( numBlocks_ ) );

    if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX )
        out.write ( reinterpret_cast<const char *> ( &numBlocksAlter_ ), sizeof ( numBlocksAlter_ ) );

    out.write ( reinterpret_cast<const char *> ( indJ_ ), numBlocks_ * sizeof ( indJ_[0] ) );
    out.write ( reinterpret_cast<const char *> ( shiftInd_ ), ( numNodes_ + 1 ) *sizeof ( shiftInd_[0] ) );
    out.write ( reinterpret_cast<const char *> ( data_ ), numBlocks_ * blockSize_ * sizeof ( data_[0] ) );
    if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) { //Alternate information
        out.write ( reinterpret_cast<const char *> ( indJAlter_ ), numBlocksAlter_ * sizeof ( indJAlter_[0] ) );
        out.write ( reinterpret_cast<const char *> ( shiftIndAlter_ ), ( numNodes_ + 1 ) *sizeof ( shiftIndAlter_[0] ) );
        std::vector<int> shiftPtrDataAlter;
        shiftPtrDataAlter.resize ( numBlocksAlter_ );
        for ( size_t ct = 0; ct < numBlocksAlter_; ct++ )
            shiftPtrDataAlter[ct] = static_cast<int> ( ptrDataAlter_[ct] - data_ );
        out.write ( reinterpret_cast<const char *> ( & ( shiftPtrDataAlter[0] ) ),
                    numBlocksAlter_ * sizeof ( shiftPtrDataAlter[0] ) );
    }//Alternate information
}

template <int dim>
sbfStiffMatrix *sbfStiffMatrixBlock<dim>::createIncompleteChol()
{
    sbfStiffMatrixBlock<dim> *cholFactor = new sbfStiffMatrixBlock<dim> ( mesh_, nullptr,
                                                                          MatrixType::DOWN_TREANGLE_MATRIX | MatrixType::INCOMPLETE_CHOL );

    cholFactor->null();

    std::unique_ptr<sbfMatrixIterator> iteratorThis ( createIterator() );
    std::unique_ptr<sbfMatrixIterator> iteratorChol ( cholFactor->createIterator() );
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow0 ( cholFactor->createIterator() );
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow1 ( cholFactor->createIterator() );

    double *blockDiag, * blockCt, * blockCt1, *block;
    double *blockDiagTarget, * blockTarget;
    bool isDirect;
    int sumShift[blockDim_][blockDim_];
    {
        int shift = blockDim_;
        for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 )
                sumShift[ct1][ct2] = shift++;
    }
    for ( size_t diagCt = 0; diagCt < numNodes_; diagCt++ ) { //Loop on block rows
        //Process diagonal block

        blockDiag = iteratorThis->diagonal ( diagCt );
        blockDiagTarget = iteratorChol->diagonal ( diagCt );

        //Nulling above diagonal elements
        for ( int ctI = 0; ctI < blockDim_; ++ctI ) for ( int ctJ = ctI + 1; ctJ < blockDim_; ++ctJ )
                blockDiagTarget[ctI * blockDim_ + ctJ] = 0;

        const int sumLength = ( blockSize_ - blockDim_ ) / 2 + blockDim_;
        double sum[sumLength];// 00 11 22 33 44 55 66 01 02 ... 12 13 ... - regular and cross sums
        for ( int ct = 0; ct < sumLength; ++ct ) sum[ct] = 0.0;

        iteratorChol->setToRow ( diagCt );
        while ( iteratorChol->isValid() ) {
            if ( static_cast<size_t>(iteratorChol->column()) >= diagCt ) break;
            blockCt = iteratorChol->data();
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = 0; ct2 < blockDim_; ++ct2 )
                    sum[ct1] += blockCt[ct1 * blockDim_ + ct2] * blockCt[ct1 * blockDim_ + ct2];
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) {
                    double tmp = 0;
                    for ( int ct3 = 0; ct3 < blockDim_; ++ct3 )
                        tmp += blockCt[ct1 * blockDim_ + ct3] * blockCt[ct2 * blockDim_ + ct3];
                    sum[sumShift[ct1][ct2]] += tmp;
                }
            iteratorChol->next();
        }//Loop on blocks in row
        int shift = blockDim_;
        for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
            blockDiagTarget[ct1 * ( blockDim_ + 1 )] = std::sqrt ( blockDiag[ct1 * ( blockDim_ + 1 )] - sum[ct1] );
            for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) {
                blockDiagTarget[ct2 * blockDim_ + ct1] = ( blockDiag[ct2 * blockDim_ + ct1] - sum[shift++] ) /
                                                         blockDiagTarget[ct1 * ( blockDim_ + 1 )];
                sum[ct2] += blockDiagTarget[ct2 * blockDim_ + ct1] * blockDiagTarget[ct2 * blockDim_ + ct1];
                for ( int ct3 = ct2 + 1; ct3 < blockDim_; ++ct3 )
                    sum[sumShift[ct2][ct3]] += blockDiagTarget[ct2 * blockDim_ + ct1]
                                               * blockDiagTarget[ct3 * blockDim_ + ct1];
            }
        }
        //Process diagonal block - END

        //Process blocks under current diagonal

        double rowSum[blockSize_];
        double blockData[blockSize_];

        iteratorChol->setToColumn ( diagCt );
        iteratorThis->setToColumn ( diagCt );
        while ( iteratorChol->isValid() ) { //Loop on blocks under current diagonal block
            unsigned int rowCt = iteratorChol->row();
            if ( rowCt <= diagCt ) {
                iteratorChol->next();
                iteratorThis->next();
                continue; //Skip abowe rows
            }

            blockTarget = iteratorChol->data();

            //May be at alternative storage
            block = iteratorThis->data ( &isDirect );

            if ( isDirect ) for ( int ct = 0; ct < blockSize_; ct++ ) blockData[ct] = block[ct];
            else for ( int ctI = 0; ctI < blockDim_; ctI++ ) for ( int ctJ = 0; ctJ < blockDim_; ctJ++ )
                        blockData[ctI * blockDim_ + ctJ] = block[ctJ * blockDim_ + ctI];
            for ( int ct = 0; ct < blockSize_; ct++ ) rowSum[ct] = 0.0;

            iteratorCholRow0->setToRow ( rowCt );
            iteratorCholRow1->setToRow ( diagCt );
            unsigned int col0 = iteratorCholRow0->column();
            unsigned int col1 = iteratorCholRow1->column();
            while ( iteratorCholRow0->isValid() && iteratorCholRow1->isValid() ) {
                if ( col0 >= diagCt ) break;
                if ( col0 < col1 ) {
                    iteratorCholRow0->next();
                    col0 = iteratorCholRow0->column();
                    continue;
                }
                if ( col0 > col1 ) {
                    iteratorCholRow1->next();
                    col1 = iteratorCholRow1->column();
                    continue;
                }
                //OK, found equal columns ID
                blockCt = iteratorCholRow0->data();
                blockCt1 = iteratorCholRow1->data();
                //collect sums
                for ( int ctI = 0, shift = 0; ctI < blockDim_; ++ctI )
                    for ( int ctJ = 0; ctJ < blockDim_; ++ctJ, ++shift )
                        for ( int ct = 0; ct < blockDim_; ++ct )
                            rowSum[shift] += blockCt[ctI * blockDim_ + ct] * blockCt1[ctJ * blockDim_ + ct];
                iteratorCholRow0->next();
                iteratorCholRow1->next();
            }//Loop on blocks in row
            for ( int ctJ = 0; ctJ < blockDim_; ++ctJ ) {
                for ( int ctI = 0; ctI < blockDim_; ++ctI ) {
                    blockTarget[ctI * blockDim_ + ctJ] = ( blockData[ctI * blockDim_ + ctJ] -
                                                           rowSum[ctI * blockDim_ + ctJ] ) /
                                                         blockDiagTarget[ctJ * blockDim_ + ctJ];
                    if ( ctJ != blockDim_ - 1 ) for ( int ct1 = 0; ct1 <= ctJ; ++ct1 )
                            rowSum[ctI * blockDim_ + ctJ + 1] += blockTarget[ctI * blockDim_ + ct1] *
                                                                 blockDiagTarget[ ( ctJ + 1 ) * blockDim_ + ct1];
                }
            }
            iteratorChol->next();
            iteratorThis->next();
        }//Loop on blocks under current diagonal block

        //Process blocks under diagonal - END
    }//Loop on block rows

    return cholFactor;
}

template <int dim>
void sbfStiffMatrixBlock<dim>::solve_L_LT_u_eq_f ( double *u, double *f, sbfMatrixIterator *iterator )
{
    sbfMatrixIterator *iter = iterator;
    if ( !iterator ) iter = createIterator();
    double sum[blockDim_], vecPart[blockDim_];
    double *block = data_;
    for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;

    //L u' = f
    int ctRow = 0;
    int ctColumn = 0;
    for ( size_t ctBlock = 0; ctBlock < numBlocks_; ctBlock++ ) { //Loop on blocks
        if ( ctBlock == static_cast<size_t>(shiftInd_[ctRow + 1]) ) {
            ctRow++;
            for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;
        }
        ctColumn = indJ_[ctBlock];
        if ( ctRow != ctColumn ) { //process non diagonal block
            //TODO this is not fatal, but still it should be implemented with iterator
            block = blockPtr ( ctRow, ctColumn );
            if ( !block ) continue;
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
                vecPart[ct1] = u[ctColumn * blockDim_ + ct1];
                for ( int ct2 = 0; ct2 < blockDim_; ++ct2 )
                    sum[ct2] += block[ct2 * blockDim_ + ct1] * vecPart[ct1];
            }
        }//process non diagonal block
        else {
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
                vecPart[ct1] = ( f[ctRow * blockDim_ + ct1] - sum[ct1] ) / block[ct1 * ( blockDim_ + 1 )];
                for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 )
                    sum[ct2] += block[ct2 * blockDim_ + ct1] * vecPart[ct1];
                u[ctRow * blockDim_ + ct1] = vecPart[ct1];
            }
        }
        block += blockSize_;
    }//Loop on blocks
    //L^T u = u'
    for ( int ctRow = numNodes_ - 1; ctRow >= 0; ctRow-- ) { //Loop on rows
        for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;
        iter->setToColumnInverse ( ctRow );
        while ( !iter->isDiagonal() ) {
            block = iter->data();
            int ctColumn = iter->row();
            for ( int ct = 0; ct < blockDim_; ++ct )
                vecPart[ct] = u[ctColumn * blockDim_ + ct];
            //transposed indexing to block
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = 0; ct2 < blockDim_; ++ct2 )
                    sum[ct1] += block[ct2 * blockDim_ + ct1] * vecPart[ct2];
            iter->next();
        }//Loop on non diaonal blocks
        block = iter->diagonal ( ctRow );
        for ( int ct1 = blockDim_ - 1; ct1 >= 0; --ct1 ) {
            vecPart[ct1] = ( u[ctRow * blockDim_ + ct1] - sum[ct1] ) / block[ct1 * ( blockDim_ + 1 )];
            for ( int ct2 = ct1 - 1; ct2 >= 0; --ct2 )
                sum[ct2] += block[ct1 * blockDim_ + ct2] * vecPart[ct1];
        }
        for ( int ct = 0; ct < blockDim_; ++ct )
            u[ctRow * blockDim_ + ct] = vecPart[ct];
    }//Loop on rows

    if ( !iterator ) delete iter;
}

template class sbfStiffMatrixBlock<3>;
template class sbfStiffMatrixBlock<6>;
