#include "sbfStiffMatrixBlock6x6.h"
#include "sbfElement.h"
#include <vector>
#include <set>
#include <assert.h>

#include "sbfElemStiffMatrixBeam6Dof.h"

sbfStiffMatrixBlock6x6::sbfStiffMatrixBlock6x6(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type) :
    sbfStiffMatrix(mesh, propSet, type)
{
    if ( !mesh_ ) throw std::runtime_error("nullptr in mesh");
    updateIndexesFromMesh();
}

sbfStiffMatrixBlock6x6::~sbfStiffMatrixBlock6x6()
{
    clean();
}

void sbfStiffMatrixBlock6x6::init()
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

void sbfStiffMatrixBlock6x6::clean()
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

void sbfStiffMatrixBlock6x6::allocate()
{
    clean();
    data_ = new double [blockSize_*numBlocks_];
    null();
    indJ_ = new int [numBlocks_];
    shiftInd_ = new int [numNodes_+1];//+1 to allow unique iteration through rows, i.e. from shiftInd_[ct] to shiftInd_[ct+1]
    if(numBlocksAlter_ > 0){
        indJAlter_ = new int [numBlocksAlter_];
        shiftIndAlter_ = new int [numNodes_+1];
        ptrDataAlter_ = new double * [numBlocksAlter_];
    }
}

void sbfStiffMatrixBlock6x6::setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter)
{
    clean();
    numBlocks_ = numBlocks;
    numBlocksAlter_ = numBlocksAlter;
    numNodes_ = numNodes;
    allocate();
}

void sbfStiffMatrixBlock6x6::updateIndexesFromMesh(int *begin, int *end)
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
    for(auto &row : indexes) indLength += row.size();

    if( type_ & MatrixType::FULL_MATRIX) {
        setNumBlocksNodes(indLength, numNodes_, 0);
        int count = 0;
        int ct = 0;
        shiftInd_[count++] = ct;
        for(auto &row : indexes) {
            for(auto nodeID : row)
                indJ_[ct++] = nodeID;
            shiftInd_[count++] = ct;
        }
    }//MatrixType::FULL_MATRIX
    else if(type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX){
        int numBeforeDiagonal = 0, numAfterDiagonal = 0;
        int size = static_cast<int>(indexes.size());
        for(int ct = 0; ct < size; ++ct) {
            auto &row = indexes[ct];
            for(auto &id : row) {
                if (id < ct) ++numBeforeDiagonal;
                else if (id > ct) ++numAfterDiagonal;
            }
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
            for(auto nodeID : row) {
                if (type_ & UP_TREANGLE_MATRIX) {
                    if (nodeID >= ct) indJ_[ctNorm++] = nodeID;
                    else {indJAlter_[ctAlter] = nodeID; ptrDataAlter_[ctAlter] = nullptr; ctAlter++;}
                }
                else {
                    if (nodeID <= ct) indJ_[ctNorm++] = nodeID;
                    else {indJAlter_[ctAlter] = nodeID; ptrDataAlter_[ctAlter] = nullptr; ctAlter++;}
                }
            }
            shiftInd_[countNorm++] = ctNorm;
            shiftIndAlter_[countAlter++] = ctAlter;
        }
        updataAlterPtr();
    }//type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX
    else
        throw std::runtime_error("Not supported matrix type");
}

void sbfStiffMatrixBlock6x6::updateIndexesFromMesh(int startElemIndex, int stopElemIndex)
{
    std::vector<int> indexes;
    indexes.resize(stopElemIndex - startElemIndex);
    for(int ct = startElemIndex; ct < stopElemIndex; ++ct) indexes[ct] = ct;
    updateIndexesFromMesh(indexes.data(), indexes.data()+indexes.size());
}

void sbfStiffMatrixBlock6x6::updateIndexesFromMesh()
{
    updateIndexesFromMesh(0, mesh_->numElements());
}

void sbfStiffMatrixBlock6x6::null()
{
    const int length = numBlocks_*blockSize_;
    for(int ct = 0; ct < length; ct++) data_[ct] = 0.0;
}

void sbfStiffMatrixBlock6x6::updataAlterPtr()
{
    if((type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX) && numBlocksAlter_ > 0){
        int count = 0;
        for(int ctIndI = 0; ctIndI < numNodes_; ctIndI++){
            for(int shift = shiftIndAlter_[ctIndI]; shift < shiftIndAlter_[ctIndI+1]; shift++)
                ptrDataAlter_[count++] = blockPtr(indJAlter_[shift], ctIndI);
        }
    }
}

double *sbfStiffMatrixBlock6x6::blockPtr(int indI, int indJ)
{
    //Search in regular storage ONLY
    int shift = shiftInd_[indI];
    double *base = data_ + shift*blockSize_;
    int searchLength = shiftInd_[indI+1] - shift;
    for(int ct = 0; ct < searchLength; ct++){//Search through row indI for column indJ
        if(indJ_[shift+ct] == indJ)
            return base;
        base += blockSize_;
    }

    return nullptr;
}

sbfMatrixIterator *sbfStiffMatrixBlock6x6::createIterator() /*const*/
{
    return new sbfStiffMatrixBlock6x6Iterator(this);
}

void sbfStiffMatrixBlock6x6::compute(int startID, int stopID)
{
    if( !propSet_ ) throw std::runtime_error("nullptr in propSet");
    sbfElement *elem = nullptr;
    sbfElemStiffMatrixBeam6Dof *stiffBeam6Dof = new sbfElemStiffMatrixBeam6Dof(elem, propSet_);
    for(int ctElem = startID; ctElem < stopID; ++ctElem) {//Loop over elements


    }//Loop over elements
}
