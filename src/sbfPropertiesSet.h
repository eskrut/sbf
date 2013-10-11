#ifndef SBFPROPERTIESSET_H
#define SBFPROPERTIESSET_H

#include "sbfMaterialProperties.h"

class DECLSPEC sbfPropertiesSet
{
private:
    //FIXME maybe it will be better to store pointers (but who should clear memory?)
    std::vector<sbfMaterialProperties> materials_;
public:
    sbfMaterialProperties * material(const int seqNumber);
    void addMaterial(sbfMaterialProperties material);
};

#endif // SBFPROPERTIESSET_H
