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

	/**
	
	0x00b4f7e0 {_i=5 _j=10 }

	A obj ������ڴ沼��
	58 8b a3 00 02 00 00 00  Base1 [vptr,_x]

	68 8b a3 00 04 00 00 00  Base2 [vptr,_y]

	74 8b a3 00 07 00 00 00  Base3[vptr,_z]

	05 00 00 00 0a 00 00  00 A [_i,_j]

	0x00b4f7e0 {_i=5 _j=10 }

	0x00b4f7e8 {_i=5 _j=10 }
	0x00b4f7e8 {_i=5 _j=10 }
	**/

	Base1* objx = &obj;//objx ���ڴ��ַ��ʼ��objһ��
	Base2* objxy = &obj;//objxy ���ڴ���ʼ��ַ = obj�׵�ַ+ƫ��8���ֽ�

	Base2* objy = (Base2*)(  ((char*)&obj)+sizeof(Base1)   );


	return 0;
}