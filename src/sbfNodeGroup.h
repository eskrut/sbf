#ifndef SBFNODEGROUP_H
#define SBFNODEGROUP_H

#include "sbfGroup.h"

#include <list>

class sbfMesh;

class DECLSPEC sbfNodeGroup : public sbfGroup
//Holds information abaut nodes group
{
public:
    sbfNodeGroup();
    virtual ~sbfNodeGroup();

private:
    std::vector<int> list_;
    sbfMesh *mesh_;

public:
    void clearGroup();
    void addNode(const int nodeInd);
    int node(const int sequenceNumber);
    int numNodes();
    void setMesh(sbfMesh * mesh);
    std::vector<int> nodeIndList();

    static std::vector<int> intersect(const std::list<sbfNodeGroup *> &list);
};

#endif // SBFNODEGROUP_H
