#include "test_sbfParalleltask.h"


void TestSbfParallelTask::case01_dummy01()
{
    class SumData : public sbfWorkerAttributes {
    public:
        using DataType = double;
        DataType * portion;
        DataType sum{0};
        int length;
    };
    auto func = [](sbfWorkerAttributes * attrRaw){
        SumData * data = static_cast<SumData *>(attrRaw);
        SumData::DataType * pointer = data->portion;
        for(int ct = 0; ct < data->length; ct++)
            data->sum += *pointer++;
        event_set(data->stop());
    };
    const int length = 1000000;
    std::vector<SumData::DataType> array(length, 1);
    std::vector<SumData *> attrs;
    for(int ct = 0; ct < sbfNumThreads; ct++) {
        attrs.push_back(new SumData);
        attrs.back()->setID(ct);
        attrs.back()->portion = &array[length/sbfNumThreads*ct];
        attrs.back()->length = ct < sbfNumThreads - 1 ? length/sbfNumThreads : length - length/sbfNumThreads*ct;
    }
    sbfParallelTask task(func, reinterpret_cast<sbfWorkerAttributes **>(&attrs[0]), sbfNumThreads);
    task.waitStop();
    SumData::DataType result = 0;
    for(auto it : attrs) result += it->sum;
    QVERIFY2(result == length, "Fail to parallel calculate");
}
