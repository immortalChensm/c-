#include <iostream> 
#include <string> 
#include <map>
#include <functional>
//未归类：函数调用运算符，function类模板
//函数对象：类重载了()
//标准库function
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
	int operator()(int v,int j) {
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

int echo(int v) {
	return v;
}
int echo() {
	return 1;
}
int main()
{

	talk(1);//()为函数调用的标记 称为“函数调用运算符"
	//重载”函数调用运算符“
	//thanZero a;
	//cout << a(100) << endl;


	thanZero b(10);
	b(100);

	//不同调用对象的相同调用形式
	//可调用对象：
	//echo 函数和 函数对象（类只要重载了“函数调用运算符”就称为函数对象） 都是可是可调用对象

	/*map<string, int (*)(int)> my;
	my["ev"] = echo;

	cout << my["ev"](166)<<endl;*/

	//["evs"] = b; 不支持


	/*function<int(int)> func = echo;
	function<int(int)> obj = b;
	function<int(int)> cl = thanZero(1);

	
	cout << func(100) << endl;
	cout << obj(200) << endl;
	cout << cl(300) << endl;*/
	//重载之后，function出错
	/*map<string, function<int(int)>> my = {
		{"f1",echo},
		{"f2",b},
		{"fc3",thanZero(2)}
	};

	my["f1"](22);
	cout << my["f1"](22) << endl;*/


	//函数指针处理函数重载的问题
	int (*p)(int) = echo;
	int (*p1)(void) = echo;

	int (*p2)(int b) = echo;

	function<int(int)> f1 = p;//不通过函数名  而是通过指针即可解决函数重载的问题
	return 0;
}