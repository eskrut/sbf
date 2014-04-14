#include "test_sbfMesh.h"
#include <QDir>
#include <QDebug>
#include <memory>

void TestSbfMesh::case01_createStandards()
{
    QVERIFY2(sbfMesh::makeBlock(1, 2, 0, 1, 1, 1) == nullptr, "Fail to process invalid parameters");
    QVERIFY2(sbfMesh::makeBlock(1, 2, 3, 1, 0, 1) == nullptr, "Fail to process invalid parameters");
    QVERIFY2(sbfMesh::makeBlock(1, 2, 3, 1, 1, 1, ElementType::BEAM_LINEAR_3DOF) == nullptr, "Fail to process invalid parameters");
    {
        float xSide = 1.0, ySide = 2.0, zSide = 3.0;
        int xPart = 2, yPart = 3, zPart = 4;
        std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
        sbfMesh * mesh = meshRes.get();
        QVERIFY2(mesh->numNodes() == (xPart+1)*(yPart+1)*(zPart+1), "Wrong nodes number");
        QVERIFY2(mesh->numElements() == xPart*yPart*zPart, "Wrong nodes number");
        QVERIFY2(mesh->minX() == 0, "Wrong boundary");
        QVERIFY2(mesh->maxZ() == zSide, "Wrong boundary");
    }
}

void TestSbfMesh::case02_readWrite()
{
    float xSide = 1.0, ySide = 2.0, zSide = 3.0;
    int xPart = 2, yPart = 3, zPart = 4;
    std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    sbfMesh * mesh = meshRes.get();
    mesh->writeMeshToFiles();

    //Create void mesh
    meshRes.reset(new sbfMesh);
    mesh = meshRes.get();
    mesh->readMeshFromFiles();
    QVERIFY2(mesh->numNodes() == (xPart+1)*(yPart+1)*(zPart+1), "Wrong nodes number");
    QVERIFY2(mesh->minX() == 0, "Wrong boundary");
    QVERIFY2(mesh->maxZ() == zSide, "Wrong boundary");
    QDir dir;
    dir.remove("ind.sba");
    dir.remove("crd.sba");
    dir.remove("mtr001.sba");
}

void TestSbfMesh::case03_addNodesElems()
{
    std::unique_ptr<sbfMesh> meshRes(new sbfMesh);
    sbfMesh * mesh = meshRes.get();
    auto newInd = mesh->addNode(0, 0, 0);
    QVERIFY2(mesh->numNodes() == 1 && newInd == 0, "Failed base add node");
    newInd = mesh->addNode(0.001, 0.001, 0.001, true, 0.01);
    QVERIFY2(mesh->numNodes() == 1 && newInd == 0, "Failed process duplicate node addition");
    std::vector<int> indexes;
    /*
     *    7-------6
     *   /|      /|     Z
     *  4-------5 |     |   Y
     *  | |     | |     |  /
     *  | 3- - -|-2     | /
     *  |/      |/      |/
     *  0-------1       0-------- X
    */
    indexes.push_back(newInd);
    indexes.push_back(mesh->addNode(1, 0, 0));
    indexes.push_back(mesh->addNode(1, 1, 0));
    indexes.push_back(mesh->addNode(0, 1, 0));
    indexes.push_back(mesh->addNode(0, 0, 1));
    indexes.push_back(mesh->addNode(1, 0, 1));
    indexes.push_back(mesh->addNode(1, 1, 1));
    indexes.push_back(mesh->addNode(0, 1, 1));
    mesh->addElement(sbfElement(ElementType::HEXAHEDRON_LINEAR, indexes));
    QVERIFY2(mesh->numNodes() == 8, "Failed to add element");
    QVERIFY2(mesh->numElements() == 1, "Failed to add element");
    QVERIFY2(mesh->maxX() == 1, "Failed to add element");
}

void TestSbfMesh::case04_geomTransformations()
{
    bool pass = true;
    int epsScale = 2;
    float xSide = 1.0, ySide = 2.0, zSide = 3.0;
    int xPart = 2, yPart = 3, zPart = 4;
    std::unique_ptr<sbfMesh> meshRes(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    sbfMesh * mesh = meshRes.get();

    //Scale
    float scaleX = 1.0/3.0, scaleY = 5.34, scaleZ = 9.888;
    mesh->scale(scaleX, scaleY, scaleZ);
    if (std::fabs(mesh->maxX() - xSide*scaleX) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug()<< "X"  << mesh->maxX() << xSide*scaleX << mesh->maxX() - xSide*scaleX << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    if (std::fabs(mesh->maxY() - ySide*scaleY) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "Y" << mesh->maxY() << ySide*scaleY << mesh->maxY() - ySide*scaleY << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    if (std::fabs(mesh->maxZ() - zSide*scaleZ) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "Z" << mesh->maxZ() << zSide*scaleZ << mesh->maxZ() - zSide*scaleZ << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    QVERIFY2(pass, "Fail to scale mesh");

    meshRes.reset(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    mesh = meshRes.get();
    pass = true;

    //Translate
    float transX = M_PI, transY = M_E, transZ = std::pow(M_PI, M_E);
    mesh->translate(transX, transY, transZ);
    if (std::fabs(mesh->maxX() - xSide - transX) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "X" << mesh->maxX() << xSide + transX << mesh->maxX() - xSide - transX << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    if (std::fabs(mesh->maxY() - ySide - transY) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "Y" << mesh->maxY() << ySide + transY << mesh->maxY() - ySide - transY << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    if (std::fabs(mesh->maxZ() - zSide - transZ) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "Z" << mesh->maxZ() << zSide + transZ << mesh->maxZ() - zSide - transZ << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    QVERIFY2(pass, "Fail to translate mesh");

    meshRes.reset(sbfMesh::makeBlock(xSide, ySide, zSide, xPart, yPart, zPart));
    mesh = meshRes.get();
    pass = true;

    //Rotate
    float rotX = 0, rotY = 0, rotZ = M_PI;
    mesh->rotate(rotX, rotY, rotZ);
    if (std::fabs(mesh->minX() + xSide) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "X" << mesh->minX() << -xSide << mesh->minX() + xSide << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    if (std::fabs(mesh->minY() + ySide) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "Y" << mesh->minY() << -ySide << mesh->minY() + ySide << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    if (std::fabs(mesh->minZ()) > std::numeric_limits<float>::epsilon()*epsScale) {
        qDebug() << "Z" << mesh->minZ() << 0 << mesh->minZ() - 0 << std::numeric_limits<float>::epsilon();
        pass = false;
    }
    QVERIFY2(pass, "Fail to translate mesh");
}

void TestSbfMesh::case05_merge()
{
    std::unique_ptr<sbfMesh> meshRes(new sbfMesh);
    sbfMesh * mesh = meshRes.get();
    mesh->addNode(0, 0, 0);
    mesh->addNode(0.001, 0, 0, false);
    mesh->addNode(0.01, 0, 0, false);
    mesh->addNode(0.1, 0, 0, false);
    QVERIFY2(mesh->numNodes() == 4, "Fail");
    mesh->mergeNodes(0.002);
    QVERIFY2(mesh->numNodes() == 3, "Fail to merge nodes");
    mesh->mergeNodes(0.02);
    QVERIFY2(mesh->numNodes() == 2, "Fail to merge nodes");
    mesh->mergeNodes(0.2);
    QVERIFY2(mesh->numNodes() == 1, "Fail to merge nodes");

    //Case with more nodes
    int numParts = 20;
    std::unique_ptr<sbfMesh> meshRes1(sbfMesh::makeBlock(1, 1, 1, numParts, numParts, numParts));
    sbfMesh * mesh1 = meshRes1.get();
    std::unique_ptr<sbfMesh> meshRes2(new sbfMesh(*mesh1));
    sbfMesh * mesh2 = meshRes2.get();
    mesh2->translate(1, 0, 0);
    mesh1->addMesh(mesh2, false, false);
    QVERIFY2(mesh1->numNodes() == 2*mesh2->numNodes() && mesh1->numElements() == 2*mesh2->numElements(), "Some error in mesh addition");
    int numMerged = mesh1->mergeNodes();
    QVERIFY2(numMerged == (numParts+1)*(numParts+1), QString("Fail to merge nodes. Expected %1, got %2").arg((numParts+1)*(numParts+1)).arg(numMerged).toStdString().c_str());
}

void TestSbfMesh::case05_merge_01()
{
    int dim = 1, num = 10;
    std::unique_ptr<sbfMesh> m1(sbfMesh::makeBlock(dim, dim, dim, num, num, num));
    std::unique_ptr<sbfMesh> m2(sbfMesh::makeBlock(2*dim, 2*dim, 2*dim, 2*num, 2*num, 2*num));
    std::unique_ptr<sbfMesh> m_add(new sbfMesh);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(dim, 0, 0);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(0, dim, 0);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(-dim, 0, 0);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(0, -dim, dim);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(dim, 0, 0);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(0, dim, 0);
    m_add->addMesh(m1.get(), false, false);
    m1->translate(-dim, 0, 0);
    m_add->addMesh(m1.get(), false, false);
    m_add->mergeNodes(0.001);

    QVERIFY2( m2->numNodes() == m_add->numNodes(), QString("Failed to merge nodes %1 %2").arg(m2->numNodes()).arg(m_add->numNodes()).toStdString().c_str() );
}

void TestSbfMesh::case06_buildCyl()
{
//    sbfMesh::makeCylinderPart(1, 2, 0, M_PI_2, 0, 5, 4, 15, 10)->writeMeshToFiles();
    sbfMesh::makeCylinderPart(std::vector<float>() = {1, 2, 3}, std::vector<float>() = {0, 1*M_PI/8, 2*M_PI/8, 3*M_PI/8, 4*M_PI/8}, std::vector<float>() = {0, 10})->writeMeshToFiles();
}
