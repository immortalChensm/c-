#include <iostream>
#include <string> 

using namespace std;
//程序转化语义

class Y
{
public:
	int _i;
	Y(const Y& obj):_i(obj._i)
	{
		cout << "copy constructo run" << endl;
	}
	Y()
	{
		_i = 0;
		cout << "consturctor run" << endl;
	}
	~Y()
	{
		cout << "destructor run" << endl;
	}
};

void test(Y tmp)
{
	return;
}
int main()
{

	//Y obj;
	//obj._i = 10;
	//Y obj1 = obj;

	//Y obj2(obj);

	//Y obj3 = (obj);//此语句就是obj5在编译器角度上，会拆分成2句，并调用了拷贝构造函数

	//cout << "**************" << endl;

	//Y obj5;
	//obj5.Y::Y(obj);
	//return 0;

	//参数的初始化

	Y obj;
	test(obj);
}