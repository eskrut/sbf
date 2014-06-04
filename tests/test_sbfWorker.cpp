#include "test_sbfWorker.h"
#include <memory>
#include <sbfReporter.h>

void TestSbfWorker::case00_dummy()
{
    const int vecLength = 1000000;
    std::vector<double> vecToSum;
    vecToSum.resize(vecLength, 1);

    //Parallel summation
    class TaskAtributes : public sbfWorkerAttributes {
    public:
        double sum{0};
        double *portion{nullptr};
        int portionLength{0};
    };

    auto lambda = [](sbfWorkerAttributes * attrRaw){
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
class AbstractTreadAttrs{
public:
    AbstractTreadAttrs() {
        start_ = new EventType;
        event_init(start_);
        stop_ = new EventType;
        event_init(stop_);
    }

public:
    EventType *start_;
    EventType *stop_;
};
void TestSbfWorker::case01_dummy()
{
    class Task : public AbstractTreadAttrs {
    public:
        void operator()() {
            event_wait(start_);
            report("test");
            event_set(stop_);
        }
    };

    Task a;
    std::thread t(a);
    event_set(a.start_);
    event_wait(a.stop_);
    t.join();
}
