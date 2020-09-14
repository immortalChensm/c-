#include <iostream>
#include <string>
#include <vector>

using namespace std;
class A {
public:
	int _x;
	void show()
	{
		;
	}
	virtual void display()
	{
		printf("display called:%p\n",this);
	}

	static void talk()
	{
		cout << "call talk func" << endl;
	}
};

class B {
public:
	virtual void test1()
	{
		cout << 1 << endl;
	}
	virtual void test2()
	{
		cout << 2 << endl;
	}
};
int main()
{

	printf("%p\n",&B::test1);
	printf("%p\n",&B::test2);

	printf("size=%d\n",sizeof(B));

	B* obj = new B();

	printf("obj的内存地址是：%#x\n",&obj);
	printf("obj的内存地址是的内容：%#x\n",obj);//是vfptr成员，该成员是虚函数表指针，也是个地址


	long* x = (long*)obj;//获取到obj内容，内容是一块vfptr指针
	long* y = (long*)*x;//获取vfptr内存指针上的数据

	using func = void(*)(void);

	//func a = (func)y[0];
	//a();
	printf("vfptr=%#x\n",y);
	printf("obj->vfptr[0]地址的内容:%#x\n",y[0]);
	printf("obj->vfptr[1]地址的内容:%#x\n",y[1]);


	int xy = 0;
	//A obj;
	//obj.display();

	//A* objx = new A();
	//objx->display();


	//void (A::*xdisplay)() = &A::display;

	//(objx->*xdisplay)();

	////printf("%p\n",(void*)&(objx->*xdisplay));
	//printf("%p\n",xdisplay);

	//cout << "**************" << endl;
	//((A*)0)->display();
	////((A*)objx)->show();

	/*bj.talk();
	objx->talk();

	A::talk();

	((A*)0)->talk();
	((A*)1)->talk();
	((A*)(200))->talk();*/

	return 0;
}