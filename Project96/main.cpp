#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace test
{
	class A {
	public:
		A()
		{
			cout << "A::A" << endl;
		}
		virtual ~A()
		{

		}
	};
	class B:public A {
	public:
		B()
		{
			cout << "B::B" << endl;
		}
		virtual ~B()
		{

		}
	};

	class C :public B {
	public:
		C():_x(10)
		{
			cout << "C::C" << endl;
		}
		virtual ~C()
		{

		}
		int _x;
	};

	void func()
	{
		C obj;
		/**
		继承之下对象的构造时机和初始化列表赋值时机
		汇编各语句的执行顺序
		1 call        test::C::C (0B8143Dh)
		2 jmp         test::C::C (0B820F0h)

		C()
			3 call        test::B::B (0B812E4h)     jmp         test::B::B (0B82000h)
			9 mov         dword ptr [eax],offset test::C::`vftable' (0B89B5Ch)

			10 00B22154  mov         eax,dword ptr [this]
			11 00B22157  mov         dword ptr [eax+4],0Ah


		{
			12 cout << "C::C" << endl;

		}


		B（）
			4 call        test::A::A (0B812FDh)
			7 mov         dword ptr [eax],offset test::B::`vftable' (0B89B48h)
		｛
				8 cout << "B::B" << endl;
		｝



		A()
			5 mov         dword ptr [eax],offset test::A::`vftable' (0B89B34h)
		{
			6 cout << "A::A" << endl;
		}
		
		**/
	}
}
int main()
{

	test::func();
	return 0;

}