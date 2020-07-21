#include <iostream> 

//理解new ,delete 做了什么事
namespace test
{
	class A {
	public:
		int _i;

		A()
		{

		}
		~A()
		{

		}
	};
	void func()
	{
		//1、new 带括号时会初始类成员的变量，否则不会初始化
		//2、带构造时，成员变量就不会清0了，就是随机值了
		//3、new干了啥
		A* a = new A();
		//调用顺序
		//1 operator new (0FF1348h)
		//1.1	_malloc (0FF128Ah) 
		//2 call        test::A::A (0FF12B7h)
		
		delete a;
		//1 test::A::~A (0CB142Eh)  
		//1 operator delete (0FA1267h)  
		//A* b = new A;

		//void* d = malloc(100);
		//int c = 1;

	}
}
int main()
{
	//new 从头说起

	test::func();
	return 0;
}