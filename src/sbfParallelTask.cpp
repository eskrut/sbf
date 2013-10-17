#include "sbfParallelTask.h"


sbfParallelTask::sbfParallelTask(std::function<void (sbfWorkerAttributes *)> workFunc, sbfWorkerAttributes **attrs, int numThreads, sbfParallelTask::StartPolicy startPolicy) :
    workFunc_(workFunc),
    numThreads_(numThreads),
    isThreadsStarted_(false),
    startPolicy_(startPolicy)
{
    threads_.resize(numThreads_, nullptr);
    for(auto & thread : threads_) thread = new ThreadType;
    attrs_.insert(attrs_.begin(), attrs, attrs + numThreads);
    if ( startPolicy_ == StartPolicy::StartImmediately ) {
       startThreads();
    }
}

sbfParallelTask::sbfParallelTask(std::function<void (sbfWorkerAttributes *)> workFunc, std::vector<sbfWorkerAttributes *> attrs, sbfParallelTask::StartPolicy startPolicy) :
    workFunc_(workFunc),
    attrs_(attrs),
    numThreads_(attrs.size()),
    isThreadsStarted_(false),
    startPolicy_(startPolicy)
{
    threads_.resize(numThreads_, nullptr);
    for(auto & thread : threads_) thread = new ThreadType;
    if ( startPolicy_ == StartPolicy::StartImmediately ) {
       startThreads();
    }
}

sbfParallelTask::~sbfParallelTask()
{
}

std::function<void (sbfWorkerAttributes *)> sbfParallelTask::workFunc() const
{
    return workFunc_;
}

void sbfParallelTask::setWorkFunc(const std::function<void (sbfWorkerAttributes *)> &workFunc)
{
    workFunc_ = workFunc;
}

//EventType *sbfParallelTask::start() const
//{
//    return start_;
//}

//EventType *sbfParallelTask::stop() const
//{
//    return stop_;
//}

//ThreadType *sbfParallelTask::threads() const
//{
//    return threads_;
//}

int sbfParallelTask::numThreads() const
{
    return numThreads_;
}

void sbfParallelTask::startThreads()
{
    if (!isThreadsStarted_) {
        using WrapParamType = std::pair<std::function<void (sbfWorkerAttributes *)>, sbfWorkerAttributes *>;
        auto wraper = [](void * param){
            WrapParamType * wrapParam = reinterpret_cast<WrapParamType*>(param);
            wrapParam->first(wrapParam->second);
        };
        for (int ct = 0; ct < numThreads_; ct++) {
            //FIXME litle leak of memory (no delete)
            createNewThread(threads_[ct], wraper, new WrapParamType{workFunc_, attrs_[ct]});
        }
        isThreadsStarted_ = true;
    }
    //TODO notify if threads already started
}

//void sbfParallelTask::setNumThreads(int numThreads)
//{
//    numThreads_ = numThreads;
//}

void sbfParallelTask::signalStart()
{
    for(int ct = 0; ct < numThreads_; ct++) event_set(attrs_[ct]->start());
}

void sbfParallelTask::waitStop()
{
    for(int ct = 0; ct < numThreads_; ct++) event_wait(attrs_[ct]->stop());
}





