#include "sbfGroupFilter.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfMesh.h"

sbfGroupFilter::sbfGroupFilter()
{
    mtrF_ = xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = typeF_ = false;
    xMin_ = yMin_ = zMin_ = -std::numeric_limits<float>::max();
    xMax_ = yMax_ = zMax_ = std::numeric_limits<float>::max();
}
sbfGroupFilter::~sbfGroupFilter()
{}

sbfGroupFilter sbfGroupFilter::makeNearX(float crd, float tolerance)
{
    sbfGroupFilter filt;
    filt.setCrdXF(crd - tolerance, crd + tolerance);
    return filt;
}

sbfGroupFilter sbfGroupFilter::makeNearY(float crd, float tolerance)
{
    sbfGroupFilter filt;
    filt.setCrdYF(crd - tolerance, crd + tolerance);
    return filt;
}

sbfGroupFilter sbfGroupFilter::makeNearZ(float crd, float tolerance)
{
    sbfGroupFilter filt;
    filt.setCrdZF(crd - tolerance, crd + tolerance);
    return filt;
}

sbfGroupFilter sbfGroupFilter::makeNodeFunc(std::function<bool (const sbfNode &)> func)
{
    sbfGroupFilter filt;
    filt.setNodeFunction(func);
    return filt;
}

sbfGroupFilter sbfGroupFilter::makeElemFunc(std::function<bool (const sbfElement &)> func)
{
    sbfGroupFilter filt;
    filt.setElemFunction(func);
    return filt;
}
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

void sbfGroupFilter::setNodeFunction(std::function<bool (const sbfNode &)> func)
{
    nodeFiltFunction = func;
}

void sbfGroupFilter::setElemFunction(std::function<bool (const sbfElement &)> func)
{
    elemFiltFunction = func;
}
bool sbfGroupFilter::isPass(const sbfElement &elem)
{
    bool passMtr = true;
    bool passType = true;
    bool passCrd = true;
    bool passFunc = true;
    if(mtrF_ && mtr_ != elem.mtr())
        passMtr = false;
    if(passMtr && typeF_ && type_ != elem.type())
        passType = false;
    if(passMtr && passType && (xMaxF_ || yMaxF_ || zMaxF_ || xMinF_ || yMinF_ || zMinF_)){
        sbfNode node = elem.centreOfMass();
        if(xMaxF_)
            if(xMax_ <= node.x())
                passCrd = false;
        if(yMaxF_ && passCrd)
            if(yMax_ <= node.y())
                passCrd = false;
        if(zMaxF_ && passCrd)
            if(zMax_ <= node.z())
                passCrd = false;
        if(xMinF_ && passCrd)
            if(xMin_ >= node.x())
                passCrd = false;
        if(yMinF_ && passCrd)
            if(yMin_ >= node.y())
                passCrd = false;
        if(zMinF_ && passCrd)
            if(zMin_ >= node.z())
                passCrd = false;
    }
    if(elemFiltFunction && passMtr && passType && passCrd){
        passFunc = elemFiltFunction(elem);
    }
    return passMtr && passCrd && passType && passFunc;
}
bool sbfGroupFilter::isPass(const sbfNode &node)
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
    if(nodeFiltFunction && !nodeFiltFunction(node))
        return false;
    return true;
}
