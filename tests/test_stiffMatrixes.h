#ifndef TEST_STIFFMATRICES_H
#define TEST_STIFFMATRICES_H

#include <QTest>
#include <QDebug>

#include "sbf.h"

class TestStiffMatrixes : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void case01_patchTest01();
    void case02_createIncompleteChol();
    void case03_CGMwP();
};

#endif // TEST_STIFFMATRICES_H
