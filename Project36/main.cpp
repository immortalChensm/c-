#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 

#include <list>

//共享数据：unique_lock取代lock_guard
//std::lock|std::lock_guard|std::mutex|std::adpot_lock
//std::lock_guard 取代了std::mutex 的lock,unlock方法
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
				//_mutex1.lock();
				//std::unique_lock<std::mutex> lock(_mutex1,std::adopt_lock);
				//std::unique_lock<std::mutex> lock(_mutex1,std::try_to_lock);

				//std::unique_lock<std::mutex> lock(_mutex1, std::defer_lock);
				//std::unique_lock<std::mutex> lock(_mutex1,std::defer_lock);
				std::unique_lock<std::mutex> lock1(_mutex1);
				//std::unique_lock<std::mutex> lock2(_mutex2);
				std::unique_lock<std::mutex> lock2(std::move(lock1));
				//std::mutex* pmx = lock.release();//要自行unlock
				//lock.lock();
				//是否拿到锁
				//if (lock.owns_lock()) {
				//if (lock.try_lock()) {
					msgRecQueue.push_back(i);
				//}
				//else {
				//	cout << "没有拿到锁，不操作共享数据，只做其它事" << endl;
				//}
					
				//}
				//else {

					//cout << "inMsgRecQueue没有拿到锁" << endl;
				//}

					//lock.unlock();
					//pmx->unlock();
				
			}

			
		}
	}

	bool outMsgRecQueueProc(int& cmd)
	{
		std::unique_lock<std::mutex> lock(_mutex1);

		std::chrono::milliseconds time(200);
		std::this_thread::sleep_for(time);

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

	//1、std::adopt_lock 表示mutex已经lock了，lock_guard表示在析构已经lock过了，不用在unique_lock类或是lock_guard构造类lock了
	//2、std::try_to_lock 尝试锁，lock.owns_lock() 拿到锁就操作共享数据，否则 做共它事情
	//3、std::defer_lock
	//unique_lock类成员：lock,unlock,try_lock release[释放mutex指针，释放所有权，它们不在有关联]
	//4、relase

	std::unique_ptr<int> p(new int(100));

	//unique_lock 所有权的转移


	cout << "main end" << endl;
	return 0;
}