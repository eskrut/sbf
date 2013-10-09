#ifndef TEST_SBFNODE_H
#define TEST_SBFNODE_H

#include <QTest>
#include "sbfNode.h"

class TestSbfNode : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void case01_construct();
    void case02_getSet();
    void case03_rotate();
    void case04_distance();
};

#endif // TEST_SBFNODE_H
