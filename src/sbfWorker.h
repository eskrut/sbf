#ifndef SBFWORKER_H
#define SBFWORKER_H

#include <boost/function.hpp>
#include "sbfDeclspec.h"

namespace funcNameSpace = boost;

enum class WorkerPolitics : short {

};

class DECLSPEC sbfWorkerAttributes
{
public:
    sbfWorkerAttributes();
    virtual ~sbfWorkerAttributes();
protected:
    funcNameSpace::function<void (sbfWorkerAttributes *)> workFunction_;
    ThreadType * thread_;
    EventType * start_;
    EventType * stop_;
    int ID_;
public:
    EventType * start() { return start_; }
    EventType * stop() { return stop_; }
    funcNameSpace::function<void (sbfWorkerAttributes *)> workFunction() const;
    void setWorkFunction(const funcNameSpace::function<void (sbfWorkerAttributes *)> &workFunction);
    int ID() const;
    void setID(int ID);
};

class DECLSPEC sbfWorker
{
public:
    sbfWorker(sbfWorkerAttributes * attributes = nullptr);
    virtual ~sbfWorker();
    void setAtributes(sbfWorkerAttributes * attributes) { attr_ = attributes; }
    void execOnce() { attr_->workFunction()(attr_); }
private:
    sbfWorkerAttributes * attr_;
};

#endif // SBFWORKER_H
