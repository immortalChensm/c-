#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;
/**
std::mutex   [lock,unlock] std::unique_lock<mutex>  lock(mutext,std::adopt|std::try_to_lock|std::defer_lock)
						   lock,unlock
						   std::lock(mutx1,mtxt2) ʱ������adopt_lock
						   std::try_to_lock ʱ������  lock.owns_lock()=true �ж��Ƿ�����
						   std::defer_lock ʱ���Ե���lock.lock()  lock.unlock() ����try_lock()==true�ж�
std::recursive_mutex �ݹ���  ���������
std::timed_mutex ���Ե���  try_lock_for  try_lock_until �ж��Ƿ���һ����ʱ��������

recursive_mutex ,timed_mutex �����ܲ���
***/
class A {
public:
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			cout << "inMsgRecvQueue:threadId=" << std::this_thread::get_id() << "ִ�У���������" << i << endl;

			
			//std::unique_lock<std::recursive_mutex> lock2(_mutext);
			//std::unique_lock<std::mutex> lock(_mutext);  can't   
			//func1();
			
			std::chrono::milliseconds dura(1000);
			//if (_mutext.try_lock_for(dura)) {  //�ȴ�1000ms���õ���ʱ
			if (_mutext.try_lock_until(chrono::steady_clock::now()+dura)) {  //�ȴ�1000ms���õ���ʱ
				msgRecvQueue.push_back(i);
				_mutext.unlock();//����
			}
			else {

				cout << "û���õ�������������������" << endl;
			}
			
			
		}
	}

	//void func1()
	//{
	//	std::unique_lock<std::recursive_mutex> lock(_mutext);
	//	//
	//	cout << "to do something1..." << endl;
	//	func2();
	//}
	//void func2()
	//{
	//	std::unique_lock<std::recursive_mutex> lock(_mutext);
	//	//
	//	cout << "to do something2..." << endl;
	//}
	bool outMsgProc(int& command)
	{
		
		std::unique_lock<std::recursive_timed_mutex> lock(_mutext);

		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);

		if (!msgRecvQueue.empty())
		{
			command = msgRecvQueue.front();
			msgRecvQueue.pop_front();
			
			return true;
		}
		
		return false;
	}
	void outMsgRecvQueue()
	{
		int command = 0;
		for (int i = 0; i < 10000; i++)
		{
			bool result = outMsgProc(command);
			if (result == true)
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
	//std::mutex _mutext;//��ռ������
	//std::recursive_mutex _mutext;//�ݹ�ʽ������
	//std::timed_mutex _mutext;//����ʱ��������
	std::recursive_timed_mutex _mutext;//����ʱ��������
	std::mutex _mutext2;
};
int main()
{




	A obj;
	std::thread outMsgObj(&A::outMsgRecvQueue, &obj);//�������ã���֤2���̹߳���ͬһ�����󣬷�����������ɶ����̵߳Ķ�����
	std::thread inMsgObj(&A::inMsgRecvQueue, &obj);

	outMsgObj.join();
	inMsgObj.join();


	cout << "i like money" << endl;

	return 0;
}