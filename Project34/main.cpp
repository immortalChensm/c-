#include <iostream>
#include <string> 
#include <fstream>
#include <thread>
using namespace std;

//跨线程间参数传递：各个子线程最好拥有独立的一份数据，如果多个线程指向同一块内存，会发生各种问题
//					跨线程间参数传递最好是值传递，对象传递时，各个子线程独立拷贝一份
//跨线程间参数互相传递，出问题的原因就是各个子线程指向了同一块内存，而主线程使用了detach的情况
//当然主线程可以不停止，也不会出问题

class A {
public:
	mutable int _i{ 0 };
	A(int j) :_i(j) {
		/*ofstream o("thread.txt", ios::out);
		o << j << endl;
		o.close();*/

		cout << "a constructor::" <<"A地址："<<this<<"thread id="<<std::this_thread::get_id()<< endl;
	}
	A(const A& obj) :_i(obj._i) {
		cout << "a copy constructor::" << "A地址：" << this<< "thread_id="<<std::this_thread::get_id()<<endl;
	}
	~A() {
		cout << "a destructor::" <<"A地址：" << this << "thread_id="<<std::this_thread::get_id()<< endl;
	}

	void worker(int um)
	{
		cout << "um=" << um << endl;
	}

	void operator()(int)
	{
		cout << "operator::" << "A地址：" << this << "thread_id=" << std::this_thread::get_id() << endl;
	}
};
//void show(const int& i, char *j)
void show(const int i, const string &j)
{
	cout << i << endl;//i参数 代码写上的是引用传递，但是是值传递，是一种复制，是安全的
	cout << j << endl;
	return;
}

//void talk(const int i, const A &obj)
void talk(const int i, A &obj)
{
	obj._i = 100;
	cout << "运行的线程函数："<<"传递到线程的参数地址："<<&obj <<"thread_id:"<<std::this_thread::get_id()<< endl;
	return;
}

void say(unique_ptr<int> t)
{
	cout << *t << endl;
}
int main()
{
	//1、传递临时对象作为线程的参数
	//总结：跨线程传递参数：
	//a 普通类型 值传递
	//b 类对象传递  临时对象传递，引用接收参数 不要存在临时类型转换
	//c 以上问题针对使用detach时，会导致主线程提前结束释放了内存，子线程会非法访问释放的内存

	//d 建议使用join就不会存在以上问题了
	
	/*int i = 1;
	int& k = i;
	char buf[] = "test";*/

	//thread t(show, i, buf);
	//thread t(show, i, string(buf));//安全的传递参数  都是值传递  引用传递，指针传递容易出问题
	//t.join();
	//show(i, buf);

	//int i = 1;
	//int j = 2;
	//thread t(talk, i, j);//在调用它的类型转换构造函数时，如果j被主线程释放了，会出错
	//thread t(talk, i, A(j));//临时对象传递 
	//cout << "main thread::" << std::this_thread::get_id() << endl;
	//thread t(talk, i, A(j));
	//thread t(talk, i, j);
	//t.join();
	//cout << "main end" << endl;

	//cout<<
	//while (1) { ; }

	//2、传递类对象，智能指针

	//A obj(10);
	//thread t(talk, i, obj);
	//thread t(talk, i, std::ref(obj));//主，子线程同共指向同一块内存地址
	//t.join();

	//cout << obj._i << endl;

	//unique_ptr<int> p(new int(100));

	//thread t(say, std::move(p));//同样的指向同一块内存，容易出问题使用detach

	//if (p == nullptr) {
	//	cout << "p null" << endl;
	//}

	//t.detach();

	//3、将类成员作为线程的初始函数
	//A obj(10);

	//thread t(&A::worker, obj, 100);//产生了拷贝构造

	//void (A:: * p)(int um) = &A::worker;

	//(obj.*p)(1000);
	//t.join();

	A obj(10);

	//thread t(obj, 1000);//产生了拷贝构造
	thread t(std::ref(obj), 500);
	t.join();


	cout << "main thread::" << std::this_thread::get_id() << endl;

	return 0;
}