#include <iostream> 
#include <string> 
//未归类：函数调用运算符，function类模板
using namespace std;
void talk(int a)
{
	cout << a << endl;
}

class thanZero {
public:
	thanZero(int v) {
		cout << "than Zero constructo called" << endl;
	}
	int operator()(int v) {
		if (v == 0)return 0;
		return v;
	}

	int operator_(int v) {
		return v + 10;
	}
};
//友元函数
//类型转换运算函数
//运算符重载函数

int main()
{

	talk(1);//()为函数调用的标记 称为“函数调用运算符"
	//重载”函数调用运算符“
	//thanZero a;
	//cout << a(100) << endl;


	thanZero b(10);
	b(100);

	return 0;
}