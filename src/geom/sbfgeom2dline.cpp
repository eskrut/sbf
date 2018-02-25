#include "sbfgeom2dline.h"

#include <assert.h>

sbfGeom2DLine::sbfGeom2DLine(const sbfNode &begin, const sbfNode &end) :
    a_(begin),
    b_(end)
{
    length_ = b_.distance(a_);
    dir_ = b_ - a_;
    dir_.setX(dir_.x()/length_);
    dir_.setY(dir_.y()/length_);
    dir_.setZ(dir_.z()/length_);
}

sbfNode sbfGeom2DLine::begin() const
{
    return a_;
}

sbfNode sbfGeom2DLine::end() const
{
    return b_;
}

sbfNode sbfGeom2DLine::nodeAtPortion(float portion) const
{
    assert(portion >= 0);
    assert(portion <= 1);
    return a_ + dir_ * length_ * portion;
}


float sbfGeom2DLine::length() const
{
    return length_;
}
