#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>

//https://zh.cppreference.com/w/cpp/thread/unique_lock
/**
std::mutex lock unlock
std::lock_guard<std::mutex> lock(_mutex)
std::lock(_mutex1,_mutex2)
std::lock_guard<std::mutex> lock(_mutex,std::adopt_lock)

std::unique_lock<std::mutex> lock(_mutex,[std::adopt_lock,std::try_to_lock,std::defer_lock])
std::try_to_lock ʱ��������lock.owns_lock()�ж��Ƿ���ס��
std::defer_lock ʱ��������lock.lock() lock.unlock lock.try_lock()==true ��������  


**/
using namespace std;

void show(int num)
{
	cout << "threadId="<<std::this_thread::get_id()<<",num="<<num << endl;
}

class A {
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			cout << "inMsgRecvQueue:threadId=" << std::this_thread::get_id() << "ִ�У���������" << i << endl;

			//_mutext.lock();
			//std::lock_guard<std::mutex> lock(_mutext);
			//_mutext2.lock();
			//_mutext.lock();
			//std::lock_guard<std::mutex> lock1(_mutext2);
			//std::lock_guard<std::mutex> lock2(_mutext);
			//std::lock(_mutext,_mutext2);
			//std::lock_guard<std::mutex> lock1(_mutext,std::adopt_lock);
			//_mutext.lock();
			//std::unique_lock<std::mutex> lock2(_mutext,std::adopt_lock);
			//std::unique_lock<std::mutex> lock(_mutext,std::try_to_lock);
			//std::unique_lock<std::mutex> lock(_mutext,std::defer_lock);
			std::unique_lock<std::mutex> lock(_mutext,std::defer_lock);
			std::unique_lock<std::mutex> lock1(std::move(lock));//����Ȩת��
			//if (lock.owns_lock()) {
			//if (lock.try_lock()==true) {
			//lock.lock();

			//do something...
			//lock.unlock();

			//lock.lock();
			std::mutex* ptx = lock1.release();
			ptx->lock();

				msgRecvQueue.push_back(i);
			//}
			//else {

			//	cout << "in�߳�û���õ�����������������Դ�������������" << endl;
			//}
			
			//_mutext.unlock();
			//_mutext2.unlock();
				ptx->unlock();
		}
	}

	bool outMsgProc(int &command)
	{
		//_mutext.lock();
		//std::lock_guard<std::mutex> lock(_mutext);
		//_mutext2.lock();
		//_mutext.lock();
		std::unique_lock<std::mutex> lock(_mutext);

		std::chrono::microseconds dura(200);
		std::this_thread::sleep_for(dura);

		if (!msgRecvQueue.empty())
		{
			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			//_mutext.unlock();
			//_mutext2.unlock();
			//_mutext.unlock();
			return true;
		}
		//_mutext.unlock();
		//_mutext2.unlock();
		//_mutext.unlock();
		return false;
	}
	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgProc(command);
			if (result==true)
			{
				cout << "outMsgRecvQueue �߳�ȡ������Ϊ��" << command << endl;
			}
			else {

				cout << "outMsgRecvQueue:threadId=" << std::this_thread::get_id() << "ִ�У�����Ϊ��" << i << endl;
			}
		}
	}
private:
	std::list<int> msgRecvQueue;
	std::mutex _mutext;
	std::mutex _mutext2;
};
int main()
{


	/*vector<thread> obj;
	for (int i = 0; i < 10; i++)
	{
		obj.push_back(thread(show,i));
	}

	for (auto itr = obj.begin(); itr != obj.end(); ++itr)
	{
		itr->join();
	}*/


	A obj;
	std::thread outMsgObj(&A::outMsgRecvQueue, &obj);//�������ã���֤2���̹߳���ͬһ�����󣬷�����������ɶ����̵߳Ķ�����
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();
	inMsgObj.join();


	cout << "i like money" << endl;

	return 0;
}