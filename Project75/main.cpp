#include <iostream> 
#include <string> 
#include <time.h>

//��ĳ�ʼ���б�
//1��ʹ�õ�ԭ������������
//2����ʼ���б��˳��Ҫ�����Ա����˳��һ�£���Ȼ����
using namespace std;

//class T
//{
//public:
//	T(int y) {}
//};
//class Base
//{
//public:
//	Base(int x, int y) {
//	}
//};
//class A:public Base{
//
//public:
//	int _x;
//	int _y;
//	int &_z;
//	const int _b;
//	T obj;
//	A(int x,int y,int z,int b):_x(x),_y(y),_z(z),_b(b),Base(x,y),obj(x)
//	{
//		/*_x = x;
//		_y = y;
//		_z = z;
//		_b = b;*/
//		
//	}
//
//};

class X {
public:
	int _x;
	X(int v=0) :_x(v) {
		printf("%p\n",this);
		cout << "ת�����캯��" << endl;
	}

	X(const X& obj):_x(obj._x) {
		printf("%p\n", this);
		cout << "�������캯��" << endl;
	}

	X& operator=(const X& obj) {
		_x = obj._x;
		printf("%p\n", this);
		cout << "��ֵ���캯��" << endl;
		return *this;
	}

	~X()
	{
		printf("%p\n", this);
		cout << "��������" << endl;
	}
};

class A {
public:
	X xobj;
	int _y;
	int _z;
	A(int v):xobj(v),_z(100),_y(_z) {
		//xobj = v;//������4�д��룬�ڱ������Ƕ���
		//_y = v;

		cout << "_y" << _y << endl;
		cout << "_z" << _z << endl;
	}
};
int main()
{

	/*int x = 10;
	A obj(1,2,x,x);*/
	
	//X obj=1;
	//obj = 1;
	//X obj1 = obj;
	//X obj;

	//obj = 1;

	A obj(10);

	//�������ӽ�
	/**
	X obj1;
	obj1.X::X();

	X objtmp;
	objtmp.X::X();

	obj1.X::operator=(objtmp);

	obj1.X::~X();
	objtmp.X::~X();
	**/
	return 0;
}