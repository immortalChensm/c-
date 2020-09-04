#include <iostream>
#include <string>
#include <string.h>
#include <vector>
//数据成员布局
using namespace std;

#pragma pack(1)//一字节对象【就是不对齐】
class A {
public:
	int _x;
	int _y;
	int _z;

	static int x;
	static int y;
	static int z;
	void test()
	{
		cout << "test" << endl;
	}
public:
	char _a;//这里在内存中占用了4个字节，并非1个字节
	int _b;
};
#pragma pack()  //取消内存对齐
int main()
{
	cout << sizeof(A) << endl;

	A obj;
	obj._x = 1;
	obj._y = 2;
	obj._z = 3;
	obj._a = 4;
	obj._b = 5;

	cout << sizeof(obj) << endl;

	//2 边界调整，内存对齐
	printf("_x=%#x\n",&(obj._x));
	printf("_y=%#x\n",&(obj._y));
	printf("_z=%#x\n",&(obj._z));
	printf("_a=%#x\n",&(obj._a));
	printf("_b=%#x\n",&(obj._b));

	int A::*b = &A::_b;
	
	void (A::*test1)() = &A::test;

	(obj.*test1)();

	//char* data = (char*)&obj;

	//int x1;
	//int pos = sizeof(int);
	//memcpy(&x1, data, pos);
	//int x2;
	//memcpy(&x2, data +pos, sizeof(int));
	//pos+= sizeof(int);
	//int x3;
	//memcpy(&x3, data + pos, sizeof(int));
	//pos += sizeof(int);

	//char x4;
	//memcpy(&x4, data + pos, sizeof(char));
	//pos += sizeof(char);
	//char x5;
	//memcpy(&x5, data + pos, sizeof(int));
	//cout << x1 << x2 << x3 << x4 << x5 << endl;

	///*int* x = new int[3]();
	/*x[0] = 1;
	x[1] = 2;
	x[2] = 3;

	A* objx = (A*)x;

	cout << objx->_x << endl;
	cout << objx->_y << endl;
	cout << objx->_z << endl;

	cout << *x << endl;
	cout << *(x + 1) << endl;
	cout << *(x + 2) << endl;

	cout << "**************" << endl;
	cout << *(int*)(objx) << endl;
	cout << *((int*)(objx)+1) << endl;
	cout << *((int*)(objx)+2) << endl;*/

	char* data = new char[100];
	int pos = 0;
	int* ax = (int*)data;
	*ax = 100;
	pos = sizeof(int);

	char* str = (char*)"hello,world";
	char *bx = (char*)(data + pos);
	strcpy(bx, str);
	pos += strlen(str);

	A* objy = (A*)(data + pos);
	objy->_x = 101;
	objy->_y = 102;
	objy->_z = 103;
	objy->_a = 104;
	objy->_b = 105;


	return 0;
}