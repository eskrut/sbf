#include "sbfGroupFilter.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfMesh.h"

sbfGroupFilter::sbfGroupFilter()
{
    mtrF_ = xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = typeF_ = false;
    xMin_ = yMin_ = zMin_ = -std::numeric_limits<float>::max();
    xMax_ = yMax_ = zMax_ = std::numeric_limits<float>::max();
    mesh_ = NULL;
}
sbfGroupFilter::~sbfGroupFilter()
{}
void sbfGroupFilter::setMtrF(int mtr)
{
    mtrF_ = true;
    mtr_ = mtr;
}
void sbfGroupFilter::unsetMtrF()
{
    mtrF_ = false;
}
void sbfGroupFilter::setTypeF(ElementType type)
{
    typeF_ = true;
    type_ = type;
}
void sbfGroupFilter::unsetTypeF()
{
    typeF_ = false;
}
void sbfGroupFilter::setCrdF(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
{
    xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = true;
    xMin_ = xMin;
    xMax_ = xMax;
    yMin_ = yMin;
    yMax_ = yMax;
    zMin_ = zMin;
    zMax_ = zMax;
}
void sbfGroupFilter::setCrdXF(float xMin, float xMax)
{
    xMaxF_ = xMinF_ = true;
    xMin_ = xMin;
    xMax_ = xMax;
}
void sbfGroupFilter::setCrdYF(float yMin, float yMax)
{
    yMaxF_ = yMinF_ = true;
    yMin_ = yMin;
    yMax_ = yMax;
}
void sbfGroupFilter::setCrdZF(float zMin, float zMax)
{
    zMaxF_ = zMinF_ = true;
    zMin_ = zMin;
    zMax_ = zMax;
}
void sbfGroupFilter::unsetCrdF()
{
    xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = false;
    xMin_ = yMin_ = zMin_ = -std::numeric_limits<float>::max();
    xMax_ = yMax_ = zMax_ = std::numeric_limits<float>::max();
}
void sbfGroupFilter::setMesh(sbfMesh *mesh)
{
    mesh_ = mesh;
}
bool sbfGroupFilter::isPass(sbfElement &elem)
{
    if(mesh_ == NULL)
        return false;
    if(mtrF_ && mtr_ == elem.mtr())
        return true;
    else if(typeF_ && type_ == elem.type())
        return true;
    else if(xMaxF_ || yMaxF_ || zMaxF_ || xMinF_ || yMinF_ || zMinF_){
        sbfNode node = elem.centreOfMass();
        if(xMaxF_)
            if(xMax_ <= node.x())
                return false;
        if(yMaxF_)
            if(yMax_ <= node.y())
                return false;
        if(zMaxF_)
            if(zMax_ <= node.z())
                return false;
        if(xMinF_)
            if(xMin_ >= node.x())
                return false;
        if(yMinF_)
            if(yMin_ >= node.y())
                return false;
        if(zMinF_)
            if(zMin_ >= node.z())
                return false;
        return true;
    }
    //else
        return false;
}
bool sbfGroupFilter::isPass(sbfNode &node)
{
    if(mesh_ == NULL)
        return false;
    {
        if(xMaxF_)
            if(xMax_ <= node.x())
                return false;
        if(yMaxF_)
            if(yMax_ <= node.y())
                return false;
        if(zMaxF_)
            if(zMax_ <= node.z())
                return false;
        if(xMinF_)
            if(xMin_ >= node.x())
                return false;
        if(yMinF_)
            if(yMin_ >= node.y())
                return false;
        if(zMinF_)
            if(zMin_ >= node.z())
                return false;
    }
    return true;
}
