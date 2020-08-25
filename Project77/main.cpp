#include <iostream> 
#include <string> 
//虚函数手工调用
//含有虚函数的类，会有一个虚函数表指针vptr【4字节或是8字节】指向一个虚拟表vtbl
using namespace std;

class Base
{
public:
	virtual void a() {
		cout << "a" << endl;
	}
	virtual void b() {
		cout << "Base::b" << endl;
	}
	virtual void c() {
		cout << "c" << endl;
	}
};
class B :public Base
{
public:
	virtual void b() {
		cout << "B::b" << endl;
	}
};
int main() {


	cout << sizeof(Base) << endl;
	cout << sizeof(B) << endl;

	//变量名：obj
	//变量地址：0x01
	//变量内容：new B  内容是一块内存地址【指针】，地址上自然有数据，是虚函数表指针
	B* obj = new B();

	printf("obj的内存地址：%#x\n",&obj);
	printf("obj的内存地址的数据：%#x\n",obj);

	printf("obj的内存地址的数据【指针】上的内容：%#x\n",*obj);

	long* x = (long*)obj;

	long* vptr = (long*)(*x);

	printf("obj的内存地址的数据【指针】上的内容：%#x\n", vptr);
	for (int i = 0; i < 4; i++) {
		printf("vptr[%d]：%#x\n",i, vptr[i]);
		
	}

	typedef void(*Func)(void);

	Func f1 = (Func)vptr[0];
	Func f2 = (Func)vptr[1];
	Func f3 = (Func)vptr[2];
	
	f1();
	f2();
	f3();

	cout << "*******************" << endl;
	Base* objx = new Base();
	long* x1 = (long*)objx;
	long* x2 = (long*)*x1;

	for (int i = 0; i < 4; i++) {
		printf("vptrparent[%d]：%#x\n", i, x2[i]);

	}

	Func f11 = (Func)x2[0];
	Func f22 = (Func)x2[1];
	Func f33 = (Func)x2[2];

	f11();
	f22();
	f33();

	int a = 0;
	return 0;
}