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
		t = atm.load();//��ԭ�ӷ�ʽ��ȡ����
		t.store(atm.load());//��ԭ�ӷ�ʽ������
		t.store(55);//��ԭ�ӷ�ʽ������

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
	std::thread outMsgObj(&A::outMsgRecvQueue, &obj);//�������ã���֤2���̹߳���ͬһ�����󣬷�����������ɶ����̵߳Ķ�����
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);
	std::thread inMsgObj2(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();

	inMsgObj.join();
	inMsgObj2.join();


	cout << "i like money" << endl;

	return 0;
}