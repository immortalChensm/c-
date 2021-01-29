#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

/**
wait(std::mutex obj,func) func����true ��������ִ��
							func����false,�ͷ�������������wait
��һ���̵߳���notify_one/notify_all ʱ���ỽ��
wait�̣߳����������»�ȡ����������ȡ�����Ϳ�����ȡ���ͻ�ִ��wait
�ĵڶ�������������true����ִ�У�����falseͬ������
û�еڶ���������Ĭ�Ͼͷ���true[ֻ���notify����ʱ]


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

			cout << "inMsgRecvQueue:threadId=" << std::this_thread::get_id() << "ִ�У���������" << i << endl;

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
			cout << "outMsgRecvQueue:threadId=" << std::this_thread::get_id() << "ִ�У�command=" << command << endl;

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
	std::thread outMsgObj(&A::outMsgRecvQueue, &obj);//�������ã���֤2���̹߳���ͬһ�����󣬷�����������ɶ����̵߳Ķ�����
	std::thread outMsgObj2(&A::outMsgRecvQueue, &obj);//�������ã���֤2���̹߳���ͬһ�����󣬷�����������ɶ����̵߳Ķ�����
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();
	outMsgObj2.join();
	inMsgObj.join();


	cout << "i like money" << endl;

	return 0;
}