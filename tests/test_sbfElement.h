#ifndef TEST_SBFELEMENT_H
#define TEST_SBFELEMENT_H

#include <QTest>

#include "sbfElement.h"
#include "sbfNode.h"
#include "sbfMesh.h"

class TestSbfElement : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void case01_constructors();
    void case02_nodesInfo();
    void case03_nodesIndexes();
    void case04_facesIndexes();
};

#endif // TEST_SBFELEMENT_H
