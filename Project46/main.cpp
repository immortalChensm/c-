#include <iostream>

namespace test
{
	
	void func()
	{
		//new delete [malloc,free] 分配内存时，还会额外的申请更多的内存来记录这块内存的其它信息，如分配的字节大小等
		//如果多次分配，会造成大量内存浪费，因为每次申请内存，都要大块的其它内存来记录一堆信息
		//特别是频繁的申请小块内存
		int* a = new int(255);
		
		delete a;
	}
}
namespace test1 {

	class A {
	public:
		static void* operator new(size_t size);
		static void operator delete(void* p);

		A()
		{
			std::cout << "A" << std::endl;
		}
		~A()
		{
			std::cout << "~A" << std::endl;
		}
	};

	void *A::operator new(size_t size) {

		A* p = (A*)malloc(size);
		return p;
	}
	void A::operator delete(void* p)
	{
		free(p);
		return;
	}
	void func()
	{

		//A* p = new A();
		//delete p;

		A* p = ::new A();//::全局操作符  不在调用重载的new,delete
		::delete p;
	}
}

namespace test2 {

	class A {
	public:
		static void* operator new[](size_t size);
		static void operator delete[](void* p);

		A()
		{
			std::cout << "A" << std::endl;
		}
		~A()
		{
			std::cout << "~A" << std::endl;
		}
	};

	void* A::operator new[](size_t size) {

		A* p = (A*)malloc(size);
		return p;
	}
	void A::operator delete[](void* p)
	{
		free(p);
		return;
	}
	void func()
	{

		//分配内存时，会多出额外的4个字节内存来记录数字2【数组长度】
		//内存地址情况：4bytes|1bytes|1bytes
		//对应地址数据：2|A类对象|A类对象
		A* p = new A[2]();
		delete[] p;
	}
}

int main()
{
	test2::func();
	
	return 0;
}