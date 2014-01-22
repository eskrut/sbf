#ifndef TEST_SBFREPORTER_H
#define TEST_SBFREPORTER_H

#include <QTest>

class TestSbfReporter : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void case01_simpleReport();
    void case02_simpleReport2();
};

#endif // TEST_SBFREPORTER_H
