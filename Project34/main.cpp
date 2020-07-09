#include <iostream>
#include <string> 
#include <fstream>
#include <thread>
using namespace std;

//���̼߳�������ݣ��������߳����ӵ�ж�����һ�����ݣ��������߳�ָ��ͬһ���ڴ棬�ᷢ����������
//					���̼߳�������������ֵ���ݣ����󴫵�ʱ���������̶߳�������һ��
//���̼߳�������ഫ�ݣ��������ԭ����Ǹ������߳�ָ����ͬһ���ڴ棬�����߳�ʹ����detach�����
//��Ȼ���߳̿��Բ�ֹͣ��Ҳ���������

class A {
public:
	mutable int _i{ 0 };
	A(int j) :_i(j) {
		/*ofstream o("thread.txt", ios::out);
		o << j << endl;
		o.close();*/

		cout << "a constructor::" <<"A��ַ��"<<this<<"thread id="<<std::this_thread::get_id()<< endl;
	}
	A(const A& obj) :_i(obj._i) {
		cout << "a copy constructor::" << "A��ַ��" << this<< "thread_id="<<std::this_thread::get_id()<<endl;
	}
	~A() {
		cout << "a destructor::" <<"A��ַ��" << this << "thread_id="<<std::this_thread::get_id()<< endl;
	}

	void worker(int um)
	{
		cout << "um=" << um << endl;
	}

	void operator()(int)
	{
		cout << "operator::" << "A��ַ��" << this << "thread_id=" << std::this_thread::get_id() << endl;
	}
};
//void show(const int& i, char *j)
void show(const int i, const string &j)
{
	cout << i << endl;//i���� ����д�ϵ������ô��ݣ�������ֵ���ݣ���һ�ָ��ƣ��ǰ�ȫ��
	cout << j << endl;
	return;
}

//void talk(const int i, const A &obj)
void talk(const int i, A &obj)
{
	obj._i = 100;
	cout << "���е��̺߳�����"<<"���ݵ��̵߳Ĳ�����ַ��"<<&obj <<"thread_id:"<<std::this_thread::get_id()<< endl;
	return;
}

void say(unique_ptr<int> t)
{
	cout << *t << endl;
}
int main()
{
	//1��������ʱ������Ϊ�̵߳Ĳ���
	//�ܽ᣺���̴߳��ݲ�����
	//a ��ͨ���� ֵ����
	//b ����󴫵�  ��ʱ���󴫵ݣ����ý��ղ��� ��Ҫ������ʱ����ת��
	//c �����������ʹ��detachʱ���ᵼ�����߳���ǰ�����ͷ����ڴ棬���̻߳�Ƿ������ͷŵ��ڴ�

	//d ����ʹ��join�Ͳ����������������
	
	/*int i = 1;
	int& k = i;
	char buf[] = "test";*/

	//thread t(show, i, buf);
	//thread t(show, i, string(buf));//��ȫ�Ĵ��ݲ���  ����ֵ����  ���ô��ݣ�ָ�봫�����׳�����
	//t.join();
	//show(i, buf);

	//int i = 1;
	//int j = 2;
	//thread t(talk, i, j);//�ڵ�����������ת�����캯��ʱ�����j�����߳��ͷ��ˣ������
	//thread t(talk, i, A(j));//��ʱ���󴫵� 
	//cout << "main thread::" << std::this_thread::get_id() << endl;
	//thread t(talk, i, A(j));
	//thread t(talk, i, j);
	//t.join();
	//cout << "main end" << endl;

	//cout<<
	//while (1) { ; }

	//2���������������ָ��

	//A obj(10);
	//thread t(talk, i, obj);
	//thread t(talk, i, std::ref(obj));//�������߳�ͬ��ָ��ͬһ���ڴ��ַ
	//t.join();

	//cout << obj._i << endl;

	//unique_ptr<int> p(new int(100));

	//thread t(say, std::move(p));//ͬ����ָ��ͬһ���ڴ棬���׳�����ʹ��detach

	//if (p == nullptr) {
	//	cout << "p null" << endl;
	//}

	//t.detach();

	//3�������Ա��Ϊ�̵߳ĳ�ʼ����
	//A obj(10);

	//thread t(&A::worker, obj, 100);//�����˿�������

	//void (A:: * p)(int um) = &A::worker;

	//(obj.*p)(1000);
	//t.join();

	A obj(10);

	//thread t(obj, 1000);//�����˿�������
	thread t(std::ref(obj), 500);
	t.join();


	cout << "main thread::" << std::this_thread::get_id() << endl;

	return 0;
}