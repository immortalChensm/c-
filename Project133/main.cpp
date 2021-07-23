#include <iostream>

using namespace std;

namespace test1
{
	class A {
	public:
		int x;
	public:
		A() {

		}
		~A() {

		}
	};
	void func()
	{

		A* a = new A;
		A* b = new A();

		delete a;
		delete b;

		//std::shared_ptr<A> c(new A(), [=](void* p) {delete p; cout << "delete" << endl; });

	}
}
namespace test2
{
	class A {
	public:
		A()
		{
			cout << "a" << endl;
		}
		~A()
		{
			cout << "~a" << endl;
		}
		static void* operator new(size_t size) {
			A* a = (A*)malloc(size);
			return a;
		}
		static void operator delete(void* p) {
			free(p);
		}
		static void* operator new[](size_t size) {
			A* a = (A*)malloc(size);
			return a;
		}
		static void operator delete[](void* p) {
			free(p);
		}
	};
	void func()
	{

		//A* o = new A();
		//delete o;

		//A* o = new A[3]();//分配时会用额外的4字节存储数组元素个数
		//delete[]o;

		//这里底层并不是只简单分配了10个字节，而是分配了一大片的内容，可能通过释放时观察内存地址知道
		char* p = new char[10];
		memset(p,0,10);
		delete []p;
	}
}
int main()
{

	test2::func();
	return 0;
}