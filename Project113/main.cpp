#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;
/**
std::mutex   [lock,unlock] std::unique_lock<mutex>  lock(mutext,std::adopt|std::try_to_lock|std::defer_lock)
						   lock,unlock
						   std::lock(mutx1,mtxt2) 时可以用adopt_lock
						   std::try_to_lock 时可以用  lock.owns_lock()=true 判断是否锁了
						   std::defer_lock 时可以调用lock.lock()  lock.unlock() 或是try_lock()==true判断
std::recursive_mutex 递归锁  可以锁多次
std::timed_mutex 可以调用  try_lock_for  try_lock_until 判断是否在一定的时间内锁了

recursive_mutex ,timed_mutex 锁性能不好
***/
class A {
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			cout << "inMsgRecvQueue:threadId=" << std::this_thread::get_id() << "执行，插入数据" << i << endl;

			
			//std::unique_lock<std::recursive_mutex> lock2(_mutext);
			//std::unique_lock<std::mutex> lock(_mutext);  can't   
			//func1();
			
			std::chrono::milliseconds dura(1000);
			//if (_mutext.try_lock_for(dura)) {  //等待1000ms，得到锁时
			if (_mutext.try_lock_until(chrono::steady_clock::now()+dura)) {  //等待1000ms，得到锁时
				msgRecvQueue.push_back(i);
				_mutext.unlock();//解锁
			}
			else {

				cout << "没有拿到锁，不操作共享数据" << endl;
			}
			
			
		}
	}

	//void func1()
	//{
	//	std::unique_lock<std::recursive_mutex> lock(_mutext);
	//	//
	//	cout << "to do something1..." << endl;
	//	func2();
	//}
	//void func2()
	//{
	//	std::unique_lock<std::recursive_mutex> lock(_mutext);
	//	//
	//	cout << "to do something2..." << endl;
	//}
	bool outMsgProc(int& command)
	{
		
		std::unique_lock<std::recursive_timed_mutex> lock(_mutext);

		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);

		if (!msgRecvQueue.empty())
		{
			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			
			return true;
		}
		
		return false;
	}
	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgProc(command);
			if (result == true)
			{
				cout << "outMsgRecvQueue 线程取出数据为：" << command << endl;
			}
			else {

				cout << "outMsgRecvQueue:threadId=" << std::this_thread::get_id() << "执行，队列为空" << i << endl;
			}
		}
	}
private:
	std::list<int> msgRecvQueue;
	//std::mutex _mutext;//独占互斥量
	//std::recursive_mutex _mutext;//递归式互斥量
	//std::timed_mutex _mutext;//带超时互斥量锁
	std::recursive_timed_mutex _mutext;//带超时互斥量锁
	std::mutex _mutext2;
};
int main()
{




	A obj;
	std::thread outMsgObj(&A::outMsgRecvQueue, &obj);//传递引用，保证2个线程共用同一个对象，否则它拷贝变成独立线程的对象了
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();
	inMsgObj.join();


	cout << "i like money" << endl;

	return 0;
}