#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 

#include <list>

//�������ݣ�unique_lockȡ��lock_guard
//std::lock|std::lock_guard|std::mutex|std::adpot_lock
//std::lock_guard ȡ����std::mutex ��lock,unlock����
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
				//_mutex1.lock();
				//std::unique_lock<std::mutex> lock(_mutex1,std::adopt_lock);
				//std::unique_lock<std::mutex> lock(_mutex1,std::try_to_lock);

				//std::unique_lock<std::mutex> lock(_mutex1, std::defer_lock);
				//std::unique_lock<std::mutex> lock(_mutex1,std::defer_lock);
				std::unique_lock<std::mutex> lock1(_mutex1);
				//std::unique_lock<std::mutex> lock2(_mutex2);
				std::unique_lock<std::mutex> lock2(std::move(lock1));
				//std::mutex* pmx = lock.release();//Ҫ����unlock
				//lock.lock();
				//�Ƿ��õ���
				//if (lock.owns_lock()) {
				//if (lock.try_lock()) {
					msgRecQueue.push_back(i);
				//}
				//else {
				//	cout << "û���õ������������������ݣ�ֻ��������" << endl;
				//}
					
				//}
				//else {

					//cout << "inMsgRecQueueû���õ���" << endl;
				//}

					//lock.unlock();
					//pmx->unlock();
				
			}

			
		}
	}

	bool outMsgRecQueueProc(int& cmd)
	{
		std::unique_lock<std::mutex> lock(_mutex1);

		std::chrono::milliseconds time(200);
		std::this_thread::sleep_for(time);

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
		for (int i = 0; i < 100000; i++)
		{
			if (outMsgRecQueueProc(cmd))
			{
				cout << "outMsgRecQueueProc:" << cmd << endl;

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

	//1��std::adopt_lock ��ʾmutex�Ѿ�lock�ˣ�lock_guard��ʾ�������Ѿ�lock���ˣ�������unique_lock�����lock_guard������lock��
	//2��std::try_to_lock ��������lock.owns_lock() �õ����Ͳ����������ݣ����� ����������
	//3��std::defer_lock
	//unique_lock���Ա��lock,unlock,try_lock release[�ͷ�mutexָ�룬�ͷ�����Ȩ�����ǲ����й���]
	//4��relase

	std::unique_ptr<int> p(new int(100));

	//unique_lock ����Ȩ��ת��


	cout << "main end" << endl;
	return 0;
}