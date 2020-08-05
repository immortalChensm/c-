#include <iostream> 
#include <string> 

using namespace std;

class A
{
public:
	int a;

	A()
	{
		printf("A::A() this=%p\n",this);
	}
	void funcA()
	{
		printf("A::funcA() this=%p\n", this);
	}
};


class B
{
public:
	int b;
	B()
	{
		printf("B() this=%p\n", this);
	}
	void funcB()
	{
		printf("B::funcB() this=%p\n", this);
	}
};


class C:public A,public B
{
public:
	int c;
	C()
	{
		printf("C() this=%p\n", this);
	}
	void funcC()
	{
		printf("C::funcC() this=%p\n", this);
	}
	void funcB()
	{
		printf("C::funcB() this=%p\n", this);
	}
};

int main()
{

	C obj;


	obj.funcA();
	obj.funcB();
	obj.B::funcB();
	obj.funcC();
	return 0;
}