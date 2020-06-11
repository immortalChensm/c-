#include <iostream>
#include <string> 
#include "head1.h"  //头文件防止重复引入
#include "head2.h"
using namespace std;

//auto const constexpr 引用  头文件防止重复引入 
constexpr int func()
{
	int a=1;
	int b=2;
	cout << a << b << endl;
	return 5;
}
int main()
{
	/*cout << "hello,world" << endl;

	cout << g_head1 << g_head2 << endl;

	int a = 100;
	int& b = a;
	b = 500;

	cout << b << a << endl;
	printf("%#x,%#x\n",&a,&b);*/

	//常量 
	/*const int c = 100;
	int& d = (int&)c;
	d = 5002;
	cout << c << d << endl;*/


	constexpr int j = 100;

	//constexpr int i = j;
	//const int k = i;

	//int a = 10;
	////j = a;
	//
	//cout << j << i << k << endl;

	//j = func();
	//cout << j << endl;

	int a = func();
	cout << a << endl;
	return 0;
}