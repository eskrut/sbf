#ifndef SBFNODEGROUP_H
#define SBFNODEGROUP_H

#include "sbfGroup.h"

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
};

#endif // SBFNODEGROUP_H
