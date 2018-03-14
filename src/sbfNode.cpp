#include "sbfNode.h"
#include <iostream>

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

sbfNode sbfNode::angle(const sbfNode &a, const sbfNode &b) const
{
    auto oa = a - *this;
    auto ob = b - *this;
    oa *= 1.0/sbfNode().distance(oa);
    ob *= 1.0/sbfNode().distance(ob);
    auto dir = sbfNode(
            oa.crd_[1] * ob.crd_[2] - oa.crd_[2] * ob.crd_[1],
            oa.crd_[2] * ob.crd_[0] - oa.crd_[0] * ob.crd_[2],
            oa.crd_[0] * ob.crd_[1] - oa.crd_[1] * ob.crd_[0]
            );
    auto length = sbfNode().distance(dir);
    if(length > 0)
        dir *= (1.0/length);
    auto dot = oa.crd_[0]*ob.crd_[0] + oa.crd_[1]*ob.crd_[1] + oa.crd_[2]*ob.crd_[2];
    auto det =
            (oa.crd_[1] * ob.crd_[2] - oa.crd_[2] * ob.crd_[1])*dir.crd_[0] +
            (oa.crd_[2] * ob.crd_[0] - oa.crd_[0] * ob.crd_[2])*dir.crd_[1] +
            (oa.crd_[0] * ob.crd_[1] - oa.crd_[1] * ob.crd_[0])*dir.crd_[2];
//    auto ang = std::acos(oa.crd_[0]*ob.crd_[0] + oa.crd_[1]*ob.crd_[1] + oa.crd_[2]*ob.crd_[2]);
    auto ang = std::atan2(det, dot);

    dir *= ang;

    auto angle = *this + dir;

    return angle;
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

sbfNode &sbfNode::operator +=(const sbfNode &operand)
{
    this->crd_[0] += operand.crd_[0];
    this->crd_[1] += operand.crd_[1];
    this->crd_[2] += operand.crd_[2];

    return *this;
}

sbfNode &sbfNode::operator -=(const sbfNode &operand)
{
    this->crd_[0] -= operand.crd_[0];
    this->crd_[1] -= operand.crd_[1];
    this->crd_[2] -= operand.crd_[2];

    return *this;
}

sbfNode &sbfNode::operator *=(float scale)
{
    this->crd_[0] *= scale;
    this->crd_[1] *= scale;
    this->crd_[2] *= scale;

    return *this;
}

sbfNode operator+(sbfNode left, const sbfNode &right)
{
    left += right;
    return left;
}

sbfNode operator-(sbfNode left, const sbfNode &right)
{
    left -= right;
    return left;
}

sbfNode operator*(sbfNode left, float scale)
{
    left *= scale;
    return left;
}

std::ostream &operator<<(std::ostream &os, const sbfNode &node)
{
    os << node.x() << "\t" << node.y() << "\t" << node.z();
    return os;
}

template<>
bool sbfNodeComparer<sbfNodeCompareType::ByCoordinates>::operator()(const sbfNode &left, const sbfNode &right) const
{
    if( std::fabs(left.x() - right.x()) > eps )
        return left.x() < right.x();
    if( std::fabs(left.y() - right.y()) > eps )
        return left.y() < right.y();
    if( std::fabs(left.z() - right.z()) > eps )
        return left.z() < right.z();
    return true;
}

template<class S>
S& sbf::pushToStream(S &s, const sbfNode &n)
{
    s << "node(" << n.x() << ", " << n.y() << ", " << n.z() <<")";
    return s;
}

