#ifndef SBFGEOM2DFACE_H
#define SBFGEOM2DFACE_H

#include "sbfgeom2dedge.h"

#include "sbfEnums.h"
class sbfMesh;

#include <vector>
#include <iterator>

class sbfGeom2DFace
{
public:
    sbfGeom2DFace(std::shared_ptr<sbfGeom2DEdge const> bottom,
                  std::shared_ptr<sbfGeom2DEdge const> right,
                  std::shared_ptr<sbfGeom2DEdge const> top,
                  std::shared_ptr<sbfGeom2DEdge const> left);

private:
    //edges
    std::shared_ptr<sbfGeom2DEdge const> b_;
    std::shared_ptr<sbfGeom2DEdge const> r_;
    std::shared_ptr<sbfGeom2DEdge const> t_;
    std::shared_ptr<sbfGeom2DEdge const> l_;

    //Portions where nodes should be created. (starts with 0, ends with 1)
    std::vector<float> portionsB_;
    std::vector<float> portionsR_;
    std::vector<float> portionsT_;
    std::vector<float> portionsL_;

    std::vector<std::vector<sbfNode>> nodes_;
//    std::vector<int> indexes_;

public:
    void setPartitions(int bottom, int right, int top = -1, int left = -1);
    template<class Iterator>
    void setPartitions(Iterator bBeg, Iterator bEnd,
                       Iterator rBeg, Iterator rEnd/*,
                       Iterator tBeg, Iterator tEnd,
                       Iterator lBeg, Iterator lEnd*/);
    void makeMesh(ElementType type = ElementType::RECTANGLE_LINEAR);
    sbfMesh *extrude(const sbfNode &dir, float length, int parts);
};

#endif // SBFGEOM2DFACE_H
