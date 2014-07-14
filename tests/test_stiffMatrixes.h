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
//    void case01_mapHexa01();
//    void case02_createIncompleteChol();
//    void case02_createIncompleteChol2();
//    void case03_solveLLTuf();
    void case04_CGMwP();

    void case10_block6x6();
    void case10_band6();
    void case11_CGMwP();
    void case11_CGMwP_band6();
};

#endif // TEST_STIFFMATRICES_H
