#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 

#include <list>

//创建多个线程|共享数据
using namespace std;

class A
{
public:
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000; i++)
		{
			cout << "inMsgRecQueue-insert: " << i << endl;
			//_mutex.lock();
			{
				//std::lock_guard<std::mutex> lock(_mutex);
				//std::lock_guard<std::mutex> lock1(_mutex1);
				//std::lock_guard<std::mutex> lock2(_mutex2);
				std::lock(_mutex1,_mutex2);
				std::lock_guard<std::mutex> lock1(_mutex1, std::adopt_lock);
				std::lock_guard<std::mutex> lock2(_mutex2, std::adopt_lock);
				//_mutex1.lock();
				//_mutex2.lock();
				msgRecQueue.push_back(i);
				//_mutex2.unlock();
				//_mutex1.unlock();
			}
			
			//_mutex.unlock();
		}
	}

	bool outMsgRecQueueProc(int &cmd)
	{
		//std::lock_guard<std::mutex> lock(_mutex1);
		//std::lock_guard<std::mutex> lock1(_mutex1);
		//std::lock_guard<std::mutex> lock2(_mutex2);
		//_mutex2.lock();
		//_mutex1.lock();
		//_mutex.lock();
		std::lock(_mutex1,_mutex2);
		if (!msgRecQueue.empty())
		{
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();
			//_mutex.unlock();
			_mutex1.unlock();
			_mutex2.unlock();
			return true;
		}
		//_mutex.unlock();
		_mutex1.unlock();
		_mutex2.unlock();
		return false;
	}
	void outMsgRecQueue()
	{
		int cmd = 0;
		for (int i = 0; i < 100000; i++)
		{
			if (outMsgRecQueueProc(cmd))
			{
				cout << "outMsgRecQueueProc:"<<cmd << endl;

			}
			else {
				cout << "outMsgRecQueue-empty: " << i << endl;
			}
		}
		cout << "outMsg end" << endl;
	}
private:
	list<int> msgRecQueue;
	std::mutex _mutex1;
	std::mutex _mutex2;
};

int main()
{
	
	A msgObj;

	std::thread outMsgObj(&A::outMsgRecQueue, &msgObj);
	std::thread inMsgObj(&A::inMsgRecQueue, &msgObj);

	
	inMsgObj.join();
	outMsgObj.join();

	//1、保护共享数据  线程操作时把共享数据锁住，操作完，解锁，方便其它线程操作
	//2、死锁【存在2个互斥锁时】产生原因：双方互相锁
	//3、死锁的解决
	//4、std::lock 它一次能锁住多个【最少2个以上】，不存在因为锁的顺序问题导致死锁 锁的规则类似sql事务【多个锁要么成功，
	//只锁住一个，另一个没有锁，就会解锁掉前面锁好的

	//5、std::lock()和std::lock_gurad<> (mutex,std::adopt_lock)
	//std::adpot_lock 表示std::lock(_mutex1,_mutex2) 中的变量已经lock过了，不需要std::lock_guard<std::mutex> lock(_mutex1)
	//在构造函数里使用_mutex1.lock了
	cout << "main end" << endl;
	return 0;
}