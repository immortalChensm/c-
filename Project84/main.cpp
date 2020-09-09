#include <iostream>
#include <string>

//虚基类继承的对象内存布局
using namespace std;

class Grand {
public:
	//int _x;
	Grand()
	{
		cout << "grand" << endl;
	}
};
class A1 :virtual public Grand
{
public:
	A1()
	{
		cout << "A1" << endl;
	}
};
class A2 :virtual public Grand
{
public:
	A2()
	{
		cout << "A2" << endl;
	}
};
class C :public A1, public A2 {
public:
	C()
	{
		cout << "c" << endl;
	}
};
int main()
{

	C obj;
	//C obj 对象的内存布局：A1->Grand 有4个字节的vbptr A2->Grand 也有4个字节的vbptr 

	cout << sizeof(Grand) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(C) << endl;

	//obj._x = 10;//编译器提示 不明确
	/*obj.A1::_x = 10;
	obj.A2::_x = 18;

	cout << obj.A1::_x << endl;
	cout << obj.A2::_x << endl;*/
	//虚继承以后  
	//A1,A2 会被编译器插入一个虚基类表指针（virtual base table pointer) 指向虚基类表 (virtual base table)


	return 0;
}