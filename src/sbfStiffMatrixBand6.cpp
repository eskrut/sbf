#include "sbfStiffMatrixBand6.h"
#include "sbfElement.h"
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

#include "sbfElemStiffMatrixBeam6Dof.h"
#include "sbfAdditions.h"

sbfStiffMatrixBand6::sbfStiffMatrixBand6(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type) :
    sbfStiffMatrix(mesh, propSet, type)
{
    init();
    if ( !mesh_ ) throw std::runtime_error("nullptr in mesh");
    updateIndexesFromMesh();
}

sbfStiffMatrixBand6::~sbfStiffMatrixBand6()
{
    clean();
}

void sbfStiffMatrixBand6::init()
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

void sbfStiffMatrixBand6::clean()
{
    if(data_ != nullptr)
    {delete [] data_; data_ = nullptr;}
    if(indJ_ != nullptr)
    {delete [] indJ_; indJ_ = nullptr;}
    if(shiftInd_ != nullptr)
    {delete [] shiftInd_; shiftInd_ = nullptr;}
    if(indJAlter_ != nullptr)
    {delete [] indJAlter_; indJAlter_ = nullptr;}
    if(shiftIndAlter_ != nullptr)
    {delete [] shiftIndAlter_; shiftIndAlter_ = nullptr;}
    if(ptrDataAlter_ != nullptr)
    {delete [] ptrDataAlter_; ptrDataAlter_ = nullptr;}
    columnsIndsPtrs_.clear();
    columnsIndsPtrsAlter_.clear();
}

void sbfStiffMatrixBand6::allocate()
{
    clean();
    data_ = new double [blockSize_*numBlocks_];
    null();
    indJ_ = new int [numNodes_*2];
    shiftInd_ = new int [numNodes_+1];//+1 to allow unique iteration through rows, i.e. from shiftInd_[ct] to shiftInd_[ct+1]
    if(numBlocksAlter_ > 0){
        indJAlter_ = new int [numNodes_*2];
        shiftIndAlter_ = new int [numNodes_+1];
        ptrDataAlter_ = new double * [numBlocksAlter_];
        for(int ct = 0; ct < numBlocksAlter_; ++ct) ptrDataAlter_[ct] = nullptr;
    }
    columnsIndsPtrs_.resize(numNodes_);
    columnsIndsPtrsAlter_.resize(numNodes_);
}

void sbfStiffMatrixBand6::setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter)
{
    clean();
    numBlocks_ = numBlocks;
    numBlocksAlter_ = numBlocksAlter;
    numNodes_ = numNodes;
    allocate();
}

void sbfStiffMatrixBand6::updateIndexesFromMesh(int *begin, int *end)
{
    std::vector<std::set<int>> indexes;
    std::vector<int> elementIDs(begin, end);
    numNodes_ = mesh_->numNodes();
    indexes.resize(numNodes_);
    for(auto ind : elementIDs) {
        std::vector<int> nodeIDs = mesh_->elemPtr(ind)->indexes();
        for(auto node1 : nodeIDs) for(auto node2 : nodeIDs) indexes[node1].insert(node2);
    }
    int indLength = 0;
    for(auto &row : indexes) indLength += *row.rbegin() - *row.begin() + 1;

    if( type_ & MatrixType::FULL_MATRIX) {
        setNumBlocksNodes(indLength, numNodes_, 0);
        int count = 0;
        int ct = 0;
        shiftInd_[count++] = ct;
        for(auto &row : indexes) {
            indJ_[ct++] = *row.begin();
            indJ_[ct++] = *row.rbegin();
            shiftInd_[count] = shiftInd_[count-1] + indJ_[ct-1] - indJ_[ct-2] + 1;
            ++count;
        }
    }//MatrixType::FULL_MATRIX
    else if(type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX){
        int numBeforeDiagonal = 0, numAfterDiagonal = 0;
        int size = static_cast<int>(indexes.size());
        for(int ct = 0; ct < size; ++ct) {
            auto &row = indexes[ct];
            numBeforeDiagonal += ct - *row.begin();
            numAfterDiagonal += *row.rbegin() - ct;
        }
        if (type_ & UP_TREANGLE_MATRIX) numBlocksAlter_ = numBeforeDiagonal;
        else numBlocksAlter_ = numAfterDiagonal;
        numBlocks_ = indLength - numBlocksAlter_;
        if ( !(type_ & MatrixType::CHOL_FACTOR || type_ & MatrixType::INCOMPLETE_CHOL || type_ & MatrixType::LDLT_FACTOR) ) {
            setNumBlocksNodes(numBlocks_, numNodes_, numBlocksAlter_);
            int countNorm = 0;
            int ctNorm = 0;
            int countAlter = 0;
            int ctAlter = 0;
            shiftInd_[countNorm++] = ctNorm;
            shiftIndAlter_[countAlter++] = ctAlter;
            size = static_cast<int>(indexes.size());
            for(int ct = 0; ct < size; ++ct) {
                auto &row = indexes[ct];
                int first = *row.begin();
                int last = *row.rbegin();
                if (type_ & UP_TREANGLE_MATRIX) {
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
                shiftInd_[countNorm] = shiftInd_[countNorm-1] + indJ_[ctNorm-1] - indJ_[ctNorm-2] + 1;
                ++countNorm;
                shiftIndAlter_[countAlter] = shiftIndAlter_[countAlter-1] + indJAlter_[ctAlter-1] - indJAlter_[ctAlter-2] + 1;
                ++countAlter;
            }
            updataAlterPtr();
        }
        else {
            numBlocksAlter_ = 0;
            setNumBlocksNodes(numBlocks_, numNodes_, numBlocksAlter_);
            int countNorm = 0;
            int ctNorm = 0;
            shiftInd_[countNorm++] = ctNorm;
            size = static_cast<int>(indexes.size());
            for(int ct = 0; ct < size; ++ct) {
                auto &row = indexes[ct];
                int first = *row.begin();
                int last = *row.rbegin();
                if (type_ & UP_TREANGLE_MATRIX) {
                    indJ_[ctNorm++] = ct;
                    indJ_[ctNorm++] = last;
                }
                else {
                    indJ_[ctNorm++] = first;
                    indJ_[ctNorm++] = ct;
                }
                shiftInd_[countNorm] = shiftInd_[countNorm-1] + indJ_[ctNorm-1] - indJ_[ctNorm-2] + 1;
                ++countNorm;
            }
        }
    }//type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX
    else
        throw std::runtime_error("Not supported matrix type");
    updateColumnsIndsPtrs();
}

void sbfStiffMatrixBand6::updateIndexesFromMesh(int startElemIndex, int stopElemIndex)
{
    std::vector<int> indexes;
    indexes.resize(stopElemIndex - startElemIndex);
    for(int ct = startElemIndex; ct < stopElemIndex; ++ct) indexes[ct] = ct;
    updateIndexesFromMesh(indexes.data(), indexes.data()+indexes.size());
}

void sbfStiffMatrixBand6::updateIndexesFromMesh()
{
    updateIndexesFromMesh(0, mesh_->numElements());
}

void sbfStiffMatrixBand6::null()
{
    const int length = numBlocks_*blockSize_;
    for(int ct = 0; ct < length; ct++) data_[ct] = 0.0;
}

void sbfStiffMatrixBand6::updataAlterPtr()
{
    if((type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX) && numBlocksAlter_ > 0){
        int count = 0;
        for(int ctIndI = 0; ctIndI < numNodes_; ctIndI++){
            for(int ctIndJ = indJAlter_[ctIndI*2]; ctIndJ <= indJAlter_[ctIndI*2+1]; ctIndJ++)
                ptrDataAlter_[count++] = blockPtr(ctIndJ, ctIndI);
        }
    }
}

double *sbfStiffMatrixBand6::blockPtr(int indI, int indJ)
{
    //Search in regular storage ONLY
    int shift = shiftInd_[indI];
    double *base = data_ + shift*blockSize_;
    if ( indJ < indJ_[indI*2] || indJ > indJ_[indI*2+1] )
        return nullptr;
    return base + (indJ - indJ_[indI*2])*blockSize_;
}

void sbfStiffMatrixBand6::updateColumnsIndsPtrs()
{
    for(auto &col : columnsIndsPtrs_) col.clear();
    for(auto &col : columnsIndsPtrsAlter_) col.clear();
    for(int indI = 0; indI < numNodes_; ++indI) {
        for(int indJ = indJ_[indI*2]; indJ <= indJ_[indI*2+1]; ++indJ)
            columnsIndsPtrs_[indJ].push_back(std::make_pair(indI, data_ + (shiftInd_[indI] + indJ - indJ_[indI*2])*blockSize_));
    }
    if((type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX) && numBlocksAlter_ > 0){
        int count = 0;
        for(int indI = 0; indI < numNodes_; ++indI){
            for(int indJ = indJAlter_[indI*2]; indJ <= indJAlter_[indI*2+1]; ++indJ)
                columnsIndsPtrsAlter_[indJ].push_back(std::make_pair(indI, ptrDataAlter_[count++]));
        }
    }
}

sbfMatrixIterator *sbfStiffMatrixBand6::createIterator()
{
    return new sbfStiffMatrixBand6Iterator(this);
}

void sbfStiffMatrixBand6::compute(int startID, int stopID)
{
    if( !propSet_ ) throw std::runtime_error("nullptr in propSet");
    null();
    sbfElement *elem = nullptr;
    sbfElemStiffMatrix *elemStiff = nullptr;
    std::map<ElementType, sbfElemStiffMatrix*> mapStiff;
    mapStiff[ElementType::BEAM_LINEAR_6DOF] = new sbfElemStiffMatrixBeam6Dof(elem, propSet_);
    std::unique_ptr<sbfMatrixIterator> iteratorPtr(createIterator());
    sbfMatrixIterator *iterator = iteratorPtr.get();
    for(int ctElem = startID; ctElem < stopID; ++ctElem) {//Loop over elements
        elem = mesh_->elemPtr(ctElem);
        assert(mapStiff.count(elem->type()) == 1);
        elemStiff = mapStiff[elem->type()];
        elemStiff->setElem(elem);
        elemStiff->computeSM();
        auto listIDData = elemStiff->rowColData();
        iterator->setToRow(listIDData.front().first.first);
        for(auto idData : listIDData) {
            double *data = nullptr;
            if( idData.first.first != iterator->row() || iterator->column() > idData.first.second)
                iterator->setToRow(idData.first.first);
            while(iterator->isValid())
                if(iterator->column() == idData.first.second && iterator->isInNormal()) {
                    data = const_cast<double *>(iterator->data());
                    break;
                }
                else iterator->next();
            if ( !data )
                throw std::runtime_error("Can't find target block in global stiffness matrix");
            for(int ct = 0; ct < blockSize_; ++ct) data[ct] += idData.second[ct];
        }
    }//Loop over elements
}

sbfStiffMatrix *sbfStiffMatrixBand6::createChol()
{
    assert(this->isValid());
    sbfStiffMatrixBand6 *cholFactor = new sbfStiffMatrixBand6(mesh_, nullptr, MatrixType::DOWN_TREANGLE_MATRIX | MatrixType::CHOL_FACTOR);

    cholFactor->null();

    std::unique_ptr<sbfMatrixIterator> iteratorThis(createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorChol(cholFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow0(cholFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow1(cholFactor->createIterator());

//    //TESTING
//    {
//        std::ofstream matrix("matrix.dat");
//        for(int ctRow = 0; ctRow < mesh_->numNodes(); ++ctRow)
//            for(int ctDofI = 0; ctDofI < 6; ++ctDofI) {
//                matrix << "[";
//                for(int ctCol = 0; ctCol < mesh_->numNodes(); ++ctCol) {
//                    double *data = this->blockPtr(ctRow, ctCol);
//                    if( data ) for(int ctDofJ = 0; ctDofJ < 6; ++ctDofJ)
//                        matrix << data[ctDofI*6+ctDofJ] << ",\t";
//                    else for(int ctDofJ = 0; ctDofJ < 6; ++ctDofJ)
//                        matrix << 0.0 << ",\t";
//                }
//                matrix << "]," << std::endl;
//            }
//    }

    double *blockDiag, *blockCt, *blockCt1, *block;
    double *blockDiagTarget, *blockTarget;
    bool isDirect;
    int sumShift[blockDim_][blockDim_];
    {
        int shift = blockDim_;
        for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2)
            sumShift[ct1][ct2] = shift++;
    }
    for(int diagCt = 0; diagCt < numNodes_; diagCt++){//Loop on block rows
        //Process diagonal block
        //if(numNodes_ > 100 && (diagCt % (numNodes_/100) == 0)) report.updateProgress(0, numNodes_, diagCt);

        blockDiag = iteratorThis->diagonal(diagCt);
        blockDiagTarget = iteratorChol->diagonal(diagCt);

        //Nulling above diagonal elements
        for(int ctI = 0; ctI < blockDim_; ++ctI) for(int ctJ = ctI+1; ctJ < blockDim_; ++ctJ) blockDiagTarget[ctI*blockDim_ + ctJ] = 0;

        const int sumLength = (blockSize_ - blockDim_)/2 + blockDim_;
        double sum[sumLength];// 00 11 22 33 44 55 66 01 02 ... 12 13 ... - regular and cross sums
        for(int ct = 0; ct < sumLength; ++ct) sum[ct] = 0.0;

        iteratorChol->setToRow(diagCt);
        while(iteratorChol->isValid()){
            if (iteratorChol->column() >= diagCt) break;
            blockCt = iteratorChol->data();
//            report("process sum in row", diagCt, iteratorChol->column());
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = 0; ct2 < blockDim_; ++ct2)
                sum[ct1] += blockCt[ct1*blockDim_ + ct2]*blockCt[ct1*blockDim_ + ct2];
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) {
                double tmp = 0;
                for(int ct3 = 0; ct3 < blockDim_; ++ct3)
                    tmp += blockCt[ct1*blockDim_ + ct3]*blockCt[ct2*blockDim_ + ct3];
                sum[sumShift[ct1][ct2]] += tmp;
            }
            iteratorChol->next();
        }//Loop on blocks in row
        int shift = blockDim_;
//        report("process diagonal", diagCt);
        for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
//            report(blockDiag[ct1*(blockDim_+1)], sum[ct1]);
            blockDiagTarget[ct1*(blockDim_+1)] = std::sqrt(blockDiag[ct1*(blockDim_+1)] - sum[ct1]);
            assert(std::isfinite(blockDiagTarget[ct1*(blockDim_+1)]));
            for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) {
                blockDiagTarget[ct2*blockDim_+ct1] = (blockDiag[ct2*blockDim_+ct1] - sum[sumShift[ct1][ct2]]) / blockDiagTarget[ct1*(blockDim_+1)];
                assert(std::isfinite(blockDiagTarget[ct2*blockDim_+ct1]));
                sum[ct2] += blockDiagTarget[ct2*blockDim_+ct1]*blockDiagTarget[ct2*blockDim_+ct1];
            }
            for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) for(int ct3 = ct2+1; ct3 < blockDim_; ++ct3)
                sum[sumShift[ct2][ct3]] += blockDiagTarget[ct2*blockDim_ + ct1]*blockDiagTarget[ct3*blockDim_ + ct1];
//            for(int ct = 0; ct < blockDim_; ++ct)
//                report(blockDiagTarget[ct*blockDim_+0], blockDiagTarget[ct*blockDim_+1], blockDiagTarget[ct*blockDim_+2], blockDiagTarget[ct*blockDim_+3], blockDiagTarget[ct*blockDim_+4], blockDiagTarget[ct*blockDim_+5]);
        }
        //Process diagonal block - END

        //Process blocks under current diagonal

        double rowSum[blockSize_];
        double blockData[blockSize_];

        iteratorChol->setToColumn(diagCt);
        iteratorThis->setToColumn(diagCt);
        while(iteratorChol->isValid() && iteratorThis->isValid()){//Loop on blocks under current diagonal block
            int rowCt = iteratorChol->row();
            if(rowCt <= diagCt){
                iteratorChol->next();
                continue; //Skip abowe rows
            }
            int rowCtThis = iteratorThis->row();
            if(rowCtThis < rowCt){
                iteratorThis->next();
                continue; //Skip abowe rows
            }
            assert(rowCt == rowCtThis);

            blockTarget = iteratorChol->data();

            //May be at alternative storage
            block = iteratorThis->data(&isDirect);

            assert(isDirect);

            if(isDirect) for(int ct = 0; ct < blockSize_; ct++) blockData[ct] = block[ct];
            else for(int ctI = 0; ctI < blockDim_; ctI++) for(int ctJ = 0; ctJ < blockDim_; ctJ++) blockData[ctI*blockDim_+ctJ] = block[ctJ*blockDim_+ctI];
            for(int ct = 0; ct < blockSize_; ct++) rowSum[ct] = 0.0;

            iteratorCholRow0->setToRow(rowCt);
            iteratorCholRow1->setToRow(diagCt);
            int col0 = iteratorCholRow0->column();
            int col1 = iteratorCholRow1->column();
            while(iteratorCholRow0->isValid() && iteratorCholRow1->isValid()) {
                col0 = iteratorCholRow0->column();
                col1 = iteratorCholRow1->column();
                if (col0 >= diagCt) break;
                //TODO rewise this code for band matrix (copyed from block matrix)
                if (col0 < col1) {
                    iteratorCholRow0->next();
                    col0 = iteratorCholRow0->column();
                    continue;
                }
                if (col0 > col1) {
                    iteratorCholRow1->next();
                    col1 = iteratorCholRow1->column();
                    continue;
                }
                assert(iteratorCholRow0->column() == iteratorCholRow1->column());
                //OK, found equal columns ID
                blockCt = iteratorCholRow0->data();
                blockCt1 = iteratorCholRow1->data();
                //collect sums
//                report("collect summ", rowCt, iteratorCholRow0->column());
                for(int ctI = 0, shift = 0; ctI < blockDim_; ++ctI)
                    for(int ctJ = 0; ctJ < blockDim_; ++ctJ, ++shift)
                        for(int ct = 0; ct < blockDim_; ++ct)
                            rowSum[shift] += blockCt[ctI*blockDim_ + ct]*blockCt1[ctJ*blockDim_ + ct];
                iteratorCholRow0->next();
                iteratorCholRow1->next();
            }//Loop on blocks in row
//            report("process block", rowCt, diagCt);
            for(int ctJ = 0; ctJ < blockDim_; ++ctJ) {
                for(int ctI = 0; ctI < blockDim_; ++ctI) {
                    blockTarget[ctI*blockDim_ + ctJ] = (blockData[ctI*blockDim_ + ctJ] - rowSum[ctI*blockDim_ + ctJ]) / blockDiagTarget[ctJ*blockDim_ + ctJ];
                    assert(std::isfinite(blockTarget[ctI*blockDim_ + ctJ]));
                    if(ctJ != blockDim_ - 1) for(int ct1 = 0; ct1 <= ctJ; ++ct1)
                        rowSum[ctI*blockDim_ + ctJ + 1] += blockTarget[ctI*blockDim_ + ct1]*blockDiagTarget[(ctJ+1)*blockDim_ + ct1];
                }
            }
//            for(int ct = 0; ct < blockDim_; ++ct)
//                report(blockTarget[ct*blockDim_+0], blockTarget[ct*blockDim_+1], blockTarget[ct*blockDim_+2], blockTarget[ct*blockDim_+3], blockTarget[ct*blockDim_+4], blockTarget[ct*blockDim_+5]);
            iteratorChol->next();
            iteratorThis->next();
        }//Loop on blocks under current diagonal block

        //Process blocks under diagonal - END
    }//Loop on block rows

    //report.finalizeProgress();
    return cholFactor;
}

sbfStiffMatrix *sbfStiffMatrixBand6::createLDLT()
{
    assert(this->isValid());
    sbfStiffMatrixBand6 *LDFactor = new sbfStiffMatrixBand6(mesh_, nullptr, MatrixType::DOWN_TREANGLE_MATRIX | MatrixType::LDLT_FACTOR);

    LDFactor->null();

    std::unique_ptr<sbfMatrixIterator> iteratorThis(createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorL(LDFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorLRow0(LDFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorLRow1(LDFactor->createIterator());

//    //TESTING
//    {
//        std::ofstream matrix("matrix.dat");
//        for(int ctRow = 0; ctRow < mesh_->numNodes(); ++ctRow)
//            for(int ctDofI = 0; ctDofI < 6; ++ctDofI) {
//                matrix << "[";
//                for(int ctCol = 0; ctCol < mesh_->numNodes(); ++ctCol) {
//                    double *data = this->blockPtr(ctRow, ctCol);
//                    if( data ) for(int ctDofJ = 0; ctDofJ < 6; ++ctDofJ)
//                        matrix << data[ctDofI*6+ctDofJ] << ",\t";
//                    else for(int ctDofJ = 0; ctDofJ < 6; ++ctDofJ)
//                        matrix << 0.0 << ",\t";
//                }
//                matrix << "]," << std::endl;
//            }
//    }

    double *blockDiag, *blockCt, *blockCt1, *block;
    double *blockDiagTarget, *blockTarget;
    bool isDirect;
    int sumShift[blockDim_][blockDim_];
    {
        int shift = blockDim_;
        for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2)
            sumShift[ct1][ct2] = shift++;
    }
    for(int diagCt = 0; diagCt < numNodes_; diagCt++){//Loop on block rows
        //Process diagonal block
        //if(numNodes_ > 100 && (diagCt % (numNodes_/100) == 0)) report.updateProgress(0, numNodes_, diagCt);

        blockDiag = iteratorThis->diagonal(diagCt);
        blockDiagTarget = iteratorL->diagonal(diagCt);

        //Nulling above diagonal elements
        for(int ctI = 0; ctI < blockDim_; ++ctI) for(int ctJ = ctI+1; ctJ < blockDim_; ++ctJ) blockDiagTarget[ctI*blockDim_ + ctJ] = 0;

        const int sumLength = (blockSize_ - blockDim_)/2 + blockDim_;
        double sum[sumLength];// 00 11 22 33 44 55 66 01 02 ... 12 13 ... - regular and cross sums
        for(int ct = 0; ct < sumLength; ++ct) sum[ct] = 0.0;

        iteratorL->setToRow(diagCt);
        while(iteratorL->isValid()){
            if (iteratorL->column() >= diagCt) break;
            blockCt = iteratorL->data();
            double *diag = iteratorL->diagonal(iteratorL->column());
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = 0; ct2 < blockDim_; ++ct2)
                sum[ct1] += blockCt[ct1*blockDim_ + ct2]*blockCt[ct1*blockDim_ + ct2]*diag[ct2*(blockDim_+1)];
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) {
                double tmp = 0;
                for(int ct3 = 0; ct3 < blockDim_; ++ct3)
                    tmp += blockCt[ct1*blockDim_ + ct3]*blockCt[ct2*blockDim_ + ct3]*diag[ct3*(blockDim_+1)];
                sum[sumShift[ct1][ct2]] += tmp;
            }
            iteratorL->next();
        }//Loop on blocks in row
        int shift = blockDim_;
        for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
            blockDiagTarget[ct1*(blockDim_+1)] = blockDiag[ct1*(blockDim_+1)] - sum[ct1];
            assert(std::isnormal(blockDiagTarget[ct1*blockDim_+ct1]));
            for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) {
                blockDiagTarget[ct2*blockDim_+ct1] = (blockDiag[ct2*blockDim_+ct1] - sum[sumShift[ct1][ct2]]) / blockDiagTarget[ct1*(blockDim_+1)];
                assert(std::isfinite(blockDiagTarget[ct2*blockDim_+ct1]));
                sum[ct2] += blockDiagTarget[ct2*blockDim_+ct1]*blockDiagTarget[ct2*blockDim_+ct1]*blockDiagTarget[ct1*(blockDim_+1)];
            }
            for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) for(int ct3 = ct2+1; ct3 < blockDim_; ++ct3)
                sum[sumShift[ct2][ct3]] += blockDiagTarget[ct2*blockDim_ + ct1]*blockDiagTarget[ct3*blockDim_ + ct1]*blockDiagTarget[ct1*(blockDim_+1)];
        }
        //Process diagonal block - END

        //Process blocks under current diagonal

        double rowSum[blockSize_];
        double blockData[blockSize_];

        iteratorL->setToColumn(diagCt);
        iteratorThis->setToColumn(diagCt);
        while(iteratorL->isValid() && iteratorThis->isValid()){//Loop on blocks under current diagonal block
            int rowCt = iteratorL->row();
            if(rowCt <= diagCt){
                iteratorL->next();
                continue; //Skip abowe rows
            }
            int rowCtThis = iteratorThis->row();
            if(rowCtThis < rowCt){
                iteratorThis->next();
                continue; //Skip abowe rows
            }
            assert(rowCt == rowCtThis);

            blockTarget = iteratorL->data();

            //May be at alternative storage
            block = iteratorThis->data(&isDirect);

            assert(isDirect);

            if(isDirect) for(int ct = 0; ct < blockSize_; ct++) blockData[ct] = block[ct];
            else for(int ctI = 0; ctI < blockDim_; ctI++) for(int ctJ = 0; ctJ < blockDim_; ctJ++) blockData[ctI*blockDim_+ctJ] = block[ctJ*blockDim_+ctI];
            for(int ct = 0; ct < blockSize_; ct++) rowSum[ct] = 0.0;

            iteratorLRow0->setToRow(rowCt);
            iteratorLRow1->setToRow(diagCt);
            int col0 = iteratorLRow0->column();
            int col1 = iteratorLRow1->column();
            while(iteratorLRow0->isValid() && iteratorLRow1->isValid()) {
                col0 = iteratorLRow0->column();
                col1 = iteratorLRow1->column();
                if (col0 >= diagCt) break;
                //TODO rewise this code for band matrix (copyed from block matrix)
                if (col0 < col1) {
                    iteratorLRow0->next();
                    col0 = iteratorLRow0->column();
                    continue;
                }
                if (col0 > col1) {
                    iteratorLRow1->next();
                    col1 = iteratorLRow1->column();
                    continue;
                }
                assert(iteratorLRow0->column() == iteratorLRow1->column());
                //OK, found equal columns ID
                blockCt = iteratorLRow0->data();
                blockCt1 = iteratorLRow1->data();
                //collect sums
//                report("collect summ", rowCt, iteratorCholRow0->column());
                for(int ctI = 0, shift = 0; ctI < blockDim_; ++ctI)
                    for(int ctJ = 0; ctJ < blockDim_; ++ctJ, ++shift)
                        for(int ct = 0; ct < blockDim_; ++ct)
                            rowSum[shift] += blockCt[ctI*blockDim_ + ct]*blockCt1[ctJ*blockDim_ + ct]*blockDiagTarget[ct*(blockDim_+1)];
                iteratorLRow0->next();
                iteratorLRow1->next();
            }//Loop on blocks in row
//            report("process block", rowCt, diagCt);
            for(int ctJ = 0; ctJ < blockDim_; ++ctJ) {
                for(int ctI = 0; ctI < blockDim_; ++ctI) {
                    blockTarget[ctI*blockDim_ + ctJ] = (blockData[ctI*blockDim_ + ctJ] - rowSum[ctI*blockDim_ + ctJ]) / blockDiagTarget[ctJ*blockDim_ + ctJ];
                    assert(std::isfinite(blockTarget[ctI*blockDim_ + ctJ]));
                    if(ctJ != blockDim_ - 1) for(int ct1 = 0; ct1 <= ctJ; ++ct1)
                        rowSum[ctI*blockDim_ + ctJ + 1] += blockTarget[ctI*blockDim_ + ct1]*blockDiagTarget[(ctJ+1)*blockDim_ + ct1]*blockDiagTarget[ct1*(blockDim_+1)];
                }
            }
//            for(int ct = 0; ct < blockDim_; ++ct)
//                report(blockTarget[ct*blockDim_+0], blockTarget[ct*blockDim_+1], blockTarget[ct*blockDim_+2], blockTarget[ct*blockDim_+3], blockTarget[ct*blockDim_+4], blockTarget[ct*blockDim_+5]);
            iteratorL->next();
            iteratorThis->next();
        }//Loop on blocks under current diagonal block

        //Process blocks under diagonal - END
    }//Loop on block rows

    //report.finalizeProgress();
    return LDFactor;
}

void sbfStiffMatrixBand6::solve_L_LT_u_eq_f(double *u, double *f, sbfMatrixIterator *iterator)
{
    sbfMatrixIterator *iter = iterator;
    if ( !iterator ) iter = createIterator();
    double sum[blockDim_], vecPart[blockDim_];
    double *block = data_;
    sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;

    //L u' = f
    int ctRow = 0;
    int ctColumn = 0;
    for (int ctBlock = 0; ctBlock < numBlocks_; ctBlock++, ctColumn++) {//Loop on blocks
        if( ctBlock == shiftInd_[ctRow+1] ) {
            ctRow++;
            ctColumn = indJ_[ctRow*2];
            sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;
        }
        if( ctRow != ctColumn ){//process non diagonal block
            //TODO this is not fatal, but still it should be implemented with iterator
            block = blockPtr(ctRow, ctColumn);
            if (!block) continue;
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
                vecPart[ct1] = u[ctColumn*blockDim_ + ct1];
                for(int ct2 = 0; ct2 < blockDim_; ++ct2)
                    sum[ct2] += block[ct2*blockDim_ + ct1]*vecPart[ct1];
            }
        }//process non diagonal block
        else {
            block = blockPtr(ctRow, ctRow);
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
                vecPart[ct1] = (f[ctRow*blockDim_ + ct1] - sum[ct1]) / block[ct1*(blockDim_+1)];
                for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2)
                    sum[ct2] += block[ct2*blockDim_ + ct1]*vecPart[ct1];
                u[ctRow*blockDim_ + ct1] = vecPart[ct1];
            }
        }
    }//Loop on blocks
    //L^T u = u'
    for (int ctRow = numNodes_ - 1; ctRow >= 0; ctRow--) {//Loop on rows
        sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;
        iter->setToColumnInverse(ctRow);
        while(!iter->isDiagonal()) {
            block = iter->data();
            int ctColumn = iter->row();
            for(int ct = 0; ct < blockDim_; ++ct)
                vecPart[ct] = u[ctColumn*blockDim_ + ct];
            //transposed indexing to block
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = 0; ct2 < blockDim_; ++ct2)
                sum[ct1] += block[ct2*blockDim_ + ct1]*vecPart[ct2];
            iter->next();
        }//Loop on non diaonal blocks
        block = iter->diagonal(ctRow);
        for(int ct1 = blockDim_-1; ct1 >= 0; --ct1) {
            vecPart[ct1] = (u[ctRow*blockDim_ + ct1] - sum[ct1]) / block[ct1*(blockDim_+1)];
            for(int ct2 = ct1-1; ct2 >= 0; --ct2)
                sum[ct2] += block[ct1*blockDim_+ct2]*vecPart[ct1];
        }
        for(int ct = 0; ct < blockDim_; ++ct)
            u[ctRow*blockDim_ + ct] = vecPart[ct];
    }//Loop on rows

    if ( !iterator ) delete iter;
}

void sbfStiffMatrixBand6::solve_L_D_LT_u_eq_f(double *u, double *f, sbfMatrixIterator *iterator)
{
    sbfMatrixIterator *iter = iterator;
    if ( !iterator ) iter = createIterator();
    double sum[blockDim_], vecPart[blockDim_];
    double *block = data_;
    sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;

    //L u' = f
    int ctRow = 0;
    int ctColumn = 0;
    for (int ctBlock = 0; ctBlock < numBlocks_; ctBlock++, ctColumn++) {//Loop on blocks
        if( ctBlock == shiftInd_[ctRow+1] ) {
            ctRow++;
            ctColumn = indJ_[ctRow*2];
            sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;
        }
        if( ctRow != ctColumn ){//process non diagonal block
            //TODO this is not fatal, but still it should be implemented with iterator
            block = blockPtr(ctRow, ctColumn);
            if (!block) continue;
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
                vecPart[ct1] = u[ctColumn*blockDim_ + ct1];
                for(int ct2 = 0; ct2 < blockDim_; ++ct2)
                    sum[ct2] += block[ct2*blockDim_ + ct1]*vecPart[ct1];
            }
        }//process non diagonal block
        else {
            block = blockPtr(ctRow, ctRow);
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
                vecPart[ct1] = (f[ctRow*blockDim_ + ct1] - sum[ct1]) /*/ block[ct1*(blockDim_+1)]*/;
                for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2)
                    sum[ct2] += block[ct2*blockDim_ + ct1]*vecPart[ct1];
                u[ctRow*blockDim_ + ct1] = vecPart[ct1];
            }
        }
    }//Loop on blocks
    //D u'' = u'
    for(int ct = 0; ct < numNodes_; ++ct) {
        block = blockPtr(ct, ct);
        for(int ct1 = 0; ct1 < 6; ++ct1)
            u[ct*blockDim_ + ct1] = u[ct*blockDim_ + ct1]/block[ct1*(blockDim_+1)];
    }
    //L^T u = u'
    for (int ctRow = numNodes_ - 1; ctRow >= 0; ctRow--) {//Loop on rows
        sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;
        iter->setToColumnInverse(ctRow);
        while(!iter->isDiagonal()) {
            block = iter->data();
            int ctColumn = iter->row();
            for(int ct = 0; ct < blockDim_; ++ct)
                vecPart[ct] = u[ctColumn*blockDim_ + ct];
            //transposed indexing to block
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) for(int ct2 = 0; ct2 < blockDim_; ++ct2)
                sum[ct1] += block[ct2*blockDim_ + ct1]*vecPart[ct2];
            iter->next();
        }//Loop on non diaonal blocks
        block = iter->diagonal(ctRow);
        for(int ct1 = blockDim_-1; ct1 >= 0; --ct1) {
            vecPart[ct1] = (u[ctRow*blockDim_ + ct1] - sum[ct1]) /*/ block[ct1*(blockDim_+1)]*/;
            for(int ct2 = ct1-1; ct2 >= 0; --ct2)
                sum[ct2] += block[ct1*blockDim_+ct2]*vecPart[ct1];
        }
        for(int ct = 0; ct < blockDim_; ++ct)
            u[ctRow*blockDim_ + ct] = vecPart[ct];
    }//Loop on rows

    if ( !iterator ) delete iter;
}

bool sbfStiffMatrixBand6::isValid()
{
    for(int ct = 0; ct < numNodes_; ++ct) {
        double *data = data_ + (shiftInd_[ct] + ct - indJ_[ct*2])*blockSize_;
        for(int ctDof = 0; ctDof < blockDim_; ctDof++)
            if(
                    data[ctDof*(blockDim_+1)] < 0 ||
                    !std::isnormal(data[ctDof*(blockDim_+1)])
                    )
                return false;
    }
    return true;
}

void sbfStiffMatrixBand6::read_stream(std::ifstream &in)
{

}

void sbfStiffMatrixBand6::write_stream(std::ofstream &out) const
{

}
