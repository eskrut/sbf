#ifndef SBFGEOM2DLINE_H
#define SBFGEOM2DLINE_H

#include "sbfgeom2dedge.h"

class sbfGeom2DLine : public sbfGeom2DEdge
{
public:
    sbfGeom2DLine(const sbfNode &begin, const sbfNode &end);

private:
    sbfNode a_;
    sbfNode b_;
    sbfNode dir_;
    float length_;

    // sbfGeom2DEdge interface
public:
    sbfNode begin() const;
    sbfNode end() const;
    sbfNode nodeAtPortion(float portion) const;
    float length() const;
};

#endif // SBFGEOM2DLINE_H
