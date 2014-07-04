#include "sbfStiffMatrix.h"
#include "sbfElement.h"
#include "sbfStiffMatrixBlock3x3.h"
#include "sbfStiffMatrixBlock6x6.h"

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
    this->read_stream(in);
    in.close();
    return true;
}

bool sbfStiffMatrix::write(const char *name) const
{
    std::ofstream out(name, std::ios::binary);
    if( !out.good() ) return false;
    this->write_stream(out);
    out.close();
    return true;
}

void sbfStiffMatrix::computeSequantially()
{
    compute(0, mesh_->numElements());
}

sbfStiffMatrix *sbfStiffMatrix::New(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType symType, MatrixStoreType storeType)
{
    int nodeDofInMesh = 0;
    mesh->applyToAllElements([&](sbfElement &elem){ nodeDofInMesh = std::max(nodeDofInMesh, elem.numNodeDof());});

    if (nodeDofInMesh == 3){
        if(storeType == MatrixStoreType::COMPACT)
            return nullptr;//new sbfStiffMatrixBlock3x3();
        else
            return nullptr;
    }
    else if (nodeDofInMesh == 6){
        if(storeType == MatrixStoreType::COMPACT)
            return new sbfStiffMatrixBlock6x6(mesh, propSet, symType);
        else
            return nullptr;

    }

    return nullptr;
}

