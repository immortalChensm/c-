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
			
			{
				
				std::lock_guard<std::mutex> lock1(_mutex1);
			
				msgRecQueue.push_back(i);
			
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
			//堵塞到其它线程调用notify_one()成员函数为止
			_condition.wait(lock, [this] {
				if (!msgRecQueue.empty())
					return true;
				return false;
			});
		}
		/*for (int i = 0; i < 100000; i++)
		{
			if (outMsgRecQueueProc(cmd))
			{
				cout << "outMsgRecQueueProc:" << cmd << endl;

			}
			else {
				cout << "outMsgRecQueue-empty: " << i << endl;
			}
		}
		cout << "outMsg end" << endl;*/
	}
private:
	list<int> msgRecQueue;
	std::mutex _mutex1;
	std::mutex _mutex2;
	std::condition_variable _condition;//条件变量对象
};

int main()
{

	//1、std::condition_variable wait,notify_one
	//A、线程等待条件满足

	A msgObj;

	std::thread outMsgObj(&A::outMsgRecQueue, &msgObj);
	std::thread inMsgObj(&A::inMsgRecQueue, &msgObj);


	inMsgObj.join();
	outMsgObj.join();

	/*[] {
		cout << "b" << endl;
	}();*/


	cout << "main end" << endl;
	return 0;
}