#include <iostream> 
#include <string>
#include <mutex>
#include <thread> 
#include <atomic>
#include <list>

//��������߳�|��������
using namespace std;

class A
{
public:
	std::atomic<int> atm;
	A()
	{
		atm = 0;
		//auto atm1 = atm; ����������ɾ���ĺ��� ������  ʹ�����Ŀ�������
		//atomice<int> atm2 = atm;
		std::atomic<int> atm3(atm.load());//��ʼ
		atm3.store(19);

	}
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000; i++)
		{


			{

				std::lock_guard<std::mutex> lock1(_mutex1);
				cout << "inMsgRecQueue-insert: " << i << endl;
				msgRecQueue.push_back(i);

				//_condition.notify_one();//���԰�wait�̻߳��� ���̵߳��������ͷŵ� ֻ֪ͨһ��
				//��Ȼִ���˻��Ѳ�������wait�߳�û���������Ļ��������ǵ�ǰ�߳�����������������������
				//��wait�߳��������������٣���������ݾ�����
				_condition.notify_all();//֪ͨ�����̣߳����ǣ��ĸ��߳����������ĸ�����
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
			//�����������̵߳���notify_one()��Ա����Ϊֹ û�еڶ���������Ĭ�Ͼ���false
			_condition.wait(lock, [this] {
				if (!msgRecQueue.empty())
					return true;
				return false;
				});


			//1��wait����trueʱ�����Ի�ȡ�������ϵĻ�ȡ����ȡ�����Ϳ�ס
			//2����ȡ����֮��Ҳ���ж�wait�ķ���ֵ������false���ǿ���trueʱ��������ִ��
			//������֮�󡾿����Լ��������Ĵ����٣����msgRecQueue�����д��������ݡ�
			cmd = msgRecQueue.front();
			msgRecQueue.pop_front();

			cout << "outMsgRecQueueProc:" << cmd << "threadid=" << std::this_thread::get_id() << endl;

			lock.unlock();//��ǰ����



		}
		
	}
private:
	list<int> msgRecQueue;
	std::mutex _mutex1;
	std::mutex _mutex2;
	std::condition_variable _condition;//������������
};

int main()
{

	//1����ٻ���  
	//wait ����falseʱ��������ǰ�̣߳���ǰ�̲߳���ִ�д���
	//notify_one �ἤ��wait�̣߳����wait�߳����������ͻ�����
	//notify_all ��������wait �߳�

	//���̲߳���ͬһ�鹲���ڴ�ʱ��������֮����ʱ����Լ��������������жϹ����ڴ����Ƿ��������ٲ���
	A msgObj;

	std::thread outMsgObj(&A::outMsgRecQueue, &msgObj);
	
	std::thread inMsgObj(&A::inMsgRecQueue, &msgObj);


	inMsgObj.join();
	outMsgObj.join();
	


	cout << "main end" << endl;
	return 0;
}