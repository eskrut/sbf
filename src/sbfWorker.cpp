#include "sbfWorker.h"
sbfWorkerAtributes::sbfWorkerAtributes() :
    workFunction_(nullptr),
    start_(nullptr),
    stop_(nullptr),
    ID_(-1)
{
}

sbfWorker::sbfWorker(sbfWorkerAtributes *atributes) :
    attr_(atributes)
{
}

sbfWorker::~sbfWorker()
{
}


std::function<void (sbfWorkerAtributes *)> sbfWorkerAtributes::workFunction() const
{
    return workFunction_;
}

void sbfWorkerAtributes::setWorkFunction(const std::function<void (sbfWorkerAtributes *)> &workFunction)
{
    workFunction_ = workFunction;
}
