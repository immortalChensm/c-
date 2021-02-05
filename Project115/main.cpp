#include <iostream>
#include <string>
#include <vector>

namespace test1
{
	class A
	{
	public:
		int _i;
		/*A()
		{

		}*/
		virtual void test() {};
	};
	void func()
	{

		int* p = new int;
		int* p1 = new int();
		int* p2 = new int(100);

		A* pa = new A;
		A* pa2 = new A();

		int x = 10;
	}
}
void main()
{

	test1::func();
	return ;
}