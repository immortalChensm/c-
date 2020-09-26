#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

//对象全局，局部构造与析构
using namespace std;
namespace test
{

	class A {
	public:
		A()
		{
			cout << "A" << endl;
		}
		~A()
		{
			cout << "~A" << endl;
		}
		int _x;
	};
	void func()
	{
		//A 的析构函数 会被编译器在多处插入调用
			A obj;
		
			
		int a = 10;
		if (a == 100) {
			return;
		}
		else if (a == 102) {
			return;
		}
		int b = 3;
	}
}
int main()
{
	test::func();
	return 0;
}