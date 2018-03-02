#include "sbfElementGroup.h"
#include "sbfMesh.h"
#include "sbfElement.h"
#include "sbfAdditions.h"

sbfElementGroup::sbfElementGroup() : sbfGroup()
{}
sbfElementGroup::~sbfElementGroup()
{}

void sbfElementGroup::clearGroup()
{
    list_.clear();
}
void sbfElementGroup::reserve(int newSize)
{
    list_.reserve(newSize);
}
void sbfElementGroup::addElement(const int element, bool checkDuplicate)
{
    if(checkDuplicate)
        for(unsigned int ct = 0; ct < list_.size(); ct++)
        {if(list_[ct] == element)
            return;}
    list_.push_back(element);
}

int sbfElementGroup::element(const int sequenceNumber)
{
    return list_[sequenceNumber];
}
int sbfElementGroup::numElems()
{
    return (int)list_.size();
}
ElementType sbfElementGroup::type()
{
    //Return element type of groupe; if many types or none return -1
    if(list_.empty())
        return ElementType::NO_DEFINED_ELEMENT;
    ElementType type = mesh_->elem(list_[0]).type();
    for(int ct = 0; ct < numElems(); ct++)
    {
        if(type != mesh_->elem(list_[ct]).type())
            return ElementType::NO_DEFINED_ELEMENT;
    }
    return type;
}
void sbfElementGroup::setMesh(sbfMesh *mesh)
{
    mesh_ = mesh;
}
void sbfElementGroup::setMtr(const int mtr_)
{
    int nElem = numElems();
    for(int ct = 0; ct < nElem; ct++)
        mesh_->elem(list_[ct]).setMtr(mtr_);
}
std::vector<int> sbfElementGroup::elemIndList()
{
    return list_;
}
std::vector<int> sbfElementGroup::nodeIndList()
{
    std::vector<int> nodeList;
    int allNodes = 0, nElem = numElems();
    for(int ct = 0; ct < nElem; ct++) allNodes += mesh_->elem(list_[ct]).numNodes();
    nodeList.reserve(allNodes*sizeof(int));
    for(int ct = 0; ct < nElem; ct++){
        sbfElement *el = mesh_->elemPtr(list_[ct]);
        int nNode = el->numNodes();
        for(int ct1 = 0; ct1 < nNode; ct1++){
            int node = el->nodeIndex(ct1);
            /*bool flag = false;
            int size = (int)nodeList.size();
            for(int ct2 = 0; ct2 < size; ct2++){
                if(nodeList[ct] == node){
                    flag = true;
                    break;
                }
            }
            if(!flag)*/
            nodeList.push_back(node);
        }
    }
    int nodeListSize = (int)nodeList.size();
    if(nodeListSize != 0)
        sbf::quickSort<int>(&nodeList[0], 0, nodeListSize-1);
    std::vector<int> nodeList_;
    if(nodeListSize > 0){
        nodeList_.reserve(nodeListSize*sizeof(int));
        nodeList_.push_back(nodeList.front());
        for(int ct = 1; ct < nodeListSize; ct++)
            if(nodeList_.back() != nodeList[ct])
                nodeList_.push_back(nodeList[ct]);
        nodeList.clear();
    }
    return nodeList_;
}
