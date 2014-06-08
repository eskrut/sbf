#include "sbfPropertiesSet.h"

sbfPropertiesSet::~sbfPropertiesSet()
{
    for(auto m : materials_)
        delete m;
    materials_.clear();
}

sbfMaterialProperties *sbfPropertiesSet::material(const int seqNumber) const
{
    return materials_[seqNumber];
}

void sbfPropertiesSet::addMaterial(sbfMaterialProperties *material)
{
    materials_.push_back(material);
}
