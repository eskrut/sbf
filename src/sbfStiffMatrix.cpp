#include "sbfStiffMatrix.h"

sbfStiffMatrix::sbfStiffMatrix(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type) :
    mesh_(mesh),
    propSet_(propSet),
    type_(type)
{
}

sbfMesh *sbfStiffMatrix::mesh() const
{
    return mesh_;
}

sbfPropertiesSet *sbfStiffMatrix::propSet() const
{
    return propSet_;
}

void sbfStiffMatrix::setPropSet(sbfPropertiesSet *propSet)
{
    propSet_ = propSet;
}

bool sbfStiffMatrix::read(const char *name)
{
    std::ifstream in(name, std::ios::binary);
    if( !in.good() ) return false;
    this->read(in);
    in.close();
    return true;
}

bool sbfStiffMatrix::write(const char *name) const
{
    std::ofstream out(name, std::ios::binary);
    if( !out.good() ) return false;
    this->write(out);
    out.close();
    return true;
}

