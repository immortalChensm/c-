#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <thread>

using namespace std;

void* operator new (size_t size)
{
	void* o = (void*)malloc(size);
	return o;
}
void* operator new[](size_t size)
{
	void* o = (void*)malloc(size);
	return o;
}

void operator delete(void* p)
{
	free(p);
}
void operator delete[](void* p)
{
	free(p);
}
namespace test1
{
	void func()
	{

		int* x = new int(10);
		cout << *x << endl;
		delete x;
	}
}
namespace test2
{
	class A
	{

	public:
		int x;
		int y;
		A()
		{
			cout << "A" << endl;
		}
		A(int p) :x(p), y(p)
		{
			cout << "A(int p)" << endl;
		}
		~A()
		{
			cout << "~A" << endl;
		}

		void* operator new (size_t size, int a, int b)
		{
			A* obj = (A*)malloc(size);
			cout << a << b << endl;
			return obj;
		}
	};

	void func()
	{
		//重定位placement new
		//在已经分配好的内存上初始化对象
		//void* o1 = new char[sizeof(A)];
		//A* obj1 = new (o1) A();

		//delete obj1;

		//void* o2 = new char[sizeof(A)];
		//A* obj2 = new (o2) A(10);
		////delete obj2;
		//obj2->~A();
		//delete (void*)obj2;
		////delete o2;

		//void* o3 = new char[sizeof(int)];
		//int* obj3 = new (o3)int(100);
		//cout << *obj3 << endl;
		//delete obj3;

		//A* obj = new (10, 20) A();

		//delete obj;

		A* obj = new A[3]();//理论24Bytes,实际是28Bytes,会用4个字节来存储数组元素个数
		//同时调用构造函数3次，析构3次
		delete[]obj;

		cout << sizeof(A) << endl;
	} 
}
int main()
{
	test1::func();
	test2::func();
	return 0;
}
