#ifndef SBFREPORTER_H
#define SBFREPORTER_H

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <utility>
#include <list>
#include "sbfTimer.h"
#include "sbfDeclspec.h" //for critical section

class sbfReporter
{
public:
    sbfReporter();
    sbfReporter(std::streambuf * out, std::streambuf * err);
    ~sbfReporter();
private:
    std::ostream * out_;
    std::ostream * err_;
    char delemeter_;
    std::string progressBarTitle_;
    int progressBarWidth_;
    char progressBarFill_;
    char progressBarEmpty_;
    bool flagAllowOtput_;
    bool isOnProgress_;
    bool flagTrackExeTime_;
    sbfTimer<> timer_;
    bool flagExclusiveOut_;
    CritSecType * lockOut_;
    std::list<std::string> errors_;
public:
    bool allowOtput() const;
    void setAllowOtput(bool allowOtput);
    int progressBarWidth() const;
    void setProgressBarWidth(int progressBarWidth);
    void createNewProgress(std::string title, int percantage = 0);
private:
    std::string progressLine(int progress);
public:
    void updateProgress(int percantage);
    void updateProgress(int min, int max, int cur);
    void finalizeProgress();

private:
    template <class T>
    void makeOutput(const T & obj, std::ostream * stream);
    template<typename T = void>
    void unpack(std::stringstream & sstr);
    template<typename T, typename ...Ts>
    void unpack(std::stringstream & sstr, T && t, Ts && ... ts);
public:
//    template <class T>
//    sbfReporter & operator<<(T obj);
    template <class First, class... Rest>
    void operator()(First && first, Rest&&... rest);
    template <class First, class... Rest>
    void error(First && first, Rest&&... rest);
};


template <class T>
void sbfReporter::makeOutput(const T & obj, std::ostream * stream)
{
    if ( flagAllowOtput_ ) {
        if (flagExclusiveOut_) critSecBegin(lockOut_);
        *stream << obj;
        if (flagExclusiveOut_) critSecEnd(lockOut_);
    }
}
//template <class T>
//sbfReporter &sbfReporter::operator<<(T obj)
//{
//    makeOutput(obj, out_);
//    return *this;
//}

template<typename T>
void sbfReporter::unpack(std::stringstream & sstr) { sstr << std::endl; return; }
template<typename T, typename ...Ts>
void sbfReporter::unpack(std::stringstream & sstr, T && t, Ts && ... ts) {
    sstr << std::forward<T>(t);
    unpack(sstr, std::forward<Ts>(ts)...);
    return;
}

template <class First, class... Rest>
void sbfReporter::operator()(First && first, Rest&&... rest)
{
    std::stringstream sstr;
    sstr << std::forward<First>(first);
    unpack(sstr, std::forward<Rest>(rest)...);
    makeOutput(sstr.str().c_str(), out_);
}
template <class First, class... Rest>
void sbfReporter::error(First && first, Rest&&... rest)
{
    std::stringstream sstr;
    sstr << std::forward<First>(first);
    unpack(sstr, std::forward<Rest>(rest)...);
    makeOutput(sstr.str(), err_);
    errors_.push_back(sstr.str());
}

static sbfReporter report;

//Debugging messages
#ifdef DEBUG
 #define debugMsg(msg) \
 report << "debugMsg:	" << msg;
#else
 #define debugMsg(msg)
#endif//DEBUG

#endif // SBFREPORTER_H
