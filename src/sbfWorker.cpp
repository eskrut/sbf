#include "sbfWorker.h"
sbfWorkerAttributes::sbfWorkerAttributes() :
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

sbfWorkerAttributes::~sbfWorkerAttributes()
{
    event_destroy(start_);
    event_destroy(stop_);
    delete start_;
    delete stop_;
    delete thread_;
}
int sbfWorkerAttributes::ID() const
{
    return ID_;
}

void sbfWorkerAttributes::setID(int ID)
{
    ID_ = ID;
}


std::function<void (sbfWorkerAttributes *)> sbfWorkerAttributes::workFunction() const
{
    return workFunction_;
}

void sbfWorkerAttributes::setWorkFunction(const std::function<void (sbfWorkerAttributes *)> &workFunction)
{
    workFunction_ = workFunction;
}

sbfWorker::sbfWorker(sbfWorkerAttributes *attributes) :
    attr_(attributes)
{
}

sbfWorker::~sbfWorker()
{
}

