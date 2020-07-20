#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 

#include <list>
#include <windows.h>

//windows �ٽ�����c++������һ����||RAII �� �Զ���������|
/**
1�����߳�
	1�����̶���̡߳�ֻ��һ���ջ����������̶߳�Ҫ������Щ�ڴ����������ڴ��е����ݡ���������������
������
std::mutex
std::recursive_mutex �����Զ�ε�������
std::timed_mutex �����Ե���try_lock_for,try_lock_unitl������һ��ʱ������������Ͳ����������ݣ������߳����������飬����һֱ��ס��
std::timed_recursive_mutex һ��

std::lock_guard<std::mutex> t
std::unique_guard<std::mutex> std::try_lock std::adopt_lock std::defer_lock 

windows �ٽ���

**/
using namespace std;
//#define _WINDOWSJQ_

#ifdef _WINDOWSJQ_ 
CRITICAL_SECTION my_sec;
#endif 

//RAII ��  Resurce Acquisition is initialization ��Դ��ȡ����ʼ��
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
			
			//EnterCriticalSection(&my_sec);//��������ν����ٽ���
			//EnterCriticalSection(&my_sec);
			CWinLock w(&my_sec);
			cout << "inMsgRecQueue-insert: " << i << endl;
			msgRecQueue.push_back(i);
			//LeaveCriticalSection(&my_sec);
			//LeaveCriticalSection(&my_sec);
#else 
			//_mutex.lock();
			//func1();//��ε���lock
			//_mutex1.lock();//������

			std::chrono::milliseconds time(100);
			//if (_mutex.try_lock_for(time)) {//�ȴ�100ms�õ���ʱ
			if (_mutex._Try_lock_until(chrono::steady_clock::now()+time)) {//�ȴ�100ms�õ���ʱ ������һ��
				cout << "inMsgRecQueue-insert: " << i << endl;
				msgRecQueue.push_back(i);
				_mutex.unlock();
			}
			else {
			
				//û��������
				std::chrono::microseconds t(100);
				std::this_thread::sleep_for(t);
				cout << "û��������������Ϣ��" << endl;
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
		//func2();//��2����
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
	std::mutex _mutex2;//��ռ������
	//std::recursive_mutex _mutex;//�ݹ��ռ������
	//std::timed_mutex _mutex;//��ʱ������
	std::recursive_timed_mutex _mutex;//�ݹ鳬ʱ������
	std::condition_variable _condition;//������������
};



int main()
{
	//windows�ٽ���
	//1����ν����ٽ��������ö��ٴΡ����������⿪��ʱ��Ҳ��ͬ���Ĵ���
	//2��recursive_mutex �ݹ��ռ������
	//std::mutex ��ռʽ��������ֻ��һ�߳�ӵ�����������̲߳�Ҫ��
	//recurive_mutex �ݹ��ռʽ������  ������ͬһ���߳��ж��.lock
	//3������ʱ��std::timed_mutex �� std::recursive_timed_mutex
	
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