#ifndef TEST_MATRIXITERATOR_H
#define TEST_MATRIXITERATOR_H

#include <QTest>
#include <QDebug>

class TestMatrixIterator : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void case01_band6();
    //    void case01_block3x3();
    void case02_band6_advanced();

};

#endif // TEST_MATRIXITERATOR_H
