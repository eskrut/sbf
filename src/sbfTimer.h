#ifndef SBFTIMER_H
#define SBFTIMER_H

#include <chrono>
#include <iomanip>
#include <sstream>

template <class clock_type = std::chrono::high_resolution_clock, class duration_type = typename clock_type::duration> class sbfTimer
{
public:
    sbfTimer();
private:
    std::chrono::time_point<clock_type, duration_type> start_;
    std::chrono::time_point<clock_type, duration_type> stop_;
    bool isRunning_;
public:
    void start();
    void stop();
    template <class target_duration = std::chrono::seconds>
    int getCount();
    std::string timeSpanStr();
};

template <class clock_type, class duration_type>
sbfTimer<clock_type, duration_type>::sbfTimer() :
    isRunning_(false)
{
}

template <class clock_type, class duration_type>
void sbfTimer<clock_type, duration_type>::start()
{
    isRunning_ = true;
    start_ = clock_type::now();
}

template <class clock_type, class duration_type>
void sbfTimer<clock_type, duration_type>::stop()
{
    stop_ = clock_type::now();
    isRunning_ = false;
}

template <class clock_type, class duration_type>
template <class target_duration>
int sbfTimer<clock_type, duration_type>::getCount()
{
    if ( isRunning_ )
        return std::chrono::duration_cast<target_duration>(clock_type::now() - start_).count();
    return std::chrono::duration_cast<target_duration>(stop_ - start_).count();
}

template <class clock_type, class duration_type>
std::string sbfTimer<clock_type, duration_type>::timeSpanStr()
{
    using namespace std::chrono;
    std::stringstream sstr;
    duration<double> span;
    if ( isRunning_ )
        span = duration_cast<duration<double>>(clock_type::now() - start_);
    else
        span = duration_cast<duration<double>>(stop_ - start_);
    sstr << std::setw(4) << duration_cast<hours>(span).count() << ":" <<
            std::setw(2) << std::setfill('0') << duration_cast<minutes>(span).count() % 60 << ":" <<
            std::setw(2) << std::setfill('0') << duration_cast<seconds>(span).count() % 60 << "." <<
            std::setw(3) << std::setfill('0') << duration_cast<milliseconds>(span).count() % 1000;
    return sstr.str();
}


#endif // SBFTIMER_H
