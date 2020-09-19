#include <iostream>
#include <string>
#include <vector> 

//rtti信息位置探讨  位于vptr虚函数表的前4个字节【一般】

using namespace std;
class Base {
public:
	/*virtual void f() {
		cout << "Base::f" << endl;
	}
	virtual void g() {
		cout << "Base::g" << endl;
	}
	virtual void h() {
		cout << "Base::h" << endl;
	}

	virtual ~Base()
	{

	}*/
};
class Base2 {
public:
	virtual void hBase2()
	{
		cout << "Base2::hBase2" << endl;
	}
	virtual ~Base2()
	{

	}
	void selffunc()
	{
		cout << "Base2::selffunc" << endl;
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

	virtual ~Derive()
	{

	}
};

int main()
{

	Base* obj = new Derive();
	//obj->g(); 都不能调用了

	Derive objx;
	Base& objxp = objx;
	//objxp.g();

	cout << typeid(*obj).name() << endl;
	cout << typeid(objxp).name() << endl;//可以检测出多态来，基类必须有虚函数，否则检测不出来
	//基类没有虚函数，则数据类型就是静态类型

	/*Derive* pobj = dynamic_cast<Derive*>(obj);
	if (pobj) {
		cout << "obj is Derive class" << endl;
		pobj->test();
	}*/

	//RTTI 
	/*const std::type_info &tp = typeid(*obj);

	cout << typeid(int).name() << endl;
	cout << typeid(Base).name() << endl;
	cout << typeid(Derive).name() << endl;*/
	return 0;
}