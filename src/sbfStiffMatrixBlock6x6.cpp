#include "sbfStiffMatrixBlock6x6.h"
#include "sbfElement.h"
#include <vector>
#include <set>

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
    for(auto & row : indexes) indLength += row.size();

    if( type_ & MatrixType::FULL_MATRIX) {

    }//MatrixType::FULL_MATRIX
    else if(type_ & UP_TREANGLE_MATRIX || type_ & DOWN_TREANGLE_MATRIX){

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

sbfMatrixIterator *sbfStiffMatrixBlock6x6::createIterator() const
{

}

void sbfStiffMatrixBlock6x6::compute(int startID, int stopID)
{

}
