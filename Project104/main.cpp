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
		B k,s,j;
		k.x = 100;
		j.x = 101;
		obj.push_back(k);
		obj.push_back(s);
		obj.push_back(j);
		for (auto itr = obj.cbegin(); itr != obj.cend(); itr++) {

			//*itr = *itr * 10;
			cout << itr->x<< endl;
		}
		auto itr = obj.begin();
		itr++;
		
		obj.erase(itr);

		for (auto itr = obj.cbegin(); itr != obj.cend(); itr++) {

			
			cout << itr->x << endl;
		}
	}
}
namespace test18
{
	void func()
	{
		std::vector<int> obj = { 1,2,3,4,5 };
		
		while (!obj.empty()) {

			auto itr = obj.begin();
			obj.erase(itr);
		}

		std::string str("china is ok");

		for (auto itr = str.begin(); itr != str.end(); ++itr) {
			*itr = toupper(*itr);
		}
		cout << str << endl;


	}
	void func1()
	{

		float x = 10;
		int j = static_cast<int>(x);
		cout << j << endl;

	class A { public:int x = 105; };
		class B:public A{};

		B obj1;
		A obj2 = static_cast<A>(obj1);

		/*float a1 = 32.34f;
		float* a2a = &a1;
		double *a2 = static_cast<double*>(a2a);*/

		const int* p = &j;

		int* y1 = const_cast<int*>(p);
		cout << *y1 << endl;


		int* z = reinterpret_cast<int*>(y1);
		cout << *z << endl;

		//int *x = dynamic_cast<int*>(z);
		//cout << x << endl;

		A *obj3 = dynamic_cast<A*>(&obj1);
		cout << obj3->x << endl;

	}
}
namespace test19
{
	class A {

	public:
		int _x;
		int _y;
		A(int x, int y) :_x(x), _y(y) {

		}
		//explicit A(int x)
		 A(int x)
		{
			_x = x;
		}
		A()
		{
			_x = 0;
			_y = 0;
		}
	};
	void test(A obj)
	{
		cout << obj._x << endl;
		return;
	}
	void func()
	{
		/*A obj{ 1,2 };
		A obj1(1, 2);
		A obj2 = { 1,2 };
		A obj3 = A(2, 3);*/
		//A obj = 2;
		test(666);

	}
}
namespace test20
{
	//class A {
	//public:
	//	//mutable int x = 0;
	//	const int x = 0;
	//	/*void test(int y) const {
	//		x = y;
	//		cout << x << endl;
	//	}*/
	//	void test(int y) const;
	//	static int j;
	//	static void show()
	//	{
	//		cout << "a" << endl;
	//	}
	//	inline void display()
	//	{
	//		cout << "inline" << endl;
	//	}
	//	A& getx(int x) {
	//		//this->x = x;
	//		return *this;
	//	}
	//};
	//void A::test(int y) const
	//{
	//	x = y;
	//	cout << x << endl;
	//}
	//int A::j = 88;

	//void func()
	//{
	//	A obj;
	//	obj.test(10);

	//	const A obj1;
	//	obj1.j = 888;
	//	//obj1.x = 100;
	//	obj1.test(100);

	//	cout << obj.j << endl;
	//	cout << obj1.j << endl;
	//	cout << A::j << endl;

	//}
}
//namespace test21
//{
//
//	class A {
//
//	public:
//		int i{ 10 };
//		/*A() {
//			cout << i << endl;
//		}
//		A(int x) :i(x) {
//			cout << i << endl;
//		}*/
//		//A() = default;
//		A() = delete;
//	};
//	void func()
//	{
//		//A obj;
//		//A obj1(100);
//	}
//}
//namespace test22
//{
//	
//	class N {
//	public:
//		int y;
//		N() {
//			cout << "call N()" << endl;
//		}
//		N(const N& obj) {
//			this->y = obj.y;
//			cout << "call N(const N& obj)"<<this->y << endl;
//		}
//	};
//	class A {
//
//	public:
//		int _x;
//		N obj;
//		A() {
//			cout << "call A()" << endl;
//		}
//		A(int x) :_x(x) {
//			cout << "call A(int x)" << endl;
//		}
//		A(const A& obj) {
//			_x = obj._x;
//			this->obj = obj.obj;
//
//			cout << "call A(const A& obj)"<<_x<< endl;
//		}
//	};
//
//	A& func1(A obj)
//	{
//		A obj2;
//		obj2._x = 100;
//		obj2.obj.y = 101;
//
//		return obj2;
//	}
//	void func()
//	{
//		/*A obj;
//
//		A obj1 = 2;
//		A obj2 = { 2 };
//		A obj3 = (2);
//
//		cout << "************" << endl;
//
//		A obj4 = obj3;
//		A obj5 = { obj3 };
//		A obj6 = { obj3 };*/
//		A obj;
//		obj._x = 100;
//		obj.obj.y = 101;
//		//A obj1 = obj;
//
//		A objx = func1(obj);
//
//
//	}
//}
namespace test23
{
	class A {
	public:
		int x = 0;
		char* p=nullptr;
		A()
		{
			cout << "A" << endl;
			p = new char[10]();
		}

		A(A& obj) {
			x = obj.x;
			//p = obj.p;
			//memcpy(p,obj.p,sizeof(obj.p));
			cout << "copy" << endl;
		}
		
		A& operator=(A& obj) {
			this->x = obj.x;
			//this->p = obj.p;
			cout << "A& operator=(A& obj) x=" << this->x << endl;
			return *this;
		}
		~A()
		{
			cout << "~A" << endl;
			if (p) {
				delete[]p;
			}
			
		}
	};

	void func()
	{
		A obj;
		A obj1 = obj;
		//A obj1;
		//obj1 = obj;
		/*obj.x = 10;
		A obj1 = obj;
		

		A obj2;
		obj2 = obj1;*/

	}
}
namespace test24
{

	class A {
	public:
		A()
		{
			cout << "A" << endl;
		}

		void show()
		{
			cout << "A::show" << endl;
		}
		void show(int) {
			cout << "A::show(int)" << endl;
		}
	};

	class B :public A {
	public:
		B()
		{
			cout << "B" << endl;
		}
		void show()
		{
			A::show();
			cout << "B show" << endl;
		}
		/*void show(int)
		{
			
			cout << "B show(int)" << endl;
		}*/
		using A::show;
	};
	void func()
	{
		B obj;
		obj.show(1);
	}
}
namespace test25
{
	class A {
	public:
		A()
		{
			cout << "A::" << endl;
		}
		/*virtual void show() final
		{
			cout << "A::show" << endl;
		}*/
		//virtual void show() = 0;
		virtual ~A()
		{
			cout << "~A::" << endl;
		}
	};
	class B:public A {
	public:
		B()
		{
			cout << "B::" << endl;
		}
		/*virtual void show() override
		{
			cout << "B::show" << endl;
		}*/
		~B()
		{
			cout << "~B::" << endl;
		}
	};
	class C :public A {
	public:
		C()
		{
			cout << "C::" << endl;
		}
		/*virtual void show() override
		{
			cout << "C::show" << endl;
		}*/
		~C()
		{
			cout << "~C::" << endl;
		}
	};
	void func()
	{
		A* obj = new B();
		//obj->show();

		//obj = new C();
		//obj->show();

		delete obj;
	}
}
namespace test26
{
	
	/*class B {
	private:
		void display()
		{
			cout << "b::display func" << endl;

		}
		friend class A;
	};
	class A {
	private:
		void show()
		{
			cout << "a::show func" << endl;
		}
		friend void test(A &obj);
	public:
		void haha(B &obj)
		{
			obj.display();
		}
	};
	void test(A& obj)
	{
		obj.show();
	}*/
	//class A;
	//
	//class B {
	//public:
	//	friend void A::show(B& obj);
	//	//friend class A;
	////private:
	//	void display()
	//	{
	//		cout << "b dis fumc" << endl;
	//	}
	//	
	//};
	//class A {
	//public:
	//	void show(B& obj)
	//	{
	//		obj.display();
	//	}
	//};
	//void func()
	//{

	//	/*A obj;
	//	test(obj);
	//	B objxl;
	//	obj.haha(objxl);*/
	//}
}
namespace test27
{

	class A {
	public:
		A()
		{
			cout << "A" << endl;
		}
		virtual void test()
		{

		}
	};
	class B :public A {
	public:
		B()
		{
			cout << "b" << endl;
		}
		void show()
		{
			cout << "b::show" << endl;
		}
	};
	void func()
	{

		A* obj = new B();

		//B* x = (B*)(obj);
		//x->show();

		B* x = dynamic_cast<B*>(obj);
		x->show();


		cout << typeid(x).name() << endl;
		cout << typeid(*x).name() << endl;
		cout << typeid(B).name() << endl;

		if (typeid(B) == typeid(*x)) {

			cout << "x 属于 B类" << endl;
		}

		const type_info &j = typeid(*x);

		cout << j.name() << endl;

	}
}
namespace test28
{
	//class A final{
	class A{
	public:
		int _x;
		A(int a):_x(a)
		{
			cout << "a" << endl;
		}
		A(const A& obj)
		{
			_x = obj._x;
			cout << "A(const A& obj)" << endl;
		}
		A& operator=(const A& obj)
		{
			_x = obj._x;
			cout << "A& operator=(const A& obj)" << endl;
			return *this;
		}
		void show()
		{
			cout << _x << endl;
		}
	};
	struct B :A {
		int j;
		B(int a,int b):j(a),A(b)
		{
			cout << "b" << endl;
		}
	};
	void func()
	{

		//A* obj = new B(1,2);
		/*B* obj = new B(10, 20);
		A* objx(obj);

		objx = obj;

		A* objy;
		objy = obj;

		objy = objx;*/


		A* obja = new A(10);
		A* objb(obja);

		objb->show();

		A* objc = obja;

		A objx = 1;

		A objy = objx;

		objy = objx;
		
	}
}
namespace test29
{
	void func()
	{
		int x = 10;
		int& y = x;

		const int& z = y;
		const int& j = 100;

		int&& y1 = 100;
		int&& z1 = x * 100;

		const int&& j1 = x*0;

		string ss = "china";
		string&& ss1 = std::move(ss);

		string&& ss2 = std::move(ss1);
	}
}
namespace test30
{
	class A {
	public:
		int a, b;
		A(int x=0, int y=0) :a(x), b(y) {
			cout << " call a" << endl;
		}
		A(const A& obj) :a(obj.a), b(obj.b) {
			cout << "call a copy" << endl;
		}

		A& operator=(const A& obj) {

			a = obj.a;
			b = obj.b;
			cout << "call a copy =" << endl;
			return *this;
		}

		~A()
		{
			cout << "call ~a" << endl;
		}
		int Add(A &obj) {

			int x = obj.a + obj.b;
			return x;
		}
	};

	A Double(const A& obj)
	{
		A objx;
		objx.a = obj.a + obj.b;
		return objx;
	}

	void func()
	{
		/*A obj;
		A obj1;
		obj = obj1;*/
		//A obj = 66;
		//A obj;
		//obj.Add(obj);

		/*A obj;
		A obj1;
		obj = obj1;*/

		//A obj;
		//obj = 1;

		A obj;
		Double(obj);
	}
}
namespace test31
{
	class A {
	public:
		int _a;
		A(int x = 100) :_a(x)
		{
			cout << "调用A普通构造函数" << endl;
		}
		A(const A& obj) :_a(obj._a) {
			cout << "调用A拷贝构造函数" << endl;
		}
		A& operator=(const A& obj) {
			cout << "调用A拷贝赋值函数" << endl;
			return *this;
		}
		A(const A&& obj)noexcept :_a(obj._a)  {
			cout << "调用A移动构造函数" << endl;
		}
		A& operator=(A&& obj) noexcept {
			cout << "调用A移动赋值函数" << endl;
			return *this;
		}
		virtual ~A()
		{
			cout << "调用A析构函数" << endl;
		}
	};
	class B {
	public:
		B() :obja(new A()) {
			cout << "调用B普通构造函数" << endl;
		}
		B(const B& obj) :obja(obj.obja)
		{
			cout << "调用B拷贝构造函数" << endl;
		}
		virtual ~B()
		{
			cout << "调用B析构函数" << endl;
		}
		A* obja;
	};
	static A test(A &obj)
	{
		A objx;
		return objx;
	}
	void func()
	{

		/*A obj;
		A* obj1 = new A(obj);
		delete obj1;


		B* obj2 = new B();

		B* obj3 = new B();

		obj3 = obj2;

		delete obj2;*/

		/*A obj;
		A obj1;
		obj1 = obj;

		obj1 = std::move(obj);

		A obj2(obj1);
		A obj3 = std::move(obj1);*/
		A objx;
		A obj = test(objx);

	}
}  
namespace test32
{
	class Grand
	{
	public:
		int _g;
		Grand(int x):_g(x)
		{
			cout << "G构造函数" << endl;
		}
		virtual ~Grand()
		{
			cout << "G析构函数" << endl;
		}
		void myinfo()
		{
			cout << _g << endl;
		}
	};
	class A :public virtual Grand
	{
	public:
		int _a;
		A(int x) :Grand(x), _a(x) {
			cout << "A构造函数" << endl;
		}
		virtual ~A()
		{
			cout << "A析构函数" << endl;
		}
		void myinfo()
		{
			cout << _a << endl;
		}
	};
	class A2 :public virtual Grand
	{
	public:
		int _a2;
		A2(int x) :Grand(x), _a2(x) {
			cout << "A2构造函数" << endl;
		}
		virtual ~A2()
		{
			cout << "A2析构函数" << endl;
		}
		void myinfo()
		{
			cout << _a2 << endl;
		}
	};
	class B
	{
	public:
		int _b;
		B()
		{
			cout << "B构造函数" << endl;
		}
		B(int x) :_b(x) {
			cout << "B构造函数x" << endl;
		}
		virtual ~B()
		{
			cout << "B析构函数" << endl;
		}
		void myinfo()
		{
			cout << _b << endl;
		}
	};
	//class C :public A,  public A2,public B
	class C :public B,public A,  public A2
	{
	public:
		int _c;
		//C(int x,int y,int z) :A(x), A2(x),B(y),_c(z) {
		C(int x,int y,int z) :A(x), A2(x),B(y),Grand(y),_c(z) {
		//C(int x,int y,int z) :A(x),_c(z) {
			cout << "C构造函数" << endl;
		}
		virtual ~C()
		{
			cout << "C析构函数" << endl;
		}
		void myinfo()
		{
			cout << _c << endl;
		}
	};

	class X {
	public:
		int x, y, z;
		X(int a,int b,int c):x(a),y(b),z(c)
		{

		}
		void show()
		{
			cout << x << y << z << endl;
		}
	};
	class Z {
	public:
		int x, y, z;
		Z(int a, int b, int c) :x(a), y(b), z(c)
		{

		}
		void show()
		{
			cout << x << y << z << endl;
		}
	};
	class Y:public X,public Z {
	public:
		using X::X;
		using Z::Z;
		Y(int a, int b, int c) :Z(a, b, c), X(a, b, c) {

		}
	};
	void func()
	{
		C test(10, 20,30);

		test.myinfo();

		//Y obj(1, 2, 3);
		//obj.show();
		//obj.X::show();  

		cout << "*******************" << endl;
		int a = 10;
		int* b = &a;
		*b = 100;
		cout <<"a=" <<a << "b="<<*b << endl;
		cout << "*******************" << endl;
	}
}
namespace test33
{
	class A {
	public:
		//typedef void(*point)(int);
		using point = void(*)(int);
		static void show(int x) {
			cout << "show:" << x << endl;
		}
		operator point() {
			return show;
		}
		int _a;
		A(int x) :_a(x) {

			cout << _a << endl;
		}
		
		operator int() const
		{
			return _a;
		}
	};
	void func()
	{
		//A obj = 1;

		//int k = obj;

		//cout << k << endl;

		A obj = 100;
		obj(1100);
		obj.operator test33::A::point()(888);

	}
}
namespace test34
{
	class A {
	public:
		A()
		{

		}
		void func()
		{
			cout << "func" << endl;
		}
		virtual void show()
		{
			cout << "virtual show" << endl;
		}
		static void disp()
		{
			cout << "static disp" << endl;
		}
		int _a;
		static int _b;
	};
	int A::_b = 10;
	void func()
	{
		A obj, * obj1;
		obj1 = &obj;

		void(A:: * f1)() = &A::func;
		void(A:: * f2)() = &A::show;
		void(*f3)() = &A::disp;

		int A::* var1 = &A::_a;
		int* x = &A::_b;

		(obj.*var1) = 10;
		*x = 100;
		cout << (obj.*var1) << *x << endl;

		(obj.*f1)();
		(obj.*f2)();

		(obj1->*f1)();
		(obj1->*f2)();
		
		f3();


		std::function<void()> f5 = std::bind(&A::func,&obj);
		//auto f5 = std::bind(&A::func,&obj);

		f5();

		
	}
}
namespace test35
{
	template<typename T,int a,int b>
	void show(T c)
	{
		T d = c + a + b;
		cout << d << endl;
	}
	template<typename T,class S>
	void disp(T a, S b) {
		cout << a << b << endl;
	}
	template<unsigned l1,unsigned l2>
	void pp(const char(&p)[l1], const char(&s)[l2]) {

		int x = strcmp(p,s);
		cout << x << endl;
	}
	template<int a,int b>
	void testss()
	{
		cout << a << b << endl;
	}
	void func()
	{
		show<int,1,2>(100);

		disp(100,"china"); 

		disp<int,std::string>(999,"like money");

		pp("test","testa");

		testss<1,2>();
	}
} 
namespace test36
{
	template<typename T>
	class A {
	public:
		typedef T* iterator;
		A()
		{

		}
		A& operator=(const A& obj);
		void show();
		iterator mybegin();
		iterator myend();
	};
	template<typename T>
	typename A<T>::iterator A<T>::mybegin()
	{

	}
	template<typename T>
	typename A<T>::iterator A<T>::myend()
	{

	}
	template<typename T>
	A<T>& A<T>::operator=(const A<T>& obj)
	{
		cout << "A===" << endl;
		return *this;
	}

	template<typename T>
	void A<T>::show()
	{
		cout << "A::show" << endl;
	}

	template<typename T,int size=10>
	class MyArr
	{
	public:
		T arr[size];
	};

	class tc
	{
	public:
		tc() { cout << "tc" << endl; }
		tc(const tc& obj) {

		}
		int operator()(int x, int y) {
			return x + y;
		}
	};
	int ok(int a, int b)
	{
		return 1;
	}

	typedef int(*Func)(int, int);

	template<typename T,typename F=tc>
	//void callok(int x, int y, Func f)
	void callok(T x, T y, F f=F())
	{
		cout << f(x, y) << endl;
	}
	template<typename T>
	typename T::size_type getLen(T str)
	{
		return str.size();
	}
	void func()
	{

		callok(10,20,ok);
		callok(10,30,tc());
		callok(100,200);

		std::string s = "test";
		cout << getLen(s) << endl;
		//A<int> obj;
		//obj.show();
		//A<int> obj1;
		//obj1 = obj;

		//MyArr<int, 100> xx;
		//MyArr<double> yy;
	}
}
namespace test37
{
	template<typename C>
	class A {
	public:
		template<typename T1,typename T2>
		A(T1 v1, T2 v2);

		template<typename T1,typename T2>
		void show(T1 a,T2 b);
		C _i;
	};

	template<typename C>
	template<typename T1, typename T2>
	A<C>::A(T1 v1, T2 v2)
	{
		cout << v1 << v2 << endl;
		_i = v1;
	}


	template<typename C>
	template<typename T1, typename T2>
	void A<C>::show(T1 a, T2 b)
	{
		cout << a << b << endl;
	}


	template A<int>;

	void func()
	{
		//A obj;
		//obj.show(10,20);

		A<int> obj(1,2);
		obj.show(100,200);

		A<float> obj1(1.2, 3.5);

	}
}
namespace test38
{

	template<typename T>
	struct m{
		typedef std::map<std::string, T> map_s;
	};

	template<typename T>
	using map_si = std::map<std::string, T>;

	//类型模板
	template<typename T>
	using map_fun = int(*)(T a,T b);

	template<typename T>
	int test(T a, T b)
	//int test(int a,int b)
	{
		cout << a + b << endl;
		return a;
	}
	void func()
	{
		m<int>::map_s m1;
		m1.insert({"first",1});

		map_si<int> m2;
		m2["second"] = 2;

		for (auto x : m2) {
			cout <<x.first<< x.second << endl;
		}

		map_fun<int> fun = test;
		//map_fun fun = test;

		test(10,20);
		fun(10,2);
	}
}
namespace test39
{
	template<typename T,typename U>
	class A {
	public:
		A()
		{
			cout << "模板泛化构造函数版本" << endl;
		}
		void show()
		{
			cout << "模板泛化show函数版本" << endl;
		}
	};
	template<>
	class A<int, int>
	{
	public:
		A()
		{
			cout << "模板int,int全特化构造函数版本" << endl;
		}
		void show()
		{
			cout << "模板int,int 全特化show函数版本" << endl;
		}
	};
	template<typename A,typename B,typename C>
	struct J {
		J()
		{
			cout << "模板J构造函数版本" << endl;
		}
		void show()
		{
			cout << "模板J show函数版本" << endl;
		}
	};
	template<typename B>
	struct J<int, B, char>
	{
		J()
		{
			cout << "模板J 偏特化数量上【局部】构造函数版本" << endl;
		}
		void show()
		{
			cout << "模板J 偏特化数量上【局部】 show函数版本" << endl;
		}
	};

	template<typename A,typename B,typename C>
	struct J<const A, B*, C&>
	{
		J()
		{
			cout << "模板J 偏特化 参数范围【局部】构造函数版本" << endl;
		}
		void show()
		{
			cout << "模板J 偏特化 参数范围【局部】 show函数版本" << endl;
		}
	};

	template <typename T,typename U>
	void ka(T a, U b) {
		cout << a << b << "函数泛化" << endl;
	}
	template<>
	void ka(int a, char b)
	{
		cout << a << b << "函数全特化" << endl;
	}
	void func()
	{
		//A<int,int> obj;
		//obj.show();

		J<int, char, double> obj;
		obj.show();

		J<int, char, char> obj1;
		obj1.show();

		J<const int, char*, char&> obj2;
		obj2.show();

		ka(1,2);
		ka(1,'b');
	}
}
namespace test40
{
	//可变参函数模板
	void show()
	{
		cout << "end show" << endl;
	}

	template<typename T,typename ...others>
	void show(T a, others...args)
	{
		//cout << sizeof...(T) << endl;
		cout << sizeof...(others) << a << endl;
		show(args...);
	}

	
	template<typename ...T>
	void show1(T...args)
	{
		cout << sizeof...(T) << endl;
		cout << sizeof...(args)  << endl;
	}
	//可变参类模板
	template<typename ...others> class myclass {}; 

	template<> class myclass<>
	{
	public:
		myclass()
		{
			cout << "empty myclass" << endl;
		}
	};
	template<typename T,typename ...others>
	class myclass<T,others...>:private myclass<others...>
	{
	public:
		myclass() :a(0)
		{
			cout << sizeof...(others) << "this="<<this << endl;
		}
		myclass(T x, others...args) :a(x), myclass<others...>(args...)
		{
			cout << a << endl;
		}
		T a;
	};
	void func()
	{

		//show(10,"china",23.4f);

		//show1(1,2,3,"bbb");

		//myclass<int, char, double> obj;
		myclass<int, char, double> obj(1,'a',123.34f);
	}
}
namespace test41
{
	void show()
	{
		cout << "end" << endl;
	}
	template<typename T,typename ...others>
	void show(T a, others...args)
	{
		cout << a << endl;
		show(args...);
	}

	template<typename...others> class myclass {};

	template<> class myclass<>
	{
	public:
		myclass()
		{
			cout << "empty" << endl;
		}
	};
	template <typename T,typename ...others>
	class myclass<T, others...> :private myclass<others...>
	{
	public:
		T x;
		myclass(T a, others...args) :x(a), myclass<others...>(args...)
		{
			cout << a << endl;
		}

	};
	void func()
	{
		show(1,2,3,"china");

		myclass<int, char, double> obj(1,'a',123.3f);
	}
}
namespace test42
{
	//模板  模板参数
	template<
		typename T,
		//template<class> class Container
		template<typename> typename Container
	>
	class myclass
	{
	public:
		T i;
		Container<T> obj;
		myclass()
		{
			for (int i = 0; i < 10; ++i)
			{
				obj.push_back(i);
			}

			for (int j = 0; j < 10; ++j)
			{
				cout << obj[j]<<endl;
			}
		}
	};

	template<typename T>
	using myVec = vector<T, allocator<T>>;
	void func()
	{

		myclass<int, myVec> obj;
	}
}
namespace test43
{
	class A {
	public:
		A()
		{
			cout << "A" << endl;
		
		}
		~A()
		{
			cout << "~A" << endl;
		}
	};
	void func()
	{


		/*int* a1 = new int();
		const int* a2 = new const int();

		auto* a3 = new auto(232);

		cout << *a3 << endl;
		cout << *a1 << endl;
		cout << *a2 << endl;  
		*/  

		int* p = new int[2];
		cout << sizeof(*p) << endl;

		delete[] p;

		A* pa = new A();
		cout << sizeof(pa) << endl;
		delete pa;
		A* pa1 = new A[2]();

		//delete pa1;
		delete[] pa1;

	}
}
namespace test45
{
	class A {
	public:
		A()
		{
			cout << "A" << endl;
		}
		~A()
		{
			cout << "~A" << endl;
		}
		void show()
		{
			cout << "show" << endl;
		}
	};
	void myfunc(shared_ptr<int> &tmp)
	{
		return;
	}
	void func()
	{
		/*std::shared_ptr<int> p(new int(100));
		cout << p << endl;
		cout << *p << endl;

		std::shared_ptr<string> p1 = std::make_shared<string>(5,'a');
		cout << *p1 << endl;

		auto p2 = std::make_shared<std::string>("china");
		cout << *p2 << endl;

		std::shared_ptr<A> p3(new A());
		p3->show();*/


		//auto p4 = make_shared<A>(new A());
		//p4->show();

		/*auto p1 = make_shared<int>(100);
		auto p2(p1);

		myfunc(p2);

		p2 = make_shared<int > (200);*/

		/*shared_ptr<int> p1 = make_shared<int>(100);

		if (p1.unique()) {
			cout << "只有p1单独指向该内存" << endl;
		}
		shared_ptr<int> p2(p1);

		cout << p2.use_count() << endl;

		if (p1.unique()) {
			cout << "只有p1单独指向该内存" << endl;
		}
		else {
			cout << "有多个对象指向该内存" << endl;
		}
		cout << *p2 << endl;
		cout << *p1 << endl;*/
		/*p2.reset(new int(1));
		if (p1.unique()) {
			cout << "只有p1单独指向该内存" << endl;
		}
		else {
			cout << "有多个对象指向该内存" << endl;
		}

		cout << *p2 << endl;
		cout << *p1 << endl;



		shared_ptr<int> p3;
		if (p3.unique()) {
			cout << "只有p2单独指向该内存" << endl;
		}
		else {
			cout << "没有对象指向该内存" << endl;
		}*/

		/*p3.reset(new int(10));
		if (p3.unique()) {
			cout << "只有p3单独指向该内存" << endl;
		}
		else {
			cout << "没有对象指向该内存" << endl;
		}*/  

		/*shared_ptr<int> p1(new int(1));
		if (p1.unique()) {
			cout << "p1单独指向该内存" << endl;
		}
		shared_ptr<int> p2(p1);
		cout << p2.use_count() << endl;

		p2 = nullptr;

		cout << p2.use_count() << endl;
		cout << p1.use_count() << endl;

		int* x = p1.get();
		*x = 100;
		cout << *x << endl;

		shared_ptr<int> a1(new int(100));
		shared_ptr<int> a2(new int(200));
		a2 = a1;

		a2.swap(a1);*/
		

		shared_ptr<int[]> p2(new int[10]);
		
		shared_ptr<int> p3(new int[10], default_delete<int[]>());
		
		shared_ptr<int[]> p4(new int[20](), [](int* p) {
			delete[]p;
		});
		
		/**p4 = 100;
		cout << *p4 << endl;
		*(p4 + 1) = 200;*/
		p4[0] = 199;
		p4[1] = 3;

		int* x = new int[10];
		x[0] = 1;
		x[1] = 2;
		cout << *x << endl;
		cout << x[1] << endl;
		cout << *(x+1) << endl;


	}
}
int main()
{
	test45::func();
	int x{ 10 };
	int y(10);
	int z = { 10 };
	int y1 = (10);
	
	int y3 = { (101) };
	int{};
	double();

	return 0;
}