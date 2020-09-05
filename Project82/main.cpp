#include <iostream> 
#include <string>
#include <vector> 
//单一继承的成员布局
using namespace std;
//class A {
//public:
//	int _i;
//	int _x;
//	static int _j;
//
//	void test()
//	{
//		_i = 10;
//		_x = 20;
//	}
//};
//int A::_j = 0;

//class Base 8 bytes
//{
//public:
//	int _x;
//	char _a;
//	char _b;
//	char _c;
//};
class Base1
{
public:
	int _x;
	char _a;
};

class Base2 :public Base1 {
public:
	char _b;
};
class Base3 :public Base2 {
public:
	char _c;
};


int main()
{
	//类的内存布局：受内存对齐，边界调整，继承的影响
	cout << sizeof(Base1) << endl;
	cout << sizeof(Base2) << endl;
	cout << sizeof(Base3) << endl;

	printf("%#x\n",&Base3::_x);
	printf("%#x\n",&Base3::_a);
	printf("%#x\n",&Base3::_b);
	printf("%#x\n",&Base3::_c);
	/*cout << sizeof(Base) << endl;
	printf("%#x\n",&Base::_x);
	printf("%#x\n",&Base::_a);
	printf("%#x\n",&Base::_b);
	printf("%#x\n",&Base::_c);

	printf("%d\n", &Base::_x);
	printf("%d\n", &Base::_a);
	printf("%d\n", &Base::_b);
	printf("%d\n", &Base::_c);*/

	/*A obj;
	A* objx = new A;
	cout << obj._j << endl;
	cout << objx->_j << endl;
	cout << A::_j << endl;


	printf("%#x\n",&A::_j);
	printf("%#x\n", &obj._j);
	printf("%#x\n",&objx->_j);

	obj.test();*/

	return 0;
}