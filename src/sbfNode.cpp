#include "sbfNode.h"

sbfNode::sbfNode()
{
    crd_[0] = crd_[1] = crd_[2] = 0.0;
}
sbfNode::sbfNode(CrdFloatType x, CrdFloatType y, CrdFloatType z)
{
    setX(x);setY(y);setZ(z);
}
sbfNode::sbfNode(const sbfNode &node)
{
    crd_[0] = node.crd_[0];
    crd_[1] = node.crd_[1];
    crd_[2] = node.crd_[2];
}
sbfNode::~sbfNode()
{
}
void sbfNode::setX(const CrdFloatType x)
{
    crd_[0] = x;
}
void sbfNode::setY(const CrdFloatType y)
{
    crd_[1] = y;
}
void sbfNode::setZ(const CrdFloatType z)
{
    crd_[2] = z;
}
CrdFloatType sbfNode::x() const
{
    return crd_[0];
}
CrdFloatType sbfNode::y() const
{
    return crd_[1];
}
CrdFloatType sbfNode::z() const
{
    return crd_[2];
}
CrdFloatType &sbfNode::crdAtKort(int kort)
{
    return crd_[kort];
}

CrdFloatType sbfNode::crdAtKort(int kort) const
{
    return crd_[kort];
}
bool sbfNode::isSame(const sbfNode &node, const CrdFloatType tolerance) const
{
    if(!isSameX(node, tolerance))
        return false;
    else if(!isSameY(node, tolerance))
        return false;
    else if(!isSameZ(node, tolerance))
        return false;
    else
        //Distance check should be here!!!!!!!!!!!!!!!!!
        return true;
}
bool sbfNode::isSameX(const sbfNode &node, const CrdFloatType tolerance) const
{
    return std::fabs(x()-node.x()) < tolerance ? true : false;
}
bool sbfNode::isSameY(const sbfNode &node, const CrdFloatType tolerance) const
{
    return std::fabs(y()-node.y()) < tolerance ? true : false;
}
bool sbfNode::isSameZ(const sbfNode &node, const CrdFloatType tolerance) const
{
    return std::fabs(z()-node.z()) < tolerance ? true : false;
}
float sbfNode::distance(const sbfNode &node) const
{
    return std::sqrt(std::pow(x()-node.x(), static_cast<CrdFloatType>(2)) +std:: pow(y()-node.y(), static_cast<CrdFloatType>(2)) + std::pow(z()-node.z(), static_cast<CrdFloatType>(2)));
}
void sbfNode::rotate(CrdFloatType rotX, CrdFloatType rotY, CrdFloatType rotZ, CrdFloatType rotOriginX, CrdFloatType rotOriginY, CrdFloatType rotOriginZ)
{
    //Rotate around vector (rotX, rotY, rotZ) to angle |(rotX, rotY, rotZ)|

    //Generate rotate matrix.
    CrdFloatType angle, dirx, diry, dirz, cs, sn;
    angle = std::sqrt(std::pow(rotX, static_cast<CrdFloatType>(2)) + std::pow(rotY, static_cast<CrdFloatType>(2)) + std::pow(rotZ, static_cast<CrdFloatType>(2)));
    if(angle < 1e-10) return;
    dirx = rotX/angle;
    diry = rotY/angle;
    dirz = rotZ/angle;
    cs = std::cos(angle);
    sn = std::sin(angle);

    CrdFloatType rot[3][3];

    rot[0][0] = cs + dirx*dirx*(1.0f - cs);
    rot[0][1] = dirx*diry*(1.0f - cs) - dirz*sn;
    rot[0][2] = dirx*dirz*(1.0f - cs) + diry*sn;

    rot[1][0] = dirx*diry*(1.0f - cs) + dirz*sn;
    rot[1][1] = cs + diry*diry*(1.0f - cs);
    rot[1][2] = diry*dirz*(1.0f - cs) - dirx*sn;

    rot[2][0] = dirx*dirz*(1.0f - cs) - diry*sn;
    rot[2][1] = diry*dirz*(1.0f - cs) + dirx*sn;
    rot[2][2] = cs + dirz*dirz*(1.0f - cs);

    CrdFloatType oldCrd_[3];
    oldCrd_[0] = x() - rotOriginX;
    oldCrd_[1] = y() - rotOriginY;
    oldCrd_[2] = z() - rotOriginZ;
    setX(rot[0][0]*oldCrd_[0] + rot[0][1]*oldCrd_[1] + rot[0][2]*oldCrd_[2] + rotOriginX);
    setY(rot[1][0]*oldCrd_[0] + rot[1][1]*oldCrd_[1] + rot[1][2]*oldCrd_[2] + rotOriginY);
    setZ(rot[2][0]*oldCrd_[0] + rot[2][1]*oldCrd_[1] + rot[2][2]*oldCrd_[2] + rotOriginZ);
}
