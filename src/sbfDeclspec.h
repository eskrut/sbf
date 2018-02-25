#ifndef SBFDECLSPEC_H
#define SBFDECLSPEC_H

//Deal with shared libraries in various systems and compillers
#ifdef _MSC_VER
 #define NOMINMAX//exclude max() and min() functions
 #ifndef THREAD_MODEL_POSIX
  #define THREAD_MODEL_WIN32//Use win32 threads unless otherwise specified
 #endif
 #ifdef SBF_DLL_EXPORTS
  #define DECLSPEC __declspec(dllexport)
 #else
  #define DECLSPEC __declspec(dllimport)
 #endif
#else /* _MSC_VER not defined */
 #ifndef THREAD_MODEL_WIN32
  #define THREAD_MODEL_POSIX//Use POSIX threads unless otherwise specified
 #endif
 #define DECLSPEC
#endif

//Using of OpenMP
#ifdef USE_OMP
 #define OMP_NUM_THS 8
 #include <omp.h>
#endif //USE_OMP


#ifndef SBF_NUM_THREADS
const int sbfNumThreads = 8;
#else
const int sbfNumThreads = SBF_NUM_THREADS;
#endif

#if defined(THREAD_MODEL_WIN32)
 #include <windows.h>
 typedef HANDLE ThreadType;
 typedef HANDLE EventType;
 typedef void* MutexType;
 typedef EventType event_t;
 static inline void event_init(event_t* event)
 {
     *event = CreateEvent(nullptr, true, false, nullptr);
 }
 static inline void event_destroy(event_t* event)
 {
     CloseHandle(*event);
 }
 static inline void event_set(event_t* event)
 {
     SetEvent(*event);
 }
 static inline void event_wait(event_t* event)
 {
     //Wait and reset event
     WaitForSingleObject(*event, INFINITE);
     ResetEvent(*event);
 }
 static inline void createNewThread(ThreadType * thread, void (*threadFunction)(void *), void *threadData)
 {
     //MSVC version of creation new work thread, uses WIN API function
     *thread = CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(threadFunction), threadData, 0, 0);
 }
 static inline void waitThreadDone(ThreadType &thread)
 {
     WaitForSingleObject(thread,  INFINITE);
     CloseHandle(thread);
 }
 static inline void cancelThread(ThreadType &thread)
 {
     TerminateThread(thread, 0);
 }
#elif defined(THREAD_MODEL_STD)
#include <thread>
#include <mutex>
#include <condition_variable>
typedef struct {
    std::mutex lock;
    std::condition_variable event;
    bool state;
    bool autoResetFlag;
} event_t;
typedef std::thread ThreadType;
typedef event_t EventType;
typedef std::recursive_mutex CritSecType;

static inline void event_init(event_t* event, bool initState = false, bool autoReset = true)
{
    event->state = initState;
    event->autoResetFlag = autoReset;
}
static inline void event_destroy(event_t* )
{
}
static inline void event_set(event_t* event)
{
    std::unique_lock<std::mutex> lck(event->lock);
    if( event->state == false ) {
        event->state = true;
        event->event.notify_one();
    }
}
static inline void event_reset(event_t* event)
{
    std::unique_lock<std::mutex> lck(event->lock);
    if( event->state == true )
        event->state = false;
}
static inline void event_wait(event_t* event, bool autoReset = true)
{
    std::unique_lock<std::mutex> lck(event->lock);
    while( event->state == false)
        event->event.wait(lck);
    if(autoReset)
        event->state=false;
}
static inline void multiplyEvent_wait(event_t* eventArray, int numEvents, bool autoReset = true)
{
    for(int ct = 0; ct < numEvents; ct++)
        event_wait(&(eventArray[ct]), autoReset);
}

static inline void createNewThread(ThreadType * thread, void (*threadFunction)(void *), void *threadData)
{
    *thread = std::thread(threadFunction, threadData);
}
static inline void waitThreadDone(ThreadType &thread)
{
    thread.join();
}
static inline void cancelThread(ThreadType &)
{
    //std::thread do not provide such option
}

static inline void critSecInit(CritSecType *) { /*Do nothing*/ }
static inline void critSecBegin(CritSecType * critSec) { critSec->lock(); }
static inline void critSecEnd(CritSecType * critSec) { critSec->unlock(); }
static inline void critSecDestroy(CritSecType *) { /*Do nothing*/ }

#else// THREAD_MODEL_POSIX
 #include <pthread.h>
 //#include <signal.h>
 typedef struct {
     pthread_mutex_t lock;
     pthread_cond_t event;
     bool flag;
     bool autoResetFlag;
 }event_t;
 typedef pthread_t ThreadType;
 typedef event_t EventType;
 typedef pthread_mutex_t CritSecType;

 static inline void event_init(event_t* event, bool initState = false, bool autoReset = true)
 {
     pthread_mutex_init(&event->lock,0);
     pthread_cond_init(&event->event,0);
     event->flag=initState;
     event->autoResetFlag = autoReset;
 }
 static inline void event_destroy(event_t* event)
 {
     pthread_mutex_destroy(&event->lock);
     pthread_cond_destroy(&event->event);
 }
 static inline void event_set(event_t* event)
 {
     pthread_mutex_lock(&event->lock);
     if (event->flag == false) {
         event->flag=true;
         pthread_cond_signal(&event->event);
     }
     pthread_mutex_unlock(&event->lock);
 }
 static inline void event_reset(event_t* event)
 {
     pthread_mutex_lock(&event->lock);
     if (event->flag == true) {
         event->flag=false;
     }
     pthread_mutex_unlock(&event->lock);
 }
 static inline void event_wait(event_t* event, bool autoReset = true)
 {
     pthread_mutex_lock(&event->lock);
     while( event->flag == false) {
         pthread_cond_wait(&event->event,&event->lock);
     }
     if(autoReset)
         event->flag=false;
     pthread_mutex_unlock(&event->lock);
     pthread_testcancel();//Placed here to correct thread cancellation, may should be placed at another place due to program effectiveness
 }
 static inline void multiplyEvent_wait(event_t* eventArray, int numEvents, bool autoReset = true)
 {
     //Wait and reset multiply events
     for(int ct = 0; ct < numEvents; ct++)
         event_wait(&(eventArray[ct]), autoReset);
 }
 static inline void createNewThread(ThreadType * thread, void (*threadFunction)(void *), void *threadData)
 {
     //gcc version of creation new work thread, uses pthred function
     pthread_create(thread, 0, reinterpret_cast<void *(*)(void *)>(threadFunction), threadData);
 }
 static inline void waitThreadDone(ThreadType &thread)
 {
     pthread_join(thread, 0);
 }
 static inline void cancelThread(ThreadType &thread)
 {
     pthread_cancel(thread);
 }
 static inline void critSecInit(CritSecType * critSec)
 {
     pthread_mutexattr_t mAttr;
     pthread_mutexattr_init(&mAttr);
     pthread_mutexattr_settype(&mAttr, PTHREAD_MUTEX_RECURSIVE);
     pthread_mutex_init(critSec, &mAttr);
     pthread_mutexattr_destroy(&mAttr);
 }
 static inline void critSecBegin(CritSecType * critSec) { pthread_mutex_lock(critSec); }
 static inline void critSecEnd(CritSecType * critSec) { pthread_mutex_unlock(critSec); }
 static inline void critSecDestroy(CritSecType * critSec) { pthread_mutex_destroy(critSec); }
#endif//THREAD_MODEL_POSIX or THREAD_MODEL_WIN32

#ifdef USE_UNROLLED_FUNCTIONS
 #define USE_MATMUL_UNROLL//Allows usage of unrolled functions in matrix multiplication
#endif

#include <type_traits>
 template<typename T, typename _ = void>
 struct is_container : std::false_type {};

 template<typename... Ts>
 struct is_container_helper {};

 template<typename T>
 struct is_container<
         T,
         std::conditional<
         false,
         is_container_helper<
         typename std::enable_if<
         ! std::is_same<typename T::value_type, char>::value, void>::type,
         typename std::enable_if<
         std::is_arithmetic<typename T::value_type>::value, void>::type,
         typename T::value_type,
         typename T::size_type,
         typename T::allocator_type,
         typename T::iterator,
         typename T::const_iterator,
         decltype(std::declval<T>().size()),
 decltype(std::declval<T>().begin()),
 decltype(std::declval<T>().end()),
 decltype(std::declval<T>().cbegin()),
 decltype(std::declval<T>().cend())
 >,
 void
 >
 > : public std::true_type {};

#endif // SBFDECLSPEC_H
