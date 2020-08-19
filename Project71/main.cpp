#include <iostream> 
#include <string>

using namespace std;

class A {
public:
	A()
	{
		cout << "AHAHA" << endl;
	}
};
class K {
public:
	K()
	{
		cout << "KHAHA" << endl;
	}
};
class B {
public:
	int _a;
	int _b;

	/*K obj1;
	A obj;*/
	void show()
	{
		cout << "IamChinese" << endl;
	}
	virtual void display()
	{
		cout << "display" << endl;
	}
};

class DemoParent
{
public:
	int _a;
};
class Demo:public DemoParent
{
public:
	void show()
	{
		cout << 1 << endl;
	}
	int _a;
	//char _b;
	/*virtual void display()
	{

	}*/
};
int main()
{
	B b;//B 类没有构造函数，但含有A,K类成员对象，编译器为会B类添加合成的默认构造函数并调用A,K类的构造函数

	//1、类成员有构造函数，但本类没有构造函数，编译器会合成加上
	//2、父类有构造函数，子类没有，但编译器也会全成加上
	//3、一个类有虚函数，就会有一个虚函数表-》指针指向虚函数表vftable地址
	//b.display();
	Demo obj;
	cout << sizeof(obj) << endl;
	return 0;
}