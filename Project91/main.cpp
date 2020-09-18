#include <iostream>
#include <string>
#include <vector>

using namespace std;
//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f" << endl;
//	}
//	virtual void g() {
//		cout << "Base::g" << endl;
//	}
//	virtual void h() {
//		cout << "Base::h" << endl;
//	}
//
//	virtual ~Base()
//	{
//
//	}
//};
//class Base2 {
//public:
//	virtual void hBase2()
//	{
//		cout << "Base2::hBase2" << endl;
//	}
//	virtual ~Base2()
//	{
//
//	}
//};
//class Derive :public Base, public Base2 {
//public:
//	virtual void i() {
//		cout << "Derive::i" << endl;
//	}
//	virtual void g() {
//		cout << "Derive::g" << endl;
//	}
//
//	void test()
//	{
//		cout << "Derive::test" << endl;
//	}
//
//	virtual ~Derive()
//	{
//
//	}
//};

class Base {
public:
	int _x;
	virtual void f()
	{

	}
	virtual ~Base()
	{

	}
};
class Dervie :public virtual Base {
public:
	virtual ~Dervie()
	{

	}
	int _y;
};
int main()
{

	/*cout << sizeof(Base) << endl;
	cout << sizeof(Base2) << endl;
	cout << sizeof(Derive) << endl;*/

	//1 子类继承几个基类，就有几个虚函数表
	//多重继承之下，有几种情况，第二个基类或是最后的基类会对虚函数的支持产生影响
	//this指针调整，调整的目的就是能正确的找到对象的首地址，从而能正确的确定数据成员的存储位置

	//a
	/*Base2* obj1 = new Derive();
	delete obj1;*/
	//obj1 静态数据类型是Base2 ，但是指向的是一个派生类的完整地址，在释放的时候，会进行this指针调整，找到Derive
	//的首地址进行释放，并不会释放一部分

	//b 
	/*Derive* obj2 = new Derive();
	obj2->hBase2();*/
	//obj2 调用的是基类的成员，同样进行了this指针偏移调整

	cout << sizeof(Dervie) << endl;

	Dervie obj;
	obj._x = 2;
	obj._y = 6;

	Dervie* pobj = new Dervie();
	pobj->f();

	//obj对象内存布局：虚基类表指针4bytes+Dervie::_y成员变量4bytes+虚函数表指针4bytes+Base::_x成员变量

	return 0;
}