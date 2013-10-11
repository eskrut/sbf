#ifndef TEST_STIFFMATRICES_H
#define TEST_STIFFMATRICES_H

#include <QTest>
#include <QDebug>

#include "sbf.h"

class TestStiffMatrices : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void case01_patchTest01();

};

#endif // TEST_STIFFMATRICES_H
