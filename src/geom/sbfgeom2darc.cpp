#include "sbfgeom2darc.h"

#include <cmath>
#include <assert.h>

sbfGeom2DArc::sbfGeom2DArc(const sbfNode &center, float radius, float begin, float angle) :
    center_(center),
    radius_(radius),
    begin_(begin),
    angle_(angle)
{
    assert(std::fabs(center_.z()) < std::numeric_limits<float>::epsilon());
}

sbfGeom2DArc::sbfGeom2DArc(const sbfNode &center, const sbfNode &begin, const sbfNode &end) :
    center_(center)
{
    assert(std::fabs(center_.z()) < std::numeric_limits<float>::epsilon());
    assert(std::fabs(begin.z()) < std::numeric_limits<float>::epsilon());
    assert(std::fabs(end.z()) < std::numeric_limits<float>::epsilon());
    radius_ = center_.distance(begin);
    auto ang = center_.angle(center_ + sbfNode(1, 0, 0), begin);
    ang -= center_;
    begin_ = ang.z();
    ang = center_.angle(begin, end);
    ang -= center_;
    angle_ = ang.z();
}


sbfNode sbfGeom2DArc::begin() const
{
    return center_ + sbfNode(std::cos(radius_ * begin_), std::sin(radius_ * begin_), 0);
}

sbfNode sbfGeom2DArc::end() const
{
    return center_ + sbfNode(std::cos(radius_ * (begin_ + angle_)), std::sin(radius_ * (begin_ + angle_)), 0);
}

sbfNode sbfGeom2DArc::nodeAtPortion(float portion) const
{
    assert(portion >= 0);
    assert(portion <= 1);
    return center_ + sbfNode(radius_ * std::cos(begin_ + angle_ * portion),
                             radius_ * std::sin(begin_ + angle_ * portion),
                             0);
}

float sbfGeom2DArc::length() const
{
    return radius_ * angle_;
}
