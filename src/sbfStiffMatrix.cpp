#include "sbfStiffMatrix.h"
#include "sbfElement.h"
#include "sbfStiffMatrixBlock.h"
#include "sbfStiffMatrixBand.h"
#include "sbfAdditions.h"
#include "sbfElement.h"
#include "sbfElemStiffMatrixBeam6Dof.h"
#include "sbfElemStiffMatrixHexa8.h"
#include <cassert>

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

void sbfStiffMatrix::compute(int startID, int stopID)
{
    if ( !propSet_ ) throw std::runtime_error ( "nullptr in propSet" );
    null();
    sbfElement *elem = nullptr;
    sbfElemStiffMatrix *elemStiff = nullptr;
    std::map<ElementType, sbfElemStiffMatrix *> mapStiff;
    mapStiff[ElementType::BEAM_LINEAR_6DOF] = new sbfElemStiffMatrixBeam6Dof ( elem, propSet_ );
    mapStiff[ElementType::HEXAHEDRON_LINEAR] = new sbfElemStiffMatrixHexa8 ( elem, propSet_ );
    std::unique_ptr<sbfMatrixIterator> iteratorPtr ( createIterator() );
    sbfMatrixIterator *iterator = iteratorPtr.get();
    for ( int ctElem = startID; ctElem < stopID; ++ctElem ) { //Loop over elements
        elem = mesh_->elemPtr ( ctElem );
        assert ( mapStiff.count ( elem->type() ) == 1 );
        elemStiff = mapStiff[elem->type()];
        assert ( elemStiff->numDOF() == iterator->numDOF() );
        elemStiff->setElem ( elem );
        elemStiff->computeSM();
        auto listIDData = elemStiff->rowColData();
        iterator->setToRow ( listIDData.front().first.first );
        for ( auto idData : listIDData ) {
            if ( type_ == DOWN_TREANGLE_MATRIX && idData.first.second > idData.first.first )
                continue;
            else if ( type_ == UP_TREANGLE_MATRIX && idData.first.second < idData.first.first )
                continue;
            double *data = nullptr;
            if ( idData.first.first != iterator->row() ||
                 iterator->column() > idData.first.second )
                iterator->setToRow ( idData.first.first );
            while ( iterator->isValid() )
                if ( iterator->column() == idData.first.second &&
                     iterator->isInNormal() ) {
                    data = const_cast<double *> ( iterator->data() );
                    break;
                }
                else iterator->next();
            if ( !data )
                throw std::runtime_error ( "Can't find target block in global stiffness matrix" );
            for ( int ct = 0; ct < iterator->dataItemSize(); ++ct )
                data[ct] += idData.second[ct];
        }
    }//Loop over elements
}

sbfStiffMatrix *sbfStiffMatrix::New(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType symType, MatrixStoreType storeType)
{
    int nodeDofInMesh = 0;
    mesh->applyToAllElements([&](sbfElement &elem){ nodeDofInMesh = std::max(nodeDofInMesh, elem.numNodeDof());});

    if (nodeDofInMesh == 3){
        if(storeType == MatrixStoreType::COMPACT)
            return new sbfStiffMatrixBlock<3>(mesh, propSet, symType);
        else
            return new sbfStiffMatrixBand<3>(mesh, propSet, symType);
    }
    else if (nodeDofInMesh == 6){
        if(storeType == MatrixStoreType::COMPACT)
            return new sbfStiffMatrixBlock<6>(mesh, propSet, symType);
        else
            return new sbfStiffMatrixBand<6>(mesh, propSet, symType);
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
        //TODO add more tests for this lock type
        const int numNodes = mesh_->numNodes();
        for(int ctRow = 0; ctRow < numNodes; ++ctRow) {
            iter->setToRow(ctRow);
            if (ctRow == nodeIndex) {
                while(iter->isValid()){
                    double *block = iter->data();
                    const int columnID = iter->column();
                    if (force) for(int ctDof = 0; ctDof < numDofPerNode; ++ctDof) force[columnID*numDofPerNode + ctDof] -= block[numDofPerNode*dofIndex + ctDof]*value;
                    for(int ctDof = 0; ctDof < numDofPerNode; ++ctDof) block[numDofPerNode*dofIndex + ctDof] = 0.0;
                    iter->next();
                }
            }
            else {
                while(iter->isValid()){
                    if (iter->column() == nodeIndex) {
                        double *block = iter->data();
                        for(int ctDof = 0; ctDof < numDofPerNode; ++ctDof) block[dofIndex + numDofPerNode*ctDof] = 0.0;
                    }
                    iter->next();
                }
            }
        }
        double *block = iter->diagonal(nodeIndex);
        for(int ctDof = 0; ctDof < numDofPerNode; ++ctDof) block[dofIndex + numDofPerNode*ctDof] = 0.0;
        block[dofIndex*(numDofPerNode+1)] = 1.0;
        force[nodeIndex*numDofPerNode+dofIndex] = value;
    }
}

