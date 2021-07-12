#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>
#include <vector>

using namespace std;

class A {
public:
	list<int> recvMsgQueue;
	std::mutex my_mutex1;
	std::mutex my_mutex2;
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++) {

			cout << "inMsgRecvQueue线程执行,插入" << i << endl;

			//my_mutex.lock();
			//std::lock_guard<std::mutex> lock(my_mutex);
			//my_mutex1.lock();
			//my_mutex2.lock();
			std::lock(my_mutex2,my_mutex1);
			std::lock_guard<std::mutex> lock1(my_mutex1,std::adopt_lock);
			std::lock_guard<std::mutex> lock2(my_mutex2,std::adopt_lock);
			
			recvMsgQueue.push_back(i);

			//my_mutex.unlock();
			//my_mutex1.unlock();
			//my_mutex2.unlock();
		}
	}

	bool outMsgProc(int& command)
	{

		//my_mutex.lock();
		//my_mutex1.lock();
		//my_mutex2.lock();
		std::lock(my_mutex1,my_mutex2);
		std::lock_guard<std::mutex> lock1(my_mutex1,std::adopt_lock);
		std::lock_guard<std::mutex> lock2(my_mutex2,std::adopt_lock);
		if (!recvMsgQueue.empty()) {

			command = recvMsgQueue.front();
			recvMsgQueue.pop_front();
			//my_mutex.unlock();
			//my_mutex2.unlock();
			//my_mutex1.unlock();
			return true;
		}
		//my_mutex.unlock();
		//my_mutex2.unlock();
		//my_mutex1.unlock();
		return false;
	}
	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i = 0; i < 10000; i++) {

			bool result = outMsgProc(command);
			if (result==true) {

				cout << "outMsgRecvQueue线程执行,取得数据" << command << endl;
			}
			else {
				cout << "outMsgRecvQueue线程执行,暂无数据" << i << endl;
			}
		}
	}
};
void myprint(int i) {

	cout << "myprint线程启动" << i << endl;
	cout << "myprint线程结束" << i << endl;
}
int main()
{


	/*vector<std::thread> threads;

	for (int i = 0; i < 10; i++) {

		threads.push_back(thread(myprint, i));
	}

	for (auto itr = threads.begin(); itr != threads.end(); itr++) {

		itr->join();
	}*/

	A obj;
	std::thread inMsg(&A::inMsgRecvQueue, &obj);
	std::thread outMsg(&A::outMsgRecvQueue, &obj);

	inMsg.join();
	outMsg.join();

	return 0;
}