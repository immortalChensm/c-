#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base1
{
public:
	int _x;
	virtual void test() {}
};
class Base2 {
public:
	int _y;
	virtual void bb() {}
};
class Base3 {
public:
	int _z;
	virtual void bb() {}
};
class A:public Base1,public Base2,public Base3 {
public:
	int _i;
	int _j;
	virtual void abc() {}
	A()
	{
		int x = 10;
	}
	~A()
	{
		int y = 100;
	}
};
int main()
{
	
	//A 类 占用12个字节，vptr指向虚函数表指针是类的首地址，占用4个字节
	cout << sizeof(A) << endl;

	printf("x=%d\n",&A::_x);
	printf("y=%d\n",&A::_y);
	printf("i=%d\n",&A::_i);
	printf("j=%d\n",&A::_j);

	//查看该对象在内存中的布局[调试，内存]
	A obj;
	obj._x = 2;
	obj._y = 4;
	obj._z = 7;
	obj._i = 5;
	obj._j = 10;


	return 0;
}