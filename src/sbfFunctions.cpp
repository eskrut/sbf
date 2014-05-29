#include "sbfFunctions.h"

#include "sbfMesh.h"
#include "sbfElemStiffMatrixHexa8.h"
#include "sbfPropertiesSet.h"
#include "sbfElement.h"

void calculateDeformStress(sbfMesh *mesh, sbfPropertiesSet *propSet, const double *displ, double *deform, double *stress)
{
    if ( !mesh ) throw std::runtime_error("Null pointer to mesh");
    if ( !propSet ) throw std::runtime_error("Null pointer to mesh");
    const int numElems = mesh->numElements();

    //forward preparation of matrixes
    sbfElemStiffMatrixHexa8 *stiffHexa8 = new sbfElemStiffMatrixHexa8();
    stiffHexa8->setPropSet(propSet);
    NodesData<int, 1> numAdditionD(mesh), numAdditionS(mesh);
    NodesData<double, 3> localDispl(100);
    NodesData<double, 6> localDeform(100), localStress(100);
    numAdditionD.null();
    numAdditionS.null();

    //TODO make it parallel
    for(int ctElem = 0; ctElem < numElems; ctElem++) { //Loop over elements
        sbfElement *elem = mesh->elemPtr(ctElem);
        const std::vector<int> &indexes = elem->indexes();
        const int numNodes = elem->numNodes();
        for(int ctNode = 0; ctNode < numNodes; ctNode++)
            for(int ct = 0; ct < 3; ct++) localDispl[ctNode*3 + ct] = displ[indexes[ctNode]*3 + ct];
        switch(elem->type()){
        case ElementType::HEXAHEDRON_LINEAR:{
            stiffHexa8->setElem(elem);
            stiffHexa8->computeDefStress(localDispl.data(), localDeform.data(), localStress.data());
            break;
        }
        default:
            throw std::runtime_error("Unknown element type");
            break;
        }
        if ( deform ) for(int ctNode = 0; ctNode < numNodes; ctNode++) {
            for(int ct = 0; ct < 6; ct++)
                deform[indexes[ctNode]*3 + ct] += localDeform[ctNode*3 + ct];
            numAdditionD[ctNode]++;
        }
        if ( stress ) for(int ctNode = 0; ctNode < numNodes; ctNode++) {
            for(int ct = 0; ct < 6; ct++) stress[indexes[ctNode]*3 + ct] += localStress[ctNode*3 + ct];
            numAdditionS[ctNode]++;
        }
    } //Loop over elements

    const int numNodes = mesh->numNodes();
    if ( deform ) for(int ctNode = 0; ctNode < numNodes; ctNode++)
        for(int ct = 0; ct < 6; ct++)
            deform[ctNode*6 + ct] /= numAdditionD[ctNode];
    if ( stress ) for(int ctNode = 0; ctNode < numNodes; ctNode++)
        for(int ct = 0; ct < 6; ct++)
            stress[ctNode*6 + ct] /= numAdditionS[ctNode];
}
