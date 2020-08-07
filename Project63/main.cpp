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
	
	K obj1;
	A obj;
	void show()
	{
		cout << "IamChinese" << endl;
	}
};
int main()
{
	B b;//B 类没有构造函数，但含有A,K类成员对象，编译器为会B类添加合成的默认构造函数并调用A,K类的构造函数
	return 0;
}