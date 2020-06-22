#include <iostream>
#include <string>

using namespace std;

//左值|左值引用|右值|右值引用|std::move强制转换左值为右值
//std::move 没有移动的操作，只是将左值强制转换为右值的功能

int main()
{

	//int i = 10;
	////int&& b{ i };//不可以
	//int&& b{ i++ };
	//
	//int&& c{ std::move(i) };//右值引用绑定强制转换的右值

	//int&& d = 100;
	////int&& e = d;//不可以
	//int&& f = std::move(d);

	//d = 1000;
	//cout << d << f << endl;
	//f = 2000;
	//cout << d << f << endl;

	string s = "test";
	string f = std::move(s);
	string&& d = std::move(s);

	cout << s << endl;
	cout << d << endl;
	cout << f << endl;

	return 0;
}