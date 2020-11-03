#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
using namespace std;

namespace test
{
	//实现无法继承的类：友元+虚继承
	class A {
	private:
		A()
		{
			cout << "a" << endl;
		}
		friend class B;
	};
	//class B :public A {//B能调用A就是因为友元
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
		//C obja;//C 无法继承
	}
}
namespace test1
{
	//调用类私有成员
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
	void func(T&& x) {//可以接左值，右值  万能引用
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
		//func<int>(30);//万能引用：T&& 必须由编译器自行推断
		A<int> obj;
		obj.show(3);
	}
}
namespace test5
{

	void show(int& i)
	{
		cout << "左值i" << i << endl;
	}
	void show(int&& i)
	{
		cout << "右值i" << i << endl;
	}

	template<typename T>
	void test(T&& x)//万能引用 会存在引用折叠规则
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
int main()
{
	test8::func();
	return 0;
}