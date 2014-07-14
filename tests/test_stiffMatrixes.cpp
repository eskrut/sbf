#include "test_stiffMatrixes.h"

#include <memory>
#include <chrono>
#include "sbfStiffMatrixBlock3x3Iterator.h"
#include "sbfStiffMatrixBand6Iterator.h"

void TestStiffMatrixes::case01_patchTest01()
{
    float xSide = 100, ySide = 10, zSide = 15;
    int xPart = 25, yPart = 5, zPart = 8;
    std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    sbfMesh * mesh = meshRes.get();
    mesh->applyToAllElements([](sbfElement & elem){elem.setMtr(1);});

    sbfPropertiesSet propSet;
    propSet.addMaterial(sbfMaterialProperties::makeMPropertiesSteel());

    std::unique_ptr<sbfStiffMatrixBlock3x3> stiffRes(new sbfStiffMatrixBlock3x3(mesh, &propSet));
    sbfStiffMatrixBlock3x3 * stiff = stiffRes.get();
//    stiff->setMesh(mesh);
//    stiff->setPropSet(&propSet);
//    stiff->updateIndexesFromMesh();

    stiff->computeSequantially();
    QVERIFY2(stiff->isValid(), "Stiffness is not valid");

    NodesData<> forces(mesh), displacements(mesh), forces2(mesh);

    displacements.null();
    DefaultWorkDataType ampX = 0.01, ampY = 0.01, ampZ = 0.01;

    //Apply displacements with uniforn strain
    int ct = 0;
    for(int ct = 0; ct < mesh->numNodes(); ++ct){
        sbfNode &node = mesh->node(ct);
        displacements.data(ct, 0) = ampX/xSide*node.x();
        displacements.data(ct, 1) = ampY/ySide*node.y();
        displacements.data(ct, 2) = ampZ/zSide*node.z();
    };

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
           ) { qDebug() << QString("Sholud be zero: %1 %2 %3 %4 (eps=%5)").arg(forces.data(ct, 0)).arg(forces.data(ct, 1)).arg(forces.data(ct, 2)).arg(ct).arg(eps); pass = false; break; }
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

    forces2.null();
    pass = true;
    std::unique_ptr<sbfMatrixIterator> iteratorPtr(stiff->createIterator());
    sbfMatrixIterator *iterator = iteratorPtr.get();
    for(int nodeCt = 0; nodeCt < mesh->numNodes(); nodeCt++) {
        iterator->setToRow(nodeCt);
        double *tmp = forces2.data() + nodeCt*3;
        while(iterator->isValid()) {
            int columnID = iterator->column();
            double *vectPart = displacements.data() + columnID*3;
            double *block = iterator->data();
            for(int rowCt = 0; rowCt < 3; ++rowCt)
                for(int colCt = 0; colCt < 3; ++colCt)
                    tmp[rowCt] += block[rowCt*3+colCt]*vectPart[colCt];
            iterator->next();
        }
        for(int ct = 0; ct < 3; ++ct)
            if ( std::fabs(forces.data(nodeCt, ct) - forces2.data(nodeCt, ct)) > eps )
            { qDebug() << QString("Sholud be equal: %1 %2 (eps=%3)").arg(forces.data(nodeCt, ct)).arg(forces2.data(nodeCt, ct)).arg(eps); pass = false; break; }
    }

    QVERIFY2(pass, "Fail to produce zero inner forces (2-nd approach)");
}

//void TestStiffMatrixes::case01_mapHexa01()
//{
//    /*
//     *    7-------6
//     *   /|      /|     Z
//     *  4-------5 |     |   Y
//     *  | |     | |     |  /
//     *  | 3- - -|-2     | /
//     *  |/      |/      |/
//     *  0-------1       0-------- X
//    */

//    /* Msp to the triangle
//     *    7-6
//     *   /| | \         Z
//     *  4-------5       |   Y
//     *  | | |   |       |  /
//     *  | 3-2   |       | /
//     *  |/    \ |       |/
//     *  0-------1       0-------- X
//    */

//    std::unique_ptr<sbfMesh> meshSmartPtr(new sbfMesh());
//    sbfMesh *m = meshSmartPtr.get();
//    for(auto z : {0, 1}) {
//        m->addNode(0, 0, z, false);
//        m->addNode(1, 0, z, false);
//        m->addNode(0, 1, z, false);
//        m->addNode(0, 1, z, false); // Yes, this is duplicate. By the way it's nodes map test
//    }
//    m->addElement(sbfElement(ElementType::HEXAHEDRON_LINEAR, {0, 1, 2, 3, 4, 5, 6, 7}));
//    sbfElemStiffMatrixHexa8 elStif(m->elemPtr(0));
//    auto vol = elStif.computeVolume();
//    auto eps = 1e-6;
//    QVERIFY2(std::fabs(vol - 0.5) < eps, "Fail to get normal volume");
//    //Surprisengly, but it pass!!! May be we should not need tetra and prisme elem matrixes.
//    //Stell we should make more strict tests.
//}

//void TestStiffMatrixes::case02_createIncompleteChol(){
//    //Create simple matrix
//    sbfStiffMatrixBlock3x3_old * matrix = new sbfStiffMatrixBlock3x3_old(4, 2);
//    /*
//     *  [   24  0   6   0   0   0   ]
//     *  [   0   8   2   0   0   0   ]
//     *  [   6   2   8   -6  2   0   ]
//     *  [   0   0   -6  24  0   0   ]
//     *  [   0   0   2   0   8   0   ]
//     *  [   0   0   0   0   0   1   ]
//     */
//    matrix->setType(MatrixType::FULL_MATRIX);
//    std::vector<int> indJ{0, 1, 0, 1}, shiftInd{0, 2, 4};
//    matrix->setIndData(2, 4, &indJ[0], &shiftInd[0]);
//    matrix->null();
//    double * block = matrix->blockPtr(0, 0);
//    block[0] = 24; block[1] = 0; block[2] = 6;
//    block[3] = 0; block[4] = 8; block[5] = 2;
//    block[6] = 6; block[7] = 2; block[8] = 8;
//    block = matrix->blockPtr(0, 1);
//    block[6] = -6; block[7] = 2;
//    block = matrix->blockPtr(1, 0);
//    block[2] = -6;
//    block[5] = 2;
//    block = matrix->blockPtr(1, 1);
//    block[0] = 24;
//    block[4] = 8;
//    block[8] = 1;

//    //std::unique_ptr<sbfStiffMatrixBlock3x3> iCholRes(matrix->makeIncompleteChol());
//    sbfStiffMatrixBlock3x3_old * iChol = matrix->makeIncompleteChol();

//    //test
//    bool pass = true;
//    const double eps = 0.0001;
//    block = iChol->blockPtr(0, 0);
//    if ( std::fabs(block[0] - 4.8990) > eps ||
//         std::fabs(block[4] - 2.8284) > eps ||
//         std::fabs(block[6] - 1.2247) > eps || std::fabs(block[7] - 0.7071) > eps || std::fabs(block[8] - 2.4495) > eps)
//        pass = false;
//    if ( !pass )
//        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];
//    block = iChol->blockPtr(1, 0);
//    if ( std::fabs(block[2] + 2.4495) > eps ||
//         std::fabs(block[5] - 0.8165) > eps )
//        pass = false;
//    if ( !pass )
//        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];
//    block = iChol->blockPtr(1, 1);
//    if ( std::fabs(block[0] - 4.2426) > eps ||
//         std::fabs(block[3] - 0.0) > eps || std::fabs(block[4] - 2.7080) > eps )
//        pass = false;
//    if ( !pass )
//        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];

//    QVERIFY2(pass, "Fail to compute incomplete Chol");

//    auto colsInRows = iChol->columnsInRows();
//    pass = true;
//    if( colsInRows[0] != std::vector<int>({0}) ) pass = false;
//    if( colsInRows[1] != std::vector<int>({0, 1}) ) pass = false;
//    QVERIFY2(pass, "Fail to get column indexes in rows");

//    auto rowsInCols = iChol->rowsInColumns();
//    pass = true;
//    if( rowsInCols[0] != std::vector<int>({0, 1}) ) pass = false;
//    if( rowsInCols[1] != std::vector<int>({1}) ) pass = false;
//    QVERIFY2(pass, "Fail to get rows indexes in columns");

//    //FIXME not working
//    //delete matrix;
//    //delete iChol;
//}

//void TestStiffMatrixes::case02_createIncompleteChol2(){
//    //Create simple matrix
//    sbfStiffMatrixBlock3x3_old * matrix = new sbfStiffMatrixBlock3x3_old(3, 2);
//    /*
//     *  [   24  0   6   0   0   0   ]
//     *  [   0   8   2   0   0   0   ]
//     *  [   6   2   8   -6  2   0   ]
//     *  [   0   0   -6  24  0   0   ]
//     *  [   0   0   2   0   8   0   ]
//     *  [   0   0   0   0   0   1   ]
//     */
//    matrix->setType(MatrixType::DOWN_TREANGLE_MATRIX);
//    std::vector<int> indJ{0, 0, 1}, shiftInd{0, 1, 3};
//    std::vector<int> indJAlt{1}, shiftIndAlt{0, 1, 1};
//    matrix->setIndData(2, 3, &indJ[0], &shiftInd[0], 1, &indJAlt[0], &shiftIndAlt[0]);
//    matrix->null();
//    double * block = matrix->blockPtr(0, 0);
//    block[0] = 24; block[1] = 0; block[2] = 6;
//    block[3] = 0; block[4] = 8; block[5] = 2;
//    block[6] = 6; block[7] = 2; block[8] = 8;
//    block = matrix->blockPtr(1, 0);
//    block[2] = -6;
//    block[5] = 2;
//    block = matrix->blockPtr(1, 1);
//    block[0] = 24;
//    block[4] = 8;
//    block[8] = 1;

//    //std::unique_ptr<sbfStiffMatrixBlock3x3> iCholRes(matrix->makeIncompleteChol());
//    sbfStiffMatrixBlock3x3_old * iChol = matrix->makeIncompleteChol();

//    //test
//    bool pass = true;
//    const double eps = 0.0001;
//    block = iChol->blockPtr(0, 0);
//    if ( std::fabs(block[0] - 4.8990) > eps ||
//         std::fabs(block[4] - 2.8284) > eps ||
//         std::fabs(block[6] - 1.2247) > eps || std::fabs(block[7] - 0.7071) > eps || std::fabs(block[8] - 2.4495) > eps)
//        pass = false;
//    if ( !pass )
//        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];
//    block = iChol->blockPtr(1, 0);
//    if ( std::fabs(block[2] + 2.4495) > eps ||
//         std::fabs(block[5] - 0.8165) > eps )
//        pass = false;
//    if ( !pass )
//        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];
//    block = iChol->blockPtr(1, 1);
//    if ( std::fabs(block[0] - 4.2426) > eps ||
//         std::fabs(block[3] - 0.0) > eps || std::fabs(block[4] - 2.7080) > eps )
//        pass = false;
//    if ( !pass )
//        qDebug() << block[0] << block[1] << block[2] << block[3] << block[4] << block[5] << block[6] << block[7] << block[8];

//    QVERIFY2(pass, "Fail to compute incomplete Chol");

//    auto colsInRows = iChol->columnsInRows();
//    pass = true;
//    if( colsInRows[0] != std::vector<int>({0}) ) pass = false;
//    if( colsInRows[1] != std::vector<int>({0, 1}) ) pass = false;
//    QVERIFY2(pass, "Fail to get column indexes in rows");

//    auto rowsInCols = iChol->rowsInColumns();
//    pass = true;
//    if( rowsInCols[0] != std::vector<int>({0, 1}) ) pass = false;
//    if( rowsInCols[1] != std::vector<int>({1}) ) pass = false;
//    QVERIFY2(pass, "Fail to get rows indexes in columns");

//    //FIXME not working
//    //delete matrix;
//    //delete iChol;
//}

//void TestStiffMatrixes::case03_solveLLTuf()
//{
//    //Create simple matrix
//    sbfStiffMatrixBlock3x3_old * matrix = new sbfStiffMatrixBlock3x3_old(3, 2);
//    /*
//     *
//     *  [   10  0   0   0   0   0   ]   [1]     [10]
//     *  [   1   10  0   0   0   0   ]   [1.9]   [20]
//     *  [   0   0   10  0   0   0   ] * [1]   = [10]
//     *  [   2   0   0   20  0   0   ]   [1]     [22]
//     *  [   0   0   0   3   10  0   ]   [2]     [23]
//     *  [   1   1   1   1   1   10  ]   [0]     [6.9]
//     *
//     */
//    matrix->setType(MatrixType::DOWN_TREANGLE_MATRIX);
//    std::vector<int> indJ{0, 0, 1}, shiftInd{0, 1, 3};
//    //Iterator expects symmetry matrix to process columns
//    std::vector<int> indJAlter{1}, shiftIndAlter{0, 1, 1};
//    matrix->setIndData(2, 3, indJ.data(), shiftInd.data(), indJAlter.size(), indJAlter.data(), shiftIndAlter.data());
//    matrix->null();
//    double * block = matrix->blockPtr(0, 0);
//    //Iterator expects symmetry matrix to process columns
//    block[0] = 10; /*block[1] = 1;*/
//    block[3] = 1; block[4] = 10;
//    block[8] = 10;
//    block = matrix->blockPtr(1, 0);
//    block[0] = 2;
//    block[6] = 1; block[7] = 1; block[8] = 1;
//    block = matrix->blockPtr(1, 1);
//    //Iterator expects symmetry matrix to process columns
//    block[0] = 20; /*block[1] = 3; block[2] = 1;*/
//    block[3] = 3; block[4] = 10; /*block[5] = 1;*/
//    block[6] = 1; block[7] = 1; block[8] = 10;

//    NodesData<> u(2), f(2), uTarget(2), f_test(2);
//    f.data()[0] = 10;
//    f.data()[1] = 20;
//    f.data()[2] = 10;
//    f.data()[3] = 22;
//    f.data()[4] = 23;
//    f.data()[5] = 6.9;

//    uTarget.data()[0] = 0.077;
//    uTarget.data()[1] = 1.9000e-01;
//    uTarget.data()[2] = 1.0000e-01;
//    uTarget.data()[3] = 2.0000e-02;
//    uTarget.data()[4] = 2.0000e-01;
//    uTarget.data()[5] = 0.0;

//    matrix->solve_L_LT_u_eq_f(u.data(), f.data());

////    matrix->multiplyByVector(u.data(), f_test.data());

//    bool pass = true;
//    double eps = 1e-8;
//    for(int ct = 0; ct < 6; ct++)
//        if ( fabs(u.data()[ct] - uTarget.data()[ct]) > eps ) pass = false;

//    if(!pass) {
//        qDebug() << u.data()[0] << u.data()[1] << u.data()[2] << u.data()[3] << u.data()[4] << u.data()[5];
//        qDebug() << uTarget.data()[0] << uTarget.data()[1] << uTarget.data()[2] << uTarget.data()[3] << uTarget.data()[4] << uTarget.data()[5];
//    }

//    QVERIFY2(pass, "Failed to make LLTuf solution");
//    //delete matrix;
//}

void TestStiffMatrixes::case04_CGMwP()
{
    sbfTimer<> timer;
    timer.start();
    float xSide = 100, ySide = 10, zSide = 10;
    float targetError = 1e-2;
    int xPart = 100, yPart = 10, zPart = 10;
    qDebug() << "Make mesh";
    std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    sbfMesh * mesh = meshRes.get();
    mesh->applyToAllElements([](sbfElement & elem){elem.setMtr(1);});
    mesh->optimizeNodesNumbering();

    qDebug() << "Prepare groups";
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

    std::unique_ptr<sbfStiffMatrixBlock3x3> stiffRes(new sbfStiffMatrixBlock3x3(mesh, &propSet));
    sbfStiffMatrixBlock3x3 * stiff = stiffRes.get();

    qDebug() << "Compute stiff matrix";
    stiff->computeSequantially();
    QVERIFY2(stiff->isValid(), "Stiffness is not valid");

    NodesData<> force(mesh), disp(mesh);
    force.null();
    disp.null();

    //FIXME make normal loading
    for( auto node : loadInds ) force.data(node, 0) = 1.0/loadInds.size();

    qDebug() << "Fixing nodes";
    for( auto node : lockInds ) stiff->lockDof(node, 0, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(mesh->nodeAt(0, 0, 0), 1, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(mesh->nodeAt(0, 0, 0), 2, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    QVERIFY2(stiff->isValid(), "Stiffness is not valid");

    qDebug() << "Make incomplete Chol";
    std::unique_ptr<sbfStiffMatrixBlock3x3> iCholRes(reinterpret_cast<sbfStiffMatrixBlock3x3*>(stiff->createIncompleteChol()));
    sbfStiffMatrixBlock3x3 * iChol = iCholRes.get();

//    qDebug() << "Prepare indexes";
//    std::vector<std::vector<int>> rowsInColumnsIndexes;
//    rowsInColumnsIndexes.resize(mesh->numNodes());
//    for(int ctRow = 0; ctRow < mesh->numNodes(); ctRow++) {
//        for(int ctColumn = 0; ctColumn <= ctRow; ctColumn++)
//            if (iChol->data(ctRow, ctColumn))
//                rowsInColumnsIndexes[ctColumn].push_back(ctRow);
//    }

    qDebug() << "Actual start";
    //Conjugate Gradient Method with Preconditioning
    //FEP - Bathe p.763

    const int numDOF = mesh->numNodes()*3;

    //_p1 stands for 'plus one'
    NodesData<> KU(mesh), Kp(mesh), r(mesh), r_p1(mesh), z(mesh), z_p1(mesh), p(mesh), p_p1(mesh), tmp(mesh);
    double *KU_ptr, *Kp_ptr, *r_ptr, *r_p1_ptr, *z_ptr, *z_p1_ptr, *p_ptr, *p_p1_ptr, *tmp_ptr, *disp_ptr;
    KU_ptr = KU.data();
    Kp_ptr = Kp.data();
    r_ptr = r.data();
    r_p1_ptr = r_p1.data();
    z_ptr = z.data();
    z_p1_ptr = z_p1.data();
    p_ptr = p.data();
    p_p1_ptr = p_p1.data();
    tmp_ptr = tmp.data();
    disp_ptr = disp.data();
    double alpha, betta;

    //initial step
//    disp.copyData(force.data());
    iChol->solve_L_LT_u_eq_f(disp.data(), force.data());
    stiff->multiplyByVector(disp.data(), KU.data());
    r.copyData((force - KU).data());

    //Solve L*L^T*z = r
    iChol->solve_L_LT_u_eq_f(z.data(), r.data());
    p.copyData(z.data());

    double rNorm = 0.0;
    for(int ct = 0; ct < numDOF; ct++) if ( rNorm < fabs(r_ptr[ct]) ) rNorm = fabs(r_ptr[ct]);
    int numIterations = 0;
    double rNormTarget = 1e-6;
//    stiff->prepareParallelMultiplyByVector(p_ptr, Kp_ptr);
    while(rNorm > rNormTarget) {
        auto timePoint1 = std::chrono::high_resolution_clock::now();
        stiff->multiplyByVector(p_ptr, Kp_ptr);
//        stiff->makeParallelMultiplyByVector();
        auto timePoint2 = std::chrono::high_resolution_clock::now();
        alpha = z.scalMul(r)/p.scalMul(Kp);
        for(int ct = 0; ct < numDOF; ct++) {
            disp_ptr[ct] += alpha*p_ptr[ct];
            r_p1_ptr[ct] = r_ptr[ct] - alpha*Kp_ptr[ct];
        }
        auto timePoint3 = std::chrono::high_resolution_clock::now();
        iChol->solve_L_LT_u_eq_f(z_p1_ptr, r_p1_ptr);
        auto timePoint4 = std::chrono::high_resolution_clock::now();
        betta = z_p1.scalMul(r_p1)/z.scalMul(r);
        for(int ct = 0; ct < numDOF; ct++) {
            p_p1_ptr[ct] = z_p1_ptr[ct] + betta*p_ptr[ct];
        }
        z.copyData(z_p1_ptr);
        p.copyData(p_p1_ptr);
        r.copyData(r_p1_ptr);
        rNorm = 0.0;
        for(int ct = 0; ct < numDOF; ct++) if ( rNorm < fabs(r_ptr[ct]) ) rNorm = fabs(r_ptr[ct]);
        numIterations++;
        auto timePoint5 = std::chrono::high_resolution_clock::now();

        if ( numIterations % 100 == 0) {
            std::cout << "MatMul         :" << std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint2 - timePoint1).count() << std::endl;
            std::cout << "VectOperation  :" << std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint3 - timePoint2).count() << std::endl;
            std::cout << "LLTSolve       :" << std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint4 - timePoint3).count() << std::endl;
            std::cout << "VectOperation2 :" << std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint5 - timePoint4).count() << std::endl;
            qDebug() << numIterations << rNorm << rNormTarget;
        }
    }

    double averDisp = 0.0;
    for( auto node : loadInds ) averDisp += disp.data(node, 0);
    averDisp /= loadInds.size();
    double E = propSet.material(0)->propertyTable("elastic module")->curValue();
    double dL = xSide*1.0/E/ySide/zSide;

    qDebug() << numIterations << averDisp << dL << std::fabs(averDisp - dL)/dL;

    if ( std::fabs(averDisp - dL)/dL > targetError ) {
        qDebug() << QString("Expected displacement of loaded side is %1, got %2, error %3").arg(dL).arg(averDisp).arg(std::fabs(averDisp - dL)/dL);
        QVERIFY2(false, "Fail to make simple tensile solution");
    }

    timer.stop();
    report("CGMwP test done in ", timer.timeSpanStr());
}

#include "sbfStiffMatrixBlock6x6.h"
#include "sbfAdditions.h"
auto mul = [](sbfStiffMatrixBlock6x6 *stiff, NodesData<double, 6> &d, NodesData<double, 6> &f){
    f.null();
    CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);
    for(int ctNode = 0; ctNode < stiff->mesh()->numNodes(); ++ctNode) {
        iterator->setToRow(ctNode);
        while(iterator->isValid()) {
            double *data = iterator->data();
            double *dataF = f.data()+6*ctNode;
            int columnID = iterator->column();
            for(int ct1 = 0; ct1 < 6; ++ct1)
                for(int ct2 = 0; ct2 < 6; ++ct2)
                    dataF[ct1] += data[ct1*6+ct2]*d.data()[6*columnID+ct2];
            iterator->next();
        }
    }
};

void TestStiffMatrixes::case10_block6x6()
{
    auto material = sbfMaterialProperties::makeMPropertiesSteel();
    auto aTable = new sbfPropertyTable("area");
    aTable->addNodeValue(24.0f, 1.0f);
    aTable->setCurParam(24.0f);
    material->addTable(aTable);
    auto gTable = new sbfPropertyTable("shear module");
    gTable->addNodeValue(24.0f, 80000.0f);
    gTable->setCurParam(24.0f);
    material->addTable(gTable);
    auto ixTable = new sbfPropertyTable("Ix");
    ixTable->addNodeValue(24.0f, 1.0f);
    ixTable->setCurParam(24.0f);
    material->addTable(ixTable);
    auto iyTable = new sbfPropertyTable("Iy");
    iyTable->addNodeValue(24.0f, 1.0f);
    iyTable->setCurParam(24.0f);
    material->addTable(iyTable);
    auto izTable = new sbfPropertyTable("Iz");
    izTable->addNodeValue(24.0f, 1.0f);
    izTable->setCurParam(24.0f);
    material->addTable(izTable);
    auto propSet = new sbfPropertiesSet();
    propSet->addMaterial(material);
    propSet->write("test.prop");

    CreateSmartAndRawPtr(sbfMesh, new sbfMesh, mesh);
    mesh->addNode(0, 0, 0);
    mesh->addNode(1, 1, 1);
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 1}));
    mesh->applyToAllElements([](sbfElement &elem){elem.setMtr(1);});

    CreateSmartAndRawPtr(sbfStiffMatrixBlock6x6, new sbfStiffMatrixBlock6x6(mesh, propSet), stiff);

    QVERIFY2(stiff->storeType() == MatrixStoreType::COMPACT, "Fail to get compact store type");

    stiff->computeSequantially();
    CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);

    NodesData<double, 6> d(mesh), f(mesh);

    for(int ct = 0; ct < mesh->numNodes(); ct++) for(int ct1 = 0; ct1 < 3; ct1++) d.data(ct, ct1) = 5.0/(ct1+1);
    mul(stiff, d, f);
    bool pass = true;
    double eps = 1e-7;
    for(int ct = 0; ct < mesh->numNodes(); ct++) for(int ct1 = 0; ct1 < 6; ct1++)
        if( std::fabs(f.data(ct, ct1)) > eps ) pass = false;
    QVERIFY2(pass, "Cant pass patch test");

    mesh->node(0).setX(std::sqrt(1.0/3));
    mesh->node(0).setY(std::sqrt(1.0/3));
    mesh->node(0).setZ(std::sqrt(1.0/3));
    mesh->node(1).setX(0);
    mesh->node(1).setY(0);
    mesh->node(1).setZ(0);
    stiff->computeSequantially();
    d.null();
    d.data(1, 0) = std::sqrt(1.0/3);
    d.data(1, 1) = std::sqrt(1.0/3);
    d.data(1, 2) = std::sqrt(1.0/3);
    mul(stiff, d, f);
    pass = true;
    if(!pass) {
        for(int ct = 0; ct < mesh->numNodes(); ct++) for(int ct1 = 0; ct1 < 6; ct1++) qDebug() << d.data(ct, ct1) << f.data(ct, ct1);
    }
    QVERIFY2(pass, "Cant pass simple loading test");
}

void TestStiffMatrixes::case10_band6()
{
    auto material = sbfMaterialProperties::makeMPropertiesSteel();
    auto aTable = new sbfPropertyTable("area");
    aTable->addNodeValue(24.0f, 1.0f);
    aTable->setCurParam(24.0f);
    material->addTable(aTable);
    auto gTable = new sbfPropertyTable("shear module");
    gTable->addNodeValue(24.0f, 80000.0f);
    gTable->setCurParam(24.0f);
    material->addTable(gTable);
    auto ixTable = new sbfPropertyTable("Ix");
    ixTable->addNodeValue(24.0f, 1.0f);
    ixTable->setCurParam(24.0f);
    material->addTable(ixTable);
    auto iyTable = new sbfPropertyTable("Iy");
    iyTable->addNodeValue(24.0f, 1.0f);
    iyTable->setCurParam(24.0f);
    material->addTable(iyTable);
    auto izTable = new sbfPropertyTable("Iz");
    izTable->addNodeValue(24.0f, 1.0f);
    izTable->setCurParam(24.0f);
    material->addTable(izTable);
    auto propSet = new sbfPropertiesSet();
    propSet->addMaterial(material);
    propSet->write("test.prop");

    CreateSmartAndRawPtr(sbfMesh, new sbfMesh, mesh);
    mesh->addNode(0, 0, 0);
    mesh->addNode(1, 1, 1);
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 1}));
    mesh->applyToAllElements([](sbfElement &elem){elem.setMtr(1);});

    CreateSmartAndRawPtr(sbfStiffMatrixBand6, new sbfStiffMatrixBand6(mesh, propSet), stiff);

    QVERIFY2(stiff->storeType() == MatrixStoreType::FULL, "Fail to get full store type");

    stiff->computeSequantially();
    CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);

    NodesData<double, 6> d(mesh), f(mesh);

    for(int ct = 0; ct < mesh->numNodes(); ct++) for(int ct1 = 0; ct1 < 3; ct1++) d.data(ct, ct1) = 5.0/(ct1+1);
//    mul(stiff, d, f);
    stiff->multiplyByVector(d.data(), f.data());
    bool pass = true;
    double eps = 1e-7;
    for(int ct = 0; ct < mesh->numNodes(); ct++) for(int ct1 = 0; ct1 < 6; ct1++)
        if( std::fabs(f.data(ct, ct1)) > eps ) pass = false;
    QVERIFY2(pass, "Cant pass patch test");

    mesh->node(0).setX(std::sqrt(1.0/3));
    mesh->node(0).setY(std::sqrt(1.0/3));
    mesh->node(0).setZ(std::sqrt(1.0/3));
    mesh->node(1).setX(0);
    mesh->node(1).setY(0);
    mesh->node(1).setZ(0);
    stiff->computeSequantially();
    d.null();
    d.data(1, 0) = std::sqrt(1.0/3);
    d.data(1, 1) = std::sqrt(1.0/3);
    d.data(1, 2) = std::sqrt(1.0/3);
//    mul(stiff, d, f);
    stiff->multiplyByVector(d.data(), f.data());
    pass = true;
    if(!pass) {
        for(int ct = 0; ct < mesh->numNodes(); ct++) for(int ct1 = 0; ct1 < 6; ct1++) qDebug() << d.data(ct, ct1) << f.data(ct, ct1);
    }
    QVERIFY2(pass, "Cant pass simple loading test");
}

void TestStiffMatrixes::case11_CGMwP()
{
    CreateSmartAndRawPtr(sbfPropertiesSet, new sbfPropertiesSet, propSet);
    propSet->read("test.prop");
    CreateSmartAndRawPtr(sbfMesh, mesh);

    float xSide = 1000;
    float xPart = 100;
    mesh->addNode(0, 0, 0, false);
    for(int ct = 1; ct <= xPart; ct++)
        mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {ct-1, mesh->addNode(xSide/xPart*ct, 0, 0, false)}));
    mesh->setMtr(1);
    CreateSmartAndRawPtr(sbfStiffMatrixBlock6x6, new sbfStiffMatrixBlock6x6(mesh, propSet), stiff);

    stiff->computeSequantially();

    NodesData<double, 6> force(mesh), disp(mesh);
    force.null();
    disp.null();
    CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iter);

    iter->setToRow(0);
    iter->diagonal(0);
    double *data = iter->data();
    for(int ct = 0; ct < 6; ++ct) data[ct*(6+1)] *= 1e3;
    double forceAmp = 1;
    force.data(mesh->numNodes()-1, 0) = forceAmp;
    force.data(mesh->numNodes()-1, 3) = forceAmp;
    force.data(mesh->numNodes()-1, 1) = forceAmp;

    CreateSmartAndRawPtr(sbfStiffMatrixBlock6x6, reinterpret_cast<sbfStiffMatrixBlock6x6*>(stiff->createChol()), iChol);

    const int numDOF = mesh->numNodes()*6;

    //_p1 stands for 'plus one'
    NodesData<double, 6> KU(mesh), Kp(mesh), r(mesh), r_p1(mesh), z(mesh), z_p1(mesh), p(mesh), p_p1(mesh), tmp(mesh);
    double *KU_ptr, *Kp_ptr, *r_ptr, *r_p1_ptr, *z_ptr, *z_p1_ptr, *p_ptr, *p_p1_ptr, *tmp_ptr, *disp_ptr;
    KU_ptr = KU.data();
    Kp_ptr = Kp.data();
    r_ptr = r.data();
    r_p1_ptr = r_p1.data();
    z_ptr = z.data();
    z_p1_ptr = z_p1.data();
    p_ptr = p.data();
    p_p1_ptr = p_p1.data();
    tmp_ptr = tmp.data();
    disp_ptr = disp.data();
    double alpha, betta;

    iChol->solve_L_LT_u_eq_f(disp.data(), force.data());
    //QVERIFY2(false, "ERROR");
    mul(stiff, disp, KU);
    r.copyData((force - KU).data());

    //Solve L*L^T*z = r
    iChol->solve_L_LT_u_eq_f(z.data(), r.data());
    p.copyData(z.data());

    double rNorm = 0.0;
    for(int ct = 0; ct < numDOF; ct++) if ( rNorm < fabs(r_ptr[ct]) ) rNorm = fabs(r_ptr[ct]);
    int numIterations = 0;
    double rNormTarget = 1e-6;

    while(rNorm > rNormTarget) {
        mul(stiff, p, Kp);
        alpha = z.scalMul(r)/p.scalMul(Kp);
        for(int ct = 0; ct < numDOF; ct++) {
            disp_ptr[ct] += alpha*p_ptr[ct];
            r_p1_ptr[ct] = r_ptr[ct] - alpha*Kp_ptr[ct];
        }
        iChol->solve_L_LT_u_eq_f(z_p1_ptr, r_p1_ptr);
        betta = z_p1.scalMul(r_p1)/z.scalMul(r);
        for(int ct = 0; ct < numDOF; ct++)
            p_p1_ptr[ct] = z_p1_ptr[ct] + betta*p_ptr[ct];
        z.copyData(z_p1_ptr);
        p.copyData(p_p1_ptr);
        r.copyData(r_p1_ptr);
        rNorm = 0.0;
        for(int ct = 0; ct < numDOF; ct++) if ( rNorm < fabs(r_ptr[ct]) ) rNorm = fabs(r_ptr[ct]);
        numIterations++;
    }

    auto mtr = propSet->material(0);
    qDebug() << numIterations << disp.data(mesh->numNodes()-1, 0) << forceAmp*xSide/mtr->propertyTable("elastic module")->curValue()/mtr->propertyTable("area")->curValue();
    qDebug() << numIterations << disp.data(mesh->numNodes()-1, 3) << forceAmp*xSide/mtr->propertyTable("shear module")->curValue()/mtr->propertyTable("area")->curValue();
    qDebug() << numIterations << disp.data(mesh->numNodes()-1, 1) << forceAmp*xSide*xSide*xSide/3/mtr->propertyTable("elastic module")->curValue()/mtr->propertyTable("Iz")->curValue();

}

void TestStiffMatrixes::case11_CGMwP_band6()
{
    CreateSmartAndRawPtr(sbfPropertiesSet, new sbfPropertiesSet, propSet);
    propSet->read("test.prop");
    CreateSmartAndRawPtr(sbfMesh, mesh);

    float xSide = 1000;
    float xPart = 100;
    mesh->addNode(0, 0, 0, false);
    for(int ct = 1; ct <= xPart; ct++)
        mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {ct-1, mesh->addNode(xSide/xPart*ct, 0, 0, false)}));
    mesh->setMtr(1);
    CreateSmartAndRawPtr(sbfStiffMatrixBand6, new sbfStiffMatrixBand6(mesh, propSet), stiff);

    stiff->computeSequantially();
    QVERIFY2(stiff->isValid(), "Not valid stiffness matrix");

    NodesData<double, 6> force(mesh), disp(mesh);
    force.null();
    disp.null();
    CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iter);

    iter->setToRow(0);
    iter->diagonal(0);
    double *data = iter->data();
    for(int ct = 0; ct < 6; ++ct) data[ct*(6+1)] *= 1e3;
    double forceAmp = 1;
    force.data(mesh->numNodes()-1, 0) = forceAmp;
    force.data(mesh->numNodes()-1, 3) = forceAmp;
    force.data(mesh->numNodes()-1, 1) = forceAmp;

    CreateSmartAndRawPtr(sbfStiffMatrixBand6, reinterpret_cast<sbfStiffMatrixBand6*>(stiff->createChol()), iChol);

    const int numDOF = mesh->numNodes()*6;

    //_p1 stands for 'plus one'
    NodesData<double, 6> KU(mesh), Kp(mesh), r(mesh), r_p1(mesh), z(mesh), z_p1(mesh), p(mesh), p_p1(mesh), tmp(mesh);
    double *KU_ptr, *Kp_ptr, *r_ptr, *r_p1_ptr, *z_ptr, *z_p1_ptr, *p_ptr, *p_p1_ptr, *tmp_ptr, *disp_ptr;
    KU_ptr = KU.data();
    Kp_ptr = Kp.data();
    r_ptr = r.data();
    r_p1_ptr = r_p1.data();
    z_ptr = z.data();
    z_p1_ptr = z_p1.data();
    p_ptr = p.data();
    p_p1_ptr = p_p1.data();
    tmp_ptr = tmp.data();
    disp_ptr = disp.data();
    double alpha, betta;

    iChol->solve_L_LT_u_eq_f(disp.data(), force.data());
    //QVERIFY2(false, "ERROR");
    stiff->multiplyByVector(disp.data(), KU.data());
//    mul(stiff, disp, KU);
    r.copyData((force - KU).data());

    //Solve L*L^T*z = r
    iChol->solve_L_LT_u_eq_f(z.data(), r.data());
    p.copyData(z.data());

    double rNorm = 0.0;
    for(int ct = 0; ct < numDOF; ct++) if ( rNorm < fabs(r_ptr[ct]) ) rNorm = fabs(r_ptr[ct]);
    int numIterations = 0;
    double rNormTarget = 1e-6;

    while(rNorm > rNormTarget) {
//        mul(stiff, p, Kp);
        stiff->multiplyByVector(p.data(), Kp.data());
        alpha = z.scalMul(r)/p.scalMul(Kp);
        for(int ct = 0; ct < numDOF; ct++) {
            disp_ptr[ct] += alpha*p_ptr[ct];
            r_p1_ptr[ct] = r_ptr[ct] - alpha*Kp_ptr[ct];
        }
        iChol->solve_L_LT_u_eq_f(z_p1_ptr, r_p1_ptr);
        betta = z_p1.scalMul(r_p1)/z.scalMul(r);
        for(int ct = 0; ct < numDOF; ct++)
            p_p1_ptr[ct] = z_p1_ptr[ct] + betta*p_ptr[ct];
        z.copyData(z_p1_ptr);
        p.copyData(p_p1_ptr);
        r.copyData(r_p1_ptr);
        rNorm = 0.0;
        for(int ct = 0; ct < numDOF; ct++) if ( rNorm < fabs(r_ptr[ct]) ) rNorm = fabs(r_ptr[ct]);
        numIterations++;
    }

    auto mtr = propSet->material(0);
    qDebug() << numIterations << disp.data(mesh->numNodes()-1, 0) << forceAmp*xSide/mtr->propertyTable("elastic module")->curValue()/mtr->propertyTable("area")->curValue();
    qDebug() << numIterations << disp.data(mesh->numNodes()-1, 3) << forceAmp*xSide/mtr->propertyTable("shear module")->curValue()/mtr->propertyTable("area")->curValue();
    qDebug() << numIterations << disp.data(mesh->numNodes()-1, 1) << forceAmp*xSide*xSide*xSide/3/mtr->propertyTable("elastic module")->curValue()/mtr->propertyTable("Iz")->curValue();
}
