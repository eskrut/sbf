#include "sbfPropertiesSet.h"

sbfMaterialProperties *sbfPropertiesSet::material(const int seqNumber)
{
    return &materials_[seqNumber];
}

void sbfPropertiesSet::addMaterial(sbfMaterialProperties material)
{
    materials_.push_back(material);
}
