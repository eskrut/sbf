#include "sbfReporter.h"


sbfReporter::sbfReporter() :
    sbfReporter(std::cout.rdbuf(), std::cerr.rdbuf())
{
}

sbfReporter::sbfReporter(std::streambuf *out, std::streambuf *err) :
    out_(new std::ostream(out)),
    err_(new std::ostream(err)),
    outMirror_(nullptr),
    delemeter_('\t'),
    placeDelimeterAtOutput_(true),
    progressBarTitle_(),
    progressBarWidth_(40),
    progressBarFill_('*'),
    progressBarEmpty_('_'),
    flagAllowOtput_(true),
    isOnProgress_(false),
    flagTrackExeTime_(true),
    minUpdateInterwalS_(0.1),
    flagExclusiveOut_(false),
    lockOut_(new CritSecType)
{
    critSecInit(lockOut_);
}

sbfReporter::~sbfReporter()
{
    critSecDestroy(lockOut_);
    delete lockOut_;
}

bool sbfReporter::placeDelimeterAtOutput() const
{
    return placeDelimeterAtOutput_;
}

void sbfReporter::setPlaceDelimeterAtOutput(bool placeDelimeterAtOutput)
{
    placeDelimeterAtOutput_ = placeDelimeterAtOutput;
}

char sbfReporter::delemeter() const
{
    return delemeter_;
}

void sbfReporter::setDelemeter(char delemeter)
{
    delemeter_ = delemeter;
}

void sbfReporter::setMirrorOutput(const std::string &fileName)
{
    unsetMirrorOutput();
    outMirror_ = new std::ofstream;
    outMirror_->open(fileName);
    if( !*outMirror_ ) {
        delete outMirror_;
        outMirror_ = nullptr;
        makeOutput("Cant make output mirroring to " + fileName, err_);
    }
}

void sbfReporter::unsetMirrorOutput()
{
    if( outMirror_ ) {
        delete outMirror_;
    }
    outMirror_ = nullptr;
}

bool sbfReporter::allowOtput() const
{
    return flagAllowOtput_;
}

void sbfReporter::setAllowOtput(bool allowOtput)
{
    flagAllowOtput_ = allowOtput;
}
int sbfReporter::progressBarWidth() const
{
    return progressBarWidth_;
}

void sbfReporter::setProgressBarWidth(int progressBarWidth)
{
    progressBarWidth_ = progressBarWidth;
}

void sbfReporter::createNewProgress(std::string title, int percantage)
{
    isOnProgress_ = true;
    progressBarTitle_ = std::move(title);
    if ( flagTrackExeTime_ )
        timer_.start();
    lastFlushSpanS_ = - minUpdateInterwalS_;
    if(flagAllowOtput_){
        *out_ << std::endl << progressBarTitle_ << std::endl;
        *out_ << progressLine(percantage);
        out_->flush();
    }
}

std::string sbfReporter::progressLine(int progress, const std::string &msg)
{
    if ( progress < 0 ) progress = 0;
    if ( progress > 100 ) progress = 100;
    std::stringstream line;
    line << "[";
    const int numAvail = (progressBarWidth_ - 2 - 1 - 3 - 1);
    const int numDone = numAvail * progress / 100;
    const int numUnDone = numAvail - numDone;
    for (int ct = 0; ct < numDone; ct++) line << progressBarFill_;
    for (int ct = 0; ct < numUnDone; ct++) line << progressBarEmpty_;
    line << "] ";
    line.width(3);
    line << progress << "% " << timer_.timeSpanStr();
    //TODO add exec time output if required
    line << msg << " ";
    return line.str();
}

void sbfReporter::updateProgress(int percantage, const std::string &msg)
{
    if ( isOnProgress_ ) {
        if(flagTrackExeTime_ && (timer_.getSeconds() - lastFlushSpanS_) >= minUpdateInterwalS_){
            lastFlushSpanS_ = timer_.getSeconds();
            if(flagAllowOtput_){
                *out_ << "\r" << progressLine(percantage, msg);
                out_->flush();
            }
        }
    }
}

void sbfReporter::updateProgress(int min, int max, int cur, const std::string &msg)
{
    const int percantage = (cur - min) * 100 / (max - min);
    updateProgress(percantage, msg);
}

void sbfReporter::updateProgress(double fractionOfOne, const std::string &msg)
{
    updateProgress(static_cast<int>(fractionOfOne * 100), msg);
}

void sbfReporter::finalizeProgress(const std::string &msg)
{
    if ( isOnProgress_ ) {
        //        if ( flagTrackExeTime_ )
        //            timer_.getCount();
        if(flagAllowOtput_){
            *out_ << "\r" << progressLine(100) << std::endl;
            *out_ << progressBarTitle_ << " DONE";
        }
        if ( flagTrackExeTime_ ) {
            timer_.stop();
            if(flagAllowOtput_)
                *out_ << " in " << timer_.getSeconds() << " seconds";
        }
        if(flagAllowOtput_){
            if(msg.size())
                *out_ << " " << msg;
            *out_ << std::endl;
            out_->flush();
        }
        isOnProgress_ = false;
    }
}
