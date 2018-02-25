#ifndef SBFGEOM2DEDGE_H
#define SBFGEOM2DEDGE_H

#include "sbfNode.h"

constexpr double operator"" _deg ( long double deg )
{
    return static_cast<double>(deg*std::atan(1)/45);
}

class sbfGeom2DEdge
{
public:
    sbfGeom2DEdge();
    virtual ~sbfGeom2DEdge() = default;

    //class api
public:
    virtual sbfNode begin() const = 0;
    virtual sbfNode end() const = 0;
    virtual sbfNode nodeAtPortion(float portion) const = 0;
    virtual float length() const = 0;
};

#endif // SBFGEOM2DEDGE_H
