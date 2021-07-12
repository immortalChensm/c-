#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class A {
public:
	mutable int m_i;
	A(int a) :m_i(a) {
		cout << "[A()]thread id=" << std::this_thread::get_id() << "this=" << this << endl;
	}
	A(const A& obj) :m_i(obj.m_i) {
		cout << "[A(const A& obj)]thread id=" << std::this_thread::get_id() << "this=" << this << endl;
	}
	~A() {
		cout << "[~A()]thread id=" << std::this_thread::get_id() << "this=" << this << endl;
	}

	void my_worker(int x) {
		cout << "[my_worker子线程]thread id=" << std::this_thread::get_id() << "this=" << this << endl;
	}

	void operator()(int x) {
		cout << "[operator子线程]thread id=" << std::this_thread::get_id() << "this=" << this << endl;
	}
};
//void test(int x, const string& t) {
//
//	cout << "start" << endl;
//	cout << "start" << endl;
//	cout << "start" << endl;
//	cout << "start" << endl;
//	cout << "start" << endl;
//	cout << x << t.c_str() << endl;
//
//	cout << "end" << endl;
//
//}
//void test(A &obj) {
//	obj.m_i = 99;
//	cout << "[test子线程]thread id=" << std::this_thread::get_id() << "this=" << &obj << endl;
//	return;
//}
void test(const int& x, char* j) {
	cout << x << endl;
}
int main()
{

	int myv = 100;
	char x[] = "china";
	cout << "[main]thread id=" << std::this_thread::get_id() << endl;
	thread myobj(test, myv, x);
	//A obj(100);
	//thread myobj(test,std::ref(obj));
	//A obj(101);
	//thread myobj(&A::my_worker,obj,10);
	//thread myobj(obj,90);

	myobj.detach();

	//cout << "main obj.m_i="<<obj.m_i << endl;

	/*while (1) {
		;
	}*/
	

	return 0;
}