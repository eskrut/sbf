#ifndef SBFNODE_H
#define SBFNODE_H

#include <cmath>
#include <climits>
#include "sbfDeclspec.h"

using CrdFloatType = float;

class DECLSPEC sbfNode
//Holds information about node coordinates
{
public:
    sbfNode();
    //Construct node with certain coordinates
    sbfNode(CrdFloatType x, CrdFloatType y, CrdFloatType z);
    //Copy constructor
    sbfNode(const sbfNode & node);
    ~sbfNode();

private:
    CrdFloatType crd_[3];

public:
    //Set/get coordinates
    void setX(const CrdFloatType x = 0.0);
    void setY(const CrdFloatType y = 0.0);
    void setZ(const CrdFloatType z = 0.0);
    CrdFloatType x() const;
    CrdFloatType y() const;
    CrdFloatType z() const;
    CrdFloatType &crdAtKort(int kort);
    CrdFloatType crdAtKort(int kort) const;
    //Check if all coordinates of nodes are equal with tolerance
    bool isSame(const sbfNode &node, const CrdFloatType tolerance = 0.001) const;
    //Check if spesific coordinate of nodes is equal with tolerance
    bool isSameX(const sbfNode &node, const CrdFloatType tolerance = 0.001) const;
    bool isSameY(const sbfNode &node, const CrdFloatType tolerance = 0.001) const;
    bool isSameZ(const sbfNode &node, const CrdFloatType tolerance = 0.001) const;
    //Returns the distance between nodes
    float distance(const sbfNode &node) const;
    //Returns the distance between node and crds
    float distance(CrdFloatType x, CrdFloatType y, CrdFloatType z) const;
    //Returns the angle [-pi:pi] betwiin oa and ob as a vector. o is this
    sbfNode angle(const sbfNode &a, const sbfNode&b) const;
    //Returns the angle value [-pi:pi] betwiin oa and ob as a vector. o is this
    double angleVal(const sbfNode &a, const sbfNode&b) const;
    //Return node at normal (with unit length) from o (this). Normal formed by oa and ob.
    sbfNode normal(const sbfNode &a, const sbfNode&b) const;
    //Rotate node around vector with components to angle of vector length
    void rotate(CrdFloatType rotX, CrdFloatType rotY, CrdFloatType rotZ, CrdFloatType rotOriginX = 0.0, CrdFloatType rotOriginY = 0.0, CrdFloatType rotOriginZ = 0.0);

    sbfNode &operator += (const sbfNode &operand);
    sbfNode &operator -= (const sbfNode &operand);
    sbfNode &operator *= (float scale);

};

sbfNode operator+(sbfNode left, const sbfNode &right);
sbfNode operator-(sbfNode left, const sbfNode &right);
sbfNode operator*(sbfNode left, float scale);

std::ostream & operator<<(std::ostream &, const sbfNode&);

enum class sbfNodeCompareType {
    ByCoordinates
};

template<sbfNodeCompareType type>
struct sbfNodeComparer {
    sbfNodeComparer(float tolerance = std::numeric_limits<float>::epsilon()) : eps(tolerance) {}
    bool operator()(const sbfNode &left, const sbfNode &right) const;

    float eps;
};

template<>
bool sbfNodeComparer<sbfNodeCompareType::ByCoordinates>::operator()(const sbfNode &left, const sbfNode &right) const;

namespace sbf {
    template<class S>
    S& pushToStream(S &s, const sbfNode& n);
}

#endif // SBFNODE_H
