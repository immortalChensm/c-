#include <iostream>
#include <thread>

using namespace std;

class A {
public:
	//mutable int m_i;
	int m_i;
	A(int x):m_i(x)
	{
		cout << "A构造函数" << m_i <<","<< this << "," << std::this_thread::get_id() << endl;
	}
	A(const A& obj):m_i(obj.m_i)
	{
		cout << "A拷贝构造函数" << m_i << "," << this << "," << std::this_thread::get_id() << endl;
	}
	~A()
	{
		cout << "~A析构函数" << m_i << "," << this << "," << std::this_thread::get_id() << endl;
	}

	void thread_worker(int num)
	{
		cout << "子线程函数" << std::this_thread::get_id() << endl;
	}

	void operator()(int num)
	{
		cout << "子线程函数" << std::this_thread::get_id() << this<<endl;
	}
};
//void show(const int i, char* p)
//void show(const int i,const A& p)
//void show(const int i,A& p)
void show(unique_ptr<int> i)
{
	
	cout << "子线程启动" << endl;
	cout << i << endl;

	cout << "子线程函数" << std::this_thread::get_id() << endl;
	cout << "子线程结束" << endl;
}
int main()
{

	cout << "主线程函数" << std::this_thread::get_id() << endl;

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
	obj.join();  //主线程会等子线程运行完
	//obj.detach();//主线程 自己执行完立马释放整个进程

	/*while (1) {

	}*/
	//cout <<"主线程："<< o.m_i << endl;
	return 0;
}