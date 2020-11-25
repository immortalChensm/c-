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
namespace test12
{
	void func()
	{
		const int a = 3;
		int x = 55;
		//constexpr int j = x;
		//cout << a << j << endl;

		int& y = x;
		y = 100;
		cout << x << y << endl;
	}
}
namespace test13
{
	void func()
	{

		int x[]{ 1,2,3,4,5 };
		for (auto& y : x) {
			cout << y << endl;
		}

		int* p = new int{ 10 };
		cout << *p << endl;

		int* z = new int[3];
		*(z++) = 100;
		*(z++) = 200;
		cout << *(z + 1) << endl;

		delete p;
		delete[] z;

		cout << typeid(NULL).name() << endl;
		cout << typeid(nullptr).name() << endl;
	}
}
namespace test14
{
	void func()
	{

		int* z = new int[5];
		//*z++ = 0;
		//z[0] = 9;
		//*z++ = 10;
		//*z++ = 10;
		//cout << *z << endl;
		if (z != nullptr) {
			int* z1 = z;
			*z1++ = 10;
			*z1++ = 20;
			cout << *z << endl;
			cout << *(z+1) << endl;
			delete[] z;
		}
		

		

	}
}
namespace test15
{
	struct stdx {

		int age;
		char name;
		void show()
		{
			age = 100;
			name = 'c';
			cout << name << this->age << endl;
		}
	};
	void func()
	{

		stdx* obj = new stdx();
		obj->show();

	}
}
namespace test16
{

	void func()
	{
		std::string s1 = "china";
		std::string s2("japanese");
		std::string s3 = { "ok" };
		//std::string s4 = ("hello");

		if (s1.empty()) {
			cout << "emp" << endl;
		}
		cout << s1.size() << endl;
		cout << s1.length() << endl;

		
		cout << s1[3] << endl;

		cout << s1 + s2 << endl;

		s3 = s2;


	}
}
namespace test17
{
	class A {
	public:
		//typename int jj;
		using baba = int;

	};
	class B {
	public:
		int x = 0;
	};
	void func()
	{
		A obj;
		A::baba tt = 100;
		cout << tt << endl;

		std::vector<int> x1 = { 1,2,3,4 };
		std::vector<int> x2(10, 2);

		std::vector<string> x3 = { "h","x" };
		std::vector<string> x4 = { 4,"hello" };

		for (auto j : x1) {
			cout << j << endl;
		}
		for (auto j : x2) {
			cout << j << endl;
		}
		for (auto j : x3) {
			cout << j << endl;
		}
		for (auto j : x4) {
			cout << j << endl;
		}

		std::vector<string> x5(x4);

		x5.push_back("china");
		for (auto j : x5) {
			cout << j << endl;
		}

		cout << "*************************" << endl;

		if (x5 != x3) {
			cout << "x5!=x3" << endl;
		}
		cout << x5.size() << endl;
		x5.clear();
		cout << x5.size() << endl;

		/*for (auto j : x3) {
			cout << j << endl;
			if (j == "h") {
				x3.push_back("bb");
				x3.pop_back();
			}
		}*/
		cout << "remove************" << endl;
		auto itr = std::find(x3.begin(),x3.end(),"h");
		cout << typeid(itr).name() << endl;
		//cout << typeid(itr).hash_code() << endl;

		itr->assign("jack");
		itr->erase();
		//cout << itr->c_str() << endl;
		//x3.erase(itr);
		for (auto j : x3) {
			cout << j << endl;
			
		}

		for (std::vector<string>::iterator itr = x3.begin(); itr != x3.end(); itr++) {

			cout << itr->data() << endl;
		}

		
	}
	void func1()
	{

		//vector<int> obj = { 1,2,3,4,5 };

		//vector<int>::iterator itr;
		//vector<int>::reverse_iterator itr;
		//vector<int>::const_iterator itr;
		vector<B> obj;
		B k,s;
		k.x = 100;
		obj.push_back(k);
		obj.push_back(s);
		for (auto itr = obj.cbegin(); itr != obj.cend(); itr++) {

			//*itr = *itr * 10;
			cout << itr->x<< endl;
		}
		auto itr = obj.begin();

		obj.erase(itr);

		for (auto itr = obj.cbegin(); itr != obj.cend(); itr++) {

			
			cout << itr->x << endl;
		}
	}
}
int main()
{
	test17::func1();
	return 0;
}