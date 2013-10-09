#include "sbfSElement.h"
#include "sbfMesh.h"

sbfSElement::sbfSElement()
{
    initialize();
}
sbfSElement::sbfSElement(sbfMesh * mesh, int index)
{
    initialize();
    mesh_ = mesh;
    seIndex_ = index;
}
void sbfSElement::initialize()
{
    numChildren_ = 0;
    seIndex_ = -1;
    mesh_ = nullptr;
    parent_ = nullptr;
    childrens_ = nullptr;
    regElemIndexes_ = nullptr;
    nodesIds_ = nullptr;
}
sbfSElement::~sbfSElement()
{
    if(childrens_ != nullptr) {delete [] childrens_; childrens_ = nullptr;}
    if(regElemIndexes_ != nullptr) {delete [] regElemIndexes_; regElemIndexes_ = nullptr;}
    if(nodesIds_ != nullptr) {delete [] nodesIds_; nodesIds_ = nullptr;}
}
std::vector<int> sbfSElement::regElemIndexes()
{
    //Collect regular elements indexes in all underlying (children) SE
    std::vector<int> indexes;

    if(numChildren_ && regElemIndexes_){//This is a lower level SE, containing only regular elements
        indexes.resize(numChildren_);
        for(int ct = 0; ct < numChildren_; ct++) indexes[ct] = regElemIndexes_[ct];
    }
    else if(numChildren_ && childrens_){
        for(int ct = 0; ct < numChildren_; ct++){//Loop on underlying SE's
            std::vector<int> indexesToAppend = childrens_[ct]->regElemIndexes();
            indexes.insert(indexes.end(), indexesToAppend.begin(), indexesToAppend.end());
        }
    }

    return indexes;
}
void sbfSElement::setRegElemIndexes (std::vector<int> regElemIndexes){
    //Since adding regular element, childrens_ should be void
    if(childrens_ != nullptr) {delete [] childrens_; childrens_ = nullptr;}
    if(regElemIndexes_ != nullptr) {delete [] regElemIndexes_; regElemIndexes_ = nullptr;}
    numChildren_ = regElemIndexes.size();
    regElemIndexes_ = new int [numChildren_];
    for(int ct = 0; ct < numChildren_; ct++) regElemIndexes_[ct] = regElemIndexes[ct];
}
void sbfSElement::setChildrens (std::vector<sbfSElement *> selems){
    //Since adding super elements, regElemIndexes_ should be void
    if(childrens_ != nullptr) {delete [] childrens_; childrens_ = nullptr;}
    if(regElemIndexes_ != nullptr) {delete [] regElemIndexes_; regElemIndexes_ = nullptr;}
    numChildren_ = selems.size();
    childrens_ = new sbfSElement * [numChildren_];
    for(int ct = 0; ct < numChildren_; ct++) childrens_[ct] = selems[ct];
}
void sbfSElement::addChildren(sbfSElement * selem){
    //Since adding super elements, regElemIndexes_ should be void
    if(regElemIndexes_ != nullptr) {delete [] regElemIndexes_; regElemIndexes_ = nullptr; numChildren_ = 0;}
    sbfSElement ** tmp = new sbfSElement * [numChildren_ + 1];
    if(childrens_ != nullptr){
        for(int ct = 0; ct < numChildren_; ct++) tmp[ct] = childrens_[ct];
        delete [] childrens_;
    }
    tmp[numChildren_++] = selem;
    childrens_ = tmp;
}
