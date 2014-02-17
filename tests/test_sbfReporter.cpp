#include "test_sbfReporter.h"
#include "sbfReporter.h"
#include <QThread>

void TestSbfReporter::case01_simpleReport()
{
    report("Simple line");
    report("Complex ", "line ", std::string("with number "), 7);

    report.createNewProgress("Test progress");
    report.updateProgress(0, 2, 0);
    report.updateProgress(50);
    QThread::msleep(250);
    report.finalizeProgress();
}

void TestSbfReporter::case02_simpleReport2()
{
    report.createNewProgress("Test progress");
    report.finalizeProgress();
}
