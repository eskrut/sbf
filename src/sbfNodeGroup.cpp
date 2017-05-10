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

//TODO add common method in sbfGroup
std::vector<int> sbfNodeGroup::intersect(const std::list<sbfNodeGroup *> &list)
{
    std::vector<std::vector<int>> ids;
    ids.reserve(list.size());
    for(const auto g : list) {
        ids.push_back(g->nodeIndList());
        std::sort(ids.back().begin(), ids.back().end());
    }
    std::vector<int> result = ids.front();
    for(auto it = ids.begin() + 1; it < ids.end(); ++it) {
        std::vector<int> localResult;
        localResult.reserve(result.size());
        std::set_intersection(result.begin(), result.end(), it->begin(), it->end(), std::back_inserter(localResult));
        result = localResult;
    }

    return result;
}
