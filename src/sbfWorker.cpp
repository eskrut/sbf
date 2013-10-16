#include "sbfWorker.h"
sbfWorkerAtributes::sbfWorkerAtributes() :
    workFunction_(nullptr),
    thread_(nullptr),
    start_(nullptr),
    stop_(nullptr),
    ID_(-1)
{
    thread_ = new ThreadType;
    event_init(start_ = new EventType);
    event_init(stop_ = new EventType);
}

sbfWorkerAtributes::~sbfWorkerAtributes()
{
    event_destroy(start_);
    event_destroy(stop_);
    delete start_;
    delete stop_;
    delete thread_;
}

std::function<void (sbfWorkerAtributes *)> sbfWorkerAtributes::workFunction() const
{
    return workFunction_;
}

void sbfWorkerAtributes::setWorkFunction(const std::function<void (sbfWorkerAtributes *)> &workFunction)
{
    workFunction_ = workFunction;
}

sbfWorker::sbfWorker(sbfWorkerAtributes *atributes) :
    attr_(atributes)
{
}

sbfWorker::~sbfWorker()
{
}

