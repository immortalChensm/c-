#include <iostream>
#include <string> 
#include <initializer_list>
#include <stdarg.h>

using namespace std;

void func(initializer_list<string> arr)
{
	for (auto it = arr.begin(); it != arr.end(); it++) {
		
		cout << *it << endl;
	}

	cout << arr.size() << endl;
}

class A {
public:
	A(const initializer_list<int>& a) {

		for (auto x : a) {
			cout << x << endl;
		}
	}
};

//double show(int num, ...)
double show(int num...)
{
	// typedef char* va_list;
	va_list val;
	double sum = 0;
	va_start(val,num);
	for (int i = 0; i < num; i++) {

		sum = sum + va_arg(val,int);
	}
	va_end(val);

	return sum;
}

void showa(int num...)
{
	va_list val;
	va_start(val, num);
	for (int i = 0; i < num; i++) {

		cout << va_arg(val, int) << endl;
	}

	va_end(val);
}

int main()
{
	//1、函数初始化列表initializer_list 可理解为某种类型值的数组

	/*initializer_list<string> arr = { "china","korean","japanese" };
	func(arr);


	func({"tom","tony","jack"});
	*/
	//2、拷贝，赋值都是共享同一块内存
	/*initializer_list<string> a = { "a","b" };
	initializer_list<string> b(a);
	initializer_list<string> c;
	c = b;*/


	//3、作为构造函数的参数
	A obj = { 1,2,3 };

	cout << show(3, 1, 2, 3) << endl;

	showa(3, 10, 20, 30);
	return 0;
}