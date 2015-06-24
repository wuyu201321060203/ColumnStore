#ifndef LOCK_H_
#define LOCK_H_

#include <stdint.h>
using namespace std;

class Lock{
	public:
		Lock();
		virtual ~Lock();
		void lock();
		void unlock();
	private:
		Mutex m_lock;
};

#endif
