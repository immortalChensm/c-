#include <iostream>
#include <string>
#include <vector>

//成员函数指针
using namespace std;
namespace test {

	class A {
	public:
		void test1(int x) {
			cout <<"test1 "<< x << endl;
		}
		void test2(int y) {
			cout << "test2 " << y << endl;
		}

		static void test3(int x) {
			cout << "test3 " << x << endl;
		}

		virtual void test4Prior(int x) {
			cout << "test4Prior virtual test4 " << x << endl;
		}
		virtual void test4(int x) {
			cout << "virtual test4 " << x << endl;
		}
	};

	void func()
	{
		//A objx;
		//void (A:: * x)(int x) = &A::test1;
		//void (A:: * y)(int y) = &A::test2;
		//void (* z)(int x) = &A::test3;
		//void (A:: * a)(int x) = &A::test4;

		//(objx.*x)(10);

		//A* objy = new A();
		//(objy->*y)(100); //call        test::A::test2(01171030h)

		//z(101);//call        test::A::test3 (01171060h)  
		//(objx.*a)(666);//call        test::A::`vcall'{0}' (0117145Fh)
		//// 通过vcall[0] 找到虚函数地址

		A* obj = new A();

		void (A:: * x)(int x) = &A::test4;

		obj->test4(100);
		(obj->*x)(101);//虚函数表:|4bytes|4bytes|
		/**
		01291071  mov         dword ptr [esi],offset test::A::`vftable' (012931E0h)  
01291077  call        test::A::test4 (01291030h)  
0129107C  push        65h  
0129107E  mov         ecx,esi  
01291080  call        test::A::`vcall'{4}' (012913BFh) 
		**/
	}
}
int main()
{

	test::func();
	return 0;
}