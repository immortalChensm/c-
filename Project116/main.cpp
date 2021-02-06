#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace test1
{
	class A {
	public:
		static void *operator new (size_t size)
		{
			A* pa = (A*)malloc(size);
			return pa;
		}
		static void operator delete(void* ptr)
		{
			free(ptr);
		}
		static void* operator new[] (size_t size)
		{
			A* pa = (A*)malloc(size);
			return pa;
		}
		static void operator delete[](void* ptr)
		{
			free(ptr);
		}
		A()
		{
			cout << "a" << endl;
		}
		~A()
		{
			cout << "~a" << endl;
		}
	};
	void func()
	{

		//int* pa = new int(10);
		//delete pa;

		//A* obj = new A();
		//delete obj;
		A* obj = new A[3]();//本身是占用3个字节的内存，但是会使用4个字节的空间来存储数组元素长度
		//就会占用7个字节
		//new/delete 在分配内存和释放内存时，内存的管理如记录占用多少个字节，会多分配额外的内存
		//来存储 其它数据的
		delete[] obj;
	}
}
int main()
{

	test1::func();
	return 0;
}