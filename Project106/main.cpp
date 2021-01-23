#include <iostream>
#include <thread>

using namespace std;

class A {
public:
	//mutable int m_i;
	int m_i;
	A(int x):m_i(x)
	{
		cout << "A���캯��" << m_i <<","<< this << "," << std::this_thread::get_id() << endl;
	}
	A(const A& obj):m_i(obj.m_i)
	{
		cout << "A�������캯��" << m_i << "," << this << "," << std::this_thread::get_id() << endl;
	}
	~A()
	{
		cout << "~A��������" << m_i << "," << this << "," << std::this_thread::get_id() << endl;
	}

	void thread_worker(int num)
	{
		cout << "���̺߳���" << std::this_thread::get_id() << endl;
	}

	void operator()(int num)
	{
		cout << "���̺߳���" << std::this_thread::get_id() << this<<endl;
	}
};
//void show(const int i, char* p)
//void show(const int i,const A& p)
//void show(const int i,A& p)
void show(unique_ptr<int> i)
{
	
	cout << "���߳�����" << endl;
	cout << i << endl;

	cout << "���̺߳���" << std::this_thread::get_id() << endl;
	cout << "���߳̽���" << endl;
}
int main()
{

	cout << "���̺߳���" << std::this_thread::get_id() << endl;

	//int x = 10;
	//char p[] = "this is test";
	int p = 101;

	//thread obj(show, x, A(p));
	A o(p);
	//thread obj(show, x, o);
	//thread obj(show, x, std::ref(o));
	//thread obj(show, x, &o);
	//unique_ptr<int> x(new int(99));
	//thread obj(&A::thread_worker, o,p);
	thread obj(o, p);
	obj.join();  //���̻߳�����߳�������
	//obj.detach();//���߳� �Լ�ִ���������ͷ���������

	/*while (1) {

	}*/
	//cout <<"���̣߳�"<< o.m_i << endl;
	return 0;
}