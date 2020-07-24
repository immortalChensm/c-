#include <iostream> 
#include <string> 

//全局new,delete重载||定位placement new
//定位new:功能是在已经分配的内存上初始化一个对象，本身并不分配内存，需要提前分配好内存
//它就是：在已经预先分配好的内存地址上构造一个对象
using namespace std;

//void* operator new(size_t size)
//{
//	return malloc(size);
//}
//void* operator new[](size_t size)
//{
//	return malloc(size);
//}
//
//void operator delete(void* p)
//{
//	free(p);
//}
//
//void operator delete[](void* p)
//{
//	free(p);
//}
namespace test
{
	class A {
	public:
		A()
		{
			cout << "A::A()" << endl;
		}

		~A()
		{
			cout << "~A::A()" << endl;
		}
	};
	void func()
	{
		int* p = new int{ 10 };
		delete p;

		char* a = new char[10];
		delete[] a;

		A* obja = new A();
		delete obja;

		A* objb = new A[2]();

		delete[] objb;


	}
}
namespace test1
{
	class A {
	public:
		int m_i;
		A():m_i(0)
		{
			int i = 100;
		}
		A(int v) :m_i(v) {

		}

		//重载定位new
		void* operator new (size_t size, void* p)
		{
			return p;
		}
		~A()
		{
			int a=10;
		}
	};
	void func()
	{

		void* tmp = (void*)new char[sizeof(A)];//预先分配内存
		A* obj = new (tmp) A();//定位new 调用A的构造函数  不会重新分配新的内存

		void* tmp1 = (void*)new char[sizeof(A)];
		A* obj1 = new (tmp1) A(100);

		//delete obj;
		//delete obj1;

		obj->~A();
		obj1->~A();

		delete[](void*)tmp;
		delete[](void*)tmp1;

		void* ints = (void*)new int;

		int* t = new (ints) int(100);
		cout << *t << endl;

		//delete t;
		delete (void*)ints;

	}
}
namespace test2 {

	class A {
	public:

		void* operator new(size_t size)
		{
			return malloc(size);
		}

		void* operator new(size_t size, int a)
		{
			return malloc(size);
		}
	};
	void func()
	{

		//A* a = new A();
		A* a = new (123) A();
	}
}

int main()
{
	test2::func();
	return 0;
}