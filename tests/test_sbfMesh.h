#ifndef TEST_SBFMESH_H
#define TEST_SBFMESH_H

#include <QTest>
#include "sbfMesh.h"
#include "sbfNode.h"
#include "sbfElement.h"

class TestSbfMesh : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void case01_createStandards();
    void case02_readWrite();
    void case03_addNodesElems();
    void case04_geomTransformations();
    void case05_merge();
};

#endif // TEST_SBFMESH_H
