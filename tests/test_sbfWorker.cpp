#include "test_sbfWorker.h"
#include <memory>

void TestSbfWorker::case00_dummy()
{
    const int vecLength = 1000000;
    std::vector<double> vecToSum;
    vecToSum.resize(vecLength, 1);

    //Parallel summation
    class TaskAtributes : public sbfWorkerAtributes {
    public:
        double sum{0};
        double *portion{nullptr};
        int portionLength{0};
    };

    auto lambda = [](sbfWorkerAtributes * attrRaw){
        TaskAtributes * attr = reinterpret_cast<TaskAtributes*>(attrRaw);
        for(int ct = 0; ct < attr->portionLength; ct++)
            attr->sum += attr->portion[ct];
    };

    TaskAtributes *attr = new TaskAtributes;
    attr->portion = &vecToSum[0];
    attr->portionLength = vecLength;
    attr->setWorkFunction(lambda);

    sbfWorker work(attr);
    work.execOnce();

    QVERIFY2(attr->sum == vecLength, "Error in non-threaded execution of worker function");
}
