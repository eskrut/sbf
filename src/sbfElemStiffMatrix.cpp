#include "sbfElemStiffMatrix.h"

#include "sbfElement.h"
#include "sbfNode.h"
#include "sbfMesh.h"

sbfElemStiffMatrix::sbfElemStiffMatrix(sbfElement *elem, sbfPropertiesSet *propSet) :
    elem_(elem),
    propSet_(propSet)
{
}

void sbfElemStiffMatrix::setElem(sbfElement *elem)
{
    elem_ = elem;
    sbfMesh *mesh = elem->mesh();
    sbfNode node;
    std::vector<int> indexes = elem->indexes();
    const int size = indexes.size();
    for(int ct = 0; ct < size; ct++)
    {
        ind_[ct] = indexes[ct];
        node = mesh->node(indexes[ct]);
        crd_[ct] = node.x();
        crd_[ct+size] = node.y();
        crd_[ct+size*2] = node.z();
    }
}

int sbfElemStiffMatrix::numIntPoints() const
{
    return numIntPoints_;
}

void sbfElemStiffMatrix::setNumIntPoints(int numIntPoints)
{
    numIntPoints_ = numIntPoints;
}
