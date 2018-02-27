#ifndef SBFREPORTER_H
#define SBFREPORTER_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>
#include <utility>
#include <list>
#include "sbfTimer.h"
#include "sbfDeclspec.h" //for critical section and is_container

class sbfReporter
{
public:
    sbfReporter();
    sbfReporter(std::streambuf * out, std::streambuf * err);
    ~sbfReporter();
private:
    std::ostream * out_;
    std::ostream * err_;
    std::ofstream * outMirror_;
    char delemeter_;
    bool placeDelimeterAtOutput_;
    std::string progressBarTitle_;
    int progressBarWidth_;
    char progressBarFill_;
    char progressBarEmpty_;
    bool flagAllowOtput_;
    bool isOnProgress_;
    bool flagTrackExeTime_;
    sbfTimer<> timer_;
    double lastProgressDuration_;
    bool flagExclusiveOut_;
    CritSecType * lockOut_;
    std::list<std::string> errors_;
public:
    bool allowOtput() const;
    void setAllowOtput(bool allowOtput);
    int progressBarWidth() const;
    void setProgressBarWidth(int progressBarWidth);
    //TODO meke nested progresses
    void createNewProgress(std::string title, int percantage = 0);
private:
    std::string progressLine(int progress, const std::string &msg = std::string());
public:
    void updateProgress(int percantage, const std::string &msg = std::string());
    void updateProgress(int min, int max, int cur, const std::string &msg = std::string());
    void updateProgress(double fractionOfOne, const std::string &msg = std::string());
    void finalizeProgress(const std::string &msg = std::string());

private:
    template <class T>
    void makeOutput(const T & obj, std::ostream * stream);
    void unpack(std::stringstream & sstr) { sstr << std::endl; return; }
    template<class T, class... Ts>
    typename std::enable_if<! is_iterable_for_reporter<T>::value, void>::type
    /*void*/ unpack(std::stringstream & sstr, T t, Ts... ts);
    template<class T, class... Ts>
    typename std::enable_if<is_iterable_for_reporter<T>::value, void>::type
    /*void*/ unpack(std::stringstream & sstr, T t, Ts... ts);
public:
//    template <class T>
//    sbfReporter & operator<<(T obj);

    template <class First, class... Rest>
    typename std::enable_if<is_iterable_for_reporter<First>::value, void>::type
     operator()(First first, Rest... rest);

    template <class First, class... Rest>
    typename std::enable_if<! is_iterable_for_reporter<First>::value, void>::type
     operator()(First first, Rest... rest);

    template <class First, class... Rest>
    void error(First first, Rest... rest);

    template <class First, class... Rest>
    void raiseError(First first, Rest... rest);

    bool placeDelimeterAtOutput() const;
    void setPlaceDelimeterAtOutput(bool placeDelimeterAtOutput);
    char delemeter() const;
    void setDelemeter(char delemeter);
    double lastProgressDuration() const { return lastProgressDuration_; }
    void setMirrorOutput(const std::string &fileName);
    void unsetMirrorOutput();
};


template <class T>
void sbfReporter::makeOutput(const T & obj, std::ostream * stream)
{
    if ( flagAllowOtput_ ) {
        if (flagExclusiveOut_) critSecBegin(lockOut_);
        *stream << obj;
        stream->flush();
        if(outMirror_) {
            *outMirror_ << obj;
            outMirror_->flush();
        }
        if (flagExclusiveOut_) critSecEnd(lockOut_);
    }
}

template<class T, class... Ts>
typename std::enable_if<! is_iterable_for_reporter<T>::value, void>::type
/*void*/ sbfReporter::unpack(std::stringstream & sstr, T t, Ts... ts) {
    if(placeDelimeterAtOutput_) sstr << delemeter_;
    sstr << std::forward<T>(t);
    unpack(sstr, ts...);
    return;
}

template<class T, class... Ts>
typename std::enable_if<is_iterable_for_reporter<T>::value, void>::type
/*void*/ sbfReporter::unpack(std::stringstream & sstr, T t, Ts... ts) {
    if(placeDelimeterAtOutput_) sstr << delemeter_;
    for(auto &r : std::forward<T>(t)) {
        sstr << r;
        if(placeDelimeterAtOutput_) sstr << delemeter_;
    }
    unpack(sstr, ts...);
    return;
}

template <class First, class... Rest>
typename std::enable_if<! is_iterable_for_reporter<First>::value, void>::type
 sbfReporter::operator()(First first, Rest... rest)
{
    std::stringstream sstr;
    sstr << std::forward<First>(first);
    unpack(sstr, rest...);
    makeOutput(sstr.str().c_str(), out_);
}

template <class First, class... Rest>
typename std::enable_if<is_iterable_for_reporter<First>::value, void>::type
 sbfReporter::operator()(First first, Rest... rest)
{
    std::stringstream sstr;
    for(auto &r : std::forward<First>(first))
    {
        sstr << r;
        if(placeDelimeterAtOutput_) sstr << delemeter_;
    }
    unpack(sstr, rest...);
    makeOutput(sstr.str().c_str(), out_);
}

template <class First, class... Rest>
void sbfReporter::error(First first, Rest... rest)
{
    std::stringstream sstr;
    sstr << std::forward<First>(first);
    unpack(sstr, rest...);
    makeOutput(sstr.str(), err_);
    errors_.push_back(sstr.str());
}

template <class First, class... Rest>
void sbfReporter::raiseError(First first, Rest... rest)
{
    std::stringstream sstr;
    sstr << std::forward<First>(first);
    unpack(sstr, rest...);
    error(sstr.str());
    throw std::runtime_error(sstr.str());
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
