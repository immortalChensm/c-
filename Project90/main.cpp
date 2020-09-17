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
class Base2 {
public:
	virtual void hBase2()
	{
		cout << "Base2::hBase2" << endl;
	}
};
class Derive :public Base,public Base2 {
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
	
};
int main()
{

	cout << sizeof(Base) << endl;
	cout << sizeof(Base2) << endl;
	cout << sizeof(Derive) << endl;

	//Derive obj;
	/*obj.f();
	
	obj.Base::g();
	
	obj.h();
	obj.hBase2();
	obj.g();

	obj.i();*/

	/*long* x = (long*)&obj;
	long* y = (long*)*x;

	using func = void(*)();

	func f1 = (func)y[0];
	func f2 = (func)y[1];
	func f3 = (func)y[2];
	

	long* y1 = (long*)*x+1;
	func f11 = (func)y1[0];
	func f22 = (func)y1[1];
	func f33 = (func)y1[2];*/

	/*Base2* obj = new Derive();

	delete obj;*/

	//类中存在继承时，父类【基类】必须有虚析构函数，否则容易造成内存泄露

	Derive obj;

	printf("obj变量所占内存的大小：%d\n",sizeof(obj));
	printf("obj变量名对应的内存地址：%#x\n",&obj);


	long* x = (long*)&obj;

	printf("0~4字节：%#x上的数据：%#x\n",x,*x);
	printf("偏移4个字节后%#x上的数据：%#x\n",x+1,*(x+1));

	long* y = x + 1;

	using Func = void(*)();
	long* xdata = (long*)*x;
	long* ydata = (long*)*y;

	Func f = (Func)(xdata[0]);
	Func g = (Func)(xdata[1]);
	Func h = (Func)(xdata[2]);
	Func i = (Func)(xdata[3]);
	Func gx = (Func)(xdata[4]);

	Func hBase2 = (Func)(ydata[0]);
	Func x2 = (Func)(ydata[1]);
	
	
	printf("base::g=%#x\n",&Base::g);
	printf("Derive::g=%#x\n",&Derive::g);

	return 0;
}