#include "sbfNodeGroup.h"
#include "sbfMesh.h"

sbfNodeGroup::sbfNodeGroup() : sbfGroup()
{}
sbfNodeGroup::~sbfNodeGroup()
{}

void sbfNodeGroup::clearGroup()
{
    list_.clear();
}
void sbfNodeGroup::addNode(const int nodeInd)
{
    for(unsigned int ct = 0; ct < list_.size(); ct++)
    {if(list_[ct] == nodeInd)
        return;}
    list_.push_back(nodeInd);
}

int sbfNodeGroup::node(const int sequenceNumber)
{
    return list_[sequenceNumber];
}
int sbfNodeGroup::numNodes()
{
    return (int)list_.size();
}
void sbfNodeGroup::setMesh(sbfMesh *mesh)
{
    mesh_ = mesh;
}
std::vector<int> sbfNodeGroup::nodeIndList()
{
    return list_;
}
