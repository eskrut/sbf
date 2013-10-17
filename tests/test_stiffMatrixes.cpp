#include "test_stiffMatrixes.h"

#include <memory>

void TestStiffMatrixes::case01_patchTest01()
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

void TestStiffMatrixes::case02_createIncompleteChol(){
    //Create simple matrix
    sbfStiffMatrixBlock3x3 * matrix = new sbfStiffMatrixBlock3x3(4, 2);
    /*
     *  [   24  0   6   0   0   0   ]
     *  [   0   8   2   0   0   0   ]
     *  [   6   2   8   -6  2   0   ]
     *  [   0   0   -6  24  0   0   ]
     *  [   0   0   2   0   8   0   ]
     *  [   0   0   0   0   0   1   ]
     */
    matrix->setType(MatrixType::FULL_MATRIX);
    std::vector<int> indJ{0, 1, 0, 1}, shiftInd{0, 2, 4};
    matrix->setIndData(2, 4, &indJ[0], &shiftInd[0]);
    matrix->null();
    double * block = matrix->blockPtr(0, 0);
    block[0] = 24; block[1] = 0; block[2] = 6;
    block[3] = 0; block[4] = 8; block[5] = 2;
    block[6] = 6; block[7] = 2; block[8] = 8;
    block = matrix->blockPtr(0, 1);
    block[6] = -6; block[7] = 2;
    block = matrix->blockPtr(1, 0);
    block[2] = -6;
    block[5] = 2;
    block = matrix->blockPtr(1, 1);
    block[0] = 24;
    block[4] = 8;
    block[8] = 1;

    //std::unique_ptr<sbfStiffMatrixBlock3x3> iCholRes(matrix->makeIncompleteChol());
    sbfStiffMatrixBlock3x3 * iChol = matrix->makeIncompleteChol();

    //test
    bool pass = true;
    const double eps = 0.0001;
    block = iChol->blockPtr(0, 0);
    if ( std::fabs(block[0] - 4.8990) > eps ||
         std::fabs(block[4] - 2.8284) > eps ||
         std::fabs(block[6] - 1.2247) > eps || std::fabs(block[7] - 0.7071) > eps || std::fabs(block[8] - 2.4495) > eps)
        pass = false;
    if ( !pass )
        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];
    block = iChol->blockPtr(1, 0);
    if ( std::fabs(block[2] + 2.4495) > eps ||
         std::fabs(block[5] - 0.8165) > eps )
        pass = false;
    if ( !pass )
        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];
    block = iChol->blockPtr(1, 1);
    if ( std::fabs(block[0] - 4.2426) > eps ||
         std::fabs(block[3] - 0.0) > eps || std::fabs(block[4] - 2.7080) > eps )
        pass = false;
    if ( !pass )
        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];

    QVERIFY2(pass, "Fail to compute incomplete Chol");
}

void TestStiffMatrixes::case03_CGMwP()
{
    float xSide = 1000, ySide = 1, zSide = 1;
    int xPart = 25, yPart = 5, zPart = 8;
    std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    sbfMesh * mesh = meshRes.get();
    mesh->applyToAllElements([](sbfElement & elem){elem.setMtr(1);});

    sbfNodeGroup * grLock = mesh->addNodeGroup();
    sbfNodeGroup * grLoad = mesh->addNodeGroup();

    sbfGroupFilter filtLock;
    filtLock.setMesh(mesh);
    filtLock.setCrdXF(-0.001, 0.001);
    grLock->addFilter(filtLock);
    sbfGroupFilter filtLoad;
    filtLoad.setMesh(mesh);
    filtLoad.setCrdXF(xSide - 0.001, xSide + 0.001);
    grLoad->addFilter(filtLoad);
    mesh->processNodeGroups();
    auto lockInds = grLock->nodeIndList();
    auto loadInds = grLoad->nodeIndList();

    sbfPropertiesSet propSet;
    propSet.addMaterial(sbfMaterialProperties::makeMPropertiesSteel());

    std::unique_ptr<sbfStiffMatrixBlock3x3> stiffRes(new sbfStiffMatrixBlock3x3());
    sbfStiffMatrixBlock3x3 * stiff = stiffRes.get();
    stiff->setMesh(mesh);
    stiff->setPropSet(&propSet);
    stiff->updateIndexesFromMesh();

    stiff->compute();

    NodesData<> force(mesh), disp(mesh);
    force.null();
    disp.null();
    for( auto node : lockInds ) stiff->lockKort(node, 0, 0, force.data());
    stiff->lockKort(mesh->nodeAt(0, 0, 0), 1, 0, force.data());
    stiff->lockKort(mesh->nodeAt(0, 0, 0), 2, 0, force.data());

    //FIXME make normal loading
    for( auto node : loadInds ) force.data(node, 0) = 1.0/loadInds.size();

    std::unique_ptr<sbfStiffMatrixBlock3x3> iCholRes(stiff->makeIncompleteChol());
    sbfStiffMatrixBlock3x3 * iChol = iCholRes.get();

    //Conjugate Gradient Method with Preconditioning
    //FEP - Bathe p.763

    //_p1 stands for 'plus one'
    NodesData<> KU(mesh), Kp(mesh), r(mesh), r_p1(mesh), p(mesh), p_p1(mesh);
    double alpha, betta;

    //initial step
    stiff->multiplyByVector(disp.data(), KU.data());
    r.copyData((force - KU).data());
    const int numNodes = mesh->numNodes();
    double sum[3], vecPart[3];
    //L p' = r
    for (int ctRow = 0; ctRow < numNodes; ctRow++) {//Loop on rows
        sum[0] = sum[1] = sum[2] = 0.0;
        double * block;
        for (int ctColumn = 0; ctColumn < ctRow; ctColumn++){//Loop on non diagonal blocks
            block = iChol->blockPtr(ctRow, ctColumn);
            if (!block) continue;
            vecPart[0] = p.data(ctColumn, 0);
            vecPart[1] = p.data(ctColumn, 1);
            vecPart[2] = p.data(ctColumn, 2);
            sum[0] += block[0]*vecPart[0] + block[1]*vecPart[1] + block[2]*vecPart[2];
            sum[1] += block[3]*vecPart[0] + block[4]*vecPart[1] + block[5]*vecPart[2];
            sum[2] += block[6]*vecPart[0] + block[7]*vecPart[1] + block[8]*vecPart[2];
        }//Loop on non diagonal blocks
        block = stiff->blockPtr(ctRow, ctRow);

        vecPart[0] = (r.data(ctRow, 0) - sum[0]) / block[0];
        sum[1] += block[3]*vecPart[0];
        sum[2] += block[6]*vecPart[0];
        vecPart[1] = (r.data(ctRow, 1) - sum[1]) / block[4];
        sum[2] += block[7]*vecPart[1];
        vecPart[2] = (r.data(ctRow, 2) - sum[2]) / block[8];
        p.data(ctRow, 0) = vecPart[0];
        p.data(ctRow, 1) = vecPart[1];
        p.data(ctRow, 2) = vecPart[2];
    }//Loop on rows
    //L^T p = p'
}
