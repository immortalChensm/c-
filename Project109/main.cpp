#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

/**
wait(std::mutex obj,func) func返回true 继续往下执行
							func返回false,释放锁，并阻塞在wait
另一个线程调用notify_one/notify_all 时将会唤醒
wait线程，它将会重新获取互斥锁，获取不到就卡，获取到就会执行wait
的第二个参数，返回true往下执行，返回false同样阻塞
没有第二个参数，默认就返回true[只针对notify唤醒时]


**/
using namespace std;

void show(int num)
{
	cout << "threadId=" << std::this_thread::get_id() << ",num=" << num << endl;
}

class A {
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{

			std::unique_lock<std::mutex> lock(_mutext);

			cout << "inMsgRecvQueue:threadId=" << std::this_thread::get_id() << "执行，插入数据" << i << endl;

			msgRecvQueue.push_back(i);
			//_my_cond.notify_one();
			_my_cond.notify_all();
			
		}
	}

	void outMsgRecvQueue()
	{
		int command = 0;
		while (true)
		{
			std::unique_lock<std::mutex> lock(_mutext);

			_my_cond.wait(lock, [this]() {
				
				if (!msgRecvQueue.empty()) {
					return true;
				}
				return false;
			});

			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			cout << "outMsgRecvQueue:threadId=" << std::this_thread::get_id() << "执行，command=" << command << endl;

			lock.unlock();
		}
	}
private:
	std::list<int> msgRecvQueue;
	std::mutex _mutext;
	std::mutex _mutext2;

	std::condition_variable _my_cond;
};
int main()
{

	A obj;
	std::thread outMsgObj(&A::outMsgRecvQueue, &obj);//传递引用，保证2个线程共用同一个对象，否则它拷贝变成独立线程的对象了
	std::thread outMsgObj2(&A::outMsgRecvQueue, &obj);//传递引用，保证2个线程共用同一个对象，否则它拷贝变成独立线程的对象了
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();
	outMsgObj2.join();
	inMsgObj.join();


	cout << "i like money" << endl;

	return 0;
}