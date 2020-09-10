#include <iostream>
#include <string>

//虚基类继承的对象内存布局
//二层结构虚基类表内容分析
using namespace std;

class Grand {
public:
	int _x;
	
};
class Grand2 {
public:
	//int _x;
	Grand2()
	{
		cout << "grand2" << endl;
	}
};
class A1 :virtual public Grand//,virtual public Grand2
{
public:
	int _a1;
};
class A2 :virtual public Grand//, virtual public Grand2
{
public:
	int _a2;
};

class C :public A1, public A2 {
public:
	
};

class X {
public:
	int _a;
	int _b;
	int _c;
	int* d = new int{ 0 };
};
int main()
{

	//obj 内存布局  https://note.youdao.com/web/#/file/WEBb85a68c37ec76463b754d565badab7d1/note/WEBb682238d4ea0062195a0614e7f8831fe/
	/*A1 obj;
	obj._x = 1;
	obj._a1 = 10;


	cout << sizeof(Grand) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(C) << endl;*/

	X obj;//4bytes|4bytes|4bytes|4bytes
	obj._a = 1;
	obj._b = 2;
	obj._c = 3;
	obj.d = new int(10);

	long* y = (long*)&obj;
	cout << y[0] << endl;
	cout << y[1] << endl;
	cout << y[2] << endl;
	//cout << *(y[3]) << endl;

	cout << *y << endl;
	cout << *(y+1) << endl;
	cout << *(y+2) << endl;

	//cout << *(*(y+3)) << endl;
	int *temp = (int*)*(y + 3);

	printf("%d\n", *temp);


	return 0;
}