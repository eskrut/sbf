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

void sbfPropertiesSet::read(const char *fileName)
{
    std::ifstream in(fileName);
    if ( !in.good() )
        throw std::runtime_error(std::string("Cant read file ") + fileName);
    size_t numMaterials;
    in >> numMaterials;
    in.ignore(10, '\n');
    materials_.resize(numMaterials, new sbfMaterialProperties);
    for(auto m : materials_)
        m->read(in);
}

void sbfPropertiesSet::write(const char *fileName) const
{
    std::ofstream out(fileName);
    if ( !out.good() )
        throw std::runtime_error(std::string("Cant write file ") + fileName);
    out << materials_.size() << std::endl;
    for(auto m : materials_)
        m->write(out);
}
