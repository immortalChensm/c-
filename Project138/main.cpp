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
	//std::mutex my_mutex1;
	//std::mutex my_mutex2;
	//std::recursive_mutex my_mutex1;
	//std::timed_mutex my_mutex1;
	std::recursive_timed_mutex my_mutex1;
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++) {

			cout << "inMsgRecvQueue线程执行,插入" << i << endl;

			//std::lock_guard<std::timed_mutex> lock(my_mutex1);
			//std::lock_guard<std::recursive_mutex> lock2(my_mutex1);
			//std::lock_guard<std::recursive_mutex> lock3(my_mutex1);
		
			std::chrono::milliseconds durar(100);
			//if (my_mutex1.try_lock_for(durar)) {
			if (my_mutex1.try_lock_until(std::chrono::steady_clock::now() + durar)) {
				recvMsgQueue.push_back(i);
				my_mutex1.unlock();
			}
			else {
				cout << "抢不到锁，做其它事情" << i << endl;
			}
			
			
		}
	}

	bool outMsgProc(int& command)
	{

		
		my_mutex1.lock();

		//std::chrono::milliseconds durar(1000);
		//std::this_thread::sleep_for(durar);
		if (!recvMsgQueue.empty()) {

			command = recvMsgQueue.front();
			recvMsgQueue.pop_front();
			my_mutex1.unlock();
			return true;
		}
		my_mutex1.unlock();
		return false;
	}
	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i = 0; i < 10000; i++) {

			bool result = outMsgProc(command);
			if (result == true) {

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



	A obj;
	std::thread inMsg(&A::inMsgRecvQueue, &obj);
	std::thread outMsg(&A::outMsgRecvQueue, &obj);

	inMsg.join();
	outMsg.join();

	return 0;
}