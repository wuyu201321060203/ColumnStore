#ifndef RW_mutexH
#define RW_mutexH

#include <muduo/base/CurrentThread.h>
#include <muduo/base/Logging.h>
#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>
#include <errno.h>

#include <CS/Config.h>

#ifdef CHECK_PTHREAD_RETURN_VALUE

#ifdef NDEBUG
__BEGIN_DECLS
extern void __assert_perror_fail (int errnum,
                                  const char *file,
                                  unsigned int line,
                                  const char *function)
    __THROW __attribute__ ((__noreturn__));
__END_DECLS
#endif

#define MCHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
                       if (__builtin_expect(errnum != 0, 0))    \
                         __assert_perror_fail (errnum, __FILE__, __LINE__, __func__);})

#else

#define MCHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
                       assert(errnum == 0); (void) errnum;})

#endif

class RWMutexLock
{
public:

    RWMutexLock():holder_(0)
    {
        MCHECK(pthread_rwlock_init(&_mutex, NULL));
    }

    ~RWMutexLock()
    {
        assert(holder_ == 0);
        MCHECK(pthread_rwlock_destroy(&_mutex));
    }

    bool isLockedByThisThread() const
    {
        return holder_ == muduo::CurrentThread::tid();//TODO
    }

    void assertLocked() const
    {
        assert(isLockedByThisThread());
    }

    void rdLock()
    {
        MCHECK(pthread_rwlock_rdlock(&_mutex));
        assignHolder();
    }

    bool tryRdLock()
    {
        int rc = pthread_rwlock_tryrdlock(&_mutex);
        if (rc == 0)
        {
            assignHolder();
            return true;
        }

        else if (rc == EBUSY)
            return false;

        else
            LOG_INFO << "try read lock failed";

        return false;
    }

    void wrLock()
    {
        MCHECK(pthread_rwlock_wrlock(&_mutex));
        assignHolder();
    }

    bool tryWrLock()
    {
        int rc = pthread_rwlock_trywrlock(&_mutex);
        if (rc == 0)
        {
            assignHolder();
            return true;
        }

        else if (rc == EBUSY)
            return false;

        else
            LOG_INFO << "try write lock failed";

        return false;
    }

    void unlock()
    {
        unassignHolder();
        MCHECK(pthread_rwlock_unlock(&_mutex));
    }

    pthread_rwlock_t* getPthreadMutex() /* non-const */
    {
        return &_mutex;
    }

private:

    void unassignHolder()
    {
        holder_ = 0;
    }

    void assignHolder()
    {
        holder_ = muduo::CurrentThread::tid();
    }

    pthread_rwlock_t _mutex;
    pid_t holder_;
};

class RWMutexLockGuard : boost::noncopyable
{
public:

    explicit RWMutexLockGuard(RWMutexLock& mutex , Choice options)
        : _mutex(mutex)
    {
        if(options == Choice::choiceRead)
            _mutex.rdLock();
        else
            _mutex.wrLock();
    }

    ~RWMutexLockGuard()
    {
        _mutex.unlock();
    }

private:

    RWMutexLock& _mutex;
};

#define RWMutexLockGuard(x) error "Missing guard object name"

#endif
