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

	//���д��ڼ̳�ʱ�����ࡾ���ࡿ������������������������������ڴ�й¶

	Derive obj;

	printf("obj������ռ�ڴ�Ĵ�С��%d\n",sizeof(obj));
	printf("obj��������Ӧ���ڴ��ַ��%#x\n",&obj);


	long* x = (long*)&obj;

	printf("0~4�ֽڣ�%#x�ϵ����ݣ�%#x\n",x,*x);
	printf("ƫ��4���ֽں�%#x�ϵ����ݣ�%#x\n",x+1,*(x+1));

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