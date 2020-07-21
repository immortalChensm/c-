#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 
#include <atomic>
#include <list>

//创建多个线程|共享数据
using namespace std;

class A
{
public:
	std::atomic<int> atm;
	A()
	{
		atm = 0;
		//auto atm1 = atm; 尝试引用已删除的函数 不可以  使用它的拷贝构造
		//atomice<int> atm2 = atm;
		std::atomic<int> atm3(atm.load());//初始
		atm3.store(19);

	}
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000; i++)
		{


			{

				std::lock_guard<std::mutex> lock1(_mutex1);
				cout << "inMsgRecQueue-insert: " << i << endl;
				msgRecQueue.push_back(i);

				//_condition.notify_one();//尝试把wait线程唤醒 该线程的锁将被释放掉 只通知一个
				//虽然执行了唤醒操作，但wait线程没有抢到锁的话，可能是当前线程抢到锁，结果插入多条数据
				//而wait线程抢到的锁次数少，处理的数据就少了
				_condition.notify_all();//通知所有线程，但是，哪个线程抢到锁就哪个运行
			}


		}
	}

	bool outMsgRecQueueProc(int& cmd)
	{
		std::lock_guard<std::mutex> lock(_mutex1);

		if (!msgRecQueue.empty())
		{
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();

			return true;
		}

		return false;
	}
	void outMsgRecQueue()
	{
		int cmd = 0;
		while (true)
		{


			std::unique_lock<std::mutex> lock(_mutex1);
			//wait 用来等待一个东西
			//wait 第二个参数lambda函数运行返回false 时，wait将解锁互斥量_mutex1，并堵塞到本行
			//堵塞到其它线程调用notify_one()成员函数为止 没有第二个参数，默认就是false
			_condition.wait(lock, [this] {
				if (!msgRecQueue.empty())
					return true;
				return false;
				});


			//1、wait返回true时，尝试获取锁，不断的获取，获取不到就卡住
			//2、获取到锁之后，也是判断wait的返回值，返回false还是卡，true时继续往下执行
			//被唤醒之后【可能自己抢到锁的次数少，造成msgRecQueue队列有大量的数据】
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();

			cout << "outMsgRecQueueProc:" << cmd << "threadid=" << std::this_thread::get_id() << endl;

			lock.unlock();//提前解锁



		}
		
	}
private:
	list<int> msgRecQueue;
	std::mutex _mutex1;
	std::mutex _mutex2;
	std::condition_variable _condition;//条件变量对象
};

int main()
{

	//1、虚假唤醒  
	//wait 返回false时会阻塞当前线程，当前线程不在执行代码
	//notify_one 会激活wait线程，如果wait线程抢到锁，就会运行
	//notify_all 激活所有wait 线程

	//多线程操作同一块共享内存时，加上锁之后，有时候可以加上条件变量，判断共享内存中是否有数据再操作
	A msgObj;

	std::thread outMsgObj(&A::outMsgRecQueue, &msgObj);
	
	std::thread inMsgObj(&A::inMsgRecQueue, &msgObj);


	inMsgObj.join();
	outMsgObj.join();
	


	cout << "main end" << endl;
	return 0;
}