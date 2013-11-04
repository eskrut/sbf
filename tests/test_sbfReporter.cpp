#include "test_sbfReporter.h"
#include "sbfReporter.h"
#include <QThread>

void TestSbfReporter::case01_simpleReport()
{
    report("Simple line");
    report("Complex ", "line ", std::string("with number "), 7);

    report.createNewProgress("Test progress");
    report.updateProgress(0, 2, 0);
//    QThread::sleep(2);
    report.updateProgress(20);
//    QThread::sleep(2);
    report.updateProgress(50);
//    QThread::sleep(2);
    report.updateProgress(80);
//    QThread::sleep(2);
    report.finalizeProgress();
}
