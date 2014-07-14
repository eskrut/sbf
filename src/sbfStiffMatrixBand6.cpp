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
        //TODO is it true?
        assert(numBeforeDiagonal == numAfterDiagonal);
        assert(numBeforeDiagonal == (indLength-numNodes_)/2);
        if (type_ & UP_TREANGLE_MATRIX) numBlocksAlter_ = numBeforeDiagonal;
        else numBlocksAlter_ = numAfterDiagonal;
        numBlocks_ = indLength - numBlocksAlter_;
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
    }//type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX
    else
        throw std::runtime_error("Not supported matrix type");
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
    sbfStiffMatrixBand6 *cholFactor = new sbfStiffMatrixBand6(mesh_, nullptr, MatrixType::DOWN_TREANGLE_MATRIX | MatrixType::CHOL_FACTOR);

    cholFactor->null();

    std::unique_ptr<sbfMatrixIterator> iteratorThis(createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorChol(cholFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow0(cholFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow1(cholFactor->createIterator());

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
        for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
            blockDiagTarget[ct1*(blockDim_+1)] = std::sqrt(blockDiag[ct1*(blockDim_+1)] - sum[ct1]);
            for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2) {
                blockDiagTarget[ct2*blockDim_+ct1] = (blockDiag[ct2*blockDim_+ct1] - sum[shift++]) / blockDiagTarget[ct1*(blockDim_+1)];
                sum[ct2] += blockDiagTarget[ct2*blockDim_+ct1]*blockDiagTarget[ct2*blockDim_+ct1];
                for(int ct3 = ct2+1; ct3 < blockDim_; ++ct3)
                    sum[sumShift[ct2][ct3]] += blockDiagTarget[ct2*blockDim_ + ct1]*blockDiagTarget[ct3*blockDim_ + ct1];
            }
        }
        //Process diagonal block - END

        //Process blocks under current diagonal

        double rowSum[blockSize_];
        double blockData[blockSize_];

        iteratorChol->setToColumn(diagCt);
        iteratorThis->setToColumn(diagCt);
        while(iteratorChol->isValid()){//Loop on blocks under current diagonal block
            int rowCt = iteratorChol->row();
            if(rowCt <= diagCt){
                iteratorChol->next();
                iteratorThis->next();
                continue; //Skip abowe rows
            }

            blockTarget = iteratorChol->data();

            //May be at alternative storage
            block = iteratorThis->data(&isDirect);

            if(isDirect) for(int ct = 0; ct < blockSize_; ct++) blockData[ct] = block[ct];
            else for(int ctI = 0; ctI < blockDim_; ctI++) for(int ctJ = 0; ctJ < blockDim_; ctJ++) blockData[ctI*blockDim_+ctJ] = block[ctJ*blockDim_+ctI];
            for(int ct = 0; ct < blockSize_; ct++) rowSum[ct] = 0.0;

            iteratorCholRow0->setToRow(rowCt);
            iteratorCholRow1->setToRow(diagCt);
            int col0 = iteratorCholRow0->column();
            int col1 = iteratorCholRow1->column();
            while(iteratorCholRow0->isValid() && iteratorCholRow1->isValid()) {
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
                //OK, found equal columns ID
                blockCt = iteratorCholRow0->data();
                blockCt1 = iteratorCholRow1->data();
                //collect sums
                for(int ctI = 0, shift = 0; ctI < blockDim_; ++ctI)
                    for(int ctJ = 0; ctJ < blockDim_; ++ctJ, ++shift)
                        for(int ct = 0; ct < blockDim_; ++ct)
                            rowSum[shift] += blockCt[ctI*blockDim_ + ct]*blockCt1[ctJ*blockDim_ + ct];
                iteratorCholRow0->next();
                iteratorCholRow1->next();
            }//Loop on blocks in row
            for(int ctJ = 0; ctJ < blockDim_; ++ctJ) {
                for(int ctI = 0; ctI < blockDim_; ++ctI) {
                    blockTarget[ctI*blockDim_ + ctJ] = (blockData[ctI*blockDim_ + ctJ] - rowSum[ctI*blockDim_ + ctJ]) / blockDiagTarget[ctJ*blockDim_ + ctJ];
                    if(ctJ != blockDim_ - 1) for(int ct1 = 0; ct1 <= ctJ; ++ct1)
                        rowSum[ctI*blockDim_ + ctJ + 1] += blockTarget[ctI*blockDim_ + ct1]*blockDiagTarget[(ctJ+1)*blockDim_ + ct1];
                }
            }
            iteratorChol->next();
            iteratorThis->next();
        }//Loop on blocks under current diagonal block

        //Process blocks under diagonal - END
    }//Loop on block rows

    //report.finalizeProgress();
    return cholFactor;
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
    for (int ctBlock = 0; ctBlock < numBlocks_; ctBlock++) {//Loop on blocks
        if( ctBlock == shiftInd_[ctRow+1] ) {
            ctRow++;
            sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;
        }
        ctColumn = indJ_[ctRow*2];
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
            for(int ct1 = 0; ct1 < blockDim_; ++ct1) {
                vecPart[ct1] = (f[ctRow*blockDim_ + ct1] - sum[ct1]) / block[ct1*(blockDim_+1)];
                for(int ct2 = ct1+1; ct2 < blockDim_; ++ct2)
                    sum[ct2] += block[ct2*blockDim_ + ct1]*vecPart[ct1];
                u[ctRow*blockDim_ + ct1] = vecPart[ct1];
            }
        }
        block += blockSize_;
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
