#ifndef SFBGEOM2DARC_H
#define SFBGEOM2DARC_H

#include "sbfgeom2dedge.h"

class sbfGeom2DArc : public sbfGeom2DEdge
{
public:
    sbfGeom2DArc(const sbfNode &center, float radius, float begin, float angle);
    sbfGeom2DArc(const sbfNode &center, const sbfNode &begin, const sbfNode &end);

private:
    sbfNode center_;
    float radius_;
    float begin_;
    float angle_;

    // sbfGeom2DEdge interface
public:
    sbfNode begin() const;
    sbfNode end() const;
    sbfNode nodeAtPortion(float portion) const;
    float length() const;
};

#endif // SFBGEOM2DARC_H
