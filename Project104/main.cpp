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

			cout << "x ���� B��" << endl;
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
int main()
{
	test30::func();
	int x{ 10 };
	int y(10);
	int z = { 10 };
	int y1 = (10);
	
	int y3 = { (101) };
	int{};
	double();

	return 0;
}