#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

class A {
public:
	std::atomic<int > atm;
	A()
	{
		atm = 0;
		//std::atomic<int> t = atm;
		std::atomic<int> t;
		t = atm.load();//以原子方式读取数据
		t.store(atm.load());//以原子方式存数据
		t.store(55);//以原子方式存数据

		cout << t << endl;
	}
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 1000000; i++)
		{
			atm++;
		}
	}

	void outMsgRecvQueue()
	{
		while (true)
		{
			cout << atm << endl;
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
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);
	std::thread inMsgObj2(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();

	inMsgObj.join();
	inMsgObj2.join();


	cout << "i like money" << endl;

	return 0;
}