#include <iostream> 
#include <string> 
#include <thread>

using namespace std;

//���̣��������еĳ���  
//һ�����̣���Ȼ��ĬĬ����һ�����߳� ��һ�����̰���һ�����̡߳� 
//�̣߳�����ִ�д����
//����̣߳�ÿ���̶߳���Ҫһ�������Ķ�ջ�ռ䣬�߳�֮����л��ᱣ���м�״̬���л���ʱ���ķѳ��������ʱ��

//cpu����ʱ�����ж�����ʱ�ǡ��������л����л�ʱ�ᱣ������̵߳�����״̬�����ȵ�����

//���̣߳�
//ÿ���߳����Լ��Ķ�������·��������һ�������������̹߳���һ���ڴ�ռ䡾�ڴ��ַ�����Կ��̼߳以����ʣ�����С
//������ָ�룬���ÿ������̼߳以�ഫ��
//�ŵ㣺�����ٶȿ죬���̼߳�ͨ��ͨ�������ڴ�ʵ�� ������С
//ȱ�㣺����һ��������

//����ִ����ϵı�־�ǣ����߳��Ƿ�ִ���꣬���߳�ִ���꣬�ʹ�����������ִ�����
//��������������һ�����̣����̵����߳�����main��������������Ǵ���һ���̣߳�ҲҪ��һ��������ʼ���У���ʼ������
//������������н����󣬾ʹ�������߳����н�����


//һ��������������������������,����������̻߳�û��ִ����ϣ��ᱻ����ϵͳǿ����ֹ
//Ҫ�뱣�����̵߳�����״̬�����߳̾�Ҫһֱ����

void myshow()
{
	cout << "thread begin" << endl;

	cout << "thread end1" << endl;
	cout << "thread end2" << endl;
	cout << "thread end3" << endl;
	cout << "thread end4" << endl;
	cout << "thread end5" << endl;
	cout << "thread end6" << endl;
	cout << "thread end7" << endl;
	cout << "thread end8" << endl;
	cout << "thread end9" << endl;
}

class Ta
{
public:
	int &_i;
	Ta(int &i) :_i(i) {};
	void operator()()
	{
		cout << "operator begin" << endl;
		cout << "_i=" << _i << endl;
	}
};
int main()
{

	//thread t(myshow);
	//t.join();
	//join ���룬���  �������̣߳������̵߳ȴ����߳�ִ����ϣ�Ȼ�����̺߳����̻߳�ϣ�Ȼ�����߳�������ִ��

	/*if (t.joinable()) {
		cout << "1 true" << endl;
	}
	else {
		cout << "2 false" << endl;
	}
	t.detach();*///���̺߳����߳̽����룬���߳̽��������߳��ں�̨�������У�ֱ���������������κι���
	//���߳̽���ϵͳ����c++����ʱ��ӹܣ��������߳����н�����������ʱ����������Դ��������ػ��̣߳�

	/*if (t.joinable()) {
		cout << "1 true" << endl;
	}
	else {
		cout << "2 false" << endl;
	}*/

	//��������ʽ�������߳�
	int j = 10;
	Ta obj(j);
	thread t(obj);

	//t.join();
	t.detach();


	cout << "main thread" << endl;
	cout << "main thread" << endl;
	cout << "main thread" << endl;
	cout << "main thread" << endl;
	cout << "main thread" << endl;
	cout << "main thread" << endl;
	cout << "main thread" << endl;

	return 0;
}