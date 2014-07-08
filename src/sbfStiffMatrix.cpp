#include "sbfStiffMatrix.h"
#include "sbfElement.h"
#include "sbfStiffMatrixBlock3x3.h"
#include "sbfStiffMatrixBlock6x6.h"
#include <cassert>
#include "sbfAdditions.h"

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
            return new sbfStiffMatrixBlock3x3(mesh, propSet, symType);
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

void sbfStiffMatrix::multiplyByVector(double *vector, double *result, sbfMatrixIterator *iterator)
{
    //TODO implement up & down triadonal matrixes
    assert(type_ == MatrixType::FULL_MATRIX);
    sbfMatrixIterator *iter = iterator;
    if (!iterator) iter = createIterator();
    //Generic matrix multiplication
    const int numNodes = mesh_->numNodes();
    const int numDofPerNode = numDof();
    const int numAllDof = numNodes*numDofPerNode;
    for(int ct = 0; ct < numAllDof; ++ct) result[ct] = 0.0;

    for(int ctNode = 0; ctNode < numNodes; ++ctNode) {
        iter->setToRow(ctNode);
        while(iter->isValid()) {
            double *data = iter->data();
            double *dataRez = result+numDofPerNode*ctNode;
            int columnID = iter->column();
            for(int ct1 = 0; ct1 < numDofPerNode; ++ct1)
                for(int ct2 = 0; ct2 < numDofPerNode; ++ct2)
                    dataRez[ct1] += data[ct1*numDofPerNode+ct2]*vector[numDofPerNode*columnID+ct2];
            iter->next();
        }
    }

    if (!iterator) delete iter;
}

void sbfStiffMatrix::lockDof(int nodeIndex, int dofIndex, double value, double *force, LockType lockType)
{
    const int numDofPerNode = numDof();
    assert(dofIndex < numDofPerNode);
    //TODO implement up & down triadonal matrixes
    assert(type_ == MatrixType::FULL_MATRIX);
    CreateSmartAndRawPtr(sbfMatrixIterator, createIterator(), iter);
    if ( lockType == LockType::APPROXIMATE_LOCK_TYPE ) {
        double *targetBlock = iter->diagonal(nodeIndex);
        const int shift = numDofPerNode*dofIndex + dofIndex;
        targetBlock[shift] *= 1e10;
        if(force) force[nodeIndex*numDofPerNode + dofIndex] = targetBlock[shift]*value;
    }
    else {
        throw std::runtime_error("EXACT_LOCK_TYPE is not implemented");
    }
}

