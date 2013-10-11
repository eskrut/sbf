#include "test_sbfNode.h"
#include <limits>

void TestSbfNode::case01_construct()
{
    sbfNode node;
    QVERIFY2(node.x() == 0 && node.y() == 0 && node.z() == 0, "Fail initialize");
    sbfNode node1(0, 1, 2);
    QVERIFY2(node1.x() == 0 && node1.y() == 1 && node1.z() == 2, "Fail initialize");
}

void TestSbfNode::case02_getSet()
{
    sbfNode node(1, 1, 1);
    node.setX();
    node.setY(5);
    node.crdAtKort(2) = 3;
    QVERIFY2(node.x() == 0 && node.y() == 5 && node.z() == 3, QString("Fail set get: %1 %2 %3").arg(node.x()).arg(node.y()).arg(node.z()).toStdString().c_str());
}

void TestSbfNode::case03_rotate()
{
    sbfNode node(1, 0, 0);
    const CrdFloatType eps = std::numeric_limits<CrdFloatType>::epsilon();
    node.rotate(0, 0, M_PI_2);
    QString err = QString("Fail to rotate! Expected (%1, %2, %3), got (%4, %5, %6). Eps = %7").arg(0).arg(-1).arg(0).arg(node.x()).arg(node.y()).arg(node.z()).arg(eps);
    QVERIFY2(std::fabs(node.x()) < eps && std::fabs(node.y() - 1) < eps && std::fabs(node.z()) < eps, err.toStdString().c_str());
}

void TestSbfNode::case04_distance()
{
    sbfNode node0, node1(3, 4, 0);
    const CrdFloatType eps = std::numeric_limits<CrdFloatType>::epsilon();
    QString err = QString("Fail to compute distance! Expected %1, got %2. Eps = %3").arg(5).arg(node0.distance(node1)).arg(eps);
    QVERIFY2(std::fabs(node0.distance(node1) - 5) < eps, err.toStdString().c_str());
}
