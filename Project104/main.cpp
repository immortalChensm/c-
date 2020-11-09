#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
#include <initializer_list>
#include <stdarg.h>
using namespace std;

namespace test
{
	//ʵ���޷��̳е��ࣺ��Ԫ+��̳�
	class A {
	private:
		A()
		{
			cout << "a" << endl;
		}
		friend class B;
	};
	//class B :public A {//B�ܵ���A������Ϊ��Ԫ
	class B:virtual public A{
		public:
			int _x;
	};

	class C :public B {

	public :
		int _y;
	};

	void func()
	{
		B obj;
		//C obja;//C �޷��̳�
	}
}
namespace test1
{
	//������˽�г�Ա
	class A {

	private:
		virtual void show()
		{
			t();
		}
		void t()
		{
			cout << "t" << endl;
		}
	};

	void func()
	{
		A obj;//0x01 = 0x02 = vtable[]
		long* x = (long*)&obj;
		long* y = (long*)*x;

		using Func = void (*)();

		Func fx = (Func)y[0];

		fx();


	}
}
namespace test2
{
	void test(int y=0)
	{
		cout << "test" << endl;
	}
	class A {
	public:
		void operator()(int x) {
			cout << x << endl;
		}
	};
	void func()
	{
		std::function<void(int)> f1 = A();
		std::function<void(int)> f2 = test;

		f1(2);
		f2(2);

		std::map<std::string, std::function<void(int)>> obj;
		obj["a"] = A();
		obj["b"] = test;

		void (*p)(int);

		p = test;

		obj["a"](100);
		obj["b"](200);

		p(500);

	}
}
namespace test3
{

	template<typename T>
	void func(T&& x) {//���Խ���ֵ����ֵ  ��������
		cout << x << endl;
	}
	template <typename T>
	class A {
	public:
		void show(T&& x) {
			cout << x << endl;
		}
	};
	void s()
	{
		int j = 100;
		//func<int>(30);//�������ã�T&& �����ɱ����������ƶ�
		A<int> obj;
		obj.show(3);
	}
}
namespace test5
{

	void show(int& i)
	{
		cout << "��ֵi" << i << endl;
	}
	void show(int&& i)
	{
		cout << "��ֵi" << i << endl;
	}

	template<typename T>
	void test(T&& x)//�������� ����������۵�����
	{
		show(x);
		show(std::forward<T>(x)); 
		show(std::move(x));
	}

	void func()
	{
		//test(100);
		int j = 10;
		test(j);
	}
}
namespace test6
{

	void test(){
		cout << "test" << endl;
	}

	class A {
	public:
		int operator()()
		{
			return 100;
		}
	};
	class N {
	public:
		double operator()()
		{
			return 10.23f;
		}
	};
	template<typename T>
	auto testx(void) {
		auto v = T()();
		
		return v;
	}
	void func()
	{
		auto x = 10;
		auto& y = x;
		auto* z = &y;
		auto f1 = test;
		auto f2 = test;
		f1();
		f2();

		std::map<string, int> obj;
		obj["a"] = 1;
		obj["b"] = 2;
		obj["c"] = 3;

		std::map<string, int>::iterator itr;
		for (itr = obj.begin(); itr != obj.end(); itr++) {

			cout << itr->first << itr->second << endl;
		}

		for (auto x = obj.begin(); x != obj.end(); x++) {
			cout << x->first << x->second << endl;
		}

		cout << N()() << endl;

		cout << testx<A>() << endl;
		cout << testx<N>() << endl;
		
	}
}
namespace test7
{
	template<typename T>
	class O {
	public:
		typename T::iterator itr;
		//decltype(T().begin()) itr;
		void getItr(T& tmp)
		{
			itr = tmp.begin();
		}
	};
	template<typename T>
	class O<const T>
	{
	public:
		typename T::const_iterator itr;
		
		void getItr(const T& tmp)
		{
			itr = tmp.begin();
		}
	};
	int show()
	{
		cout << "show" << endl;
		return 1;
	}

	int x1(int x) {
		cout << "int x1" << endl;
		return x + 1;
	}
	double x1(double x) {
		cout << "double x1" << endl;
		return x + 1.24f;
	}

	template<typename T>
	auto a(T& tv)->decltype(x1(tv)) {

		return x1(tv);
	}

	decltype(auto) bbc(int &x) {

		return (x );
	}

	class C {
	public:
		void show()
		{
			cout << "c show" << endl;
		}
		decltype(auto) begin()
		{
			return 0;
		}
	};
	void func()
	{
		//int j = 10;
		//bbc(j) = 200;
		//cout << j << endl;

		//C().show();
		decltype(C().begin()) j = 100;
		cout << j << endl;
		//int j = 10;
		//cout << a(j)<<endl;
		/*int x = 10;
		decltype(x) y = 10;

		decltype(10) j = 102;
		cout << j << endl;

		decltype((100)) k = y;
		y = 22;
		cout << k << endl;
		cout << y << endl;

		decltype(show()) funcx = 10;*/
		//funcx();
		//show();

		//decltype(show) fun;
		//cout<<fun()<<endl;
		/*std::function<decltype(show)> fun1 = show;
		cout<<fun1()<<endl;

		cout << "******************" << endl;
		using arr = const std::vector<int>;
		arr x1 = { 1,2,3 };
		O<arr> yobj;
		yobj.getItr(x1);*/
	}
}
namespace test8
{


	void a(int x)
	{
		cout << "a" <<x<< endl;
	}
	void b(int j,std::function<void(int)> f)
	{
		f(j);
	}
	class A {
	public:
		/*void show()
		{
			cout << "A::show" << endl;
		}
		void operator()()
		{
			cout << "A::operator()" << endl;
		}*/

		/*static int p() {
			cout << 1000 << endl;
			return 1;
		}
		using x = int(*)(void);
		operator x() {
			return p;
		}*/

		void showa(int &x,int &y)
		{
			cout << "show a" << x<<y<<endl;
			x++;
			y++;
		}

		int _x;
	};

	void func()
	{
		A obj;

		std::function<void(int)> f1 = std::bind(a,std::placeholders::_1);

		b(10,f1);

		auto  f2 = std::bind(b, std::placeholders::_1, std::placeholders::_2);

		f2(100,a);

		[]() {
			cout << "123" << endl;
		}();
		obj._x = 22;
		[&] {
		
			cout << obj._x << endl;

		}();
		static int jj = 100;
		[&]()->A {
			
			cout << "objx obj" <<jj<< endl;
			return obj;
		}();

		/*std::function<int& (void)> f1 = std::bind(&A::_x,&obj);
		f1() = 100;

		cout << obj._x << endl;*/

		/*int a1 = 10, a2 = 20;
		auto f1 = std::bind(&A::showa,obj,std::placeholders::_1,a1);
		f1(a2);

		cout << a1 << a2 << endl;

		std::function<void(int, int)> f2 = std::bind(&A::showa,&obj,a1,a2);
		f2(a1,a2);*/


		//void (A:: * b)(void) = &A::showa;
		//A obj;
		//(obj.*b)();
		//std::function<void(void)> f1 = a;
		//f1();

		/*A obj;
		std::function<void(void)> f2 = obj;
		f2();*/
		//A obj;
		//std::function<int(void)> f3 = obj;
		//f3();
	}
}
namespace test9
{
	void func()
	{

		std::function<int(int)> f1 = [](int v) {

			return v + 10;
		};

		cout << f1(100) << endl;

		int j = 10;
		auto f2 = [=](int v) mutable{

			j = 1020;
			cout << v << endl;
		};

		f2(1000);
		cout << j << endl;

		std::function<int(int)> f3 = std::bind([](int v) {
			cout << v << endl;
			return v;
		},888);

		f3(2);

		cout << "***************" << endl; 

		vector<int> ks = { 1,2,3,4,5 };

		for_each(ks.begin(), ks.end(), [](int k) {

			cout << k << endl;
			});

		auto result = find_if(ks.begin(), ks.end(), [](int k) {
		
			cout << k << endl;

			if (k > 2) {
				return true;
			}
			return false;
		});

		if (result != ks.end()) {

			cout << "find elem\r\n";
		}
		else {
			cout << "not found\r\n";
		}
	}
}
namespace test10
{
	std::vector<std::function<bool(int)>> gv;
	void myfunc()
	{

		static int c = 10;
		gv.push_back([a=c](int v) {
			
			cout << "v=" << v << endl;
			cout << "c=" << c << endl;
			cout << "a=" << a << endl;
			return true;
		});
		c++;

	}
	class A
	{
	public:
		int _x = 100;
		void addItem()
		{
			gv.push_back([y=_x](int v) {

				cout << "x=" << y << endl;
				return true;
			});
		}
	};

	void func()
	{
		//myfunc();
		//gv[0](100);

		A* obj = new A();
		obj->addItem();
		delete obj;
		gv[0](101);
	}
}
namespace test11
{
	void test(std::initializer_list<std::string> args)
	{
		for (auto beg = args.begin(); beg != args.end(); ++beg)
		{
			cout << (*beg).c_str() << endl;
		}

		cout << args.size() << endl;

		for (auto itr : args) {
			cout << itr.c_str() << endl;
		}
	}

	class A {
	public:
		explicit A(std::initializer_list<int> args) {

			for (auto x : args) {
				cout << x << endl;
			}
		}
	};
	int sum(int num, ...)
	{
		va_list valist;
		va_start(valist,num);

		int t = 0;

		for (int i = 0; i < num; i++) {

			t+=va_arg(valist, int);
		}
		va_end(valist);
		return t;

	}
	void func()
	{
		test({ "a","b","c" });
		A obj{ 1,2,3 };
		//A obj1 = { 10,20,30 };

		cout << sum(2,100,200) << endl;
	}
}
int main()
{
	test11::func();
	return 0;
}