#include "test_stiffMatrices.h"

#include <memory>

void TestStiffMatrices::case01_patchTest01()
{
    float xSide = 1000, ySide = 1, zSide = 1;
    int xPart = 25, yPart = 5, zPart = 8;
    std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    sbfMesh * mesh = meshRes.get();
    mesh->applyToAllElements([](sbfElement & elem){elem.setMtr(1);});

    sbfPropertiesSet propSet;
    propSet.addMaterial(sbfMaterialProperties::makeMPropertiesSteel());

    std::unique_ptr<sbfStiffMatrixBlock3x3> stiffRes(new sbfStiffMatrixBlock3x3());
    sbfStiffMatrixBlock3x3 * stiff = stiffRes.get();
    stiff->setMesh(mesh);
    stiff->setPropSet(&propSet);
    stiff->updateIndexesFromMesh();

    stiff->compute();

    NodesData<> forces(mesh), displacements(mesh);

    displacements.null();
    DefaultWorkDataType ampX = 0.01, ampY = 0.001, ampZ = 0.005;

    //Apply displacements with uniforn strain
    int ct = 0;
    auto setDispl = [&](sbfNode & node) {
        displacements.data(ct, 0) = ampX/xSide*node.x();
        displacements.data(ct, 1) = ampY/ySide*node.y();
        displacements.data(ct++, 2) = ampZ/zSide*node.z();
    };
    mesh->applyToAllNodes(setDispl);

    //Make multiplycation
    stiff->multiplyByVector(displacements.data(), forces.data());

    //Check result forces
    bool pass = true;
    DefaultWorkDataType eps = 1e-9; // std::numeric_limits<DefaultWorkDataType>::epsilon() works bad :( it's to precise
    for(int ct = 0; ct < mesh->numNodes(); ct++){
        sbfNode node = mesh->node(ct);
        if ( // inner nodes
                node.x() > 0 && node.x() < xSide &&
                node.y() > 0 && node.y() < ySide &&
                node.z() > 0 && node.z() < zSide &&
                (
                    std::fabs(forces.data(ct, 0)) > eps ||
                    std::fabs(forces.data(ct, 1)) > eps ||
                    std::fabs(forces.data(ct, 2)) > eps
                )
           ) { pass = false; break; }
        if ( // outer nodes
                (
                    ( node.x() == 0 || node.x() == xSide ) ||
                    ( node.y() == 0 || node.y() == ySide ) ||
                    ( node.z() == 0 || node.z() == zSide )
                ) &&
                (
                    std::fabs(forces.data(ct, 0)) < eps &&
                    std::fabs(forces.data(ct, 1)) < eps &&
                    std::fabs(forces.data(ct, 2)) < eps
                )
             ) { pass = false; break; }
    }

    QVERIFY2(pass, "Fail to produce zero inner forces");
}
