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
	
	//A �� ռ��12���ֽڣ�vptrָ���麯����ָ��������׵�ַ��ռ��4���ֽ�
	cout << sizeof(A) << endl;

	printf("x=%d\n",&A::_x);
	printf("y=%d\n",&A::_y);
	printf("i=%d\n",&A::_i);
	printf("j=%d\n",&A::_j);

	//�鿴�ö������ڴ��еĲ���[���ԣ��ڴ�]
	A obj;
	obj._x = 2;
	obj._y = 4;
	obj._z = 7;
	obj._i = 5;
	obj._j = 10;


	return 0;
}