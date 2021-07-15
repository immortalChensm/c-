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
			cout << "inMsgRecvQueue�߳�ִ��,����" << i << endl;
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

			cout <<"threadid="<<std::this_thread::get_id()<< "outMsgRecvQueue�߳�ִ��,ȡ������" << command << endl;

			lock.unlock();

			//ȡ�����ݿ�����һЩ����
			//wait �����ڶ��������Ǻ�������falseʱ���ͷŵ�ǰ�߳���������
			//�������̵߳���notifyʱ���ᱻ����
			//1 ����ʱ��ǰ�߳�ҲҪ������������Ҳ������жϵڶ������Ƿ񷵻�true
			//����false����������true����ִ��

			//2�����ǰ�߳��������Ļ������ˣ���notify�̻߳������������
			//����ǰ�߳�ȡ�����ݻ������ˣ��ᵼ�µ�ǰ��Ϣ�б���࣬����
			//notify�̴߳������ˣ����²���ִ��notify�ˣ�����ǰwait�̻߳�һֱ����
			//��������û�д�����

		}
		
	}
};
void myprint(int i) {

	cout << "myprint�߳�����" << i << endl;
	cout << "myprint�߳̽���" << i << endl;
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