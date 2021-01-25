#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>

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

			_mutext.lock();
			msgRecvQueue.push_back(i);
			_mutext.unlock();
		}
	}

	bool outMsgProc(int &command)
	{
		_mutext.lock();
		if (!msgRecvQueue.empty())
		{
			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			_mutext.unlock();
			return true;
		}
		_mutext.unlock();
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