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
namespace test15
{
	class X {
	public:
		int x, y;
		X(int a=0, int b=0) :x(a), y(b) {

			cout << "x constructor" << endl;
		}
		X(const X& obj) :x(obj.x), y(obj.y)
		{
			cout << "x copy constructor" << endl;
		}
		~X() {
			cout << "x destructor" << endl;
		}
	};
	X tempx(X& obj)
	{
		X temp;
		temp.X::X(obj.x*2,obj.y*2);
		return temp;

	}
	void func()
	{
		X obj(1, 2);
		X j = tempx(obj);
	}
}
namespace test16
{

	class X {
	public:
		int i;
		int* mi;
		X() {
			mi = new int(11);
			cout << "X " << endl;
		}
		X(const X& obj) {
			i = obj.i;
			mi = new int(0);
			memcpy(mi,obj.mi,sizeof(int));
			cout << "X(const X& obj)" << endl;
		}
		~X() {
			delete mi;
			cout << "~X" << endl;
		}
		X(int v) :i(v) {
			mi = new int(11);
			cout << "X(int v) :i(v)" << endl;
		}
	};
	void func()
	{

		/*X x1 = 1;
		X x2(2);
		X x3 = (X)100;
		X x4 = X(101);*/

		X x1(10);//x1,x2 的成员mi指向同一块内存，释放2次
		X x2(x1);
	}
}
namespace test17
{
	//成员初始化列表 在一定程序上（类类成员）会提升性能
	class X {
	public:
		int i;
		X(int a = 0) :i(a) {
			
			cout <<"this="<<this<<" X constructor " << endl;
		}
		X(const X& obj):i(obj.i) {
			cout << "this=" << this << " X(const X& obj) constructor " << endl;
		}
		X& operator=(const X& obj) {
			i = obj.i;
			cout << "this=" << this << " X& operator=(const X& obj) constructor " << endl;
			return *this;
		}
		~X() {
			cout << "~X" << endl;
		}
	};
	class Base {
	public:
		int x, y;
		Base(int a, int b) :x(a), y(b) {

		}
	};
	//class A:public Base {
	class A{
	public:
		int x;
		int& y;
		//Base obj;
		//A(int v) :y(v),obj(v,v) {
		//A(int v) :y(v),Base(v,v) {
		X obj;
		//A(int v) :y(v),obj(v) {
		A(int v) :y(v) {
			obj = 100;
			cout << "A 成员初始化列表" << endl;
		}
	};
	void func()
	{
		A obj(100);
	}
}
namespace test18
{
	//虚函数表的位置
	class A {
	public:
		int i;
		virtual void testfunc(){}
	};
	void func()
	{
		A obj;
		int len = sizeof(obj);

		cout << "obj size=" << len << endl;

		char* p1 = reinterpret_cast<char*>(&obj);
		char* p2 = reinterpret_cast<char*>(&(obj.i));

		if (p1 == p2) {

			cout << "vptr 在对象内存后面" << endl;
		}
		else {

			cout << "vptr 在对象内存前面" << endl;
		}
	}
}
namespace test19
{
	class Base {
	public:
		virtual void f() {
			cout << "Base::f" << endl;
		}
		virtual void g()
		{
			cout << "Base::g" << endl;
		}
		virtual void h()
		{
			cout << "Base::h" << endl;
		}
	};
	class Dervie :public Base {
	public:
		virtual void g()
		{
			cout << "Dervie::g" << endl;
		}
	};
	void func()
	{

		Dervie* obj = new Dervie();
		//变量名 obj  0x000
		//变量值  new Dervie 它是一块内存地址  该内存地址存储一个虚函数表
		//变量类型  Dervie *

		long* pvptbl = (long*)obj;//得 到obj上的值，该值是个内存地址，该内存地址存储的内容是虚函数表
		long* vptb = (long*)(*pvptbl);

		for (int i = 0; i < 4; i++) {

			printf("Dervie[%d]=0X:%p\n",i,vptb[i]);
		}

		typedef void(*Func)(void);

		Func f = (Func)vptb[0];
		Func g = (Func)vptb[1];
		Func h = (Func)vptb[2];

		f();
		g();
		h();

		cout << "*************************" << endl;
		Base* obj1 = new Base();
		long* parvptbl = (long*)obj1;
		long* parvptb = (long*)(*parvptbl);
		for (int i = 0; i < 4; i++) {

			printf("Base[%d]=0X:%p\n", i, parvptb[i]);
		}
		Func parf = (Func)parvptb[0];
		Func parg = (Func)parvptb[1];
		Func parh = (Func)parvptb[2];

		parf();
		parg();
		parh();

		cout << "***************************" << endl;

		int a = 100;
		int* b = &a;
		int** c = &b;

		printf("c的内容是b的地址%x\n",c);
		printf("b的内容是a的地址%x\n",b);
		printf("a的内容是%d\n",a);

		printf("c=%d\n",*(*c));
		printf("a=%d",*(&a));

		cout << "********************************" << endl;

		Dervie objx;

		long* vptr1 = (long*)(&objx);
		long* vptable = (long*)(*vptr1);
		for (int i = 0; i < 4; i++) {

			printf("Dervie[%d]=0X:%p\n", i, vptable[i]);
		}
		Func parf1 = (Func)vptable[0];
		Func parg1 = (Func)vptable[1];
		Func parh1 = (Func)vptable[2];

	}
}
namespace test20
{
	class Base1
	{
	public:
		virtual void f()
		{
			cout << "Base1::f" << endl;
		}
		virtual void g()
		{
			cout << "Base1::g" << endl;
		}
	};
	class Base2
	{
	public:
		virtual void h()
		{
			cout << "Base2::h" << endl;
		}
		virtual void i()
		{
			cout << "Base2::i" << endl;
		}
	};
	class Dervied :public Base1, public Base2
	{
	public:
		virtual void g()
		{
			cout << "Dervied::g" << endl;
		}
		virtual void i()
		{
			cout << "Dervied::i" << endl;
		}
		virtual void mi()
		{
			cout << "Derviced::mi" << endl;
		}
		virtual void mh()
		{
			cout << "Dervied::mh" << endl;
		}
		virtual void mg()
		{
			cout << "Derviced::mg" << endl;
		}
	};
	void func()
	{

		cout << sizeof(Base1) << endl;
		cout << sizeof(Base2) << endl;
		cout << sizeof(Dervied) << endl;

		Dervied ins;
		Base1& b1 = ins;
		Base2& b2 = ins;
		Dervied d = ins;


		long* vptr1 = (long*)(&ins);
		long* vptable1 = (long*)(*vptr1);

		typedef void(*Func)(void);
		Func f1 = (Func)(vptable1[0]);//0x008571ee {Project119.exe!test20::Base1::f(void)}
		Func f2 = (Func)(vptable1[1]);//0x008571e4 {Project119.exe!test20::Dervied::g(void)}
		Func f3 = (Func)(vptable1[2]);//0x008571da {Project119.exe!test20::Dervied::mi(void)}
		Func f4 = (Func)(vptable1[3]);//0x00857211 {Project119.exe!test20::Dervied::mh(void)}
		Func f5 = (Func)(vptable1[4]);//0x00857207 {Project119.exe!test20::Dervied::mg(void)}
		Func f6 = (Func)(vptable1[5]);
		Func f7 = (Func)(vptable1[6]);
		Func f8 = (Func)(vptable1[7]);


		long* vptr2 = vptr1 + 1;
		long* vptable2 = (long*)(*vptr2);

		Func f11 = (Func)(vptable2[0]);//0x008571fd {Project119.exe!test20::Base2::h(void)}
		Func f22 = (Func)(vptable2[1]);//0x0085720c {Project119.exe!test20::Dervied::i(void)}
		Func f33 = (Func)(vptable2[2]);
		Func f44 = (Func)(vptable2[3]);

		int x = 0;

		//子类继承  多个基类（每个基类都有虚函数）时，会有多个虚函数表指针

	}
}
namespace test21
{
	//数据成员绑定时机
	typedef string my;
	class A {
		typedef int my;
	public:
		void show(my a) {
			x = a;
		}
		typedef int my;
		my x;
	};
	void func()
	{
		A obj;
	}
}
namespace test22
{
#pragma pack(1)
	class A {
	public:
		int x;
		int y;
	public:
		int z;
		static int s_x;
		static int s_y;
		static int s_z;
		char j;
		int m;
		int k;
		void printOffset()
		{
			printf("x=%d\n",&A::x);
			printf("y=%d\n",&A::y);
			printf("z=%d\n",&A::z);
			printf("j=%d\n",&A::j);
			printf("m=%d\n",&A::m);
			printf("k=%d\n",&A::k);
		}
	};
#pragma pack()
	void func()
	{
		A obj;
		printf("obj size=%d\n",sizeof(obj));
		printf("A size=%d\n",sizeof(A));
		printf("x=%p\n",&obj.x);
		printf("y=%p\n",&obj.y);
		printf("z=%p\n",&obj.z);
		printf("j=%p\n",&obj.j);
		printf("m=%p\n",&obj.m);
		printf("k=%p\n",&obj.k);

		obj.printOffset();
		obj.x = 100;
		int A::* mx = &A::x;
		cout << (obj.*mx) << endl;

		void (A::*f1)(void) = &A::printOffset;

		(obj.*f1)();

	}
}
namespace test23
{
	class A {
	public:
		int i;
		int j;
		static int x;
		void test()
		{
			i = 10;
			j = 20;
		}
	};
	int A::x = 0;
	void func()
	{
		A obj;
		obj.x = 101;
		A* obj1 = new A();
		obj1->i = 1;
		obj1->j = 2;
		obj1->x = 102;


		printf("obj.x=%d\n",obj.x);
		printf("obj1->x=%d\n",obj1->x);

		A::x = 100;
		printf("obj.x=%d\n", obj.x);
		printf("obj1->x=%d\n", obj1->x);

		printf("obj.x=%p\n",&obj.x);
		printf("obj1->x=%p\n",&obj1->x);
		printf("A::x=%p\n",&A::x);

		printf("i=%d\n",&A::i);
		printf("j=%d\n",&A::j);
		printf("x=%d\n",&A::x);

		printf("size=%d\n",sizeof(A));

		char* data = new char[sizeof(A)];

		data = (char*)obj1;

		int* i = (int*)data;
		int* j = (int*)(data+4);

		printf("i=%d\n",*i);
		printf("j=%d\n",*j);

		*i = 8;
		*j = 6;
		printf("i=%d\n", obj1->i);
		printf("j=%d\n", obj1->j);

		int z = 300;

		char* a1 = (char*)&z;
		char* a2 = a1+1;
		char* a3 = a1+2;
		char* a4 = a1+3;

		int za = 0;
		za = (int)*a1;
		
		za|= (int)*a2<<8;

		printf("a2=%d\n",(int)*a2);

		int ha = 12;

	}
}
namespace test24
{
	void func()
	{
		//0000 0001 0010 1100
		int x = 300;
		uint8_t data[4] = { 0 };

		data[0] = (x >> 8)&0xFF; //内存低位存值高位
		cout << data[0] << endl;
		cout << (x >> 8) << endl;
		data[1] = x & 0xFF;//内存高位存值低位
		cout << data[1] << endl;
		cout << (x & 0xFF) << endl;

		int y = 0;//内存从低到高
		//y 0000 0000 0000 0001
		y|= data[0]<<8;//值高位
		cout << y << endl;
		y |= data[1];
	
		cout << y << endl;

	}
}
namespace test25
{
	//存在内存对齐，填充，它们之间并不会挨在一起
	class A {
	public:
		int i;
		char a;
		char b;
		char c;
	};
	class Base1 {
	public:
		int i;
		char a;
	};
	class Base2 :public Base1 {
	public:
		char b;
	};
	class Base3 :public Base2 {
	public:
		char c;
	};
	void func()
	{
		cout << sizeof(A) << endl;
		cout << sizeof(Base1) << endl;
		cout << sizeof(Base2) << endl;
		cout << sizeof(Base3) << endl;

		printf("A:i=%d\n",&A::i);
		printf("A:a=%d\n",&A::a);
		printf("A:b=%d\n",&A::b);
		printf("A:c=%d\n",&A::c);

		printf("Base3:i=%d\n", &Base3::i);
		printf("Base3:a=%d\n", &Base3::a);
		printf("Base3:b=%d\n", &Base3::b);
		printf("Base3:c=%d\n", &Base3::c);
	}
}
namespace test26
{
	//类成员数据布局
	//打印出来的偏移并不一定正确
	//最好调试看各个成员在内存中的数据存储情况
	//一个类有虚函数，就会有虚函数表
	//并且类对象会添加新成员vptr虚函数表指针指向虚函数表
	//而这个添加新成员赋值操作是由编程器在构造函数中额外添加的
	class Base {
	public:
		int mi;
		//virtual void show(){}
	};
	class A:public Base {
	public:
		int i;
		int j;
		virtual void test(){}
		A() {
			int a = 10;
		}
		~A()
		{
			int b = 0;
		}
	};
	void func()
	{
		A obj;
		cout << sizeof(A) << endl;

		printf("A::i=%d\n",&A::i);
		printf("A::j=%d\n",&A::j);
		printf("A::mi=%d\n",&A::mi);

		obj.i = 2;
		obj.j = 3;
		obj.mi = 6;
	}
}
namespace test27
{
	class Base1 {
	public:
		int mi1;
		virtual void show1(){}
	};
	class Base2
	{
	public:
		int mi2;
		virtual void show2() {}
	};
	class A :public Base1,public Base2 {
	public:
		int i;
		int j;
		virtual void test() {}
		A() {
			int a = 10;
		}
		~A()
		{
			int b = 0;
		}
	};
	void func()
	{
		A obj;
		cout << sizeof(A) << endl;

		printf("A::mi1=%d\n", &A::mi1);
		printf("A::mi2=%d\n", &A::mi2);
		printf("A::i=%d\n", &A::i);
		printf("A::j=%d\n", &A::j);

		obj.i = 2;
		obj.j = 3;
		obj.mi1 = 8;
		obj.mi2 = 9;
		
		//obj 对象内存布局
		//dc 93 87 00 08 00 00 00 ec 93 87 00 09 00 00 00 02 00 00 00 03 00 00 00
		//vptr         mi1        vptr        mi2         i           j
	}
}
namespace test28
{
	//虚基类
	//
	class Grand
	{
	public:
		int m_grand;
	};
	//虚继承
	class A1 : virtual public Grand {
	public:
		int m_a1;
	};
	class A2 : virtual public Grand {
	public:
		int m_a2;
	};
	//C1对象布局：A1 成员+A1虚基类表指针vbptr=vbtable virtual base table
	//A2成员+A2虚基类表指针+基类m_grand+m_c1
	class C1 :public A1, public A2 {
	public:
		int m_c1;
	};
	void func()
	{
		cout << sizeof(Grand) << endl;
		cout << sizeof(A1) << endl;
		cout << sizeof(A2) << endl;
		cout << sizeof(C1) << endl;

		C1 obj;
		//obj.m_grand = 10;
		obj.A1::m_grand = 10;

	}
}
namespace test29
{
	void func()
	{
		char a1[] = { 97,98,99,NULL };

		char a2[] = { 0b01100111,0b01101111,0b01101111,0b01100100,0b01110011 ,NULL };
		char a3[] = { 0b01110011,104,111,112,NULL };
		char a4[] = { 114,0145,109,111,118,101,83,104,111,112,NULL };
		char a5[] = { 97,100,100,65,112,112,76,111,103 ,NULL };
		char a6[] = { 108,111,103,105,110,82,114,67,111,100,101,NULL };
		char a7[] = { 115,99,97,110,76,111,103,105,110,82,114,67,111,0x64,101,82,101,0b01110011,117,108,116,NULL };
		char a8[] = { 97,100,0b01110011,68,0145,116,97,105,108 ,NULL };
		char a9[] = { 100,0145,116,97,105,108,NULL };
		char a10[] = { 97,112,112,76,105,0b01110011,116,115 ,NULL };
		char a11[] = { 0b01110011,121,0b01110011,116,101,109,83,101,116,116,105,110,103,NULL };
		char a12[] = { 116,114,97,110,0b01110011,102,101,114,82,101,102,117,110,100 ,NULL };
		char a13[] = { 103,101,116,85,0b01110011,101,114,70,114,105,101,110,100,73,110,102,111,65,0x64,109,105,110 ,NULL };
		char a14[] = { 117,115,101,114,80,114,111,102,105,108,101,85,115,101,70,111,114,65,100,109,105,110,NULL };
		char a15[] = { 97,99,99,111,117,110,116,68,101,108,101,116,101,72,97,110,0x64,108,101,114,NULL };
		char a16[] = { 105,0x64,99,97,114,0x64,NULL };
		char a17[] = { 116,114,97,110,115,102,0145,114,NULL };
		char a18[] = { 97,108,105,112,97,121,78,111,116,105,102,121,72,97,110,100,108,101,114,NULL };
		char a19[] = { 119,101,99,104,97,116,78,111,116,105,102,121,72,97,110,100,108,101,114,NULL };
		char a20[] = { 115,101,110,0x64,67,117,0x73,116,111,109,77,101,115,115,97,103,101,NULL };
		char a21[] = { 103,101,116,67,111,115,70,105,108,101 ,NULL };
		char a22[] = { 99,117,115,116,111,109,101,114,83,101,114,118,105,99,101,76,111,103,105,110,NULL };
		char a23[] = { 99,111,110,116,97,99,116,85,115 ,NULL };
		char a24[] = { 116,0145,0b01110011,116 ,NULL };
		char a25[] = { 105,110,100,101,120 ,NULL };
		char a26[] = { 99,104,101,99,107,67,111,100,101,NULL };
		char a27[] = { 115,101,110,0x64,71,114,111,117,112,77,101,115,115,97,103,101,NULL };
		char a28[] = { 105,109,67,97,108,108,66,97,99,107,82,101,115,112,111,110,115,101 ,NULL };
		char a29[] = { 114,0145,102,117,110,0x64,82,0145,100,80,97,99,107,101,116,115,NULL };
		char a30[] = { 114,0145,115,111,108,118,101,85,115,101,114,83,104,105,112,78,117,109,NULL };
		char a31[] = { 114,0145,115,111,108,118,101,85,115,101,114,80,114,97,105,115,101 ,NULL };
		char a32[] = { 0x64,0145,116,97,105,108 ,NULL };
		char a33[] = { 104,111,116 ,NULL };
		char a34[] = { 114,101,103,105,0b01110011,116,101,114,NULL };
		char a35[] = { 118,101,114,105,102,121,67,111,0x64,101 ,NULL };
		char a36[] = { 98,105,114,116,104,76,111,99,97,116,105,111,110 ,NULL };
		char a37[] = { 108,111,103,105,110 ,NULL };
		char a38[] = { 102,111,114,103,111,116,80,97,0b01110011,0b01110011,119,111,114,100,NULL };
		char a39[] = { 104,97,110,100,78,117,109,NULL };
		char a40[] = { 116,97,103,0b01110011 ,NULL };

		const char *actions[] = {
			a1,
			a2,a3,a4,a5,a6,a7,a8,a9,a10,
			a11,a12,a13,a14,a15,a16,a17,a18,a19,
			a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,
			a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,
			NULL
		};

		cout << sizeof(actions) / sizeof(char) << endl;
		int i = 0;
		while (actions[i]!=NULL) {

			if (strcmp(actions[i], "abc") == 0) {
				break;
			}
			//cout << i << actions[i] << endl;
			
			i++;
		}
		

	}
}
namespace test30
{
	//类虚继承会存在虚基类表指针
	//虚基类表指针里存储的实际是上父类的一些成员偏移值
	//当类对象对类成员操作时，会取得虚基类地址里的偏移值
	class Grand {
	public:
		int m_grand;
	};
	class Grand1 {
	public:
		int m_grand1;
	};
	class A1:virtual public Grand,virtual public Grand1 {
	public:
		int _a1;
	};
	class A2 :virtual public Grand {
	public:
		int _a2;
	};
	class C :public A1, public A2 {
	public:
		int c;
	};
	void func()
	{
		A1 obj;
		cout << sizeof(obj) << endl;
		obj.m_grand = 3;
		obj.m_grand1 = 2;
		obj._a1 = 4;
	}
}
namespace test31
{
	void func(char )
	{
		//
		//const char code[] = { 0x03,0x1b,0x17,0x00,0x00,0x00,0x02,0xD0,0x03,0xE8,0x00,0x00,0x20,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x48,0x03,0x0F,0x02,0x0B,0x76,0x0B,0x82 };
		//const char code[] = { 0x05,0x0A, 0x30 ,0x31 ,0x32, 0x33,0x34,0x35,0x36,0x37,0x38,0x39 };
		const char code[] = {0x04,0x00,0x00};
		int i = 0;
		short int sum = 0;
		for (i = 0; i < 3; i++)
			sum += code[i];//将每个数相加


		printf("0x%x\n", sum);
		sum = ~sum;
		printf("0x%x\n", sum);
		sum += 1;


		
		//sum = sum & 0xff;
		printf("0x%x\n", sum);

		//取低位
		unsigned char op1 = (sum >>8)&0xFF;
		//取高位
		unsigned char op2 = sum & 0xFF;
		printf("0x%x\n", op1);
		printf("0x%x\n", op2);
	}
}
namespace test32
{
	class Grand {
	public:
		int m_grand;
	};
	class A1 :virtual public Grand {
	public:
		int m_a1;
	};
	class A2 :virtual public Grand {
	public:
		int m_a2;
	};

	class C1 :public A1, public A2 {
	public:
		int m_c1;
	};

	void func()
	{
		cout << sizeof(Grand) << endl;
		cout << sizeof(A1) << endl;
		cout << sizeof(A2) << endl;
		cout << sizeof(C1) << endl;
		//obj内存布局：有虚基类表，表里存储的是基类成员的偏移值
		//当给m_grand赋值时，汇编代码会取得该偏移值
		C1 obj;
		obj.m_grand = 2;
		obj.m_a1 = 3;
		obj.m_a2 = 4;
		obj.m_c1 = 5;
	}
}

namespace test33
{

	template<typename T1,class T2>
	T1 test(T1 a, T2 b)
	{
		T1 c = a + b;
		return c;
	}
	class A {
	public:
		int num;
		A(int b=0) :num(b) {
			
		}
	
	};
	struct B {
		int num;
		B(int b = 0) :num(b) {

		}
	};
	template<class T1,class T2>
	T1 operator+(const T1& obj1, const T2& obj2) {

		T1 obj;
		obj.num = obj1.num + obj2.num;
		return obj;
	}
}

namespace test34
{
	class A {
	public:
		int i;
		int j;
		int k;

		void show() {
			cout << i << j << k << endl;
		}
	};
	void func() {

		printf("i的偏移值%d\n",&A::i);
		printf("j的偏移值%d\n",&A::j);
		printf("k的偏移值%d\n",&A::k);

		A obj;
		printf("i的地址=%p\n",&obj.i);
		printf("j的地址=%p\n",&obj.j);
		printf("i的地址=%p\n",&obj.k);

		A* obj1 = new A();
		printf("i指针变量的地址=%p\n", &obj1->i);
		printf("j指针变量的地址=%p\n", &obj1->j);
		printf("i指针变量的地址=%p\n", &obj1->k);

		int A::* x = &A::i;
		obj.*x = 100;
		int A::* y = &A::j;
		int A::* z = &A::k;

		cout << obj.i << obj.*x << endl;

		void (A::* func)(void) = &A::show;
		(obj.*func)();

		printf("x=%d,size=%d\n",x,sizeof(x));
		printf("y=%d,size=%d\n",y,sizeof(y));
		printf("z=%d,size=%d\n",z,sizeof(z));
	}
}
namespace test35
{
	class A {
	public:
		int i;
		//编译器实现时是
		//void myfunc(const A*this,int a) 实际上会编译成全局函数，调用时传递A并让this接收
		void myfunc(int a) {
			i += a;
			cout << "this=" << this << endl;
		}
	};
	void gmyfunc( A*obj,int x) {
		obj->i+= x;
	}
	void func() {

		A obj;
		cout << "obj=" << &obj << endl;
		obj.myfunc(10);
		gmyfunc(&obj,20);
	}
}
namespace test36
{
	class A {
	public:
		int m_i;
		void myfunc(int abc)
		{
			//m_i = abc;
			printf("myfunc called");
		}
		virtual void myvfunc()
		{
			printf("virtual void myvfunc called %p\n",this);
		}

		static void mystfunc()
		{
			printf("static void mystfunc called \n");
		}
	};
	void func()
	{
		//c++ 类成员函数编译器处理后会变成全局函数  当涉及到类成员变量调用时，建议在栈或是堆中实例化类对象
		//否则可以以其它方式调用
		A obj;
		A* obj1 = new A();
		obj.myvfunc();
		obj1->myvfunc();

		obj.mystfunc();
		obj1->mystfunc();
		A::mystfunc();

		((A*)0)->mystfunc();
		((A*)0)->myfunc(1);
		((A*)1)->myfunc(2);

		((A*)"china")->myfunc(3);
		delete obj1;
	}
}
namespace test37
{
	class A {
	public:
		int i;
		virtual void a() {

		}
		virtual void b() {

		}
	};
	void func() {

		cout << sizeof(A) << endl;
		printf("a=%p\n",&A::a);
		printf("b=%p\n",&A::b);
		A* obj = new A();
		
	}
}
namespace test38
{
	class A {
	public:
		mutable  int x;
	};
	class B {
	public:
		mutable  int x;
	};
	void func() {

		printf("A size=%d\n",sizeof(A));
		int arr[3] = { 0 };

		int* x = arr;//可以
		printf("x=%p,arr=%p\n",x,arr);//可以

		int* y = arr + 1;
		printf("y=%p,arr=%p\n", y, arr+1);

		int* z = &arr[0] + 1;

		printf("z=%p,arr=%p\n",z,&arr[0]+1);

		int* x1 = arr;
		x1 = (int*)new A();
		*x1 = 100;
		int* x2 = arr + 1;
		x2 = (int*)new A();
		*x2 = 200;
		int* x3 = arr + 2;
		x3 = (int*)new B();
		*x3 = 200;

		
		cout << ((A*)(x1))->x << endl;
		cout << ((A*)(x2))->x << endl;
		cout << ((A*)(x3))->x << endl;


		*(arr + 1) = 100;
		*(arr + 2) = 300;
		*arr = 500;

		printf("arr[0]=%d,arr[1]=%d,arr[2]=%d\n",arr[0],arr[1],arr[2]);

	}
}
namespace test39
{
	class Base {
	public:
		void show() {
			cout << "Base::show()" << endl;
		}

		virtual void printf(int v=100) {
			cout << "Base::printf()" <<v<< endl;
		}
	};
	class Dervie :public Base {
	public:
		void show() {
			cout << "Dervie::show()" << endl;
		}
		virtual void printf(int v=300) {
			cout << "Dervie::printf()" <<v<< endl;
		}
	};
	void func()
	{
		Base obj1;
		Dervie obj2;
		obj1.show();
		obj2.show();

		Base* obj3 = new Base();
		Dervie* obj4 = new Dervie();
	
		obj3->printf();
		cout << "***************" << endl;
		obj3 = obj4;

		obj3->show();
		obj4->show();

		obj3->printf();
		obj4->printf();
		
	}
}
namespace test40
{
	class Base {
	public:
		virtual void f() {
			cout << "Base::f" << endl;
		}
		virtual void g() {
			cout << "Base::g" << endl;
		}
		virtual void h() {
			cout << "Base::h" << endl;
		}
	};
	class Base2 {
	public:
		virtual void Hbase() {

		}
		virtual ~Base2(){

		}
	};
	class Dervied :public Base,public Base2 {
	public:
		virtual void g()
		{
			cout << "Dervied::g" << endl;
		}
		virtual void i()
		{
			cout << "Dervied::i" << endl;
		}
	};
	void func()
	{
		/*Base* obj = new Dervied();
		obj->g();

		Dervied* obj1 = new Dervied();

		long* x = (long*)obj1;
		long* y = (long*)*x;

		using Func = void(*)();
		Func f = (Func)y[0];

		f();

		delete obj;
		delete obj1;*/

		Base2* obj = new Dervied();
		
		delete obj;

	}
}
namespace test41
{
	void func()
	{
		auto x = 100;
		auto y = "china";
		int& z = x;
		z = 200;
		cout << x << y << z << endl;

		const int j = 100;
		//j = 200;
		constexpr int k = 200;
		//k = 300;
		cout << j << k << endl;

	}
}
namespace test42
{
	void func()
	{
		int num[4]{ 1,2,3,4 };
		for (auto &x : num) {
			cout << x << endl;
		}

		int* x1 = new int;
		*x1 = 100;
		int* x2 = new int(100);
		cout << *x1 << *x2 << endl;

		delete x1;
		delete x2;

		int* x3 = new int[100];

		*x3 = 1;
		*(x3 + 2) = 2;

		cout << *x3 << endl;
		cout << *(x3 + 2) << endl;
		delete[] x3;

		int* x4 = (int*)malloc(10*sizeof(int));
		x4[0] = 100;
		x4[1] = 500;
		cout << x4[1] << endl;
		free(x4);

		int* a = NULL;
		int* b = nullptr;

		if (a == b) {
			cout << "a==b" << endl;
		}

		cout << typeid(NULL).name() << endl;
		cout << typeid(nullptr).name() << endl;

	}
}
namespace test43
{
	struct student {

		int age;
		char name[100];
		void test()
		{
			age++;
		}
	};

	void test(student& stu) {
		stu.age + 10;
	}
	void test1(student* stu) {
		stu->age += 200;
	}
	void func()
	{
		student tony;
		tony.age = 100;
		strcpy_s(tony.name,sizeof(tony.name),"tony");

		tony.test();

		test(tony);
		test1(&tony);

		cout << tony.age << tony.name << endl;
	}
}
namespace test44
{
	auto func1(int x, int b)->int {
		return x + b;
	}
	inline auto func2()-> void {
		return;
	}


	void func() {

		//cout << func1(10, 20) << endl;
		string s1{ "ilikephp" };
		cout << s1.size() << endl;
		cout << s1.length() << endl;
		cout << s1.empty() << endl;
		//cout << s1.reserve(1) << endl;
		cout << s1[2] << endl;
		cout << s1.c_str() << endl;
		cout << s1.data() << endl;

		if (s1 == "c") {
			cout << "equal" << endl;
		}

		s1 = s1 + "开了";
		cout << s1 << endl;

		cout << s1.find("k") << endl;

	}
}

int main()
{
	test44::func();
	//using namespace test33;

	/*cout<<test33::test(10,22) << endl;
	cout<<test33::test(10.32,22.43) << endl;
	cout<<test33::test((std::string)"china", (std::string)"good") << endl;
	test33::A objx(1);
	test33::A objy(2);
	cout<<test33::test(objx,objy).num<<endl;

	test33::B objx1(10);
	test33::B objy1(20);
	cout << test33::test(objx1, objy1).num << endl;*/


	/*test33::A obj(1);
	test33::A obj2(2);
	test33::A obj3 = obj + obj2;*/
	

	return 0;
}