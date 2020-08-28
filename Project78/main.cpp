#include <iostream>
#include <string>
#include <vector> 

using namespace std;
//���ؼ̳е��麯����
class A {
public:
	virtual void f()
	{
		cout << "A::f()" << endl;
	}
	virtual void g()
	{
		cout << "A::g()" << endl;
	}
};
class B {
public:
	virtual void h()
	{
		cout << "B::h()" << endl;
	}
	virtual void i()
	{
		cout << "B::i()" << endl;
	}
};
class Derived :public A, public B {

public:
	virtual void f()
	{
		cout << "Derived::f()" << endl;
	}
	virtual void i()
	{
		cout << "Derived::i()" << endl;
	}

	virtual void mi()
	{
		cout << "Derived::mi()" << endl;
	}
	virtual void mj()
	{
		cout << "Derived::mj()" << endl;
	}
	virtual void mh()
	{
		cout << "Derived::mh()" << endl;
	}
};
int main()
{

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(Derived) << endl;


	Derived obj;//��2���麯��ָ��
	Derived& objx = obj;

	long* vptr = (long*)&objx;
	long* vp1 = (long*)*vptr;//��һ���麯��ָ��

	long *vptr2 = vptr + 1;
	long* vp2 = (long*)*vptr2;//�ڶ����麯��ָ��


	typedef void(*Func)(void);

	Func f1 = (Func)vp1[0];
	Func f2 = (Func)vp1[1];
	Func f3 = (Func)vp1[2];
	Func f4 = (Func)vp1[3];
	Func f5 = (Func)vp1[4];

	f1();
	f2();
	f3();
	f4();
	f5();
	Func f11 = (Func)vp2[0];
	Func f22 = (Func)vp2[1];
	Func f33 = (Func)vp2[2];
	Func f44 = (Func)vp2[3];
	Func f55 = (Func)vp2[4];
	cout << "************" << endl;
	f11();
	f22();
	f33();
	f44();
	f55();

	//win ������Ա���ߣ�cl /dl reportSingleClassLayoutDerived main.cpp ���Բ鿴����麯����ṹ
	//g++ -fdump-class-hierarchy -fsyntax-only xxx.cpp
	return 0;
}