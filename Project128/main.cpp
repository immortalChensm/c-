#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>
#include <vector>
#include <condition_variable>

using namespace std;

class A {
public:
	list<int> recvMsgQueue;
	std::mutex my_mutex;
	std::condition_variable my_cond;
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++) {

			
			std::unique_lock<std::mutex> lock(my_mutex);
			cout << "inMsgRecvQueue线程执行,插入" << i << endl;
			recvMsgQueue.push_back(i);

			//my_cond.notify_one();
			my_cond.notify_all();
			
		}
	}

	void outMsgRecvQueue()
	{
		int command = 0;

		while (true) {

			std::unique_lock<std::mutex> lock(my_mutex);

			my_cond.wait(lock, [this] {
			
				if (recvMsgQueue.empty()) {
					return false;
				}
				return true;
			});

			command = recvMsgQueue.front();
			recvMsgQueue.pop_front();

			cout <<"threadid="<<std::this_thread::get_id()<< "outMsgRecvQueue线程执行,取得数据" << command << endl;

			lock.unlock();

			//取得数据可以做一些事情
			//wait 函数第二个参数是函数返回false时会释放当前线程锁并阻塞
			//当其它线程调用notify时，会被唤醒
			//1 唤醒时当前线程也要抢到锁，并且也会进行判断第二参数是否返回true
			//返回false还是阻塞，true往下执行

			//2如果当前线程抢到锁的机会少了，则notify线程会插入过多的数据
			//但当前线程取出数据机会少了，会导致当前消息列表过多，甚至
			//notify线程处理完了，导致不再执行notify了，而当前wait线程会一直阻塞
			//导致数据没有处理完

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
	std::thread outMsg2(&A::outMsgRecvQueue, &obj);

	inMsg.join();
	outMsg.join();
	outMsg2.join();

	return 0;
}