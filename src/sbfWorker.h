#ifndef SBFWORKER_H
#define SBFWORKER_H

#include <functional>
#include "sbfDeclspec.h"

enum class WorkerPolitics : short {

};

class DECLSPEC sbfWorkerAtributes
{
public:
    sbfWorkerAtributes();
    virtual ~sbfWorkerAtributes();
protected:
    std::function<void (sbfWorkerAtributes *)> workFunction_;
    ThreadType * thread_;
    EventType * start_;
    EventType * stop_;
    int ID_;
public:
    const EventType * start() { return start_; }
    const EventType * stop() { return stop_; }
    std::function<void (sbfWorkerAtributes *)> workFunction() const;
    void setWorkFunction(const std::function<void (sbfWorkerAtributes *)> &workFunction);
};

class DECLSPEC sbfWorker
{
public:
    sbfWorker(sbfWorkerAtributes * atributes);
    virtual ~sbfWorker();
    void execOnce() { attr_->workFunction()(attr_); }
private:
    sbfWorkerAtributes * attr_;
};

#endif // SBFWORKER_H
