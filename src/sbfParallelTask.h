#ifndef SBFPARALLELTASK_H
#define SBFPARALLELTASK_H

#include <boost/function.hpp>
#include <memory>
#include "sbfDeclspec.h"
#include "sbfWorker.h"
#include <vector>

namespace funcNameSpace = boost;

class sbfParallelTask
{
public:
    enum class StartPolicy {StartImmediately, DelayedStart};
public:
    sbfParallelTask(funcNameSpace::function<void (sbfWorkerAttributes *)> workFunc, sbfWorkerAttributes ** attrs, int numThreads = sbfNumThreads, StartPolicy startPolicy = StartPolicy::StartImmediately);
    sbfParallelTask(funcNameSpace::function<void (sbfWorkerAttributes *)> workFunc, std::vector<sbfWorkerAttributes *> attrs, StartPolicy startPolicy = StartPolicy::StartImmediately);
    ~sbfParallelTask();
    funcNameSpace::function<void (sbfWorkerAttributes *)> workFunc() const;
    void setWorkFunc(const funcNameSpace::function<void (sbfWorkerAttributes *)> &workFunc);
//    EventType *start() const;
//    EventType *stop() const;
//    ThreadType *threads() const;
    int numThreads() const;
//    void setNumThreads(int numThreads);
    void startThreads();
    void signalStart();
    void waitStop();

private:
    funcNameSpace::function<void (sbfWorkerAttributes *)> workFunc_;
//    EventType * start_;
//    EventType * stop_;
    std::vector<ThreadType*> threads_;
    std::vector<sbfWorkerAttributes*> attrs_;
    int numThreads_;
    bool isThreadsStarted_;
    StartPolicy startPolicy_;
};

#endif // SBFPARALLELTASK_H
