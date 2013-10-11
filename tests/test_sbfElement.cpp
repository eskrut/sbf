#include "test_sbfElement.h"
#include <QDebug>

void TestSbfElement::case01_constructors()
{
    {
        //Test default constructor
        sbfElement elem;
        QVERIFY2(elem.type() == ElementType::NO_DEFINED_ELEMENT, "Wrong default type");
        QVERIFY2(elem.numNodes() == 0, "Wrong default nodes number");
        QVERIFY2(elem.mesh() == nullptr, "Wrong default meth ptr");
        QVERIFY2(elem.mtr() == 0, "Wrong default material");
    }
    {
        const int numNodes = 8;
        sbfElement elem(numNodes);
        QVERIFY2(elem.type() == ElementType::NO_DEFINED_ELEMENT, "Wrong default type");
        QVERIFY2(elem.numNodes() == numNodes, "Wrong nodes number");
        QVERIFY2(elem.mesh() == nullptr, "Wrong default meth ptr");
        QVERIFY2(elem.mtr() == 0, "Wrong default material");
    }
    {
        std::vector<int> nodesInds({0, 1, 2, 3, 4, 5, 6, 7});
        sbfElement elem(ElementType::HEXAHEDRON_LINEAR, nodesInds);
        QVERIFY2(elem.type() == ElementType::HEXAHEDRON_LINEAR, "Wrong type");
        QVERIFY2(elem.numNodes() == static_cast<int>(nodesInds.size()), "Wrong nodes number");
        QVERIFY2(elem.mesh() == nullptr, "Wrong default meth ptr");
        QVERIFY2(elem.mtr() == 0, "Wrong default material");
        bool pass = true;
        for(int ct = 0; ct < static_cast<int>(nodesInds.size()); ct++) if ( elem.nodeIndex(ct) != ct ) {pass = false; break;}
        QVERIFY2(pass, "Fail to set indexes");
    }
    {
        sbfElement elem(ElementType::HEXAHEDRON_LINEAR, {0,1,2,3,4,5,6,7});
        QVERIFY2(elem.type() == ElementType::HEXAHEDRON_LINEAR, "Wrong type");
        QVERIFY2(elem.numNodes() == 8, "Wrong nodes number");
        QVERIFY2(elem.mesh() == nullptr, "Wrong default meth ptr");
        QVERIFY2(elem.mtr() == 0, "Wrong default material");
        bool pass = true;
        for(int ct = 0; ct < 8; ct++) if ( elem.nodeIndex(ct) != ct ) {pass = false; break;}
        QVERIFY2(pass, "Fail to set indexes");
    }
}

void TestSbfElement::case02_nodesInfo()
{
    sbfElement elem;
    QVERIFY2(elem.max(0) != elem.max(0) /*This checks for nan*/, "Fail to get void max");
    elem.setNodes({0,1,2,3,4,5,6,7,8});
    QVERIFY2(elem.max(0) != elem.max(0), "Fail to get max with void mesh");
    sbfMesh mesh;
    for(int ct = 0; ct < elem.numNodes(); ct++)
        mesh.addNode(5*ct, 6*ct, -8*ct);
    elem.setMesh(&mesh);
    QVERIFY2(elem.max(0) == 5*(elem.numNodes()-1), "Fail to get max");
    QVERIFY2(elem.min(2) == -8*(elem.numNodes()-1), "Fail to get min");
}

void TestSbfElement::case03_nodesIndexes()
{
    sbfElement elem(ElementType::TETRAHEDRON_LINEAR, {0,1,2,3});
    QVERIFY2(elem.indexes() == std::vector<int>({0,1,2,3}), "Fail to get valid indexes.");
}

void TestSbfElement::case04_facesIndexes()
{
    std::list<sbfElement> elems;
    auto gen = [](int numNodes){
        std::vector<int> nodes;
        for(int ct = 0; ct < numNodes; ct++) nodes.push_back(ct);
        return nodes;
    };
    //FIXME add tests for all elements
    elems.push_back(sbfElement(ElementType::TETRAHEDRON_LINEAR, gen(4)));
    elems.push_back(sbfElement(ElementType::TETRAHEDRON_QUADRATIC, gen(10)));
    elems.push_back(sbfElement(ElementType::HEXAHEDRON_LINEAR, gen(8)));
    elems.push_back(sbfElement(ElementType::HEXAHEDRON_QUADRATIC, gen(20)));

    auto chechFunc = [&](sbfElement elem){
        bool pass = false;
        auto facesIndexes = elem.facesNodesIndexes();
        switch ( elem.type() ) {
        case ElementType::TETRAHEDRON_LINEAR:
            if ( facesIndexes == sbfElement::FacesNodesIndsContainer{{0,1,2},{0,3,1},{1,3,2},{2,3,0}}) pass = true; break;
        case ElementType::TETRAHEDRON_QUADRATIC:
            if ( facesIndexes == sbfElement::FacesNodesIndsContainer{{0,4,1,5,2,6},{0,7,3,8,1,4},{1,8,3,9,2,5},{2,9,3,7,0,6}}) pass = true; break;
        case ElementType::HEXAHEDRON_LINEAR:
            if ( facesIndexes == sbfElement::FacesNodesIndsContainer{{0,1,2,3},{4,7,6,5},{0,4,5,1},{1,5,6,2},{2,6,7,3},{3,7,4,0}}) pass = true; break;
        case ElementType::HEXAHEDRON_QUADRATIC:
            if ( facesIndexes == sbfElement::FacesNodesIndsContainer{{0,8,1,9,2,10,3,11},{4,19,7,18,6,17,5,16},{0,12,4,16,5,13,1,8},{1,13,5,17,6,14,2,9},{2,14,6,18,7,15,3,10},{3,15,7,19,4,12,0,11}}) pass = true; break;
        default:
            break;
        }
        QVERIFY2(pass, QString("Failed to process faces indexes for '%1' element type").arg(static_cast<int>(elem.type())).toStdString().c_str());
    };

    for(auto elem : elems) chechFunc(elem);
}
