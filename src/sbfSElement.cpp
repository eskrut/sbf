#include "sbfSElement.h"
#include "sbfMesh.h"
#include "sbfElement.h"
#include <set>

sbfSElement::sbfSElement()
{
    initialize();
}
sbfSElement::sbfSElement(const sbfMesh *mesh, int index)
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
    //FIXME THIS IS SUCKS!!!
    //Since adding super elements, regElemIndexes_ should be void
    if(childrens_ != nullptr) {delete [] childrens_; childrens_ = nullptr;}
    if(regElemIndexes_ != nullptr) {delete [] regElemIndexes_; regElemIndexes_ = nullptr;}
    numChildren_ = selems.size();
    childrens_ = new sbfSElement * [numChildren_];
    for(int ct = 0; ct < numChildren_; ct++) childrens_[ct] = selems[ct];
}
void sbfSElement::addChildren(sbfSElement * selem){
    //FIXME THIS IS SUCKS!!!
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

void sbfSElement::updateStat()
{
    std::array<double, FacesMapType::weightsLength> weights;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distr(0, 100);
    for(int ct = 0; ct < FacesMapType::weightsLength; ++ct) weights[ct] = distr(generator);
    processUpdateInChilds(weights);
}

sbfSElement::FacesMapType sbfSElement::processUpdateInChilds(const std::array<double, FacesMapType::weightsLength> &weights)
{
    FacesMapType thisFaces(weights);
    if(childrens_)
        for(int ct = 0; ct < numChildren_; ++ct){
            auto childFaces(childrens_[ct]->processUpdateInChilds(weights));
            for(const auto &rec : childFaces.map)
                thisFaces.map.insert(rec);
        }
    if(regElemIndexes_) {
        sbfMesh *m = const_cast<sbfMesh*>(this->mesh_);
        for(int ct = 0; ct < numChildren_; ++ct) {
            sbfElement *elem = m->elemPtr(regElemIndexes_[ct]);
            auto faces = elem->facesNodesIndexes();
            for(auto &f : faces)
                thisFaces.addFace(std::move(f));
        }
    }
    std::set<int> allNodes, outerNodes;
    FacesMapType tmp(weights);
    for(const auto &rec : thisFaces.map) {
        if(thisFaces.map.count(rec.first) == 1) {
            for(auto it : rec.second)
                outerNodes.insert(it);
            tmp.map.insert(rec);
        }
        for(auto it : rec.second)
            allNodes.insert(it);
    }
    for(auto it : outerNodes) outerNodes_.insert(it);
    for(auto it : allNodes) if ( !outerNodes.count(it) ) innerNodes_.insert(it);
    stat_.numOuterNodes = outerNodes.size();
    stat_.numInnerNodes = allNodes.size() - outerNodes.size();
    stat_.numSEelements = childrens_ ? numChildren_ : 0;
    stat_.numAverallNodes = regElemIndexes_ ? allNodes.size() : 0;
    if(childrens_) for(int ct = 0; ct < numChildren_; ++ct) stat_.numAverallNodes += childrens_[ct]->stat_.numAverallNodes;
    return tmp;
}
