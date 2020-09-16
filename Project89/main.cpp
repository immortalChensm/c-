#include <iostream>
#include <string>
#include <vector>

using namespace std;
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
class Derive :public Base {
public:
	virtual void i() {
		cout << "Derive::i" << endl;
	}
	virtual void g() {
		cout << "Derive::g" << endl;
	}
	
	void test()
	{
		cout << "Derive::test" << endl;
	}
	virtual void t() = 0;
	// virtual final void t1() ;
};
int main()
{

	Derive obj;
	Derive* objx = &obj;

	objx->i();
	objx->f();
	objx->g();
	objx->h();

	cout << "***************" << endl;

	Base* obj1 = new Derive();
	obj1->g();

	Derive objy;
	Base& obj2 = objy;
	obj2.g();

	return 0;
}