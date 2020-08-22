#include <iostream> 
#include <string> 
#include <time.h>

//类的初始化列表
//1、使用的原因，能提升性能
//2、初始化列表的顺序，要和类成员定义顺序一致，不然出错
using namespace std;

//class T
//{
//public:
//	T(int y) {}
//};
//class Base
//{
//public:
//	Base(int x, int y) {
//	}
//};
//class A:public Base{
//
//public:
//	int _x;
//	int _y;
//	int &_z;
//	const int _b;
//	T obj;
//	A(int x,int y,int z,int b):_x(x),_y(y),_z(z),_b(b),Base(x,y),obj(x)
//	{
//		/*_x = x;
//		_y = y;
//		_z = z;
//		_b = b;*/
//		
//	}
//
//};

class X {
public:
	int _x;
	X(int v=0) :_x(v) {
		printf("%p\n",this);
		cout << "转换构造函数" << endl;
	}

	X(const X& obj):_x(obj._x) {
		printf("%p\n", this);
		cout << "拷贝构造函数" << endl;
	}

	X& operator=(const X& obj) {
		_x = obj._x;
		printf("%p\n", this);
		cout << "赋值构造函数" << endl;
		return *this;
	}

	~X()
	{
		printf("%p\n", this);
		cout << "析构函数" << endl;
	}
};

class A {
public:
	X xobj;
	int _y;
	int _z;
	A(int v):xobj(v),_z(100),_y(_z) {
		//xobj = v;//会生成4行代码，在编译器角度上
		//_y = v;

		cout << "_y" << _y << endl;
		cout << "_z" << _z << endl;
	}
};
int main()
{

	/*int x = 10;
	A obj(1,2,x,x);*/
	
	//X obj=1;
	//obj = 1;
	//X obj1 = obj;
	//X obj;

	//obj = 1;

	A obj(10);

	//编译器视角
	/**
	X obj1;
	obj1.X::X();

	X objtmp;
	objtmp.X::X();

	obj1.X::operator=(objtmp);

	obj1.X::~X();
	objtmp.X::~X();
	**/
	return 0;
}