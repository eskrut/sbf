#include "sbfStiffMatrixBand.h"
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
sbfStiffMatrixBand<dim>::sbfStiffMatrixBand (sbfMesh *mesh,
                                              sbfPropertiesSet *propSet,
                                              MatrixType type , bool makeReport) :
    sbfStiffMatrix ( mesh, propSet, type )
{
    init();
    if ( !mesh_ ) throw std::runtime_error ( "nullptr in mesh" );
    updateIndexesFromMesh(makeReport);
}

template <int dim>
sbfStiffMatrixBand<dim>::sbfStiffMatrixBand ( sbfStiffMatrixConstructData *constrData ) :
    sbfStiffMatrix ( nullptr, nullptr, constrData->type )
{
    init();
    construct ( constrData );
}

template <int dim>
sbfStiffMatrixBand<dim>::~sbfStiffMatrixBand()
{
    clean();
}

template <int dim>
void sbfStiffMatrixBand<dim>::init()
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
void sbfStiffMatrixBand<dim>::clean()
{
    if ( data_ != nullptr ) {
        delete [] data_;
        data_ = nullptr;
    }
    if ( indJ_ != nullptr ) {
        delete [] indJ_;
        indJ_ = nullptr;
    }
    if ( shiftInd_ != nullptr ) {
        delete [] shiftInd_;
        shiftInd_ = nullptr;
    }
    if ( indJAlter_ != nullptr ) {
        delete [] indJAlter_;
        indJAlter_ = nullptr;
    }
    if ( shiftIndAlter_ != nullptr ) {
        delete [] shiftIndAlter_;
        shiftIndAlter_ = nullptr;
    }
    if ( ptrDataAlter_ != nullptr ) {
        delete [] ptrDataAlter_;
        ptrDataAlter_ = nullptr;
    }
    columnsIndsPtrs_.clear();
    columnsIndsPtrsAlter_.clear();
}

template <int dim>
void sbfStiffMatrixBand<dim>::allocate()
{
    clean();
    try {
        data_ = new double [blockSize_ * numBlocks_];
        null();
        indJ_ = new size_t [numNodes_ * 2];
        //+1 to allow unique iteration through rows,
        //i.e. from shiftInd_[ct] to shiftInd_[ct+1]
        shiftInd_ = new size_t [numNodes_ + 1];
        if ( numBlocksAlter_ > 0 ) {
            indJAlter_ = new size_t [numNodes_ * 2];
            shiftIndAlter_ = new size_t [numNodes_ + 1];
            ptrDataAlter_ = new double * [numBlocksAlter_];
            for ( size_t ct = 0; ct < numBlocksAlter_; ++ct ) ptrDataAlter_[ct] = nullptr;
        }
        columnsIndsPtrs_.resize ( numNodes_ );
        columnsIndsPtrsAlter_.resize ( numNodes_ );
    }
    catch ( std::bad_alloc &e ) {
        std::string err = "Cant allocate enough memory for band stiffness matrix. Required memory is ";
        err += std::to_string ( ( ( blockSize_ * numBlocks_ ) * sizeof ( double ) +
                                  ( numNodes_ * 2 + numNodes_ + 1 + numNodes_ * 2 + numNodes_ + 1 ) * sizeof ( int ) +
                                  ( numBlocksAlter_ ) * ( sizeof ( double * ) ) ) / 1024.0 / 1024.0 / 1024.0 ) + "Gb";
        report.error ( err );
        throw e;
    }
    catch ( ... ) {
        std::string err = "Unknown error during stiffness matrix allocation";
        report.error ( err );
        throw std::runtime_error ( err );
    }
}

template <int dim>
void sbfStiffMatrixBand<dim>::setNumBlocksNodes ( int numBlocks,
                                                  int numNodes,
                                                  int numBlocksAlter )
{
    clean();
    numBlocks_ = numBlocks;
    numBlocksAlter_ = numBlocksAlter;
    numNodes_ = numNodes;
    allocate();
}

template <int dim>
void sbfStiffMatrixBand<dim>::updateIndexesFromMesh ( int *begin, int *end , bool makeReport )
{
    if ( makeReport ) report.createNewProgress ( "Update stiff indexes" );
    std::vector<std::set<int>> indexes;
    numNodes_ = mesh_->numNodes();
    indexes.resize ( numNodes_ );
    sbfThreadPool pool ( sbfNumThreads );
    std::array<std::mutex, sbfNumThreads> indexesPartLocks;
    std::array<std::future<int>, sbfNumThreads> futures;
    auto computer = [&] ( int computorID, int numComputors, int numAllRows ) -> int {
        int *localStart = begin + ( end - begin ) * computorID / numComputors ;
        int *localStop = begin + ( end - begin ) * ( computorID + 1 ) / numComputors;
        if ( localStop > end ) localStop = end;
        for ( int *ind = localStart; ind < localStop; ++ind )
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
    int indLength = 0;
    for ( auto &row : indexes ) indLength += *row.rbegin() - *row.begin() + 1;

    if ( type_ & MatrixType::FULL_MATRIX ) {
        setNumBlocksNodes ( indLength, numNodes_, 0 );
        int count = 0;
        int ct = 0;
        shiftInd_[count++] = ct;
        for ( auto &row : indexes ) {
            indJ_[ct++] = *row.begin();
            indJ_[ct++] = *row.rbegin();
            shiftInd_[count] = shiftInd_[count - 1] + indJ_[ct - 1] - indJ_[ct - 2] + 1;
            ++count;
            if ( makeReport && indexes.size() > 10 &&
                 ( &row - & ( indexes.front() ) ) % ( indexes.size() / 10 ) == 0 ) report.updateProgress ( 0, indexes.size(),
                             &row - & ( indexes.front() ) );
        }
    }//MatrixType::FULL_MATRIX
    else if ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) {
        int numBeforeDiagonal = 0, numAfterDiagonal = 0;
        int size = static_cast<int> ( indexes.size() );
        for ( int ct = 0; ct < size; ++ct ) {
            auto &row = indexes[ct];
            numBeforeDiagonal += ct - *row.begin();
            numAfterDiagonal += *row.rbegin() - ct;
        }
        if ( type_ & UP_TREANGLE_MATRIX ) numBlocksAlter_ = numBeforeDiagonal;
        else numBlocksAlter_ = numAfterDiagonal;
        numBlocks_ = indLength - numBlocksAlter_;
        if ( ! ( type_ & MatrixType::CHOL_FACTOR ||
                 type_ & MatrixType::INCOMPLETE_CHOL ||
                 type_ & MatrixType::LDLT_FACTOR ) ) {
            setNumBlocksNodes ( numBlocks_, numNodes_, numBlocksAlter_ );
            int countNorm = 0;
            int ctNorm = 0;
            int countAlter = 0;
            int ctAlter = 0;
            shiftInd_[countNorm++] = ctNorm;
            shiftIndAlter_[countAlter++] = ctAlter;
            size = static_cast<int> ( indexes.size() );
            for ( int ct = 0; ct < size; ++ct ) {
                auto &row = indexes[ct];
                int first = *row.begin();
                int last = *row.rbegin();
                if ( type_ & UP_TREANGLE_MATRIX ) {
                    indJ_[ctNorm++] = ct;
                    indJ_[ctNorm++] = last;
                    indJAlter_[ctAlter++] = first;
                    indJAlter_[ctAlter++] = ct - 1;
                }
                else {
                    indJ_[ctNorm++] = first;
                    indJ_[ctNorm++] = ct;
                    indJAlter_[ctAlter++] = ct + 1;
                    indJAlter_[ctAlter++] = last;
                }
                shiftInd_[countNorm] = shiftInd_[countNorm - 1] + indJ_[ctNorm - 1] - indJ_[ctNorm - 2] + 1;
                ++countNorm;
                shiftIndAlter_[countAlter] = shiftIndAlter_[countAlter - 1] + indJAlter_[ctAlter - 1] -
                                             indJAlter_[ctAlter - 2] + 1;
                ++countAlter;
                if ( makeReport && ct % ( size / 10 ) == 0 ) report.updateProgress ( 0, size, ct );
            }
            updataAlterPtr();
        }
        else {
            numBlocksAlter_ = 0;
            setNumBlocksNodes ( numBlocks_, numNodes_, numBlocksAlter_ );
            int countNorm = 0;
            int ctNorm = 0;
            shiftInd_[countNorm++] = ctNorm;
            size = static_cast<int> ( indexes.size() );
            for ( int ct = 0; ct < size; ++ct ) {
                auto &row = indexes[ct];
                int first = *row.begin();
                int last = *row.rbegin();
                if ( type_ & UP_TREANGLE_MATRIX ) {
                    indJ_[ctNorm++] = ct;
                    indJ_[ctNorm++] = last;
                }
                else {
                    indJ_[ctNorm++] = first;
                    indJ_[ctNorm++] = ct;
                }
                shiftInd_[countNorm] = shiftInd_[countNorm - 1] + indJ_[ctNorm - 1] - indJ_[ctNorm - 2] + 1;
                ++countNorm;
                if ( makeReport && size > 10 && ct % ( size / 10 ) == 0 ) report.updateProgress ( 0, size, ct );
            }
        }
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
void sbfStiffMatrixBand<dim>::updateIndexesFromMesh ( int startElemIndex,
                                                      int stopElemIndex ,
                                                      bool makeReport )
{
    std::vector<int> indexes;
    indexes.resize ( stopElemIndex - startElemIndex );
    for ( int ct = startElemIndex; ct < stopElemIndex; ++ct ) indexes[ct] = ct;
    updateIndexesFromMesh ( indexes.data(), indexes.data() + indexes.size(), makeReport );
}

template <int dim>
void sbfStiffMatrixBand<dim>::updateIndexesFromMesh ( bool makeReport )
{
    updateIndexesFromMesh ( 0, mesh_->numElements(), makeReport );
}

template <int dim>
void sbfStiffMatrixBand<dim>::updataAlterPtr()
{
    if ( ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX )
         && numBlocksAlter_ > 0 ) {
        int count = 0;
        for ( size_t ctIndI = 0; ctIndI < numNodes_; ctIndI++ ) {
            for ( size_t ctIndJ = indJAlter_[ctIndI * 2];
                  ctIndJ <= indJAlter_[ctIndI * 2 + 1];
                  ctIndJ++ )
                ptrDataAlter_[count++] = blockPtr ( ctIndJ, ctIndI );
        }
    }
}

template <int dim>
double *sbfStiffMatrixBand<dim>::blockPtr ( size_t indI, size_t indJ )
{
    //Search in regular storage ONLY
    size_t shift = shiftInd_[indI];
    double *base = data_ + shift * blockSize_;
    if ( indJ < indJ_[indI * 2] || indJ > indJ_[indI * 2 + 1] )
        return nullptr;
    return base + ( indJ - indJ_[indI * 2] ) * blockSize_;
}

template <int dim>
void sbfStiffMatrixBand<dim>::updateColumnsIndsPtrs()
{
    for ( auto &col : columnsIndsPtrs_ ) col.clear();
    for ( auto &col : columnsIndsPtrsAlter_ ) col.clear();
    for ( size_t indI = 0; indI < numNodes_; ++indI ) {
        if ( shiftInd_[indI + 1] - shiftInd_[indI] > 0 )
            for ( size_t indJ = indJ_[indI * 2]; indJ <= indJ_[indI * 2 + 1]; ++indJ )
                columnsIndsPtrs_[indJ].push_back (
                    std::make_pair ( indI,
                                     data_ + ( shiftInd_[indI] + indJ - indJ_[indI * 2] ) *blockSize_ )
                );
    }
    if ( ( type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX ) &&
         numBlocksAlter_ > 0 ) {
        int count = 0;
        for ( size_t indI = 0; indI < numNodes_; ++indI ) {
            if ( shiftIndAlter_[indI + 1] - shiftIndAlter_[indI] > 0 )
                for ( size_t indJ = indJAlter_[indI * 2];
                      indJ <= indJAlter_[indI * 2 + 1];
                      ++indJ )
                    columnsIndsPtrsAlter_[indJ].push_back (
                        std::make_pair ( indI, ptrDataAlter_[count++] )
                    );
        }
    }
}

template <int dim>
void sbfStiffMatrixBand<dim>::null()
{
    const int length = numBlocks_ * blockSize_;
    for ( int ct = 0; ct < length; ct++ ) data_[ct] = 0.0;
}

template <int dim>
sbfMatrixIterator *sbfStiffMatrixBand<dim>::createIterator()
{
    return new sbfStiffMatrixBandIterator<dim> ( this );
}

template <int dim>
bool sbfStiffMatrixBand<dim>::isValid()
{
    for ( size_t ct = 0; ct < numNodes_; ++ct ) {
        double *data = data_ + ( shiftInd_[ct] + ct - indJ_[ct * 2] ) * blockSize_;
        for ( int ctDof = 0; ctDof < blockDim_; ctDof++ )
            if (
                data[ctDof * ( blockDim_ + 1 )] < 0 ||
                !std::isnormal ( data[ctDof * ( blockDim_ + 1 )] )
            )
                return false;
    }
    const size_t length = numBlocks_ * blockDim_;
    for ( size_t ct = 0; ct < length; ++ct )
        assert ( std::isfinite ( data_[ct] ) );
    return true;
}

template <int dim>
void sbfStiffMatrixBand<dim>::read_stream ( std::ifstream &in )
{
    ( void ) ( in );
}

template <int dim>
void sbfStiffMatrixBand<dim>::write_stream ( std::ofstream &out ) const
{
    ( void ) ( out );
}

template <int dim>
sbfStiffMatrix *sbfStiffMatrixBand<dim>::createChol ( bool makeReport )
{
    assert ( this->isValid() );
    sbfStiffMatrixBand<dim> *cholFactor = new sbfStiffMatrixBand<dim> ( mesh_, nullptr,
                                                                        MatrixType::DOWN_TREANGLE_MATRIX |
                                                                        MatrixType::CHOL_FACTOR );

    static_assert (sbfNumThreads == 1, "Seems to be fatal error, should be fixed");
    const int usingNumThreads = sbfNumThreads * 1;
    if ( makeReport )
        report.createNewProgress ( "Computing chol factor in parallel " + std::to_string ( usingNumThreads ) );
    cholFactor->null();

    std::atomic<long int> diagProcessed ( -1 );

    sbfThreadPool pool ( usingNumThreads );
    //One computing function will be called from this thread
    std::array < std::future<int>, usingNumThreads - 1 > futures;

    auto computer = [&] ( int computerID, int numComputors ) -> int {
        std::unique_ptr<sbfMatrixIterator> iteratorThis ( createIterator() );
        std::unique_ptr<sbfMatrixIterator> iteratorChol ( cholFactor->createIterator() );
        std::unique_ptr<sbfMatrixIterator> iteratorCholRow0 ( cholFactor->createIterator() );
        std::unique_ptr<sbfMatrixIterator> iteratorCholRow1 ( cholFactor->createIterator() );
        int sumShift[blockDim_][blockDim_];
        {
            int shift = blockDim_;
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 )
                    sumShift[ct1][ct2] = shift++;
        }
        for ( size_t curRow = 0 + computerID; curRow < numNodes_; curRow += numComputors )
        {
            //Process blocks in this row until diagonal block
            iteratorChol->setToRow ( curRow );
            iteratorThis->setToRow ( curRow );
            long int safeToProcess = diagProcessed;
            for ( size_t ctCol = std::min ( iteratorChol->column(), iteratorThis->column() ); ctCol < curRow; ) {
                double rowSum[blockSize_];
                double blockData[blockSize_];
                bool isDirect;
                double *blockThis, *blockTarget;
                //Find pointers to source and target blocks to factorize
                while ( iteratorChol->isValid() && iteratorThis->isValid() ) {
                    auto cChol = iteratorChol->column();
                    auto cThis = iteratorThis->column();
                    if ( cChol == ctCol && cThis == ctCol ) break;
                    if ( cChol < ctCol ) iteratorChol->next();
                    if ( cThis < ctCol ) iteratorThis->next();
                }
                blockThis = iteratorThis->data ( &isDirect );
                assert ( isDirect );
                blockTarget = iteratorChol->data();
                if ( isDirect ) for ( int ct = 0; ct < blockSize_; ct++ ) blockData[ct] = blockThis[ct];
                else for ( int ctI = 0; ctI < blockDim_; ctI++ ) for ( int ctJ = 0; ctJ < blockDim_; ctJ++ )
                            blockData[ctI * blockDim_ + ctJ] = blockThis[ctJ * blockDim_ + ctI];
                for ( int ct = 0; ct < blockSize_; ct++ ) rowSum[ct] = 0.0;
                //This is checking for atomic variable
                bool processed = false;
                while ( !processed ) {
                    if ( static_cast<long int>(ctCol) <= safeToProcess || static_cast<long int>(ctCol) <= diagProcessed ) {
                        //OK diagonal of column ctCol is already processed
                        iteratorCholRow0->setToRow ( curRow );
                        iteratorCholRow1->setToRow ( ctCol );
                        auto col0 = iteratorCholRow0->column();
                        auto col1 = iteratorCholRow1->column();
                        while ( iteratorCholRow0->isValid() && iteratorCholRow1->isValid() ) {
                            col0 = iteratorCholRow0->column();
                            col1 = iteratorCholRow1->column();
                            if ( col0 >= ctCol ) break;
                            //TODO rewise this code for band matrix (copyed from block matrix)
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
                            assert ( iteratorCholRow0->column() == iteratorCholRow1->column() );
                            //OK, found equal columns ID
                            double *blockCt = iteratorCholRow0->data();
                            double *blockCt1 = iteratorCholRow1->data();
                            for ( int ctI = 0, shift = 0; ctI < blockDim_; ++ctI )
                                for ( int ctJ = 0; ctJ < blockDim_; ++ctJ, ++shift )
                                    for ( int ct = 0; ct < blockDim_; ++ct )
                                        rowSum[shift] += blockCt[ctI * blockDim_ + ct] * blockCt1[ctJ * blockDim_ + ct];
                            iteratorCholRow0->next();
                            iteratorCholRow1->next();
                        }//Loop on blocks in row

                        double *blockDiagTarget = iteratorChol->diagonal ( ctCol );

                        for ( int ctJ = 0; ctJ < blockDim_; ++ctJ ) {
                            for ( int ctI = 0; ctI < blockDim_; ++ctI ) {
                                blockTarget[ctI * blockDim_ + ctJ] = ( blockData[ctI * blockDim_ + ctJ] -
                                                                       rowSum[ctI * blockDim_ + ctJ] ) /
                                                                     blockDiagTarget[ctJ * blockDim_ + ctJ];
                                assert ( std::isfinite ( blockTarget[ctI * blockDim_ + ctJ] ) );
                                if ( ctJ != blockDim_ - 1 ) for ( int ct1 = 0; ct1 <= ctJ; ++ct1 )
                                        rowSum[ctI * blockDim_ + ctJ + 1] += blockTarget[ctI * blockDim_ + ct1] *
                                                                             blockDiagTarget[ ( ctJ + 1 ) * blockDim_ + ct1];
                            }
                        }
                        ++ctCol;
                        processed = true;
                    }
                    else
                        std::this_thread::yield();
                }
            }
            //Process diagonal block
            {
                double *blockDiag = iteratorThis->diagonal ( curRow );
                double *blockDiagTarget = iteratorChol->diagonal ( curRow );

                //Nulling above diagonal elements
                for ( int ctI = 0; ctI < blockDim_; ++ctI ) for ( int ctJ = ctI + 1; ctJ < blockDim_; ++ctJ )
                        blockDiagTarget[ctI * blockDim_ + ctJ] = 0;

                const int sumLength = ( blockSize_ - blockDim_ ) / 2 + blockDim_;
                double sum[sumLength];// 00 11 22 33 44 55 66 01 02 ... 12 13 ... - regular and cross sums
                for ( int ct = 0; ct < sumLength; ++ct ) sum[ct] = 0.0;

                iteratorChol->setToRow ( curRow );
                while ( iteratorChol->isValid() ) {
                    if ( iteratorChol->column() >= curRow ) break;
                    double *blockCt = iteratorChol->data();
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

                for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
                    blockDiagTarget[ct1 * ( blockDim_ + 1 )] = std::sqrt ( blockDiag[ct1 * ( blockDim_ + 1 )] - sum[ct1] );
                    assert ( std::isfinite ( blockDiagTarget[ct1 * ( blockDim_ + 1 )] ) );
                    for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) {
                        blockDiagTarget[ct2 * blockDim_ + ct1] = ( blockDiag[ct2 * blockDim_ + ct1] - sum[sumShift[ct1][ct2]] ) /
                                                                 blockDiagTarget[ct1 * ( blockDim_ + 1 )];
                        assert ( std::isfinite ( blockDiagTarget[ct2 * blockDim_ + ct1] ) );
                        sum[ct2] += blockDiagTarget[ct2 * blockDim_ + ct1] * blockDiagTarget[ct2 * blockDim_ + ct1];
                    }
                    for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) for ( int ct3 = ct2 + 1; ct3 < blockDim_; ++ct3 )
                            sum[sumShift[ct2][ct3]] += blockDiagTarget[ct2 * blockDim_ + ct1] *
                                                       blockDiagTarget[ct3 * blockDim_ + ct1];
                }
            }
            //OK update diagProcessed
            diagProcessed = curRow;

            //FIXME
            if ( makeReport && computerID == 0 && numNodes_ > 42 && curRow > ( numNodes_ / 42 ) && curRow % ( numNodes_ / 42 ) == 0 )
                report.updateProgress ( 0, numNodes_, curRow );
        }
        return 0;
    };


    for ( int ct = 0; ct < usingNumThreads - 1; ++ct )
        futures[ct] = pool.enqueue ( computer, ct, usingNumThreads );
    computer ( usingNumThreads - 1, usingNumThreads );
    for ( int ct = 0; ct < usingNumThreads - 1; ++ct )
        futures[ct].get();

    if ( makeReport ) report.finalizeProgress();

    return cholFactor;
}

template <int dim>
sbfStiffMatrix *sbfStiffMatrixBand<dim>::createLDLT ( bool makeReport )
{
    assert ( this->isValid() );
    sbfStiffMatrixBand<dim> *ldltFactor = new sbfStiffMatrixBand<dim> ( mesh_, nullptr,
                                                                        MatrixType::DOWN_TREANGLE_MATRIX |
                                                                        MatrixType::LDLT_FACTOR );

    const int usingNumThreads = sbfNumThreads * 1;
    if ( makeReport ) report.createNewProgress ( "Computing LDLT factor in parallel " + std::to_string (
                                                         usingNumThreads ) );
    ldltFactor->null();

    std::atomic<long int> diagProcessed ( -1 );

    sbfThreadPool pool ( usingNumThreads );
    //One computing function will be called from this thread
    std::array < std::future<int>, usingNumThreads - 1 > futures;

    auto computer = [&] ( int computerID, int numComputors ) -> int {
        std::unique_ptr<sbfMatrixIterator> iteratorThis ( createIterator() );
        std::unique_ptr<sbfMatrixIterator> iteratorL ( ldltFactor->createIterator() );
        std::unique_ptr<sbfMatrixIterator> iteratorLRow0 ( ldltFactor->createIterator() );
        std::unique_ptr<sbfMatrixIterator> iteratorLRow1 ( ldltFactor->createIterator() );
        int sumShift[blockDim_][blockDim_];
        {
            int shift = blockDim_;
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 )
                    sumShift[ct1][ct2] = shift++;
        }
        for ( size_t curRow = 0 + computerID; curRow < numNodes_; curRow += numComputors )
        {
            //Process blocks in this row until diagonal block
            iteratorL->setToRow ( curRow );
            iteratorThis->setToRow ( curRow );
            long int safeToProcess = diagProcessed;
            for ( size_t ctCol = std::min ( iteratorL->column(), iteratorThis->column() ); ctCol < curRow; ) {
                double rowSum[blockSize_];
                double blockData[blockSize_];
                bool isDirect;
                double *blockThis, *blockTarget;
                //Find pointers to source and target blocks to factorize
                while ( iteratorL->isValid() && iteratorThis->isValid() ) {
                    auto cChol = iteratorL->column();
                    auto cThis = iteratorThis->column();
                    if ( cChol == ctCol && cThis == ctCol ) break;
                    if ( cChol < ctCol ) iteratorL->next();
                    if ( cThis < ctCol ) iteratorThis->next();
                }
                blockThis = iteratorThis->data ( &isDirect );
                assert ( isDirect );
                blockTarget = iteratorL->data();
                if ( isDirect ) for ( int ct = 0; ct < blockSize_; ct++ ) blockData[ct] = blockThis[ct];
                else for ( int ctI = 0; ctI < blockDim_; ctI++ ) for ( int ctJ = 0; ctJ < blockDim_; ctJ++ )
                            blockData[ctI * blockDim_ + ctJ] = blockThis[ctJ * blockDim_ + ctI];
                for ( int ct = 0; ct < blockSize_; ct++ ) rowSum[ct] = 0.0;
                //This is checking for atomic variable
                bool processed = false;
                while ( !processed ) {
                    if ( static_cast<long int>(ctCol) <= safeToProcess || static_cast<long int>(ctCol) <= diagProcessed ) {
                        //OK diagonal of column ctCol is already processed
                        iteratorLRow0->setToRow ( curRow );
                        iteratorLRow1->setToRow ( ctCol );
                        auto col0 = iteratorLRow0->column();
                        auto col1 = iteratorLRow1->column();
                        while ( iteratorLRow0->isValid() && iteratorLRow1->isValid() ) {
                            col0 = iteratorLRow0->column();
                            col1 = iteratorLRow1->column();
                            if ( col0 >= ctCol ) break;
                            //TODO rewise this code for band matrix (copyed from block matrix)
                            if ( col0 < col1 ) {
                                iteratorLRow0->next();
                                col0 = iteratorLRow0->column();
                                continue;
                            }
                            if ( col0 > col1 ) {
                                iteratorLRow1->next();
                                col1 = iteratorLRow1->column();
                                continue;
                            }
                            assert ( iteratorLRow0->column() == iteratorLRow1->column() );
                            //OK, found equal columns ID
                            double *blockCt = iteratorLRow0->data();
                            double *blockCt1 = iteratorLRow1->data();
                            double *diagonal = iteratorL->diagonal ( col0 );
                            for ( int ctI = 0, shift = 0; ctI < blockDim_; ++ctI )
                                for ( int ctJ = 0; ctJ < blockDim_; ++ctJ, ++shift )
                                    for ( int ct = 0; ct < blockDim_; ++ct )
                                        rowSum[shift] += blockCt[ctI * blockDim_ + ct] * blockCt1[ctJ * blockDim_ + ct] *
                                                         diagonal[ct * ( blockDim_ + 1 )];
                            iteratorLRow0->next();
                            iteratorLRow1->next();
                        }//Loop on blocks in row

                        double *blockDiagTarget = iteratorL->diagonal ( ctCol );

                        for ( int ctJ = 0; ctJ < blockDim_; ++ctJ ) {
                            for ( int ctI = 0; ctI < blockDim_; ++ctI ) {
                                blockTarget[ctI * blockDim_ + ctJ] = ( blockData[ctI * blockDim_ + ctJ] -
                                                                       rowSum[ctI * blockDim_ + ctJ] ) /
                                                                     blockDiagTarget[ctJ * blockDim_ + ctJ];
                                assert ( std::isfinite ( blockTarget[ctI * blockDim_ + ctJ] ) );
                                if ( ctJ != blockDim_ - 1 ) for ( int ct1 = 0; ct1 <= ctJ; ++ct1 )
                                        rowSum[ctI * blockDim_ + ctJ + 1] += blockTarget[ctI * blockDim_ + ct1] *
                                                                             blockDiagTarget[ ( ctJ + 1 ) * blockDim_ + ct1] *
                                                                             blockDiagTarget[ct1 * ( blockDim_ + 1 )];
                            }
                        }
                        ++ctCol;
                        processed = true;
                    }
                    else
                        std::this_thread::yield();
                }
            }
            //Process diagonal block
            {
                double *blockDiag = iteratorThis->diagonal ( curRow );
                double *blockDiagTarget = iteratorL->diagonal ( curRow );

                //Nulling above diagonal elements
                for ( int ctI = 0; ctI < blockDim_; ++ctI ) for ( int ctJ = ctI + 1; ctJ < blockDim_; ++ctJ )
                        blockDiagTarget[ctI * blockDim_ + ctJ] = 0;

                const int sumLength = ( blockSize_ - blockDim_ ) / 2 + blockDim_;
                double sum[sumLength];// 00 11 22 33 44 55 66 01 02 ... 12 13 ... - regular and cross sums
                for ( int ct = 0; ct < sumLength; ++ct ) sum[ct] = 0.0;

                iteratorL->setToRow ( curRow );
                while ( iteratorL->isValid() ) {
                    if ( iteratorL->column() >= curRow ) break;
                    double *blockCt = iteratorL->data();
                    double *diagonal = iteratorL->diagonal ( iteratorL->column() );
                    for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = 0; ct2 < blockDim_; ++ct2 )
                            sum[ct1] += blockCt[ct1 * blockDim_ + ct2] * blockCt[ct1 * blockDim_ + ct2] *
                                        diagonal[ct2 * ( blockDim_ + 1 )];
                    for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) {
                            double tmp = 0;
                            for ( int ct3 = 0; ct3 < blockDim_; ++ct3 )
                                tmp += blockCt[ct1 * blockDim_ + ct3] * blockCt[ct2 * blockDim_ + ct3] *
                                       diagonal[ct3 * ( blockDim_ + 1 )];
                            sum[sumShift[ct1][ct2]] += tmp;
                        }
                    iteratorL->next();
                }//Loop on blocks in row

                for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
                    blockDiagTarget[ct1 * ( blockDim_ + 1 )] = blockDiag[ct1 * ( blockDim_ + 1 )] - sum[ct1];
                    assert ( std::isfinite ( blockDiagTarget[ct1 * ( blockDim_ + 1 )] ) );
                    for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) {
                        blockDiagTarget[ct2 * blockDim_ + ct1] = ( blockDiag[ct2 * blockDim_ + ct1] - sum[sumShift[ct1][ct2]] ) /
                                                                 blockDiagTarget[ct1 * ( blockDim_ + 1 )];
                        assert ( std::isfinite ( blockDiagTarget[ct2 * blockDim_ + ct1] ) );
                        sum[ct2] += blockDiagTarget[ct2 * blockDim_ + ct1] * blockDiagTarget[ct2 * blockDim_ + ct1] *
                                    blockDiagTarget[ct1 * ( blockDim_ + 1 )];
                    }
                    for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 ) for ( int ct3 = ct2 + 1; ct3 < blockDim_; ++ct3 )
                            sum[sumShift[ct2][ct3]] += blockDiagTarget[ct2 * blockDim_ + ct1] *
                                                       blockDiagTarget[ct3 * blockDim_ + ct1] *
                                                       blockDiagTarget[ct1 * ( blockDim_ + 1 )];
                }
            }
            //OK update diagProcessed
            diagProcessed = curRow;

            if ( makeReport && computerID == 0 && curRow > ( numNodes_ / 40 ) && curRow % ( numNodes_ / 40 ) == 0 )
                report.updateProgress ( 0, numNodes_, curRow );
        }
        return 0;
    };


    for ( int ct = 0; ct < usingNumThreads - 1; ++ct )
        futures[ct] = pool.enqueue ( computer, ct, usingNumThreads );
    computer ( usingNumThreads - 1, usingNumThreads );
    for ( int ct = 0; ct < usingNumThreads - 1; ++ct )
        futures[ct].get();

    if ( makeReport ) report.finalizeProgress();

    return ldltFactor;
}

template <int dim>
void sbfStiffMatrixBand<dim>::solve_L_LT_u_eq_f ( double *u, double *f,
                                                  sbfMatrixIterator *iterator )
{
    sbfMatrixIterator *iter = iterator;
    if ( !iterator ) iter = createIterator();
    double sum[blockDim_], vecPart[blockDim_];
    double *block = data_;
    for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;

    //L u' = f
    int ctRow = 0;
    int ctColumn = 0;
    for ( size_t ctBlock = 0; ctBlock < numBlocks_; ctBlock++, ctColumn++ ) { //Loop on blocks
        if ( ctBlock == shiftInd_[ctRow + 1] ) {
            ctRow++;
            ctColumn = indJ_[ctRow * 2];
            for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;
        }
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
            block = blockPtr ( ctRow, ctRow );
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
                vecPart[ct1] = ( f[ctRow * blockDim_ + ct1] - sum[ct1] ) / block[ct1 * ( blockDim_ + 1 )];
                for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 )
                    sum[ct2] += block[ct2 * blockDim_ + ct1] * vecPart[ct1];
                u[ctRow * blockDim_ + ct1] = vecPart[ct1];
            }
        }
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

template <int dim>
void sbfStiffMatrixBand<dim>::solve_L_D_LT_u_eq_f ( double *u, double *f,
                                                    sbfMatrixIterator *iterator )
{
    sbfMatrixIterator *iter = iterator;
    if ( !iterator ) iter = createIterator();
    double sum[blockDim_], vecPart[blockDim_];
    double *block = data_;
    for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;

    //L u' = f
    int ctRow = 0;
    int ctColumn = 0;
    for ( size_t ctBlock = 0; ctBlock < numBlocks_; ctBlock++, ctColumn++ ) { //Loop on blocks
        if ( ctBlock == shiftInd_[ctRow + 1] ) {
            ctRow++;
            ctColumn = indJ_[ctRow * 2];
            for ( int ct = 0; ct < blockDim_; ++ct ) sum[ct] = 0.0;
        }
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
            block = blockPtr ( ctRow, ctRow );
            for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
                vecPart[ct1] = ( f[ctRow * blockDim_ + ct1] - sum[ct1] ) /*/ block[ct1*(blockDim_+1)]*/;
                for ( int ct2 = ct1 + 1; ct2 < blockDim_; ++ct2 )
                    sum[ct2] += block[ct2 * blockDim_ + ct1] * vecPart[ct1];
                u[ctRow * blockDim_ + ct1] = vecPart[ct1];
                assert ( std::isnormal ( u[ctRow * blockDim_ + ct1] ) );
            }
        }
    }//Loop on blocks
    //D u'' = u'
    for ( size_t ct = 0; ct < numNodes_; ++ct ) {
        block = blockPtr ( ct, ct );
        for ( int ct1 = 0; ct1 < blockDim_; ++ct1 ) {
            u[ct * blockDim_ + ct1] = u[ct * blockDim_ + ct1] / block[ct1 * ( blockDim_ + 1 )];
            assert ( std::isfinite ( u[ct * blockDim_ + ct1] ) );
        }
    }
    //L^T u = u''
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
            vecPart[ct1] = ( u[ctRow * blockDim_ + ct1] - sum[ct1] ) /*/ block[ct1*(blockDim_+1)]*/;
            for ( int ct2 = ct1 - 1; ct2 >= 0; --ct2 )
                sum[ct2] += block[ct1 * blockDim_ + ct2] * vecPart[ct1];
        }
        for ( int ct = 0; ct < blockDim_; ++ct ) {
            u[ctRow * blockDim_ + ct] = vecPart[ct];
            assert ( std::isnormal ( u[ctRow * blockDim_ + ct] ) );
        }
    }//Loop on rows

    if ( !iterator ) delete iter;
}

template <int dim>
sbfStiffMatrixConstructData *sbfStiffMatrixBand<dim>::constructData() const
{
    sbfStiffMatrixBandConstructData<dim> *constrData = new sbfStiffMatrixBandConstructData<dim>;
    constrData->numNodes = numNodes_;
    constrData->numBlocks = numBlocks_;
    constrData->numBlocksAlter = numBlocksAlter_;
    constrData->data = data_;
    constrData->indJ = indJ_;
    constrData->shiftInd = shiftInd_;
    constrData->indJAlter = indJAlter_;
    constrData->shiftIndAlter = shiftIndAlter_;
    constrData->ptrDataAlter = ptrDataAlter_;

    return constrData;
}

template <int dim>
void sbfStiffMatrixBand<dim>::construct ( sbfStiffMatrixConstructData *constrData )
{
    clean();
    sbfStiffMatrix::construct ( constrData );
    sbfStiffMatrixBandConstructData<dim> *cData = reinterpret_cast<sbfStiffMatrixBandConstructData<dim> *> ( constrData );
    numNodes_ = cData->numNodes;
    numBlocks_ = cData->numBlocks;
    numBlocksAlter_ = cData->numBlocksAlter;
    data_ = cData->data;
    indJ_ = cData->indJ;
    shiftInd_ = cData->shiftInd;
    indJAlter_ = cData->indJAlter;
    shiftIndAlter_ = cData->shiftIndAlter;
    ptrDataAlter_ = cData->ptrDataAlter;
    size_t minColID = std::numeric_limits<size_t>::max();
    size_t maxColID = std::numeric_limits<size_t>::min();
    for ( size_t ct = 0; ct < numNodes_; ++ct ) {
        int s0 = shiftInd_[ct];
        int s1 = shiftInd_[ct + 1];
        if ( s0 != s1 ) {
            minColID = std::min ( minColID, indJ_[2 * ct] );
            maxColID = std::max ( maxColID, indJ_[2 * ct + 1] );
        }
    }
    columnsIndsPtrs_.resize ( maxColID - minColID + 1 );
    columnsIndsPtrsAlter_.resize ( maxColID - minColID + 1 );
    updateColumnsIndsPtrs();
}

template class sbfStiffMatrixBand<3>;
template class sbfStiffMatrixBand<6>;
