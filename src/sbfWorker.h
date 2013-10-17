#ifndef SBFWORKER_H
#define SBFWORKER_H

#include <functional>
#include "sbfDeclspec.h"

enum class WorkerPolitics : short {

};

class DECLSPEC sbfWorkerAttributes
{
public:
    sbfWorkerAttributes();
    virtual ~sbfWorkerAttributes();
protected:
    std::function<void (sbfWorkerAttributes *)> workFunction_;
    ThreadType * thread_;
    EventType * start_;
    EventType * stop_;
    int ID_;
public:
    EventType * start() { return start_; }
    EventType * stop() { return stop_; }
    std::function<void (sbfWorkerAttributes *)> workFunction() const;
    void setWorkFunction(const std::function<void (sbfWorkerAttributes *)> &workFunction);
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
