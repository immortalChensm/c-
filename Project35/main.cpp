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
			//_mutex.lock();
			{
				//std::lock_guard<std::mutex> lock(_mutex);
				//std::lock_guard<std::mutex> lock1(_mutex1);
				//std::lock_guard<std::mutex> lock2(_mutex2);
				std::lock(_mutex1,_mutex2);
				std::lock_guard<std::mutex> lock1(_mutex1, std::adopt_lock);
				std::lock_guard<std::mutex> lock2(_mutex2, std::adopt_lock);
				//_mutex1.lock();
				//_mutex2.lock();
				msgRecQueue.push_back(i);
				//_mutex2.unlock();
				//_mutex1.unlock();
			}
			
			//_mutex.unlock();
		}
	}

	bool outMsgRecQueueProc(int &cmd)
	{
		//std::lock_guard<std::mutex> lock(_mutex1);
		//std::lock_guard<std::mutex> lock1(_mutex1);
		//std::lock_guard<std::mutex> lock2(_mutex2);
		//_mutex2.lock();
		//_mutex1.lock();
		//_mutex.lock();
		std::lock(_mutex1,_mutex2);
		if (!msgRecQueue.empty())
		{
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();
			//_mutex.unlock();
			_mutex1.unlock();
			_mutex2.unlock();
			return true;
		}
		//_mutex.unlock();
		_mutex1.unlock();
		_mutex2.unlock();
		return false;
	}
	void outMsgRecQueue()
	{
		int cmd = 0;
		for (int i = 0; i < 100000; i++)
		{
			if (outMsgRecQueueProc(cmd))
			{
				cout << "outMsgRecQueueProc:"<<cmd << endl;

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

	//1��������������  �̲߳���ʱ�ѹ���������ס�������꣬���������������̲߳���
	//2������������2��������ʱ������ԭ��˫��������
	//3�������Ľ��
	//4��std::lock ��һ������ס���������2�����ϡ�����������Ϊ����˳�����⵼������ ���Ĺ�������sql���񡾶����Ҫô�ɹ���
	//ֻ��סһ������һ��û�������ͻ������ǰ�����õ�

	//5��std::lock()��std::lock_gurad<> (mutex,std::adopt_lock)
	//std::adpot_lock ��ʾstd::lock(_mutex1,_mutex2) �еı����Ѿ�lock���ˣ�����Ҫstd::lock_guard<std::mutex> lock(_mutex1)
	//�ڹ��캯����ʹ��_mutex1.lock��
	cout << "main end" << endl;
	return 0;
}