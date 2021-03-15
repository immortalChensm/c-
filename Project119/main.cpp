#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional> //stpl 组成部分里的仿函数对象
//https://zh.cppreference.com/w/cpp/container#.E9.A1.BA.E5.BA.8F.E5.AE.B9.E5.99.A8 
//各种容器类模板相关成员函数
using namespace std;

class A {
public:
	int m_i;
	A(int x) :m_i(x)
	{
		cout << "A()" << endl;
	}
	A(const A& obj):m_i(obj.m_i)
	{
		cout << "A(const A&obj)" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	bool operator <(A o) const {
		//return true;
		return m_i < o.m_i;
	}
};
namespace test1
{
	void func()
	{

		queue<A> obj;
		obj.push(A(1));
		obj.push(A(2));
		obj.push(A(3));

		cout << obj.size() << endl;

		cout << obj.front().m_i << endl;
		cout << obj.front().m_i << endl;

		A obj1 = obj.front();
		cout << obj1.m_i << endl;

		/*for (int i = 0; i < obj.size(); i++)
		{
			obj.pop();
			cout << "数据："<<obj.front().m_i << endl;
		}*/
	}
}
namespace test2
{
	
	
	void func()
	{
		list<A> obj;
		obj.push_front(A(1));
		obj.push_front(A(2));
		obj.push_front(A(3));


		//obj.pop_front();
		//obj.pop_back();
		auto itr = obj.begin();
		itr++;
		obj.erase(itr);

		for (auto itr = obj.begin(); itr != obj.end(); itr++)
		{
			cout << itr->m_i << endl;
		}
	}
}
namespace test3
{
	void func()
	{
		set<A> obj;
		obj.insert(A(1));
		obj.insert(A(2));
		obj.insert(A(3));
		obj.insert(A(3));

		for (auto itr = obj.begin(); itr != obj.end(); itr++) {
			cout << itr->m_i << endl;
		}
	}
}
namespace test4
{
	void func()
	{
		//分配器  内存分配
		std::allocator<int> alloc;
		int* p = alloc.allocate(3);
		int* q = p;
		*q = 1; q++;
		*q = 2; q++;
		*q = 3;
		cout << *p << *(p + 1) << *(p + 2) << endl;

		alloc.deallocate(p,3);

		list<int, std::allocator<int>> obj;
		obj.push_back(1);
		obj.push_back(2);
		obj.push_back(3);

		for (auto itr = obj.begin(); itr != obj.end(); itr++)
		{
			cout << *itr << endl;
			printf("%p\n",&(*itr));
		}
		
	}
}
namespace test5
{
	void func()
	{
		vector<int> obj = { 1,2,3,4,5 };
		vector<int>::iterator itr = obj.begin();
		for (; itr != obj.end(); itr++) {

			cout << *itr << endl;
			*itr = *itr + 10;
		}

		for (auto x = obj.begin(); x != obj.end(); x++) {
			cout << *x << endl;
		}
	}
}
namespace test6
{

	class B {
	public:
		bool operator()(int x, int y) {
			return x > y;
		}
	};
	void func()
	{

		//vector<int> obj = { 6,3,2,4,1,5 };
		//list<int> obj = { 6,3,2,4,1,5 };
		map<int, std::string> obj;
		obj.insert(std::make_pair(1,"ok1"));
		obj.insert(std::make_pair(3,"ok2"));
		obj.insert(std::make_pair(2,"ok3"));


		auto x = obj.find(2);
		if (x!=obj.end()) {
			cout << x->first << x->second << endl;
		}

		/*sort(obj.begin(),obj.end(),B());
		for_each(obj.begin(), obj.end(), [](int v) {
			cout << v << endl;
			});


		auto result = find(obj.begin(),obj.end(),5);
		if (*result) {
			cout <<"findout:"<< *result << endl;
		}


		auto xret = find_if(obj.begin(), obj.end(), [](int v) {
			if (v == 3) {
				return v;
			}
		});

		if (*xret) {
			cout <<"find_if:"<< *xret << endl;
		}*/
	}
}
namespace test7
{
	template<typename T>
	class A {
	public:
		bool operator()(T x, T y)
		{
			return x > y;
		}
	};
	void func()
	{

		vector<int> obj = { 1,5,6,3,2,8,9,55 };

		//sort(obj.begin(),obj.end(),A<int>());
		//sort(obj.begin(),obj.end(),greater<int>());//使用仿函数  系统内置类对象
		sort(obj.begin(),obj.end(),less<int>());//使用仿函数  系统内置类对象

		for (auto itr = obj.begin(); itr != obj.end(); itr++) {

			cout << *itr << endl;
		}

		
		int x = greater<int>()(300,200);

		cout << x << endl;

	}
}
namespace test8
{
	//适配器  在已有的容器，分配器，迭代器，算法上增加或减少一些代码
	class A {
	public:
		bool operator()(int v) {
			return 10 < v;
		}
	};
	void func()
	{

		vector<int> obj = { 1,2,3,4,5,10,200,500,666,5,5 };

		int x = count(obj.begin(),obj.end(),5);

		cout << x << endl;

		//int y = count_if(obj.begin(),obj.end(),A());
		int y = count_if(obj.begin(),obj.end(),bind(less<int>(),10,std::placeholders::_1));
		//less<int>()  == bool operator()(10,_1)
		cout << y << endl;


		for (vector<int>::reverse_iterator itr = obj.rbegin(); itr != obj.rend(); itr++) {

			cout << *itr << endl;
		}
	}
}
namespace test9
{
	//对象所占用的空间大小
	class A {
	public:
		int x;
		void func() {

		}
		static void test()
		{

		}
		virtual void bb()
		{

		}
		char y;
	};

	void func()
	{
		//A *obj = new A();
		A obj;
		int x = sizeof(obj);

		cout << x << endl;

		int* y;
		int* j;
		cout << sizeof(y) << endl;
		cout << sizeof(char*) << endl;
		cout << sizeof(A *) << endl;
	}
}
namespace test10
{
	class A {
	public:
		int a;
		A()
		{
			cout << "A::A() this=" << this << endl;
		}
		void funcA()
		{
			cout << "A::funcA() this=" << this << endl;
		}
	};
	class B {
	public:
		int b;
		B()
		{
			cout << "B::B() this=" << this << endl;
		}
		void funcB()
		{
			cout << "B::funcB() this=" << this << endl;
		}
	};

	class C :public A,public B {
	public:
		int c;
		C()
		{
			cout << "C::C() this=" << this << endl;
		}
		void funcC()
		{
			cout << "C::funcC() this=" << this << endl;
		}
		void funcB()
		{
			cout << "C::funcB() this=" << this << endl;
		}
	};

	void func()
	{
		//this 指针调整
		cout << sizeof(A) << endl;
		cout << sizeof(B) << endl;
		cout << sizeof(C) << endl;

		C obj;
		obj.funcA();
		obj.funcB();
		obj.funcC();

	}
}
namespace test11
{
	class A {
	public:
		A()
		{
			cout << "A::A" << endl;
		}
	};

	class X {
	public:
		int a;
		int b;
		void func()
		{
			cout << "X::func" << endl;
		}
	};
	void func()
	{
		X obj;
	}
}
namespace test12
{
	/*class A {
	public:
		A() {
			int x = 10;
		}
	};
	class B :public A {

	};*/
	/*class Grand
	{
	public:
	};
	class A :virtual public Grand {

	};
	class A2 :virtual public Grand
	{

	};
	class C :public A, public A2 {

	};*/
	class A {

	};
	class B :public A {
	public:
		virtual void test()
		{
			int x = 100;
		}
	};
	void func()
	{
		//B obj;//会合成B 构造函数
		//0C8D71C  mov         dword ptr [eax],offset test12::C::`vbtable' (0CB3068h)  
		//00C8D722  mov         eax, dword ptr[this]
		//00C8D725  mov         dword ptr[eax + 4], offset test12::C::`vbtable' (0CB30B0h)
		//  test12::A::A (0C85B95h)  
		// test12::A2::A2 (0C8610Dh)  
		//C obj;
		B obj;

	}
}
namespace test13
{
	//拷贝构造函数合成情况测试
	//class A {
	//public:
	//	A(const A& obj) {
	//		cout << "A copy func" << endl;
	//	}
	//	A()
	//	{

	//	}
	//};
	//class B//:public A 
	//{
	//public:
	//	int x;
	//	//A obj;
	//	//virtual void test() {

	//	//}

	////};
	class Grand
	{
	public:
		Grand()
		{
			cout << "Grand::grand" << endl;
		}
	};
	class A :virtual public Grand {

	};
	class A1 :virtual public Grand {

	};
	class C :public A, public A1 {

	};
	void func()
	{
		//B obj;
		//B obj1 = obj;
		C obj;
		C obj1 = obj;
	}
}
namespace test14
{
	class X {
	public:
		int i;
		X(const X& obj) {
			i = obj.i;
			cout << "X copy function" << endl;
		}
		X() {
			cout << "x FUNCTION" << endl;
		}
		~X() {
			cout << "~X FUNCTION" << endl;
		}
		void show()
		{
			cout << "x::show function" << endl;
			cout << i << endl;
		}
	};
	/*X funx(X obj) {
		X objx;
		objx.i = obj.i;
		return objx;
	}*/
	void funx(X& obj) {

		X objx;
		objx.i = 101;
		obj.X::X(objx);
	}
	void func()
	{

		X obj;
		obj.i = 100;

		//X objx = funx(obj);
		//funx(obj);

		//obj.show();
		(funx(obj), obj).show();
		

		//X obj1 = obj;
		//X obj1;
		//obj1.X::X(obj);
	}
}
int main()
{
	test14::func();
	return 0;
}