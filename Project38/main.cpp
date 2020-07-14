#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 

#include <list>

//��������߳�|��������
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
			//wait �����ȴ�һ������
			//wait �ڶ�������lambda�������з���false ʱ��wait������������_mutex1��������������
			//�����������̵߳���notify_one()��Ա����Ϊֹ
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
	std::condition_variable _condition;//������������
};

int main()
{

	//1��std::condition_variable wait,notify_one
	//A���̵߳ȴ���������

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