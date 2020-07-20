#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 

#include <list>
#include <windows.h>

//windows 临界区【c++互斥量一样】||RAII 类 自动析构技术|
/**
1、多线程
	1个进程多个线程【只有一块堆栈区】，多个线程都要访问这些内存区【共享内存中的数据】，容易引发错乱
互斥量
std::mutex
std::recursive_mutex 【可以多次调用锁】
std::timed_mutex 【可以调用try_lock_for,try_lock_unitl，持续一段时间如果抢到锁就操作共享数据，否则线程做其它事情，不会一直卡住】
std::timed_recursive_mutex 一样

std::lock_guard<std::mutex> t
std::unique_guard<std::mutex> std::try_lock std::adopt_lock std::defer_lock 

windows 临界区

**/
using namespace std;
//#define _WINDOWSJQ_

#ifdef _WINDOWSJQ_ 
CRITICAL_SECTION my_sec;
#endif 

//RAII 类  Resurce Acquisition is initialization 资源获取即初始化
class CWinLock  
{
public:
	CWinLock(CRITICAL_SECTION *tmp)
	{
	
		my_tsec = tmp;
		EnterCriticalSection(my_tsec);
	}
	~CWinLock()
	{
		LeaveCriticalSection(my_tsec);
	}
private:
	CRITICAL_SECTION* my_tsec;
};

class A
{
public:
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000; i++)
		{

#ifdef _WINDOWSJQ_
			
			//EnterCriticalSection(&my_sec);//加锁，多次进入临界区
			//EnterCriticalSection(&my_sec);
			CWinLock w(&my_sec);
			cout << "inMsgRecQueue-insert: " << i << endl;
			msgRecQueue.push_back(i);
			//LeaveCriticalSection(&my_sec);
			//LeaveCriticalSection(&my_sec);
#else 
			//_mutex.lock();
			//func1();//多次调用lock
			//_mutex1.lock();//不可以

			std::chrono::milliseconds time(100);
			//if (_mutex.try_lock_for(time)) {//等待100ms拿到锁时
			if (_mutex._Try_lock_until(chrono::steady_clock::now()+time)) {//等待100ms拿到锁时 和上面一样
				cout << "inMsgRecQueue-insert: " << i << endl;
				msgRecQueue.push_back(i);
				_mutex.unlock();
			}
			else {
			
				//没有抢到锁
				std::chrono::microseconds t(100);
				std::this_thread::sleep_for(t);
				cout << "没有抢到锁，我休息了" << endl;
			}
			
			//_mutex1.unlock();
			//_mutex.unlock();
#endif

		}
	}

	bool outMsgRecQueueProc(int& cmd)
	{
#ifdef _WINDOWSJQ_
		EnterCriticalSection(&my_sec);
		
		if (!msgRecQueue.empty())
		{
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();
			LeaveCriticalSection(&my_sec);
			return true;
		}
		LeaveCriticalSection(&my_sec);
		
		
#else
		_mutex.lock();
		//std::chrono::microseconds t(1000000000);
		//std::this_thread::sleep_for(t);
		if (!msgRecQueue.empty())
		{
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();
			_mutex.unlock();
			return true;
		}
		_mutex.unlock();
		
#endif
		return false;
	}
	void outMsgRecQueue()
	{
		int cmd = 0;
		for (int i = 0; i < 100000; i++)
		{
			if (outMsgRecQueueProc(cmd))
			{
				cout << "outMsgRecQueueProc:" << cmd << endl;

			}
			else {
				cout << "outMsgRecQueue-empty: " << i << endl;
			}
		}
	
		cout << "outMsg end" << endl;
	}

	void func1()
	{
		//std::lock_guard<std::recursive_mutex> lock(_mutex);
		//do something...
		//func2();//锁2次了
	}
	void func2()
	{
		
		//std::lock_guard<std::recursive_mutex> lock(_mutex);
		//do something...
	}
	A()
	{
#ifdef _WINDOWSJQ_ 
		InitializeCriticalSection(&my_sec);
#endif
	}
private:
	list<int> msgRecQueue;
	std::mutex _mutex1;
	std::mutex _mutex2;//独占互斥锁
	//std::recursive_mutex _mutex;//递归独占互斥锁
	//std::timed_mutex _mutex;//超时互斥量
	std::recursive_timed_mutex _mutex;//递归超时互斥量
	std::condition_variable _condition;//条件变量对象
};



int main()
{
	//windows临界区
	//1、多次进入临界区，调用多少次【加锁】，解开的时候也是同样的次数
	//2、recursive_mutex 递归独占互斥量
	//std::mutex 独占式互斥量，只有一线程拥有锁，其它线程不要吧
	//recurive_mutex 递归独占式互斥量  可以在同一个线程中多次.lock
	//3、带超时的std::timed_mutex 和 std::recursive_timed_mutex
	
	A msgObj;
	
	std::thread outMsgObj(&A::outMsgRecQueue, &msgObj);
	//std::thread outMsgObj2(&A::outMsgRecQueue, &msgObj);
	
	std::thread inMsgObj(&A::inMsgRecQueue, &msgObj);

	inMsgObj.join();
	outMsgObj.join();
	//outMsgObj2.join();


	cout << "main end" << endl;
	return 0;
}