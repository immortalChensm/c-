#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace test
{
	class A {
	public:
		A() {
			int x = 1;
		}
		~A()
		{
			int y = 2;
		}
		void* operator new [](size_t size) {
			A* obj = (A*)malloc(size);
			return obj;
		}
		void operator delete[](void *obj);
	};
	void A::operator delete[](void* obj) {
		free(obj);
	}

	void func()
	{

		A* obj = new A[3]();
		delete[] obj;
	}
}
namespace test1
{

	class A {
	public:
		int _x;
	};
	void func()
	{
		A* data = reinterpret_cast<A*>(new char[10 * sizeof(A)]);

		A* obj1 = (A*)data;

		obj1->_x = 1;
		
		(obj1 + 1)->_x = 2;
		(obj1 + 2)->_x = 2;


		cout << obj1->_x << endl;
		cout << data->_x << endl;
		cout << (obj1 + 2)->_x << endl;
		cout << (data + 2)->_x << endl;


		char* x = new char[10 * sizeof(A)];

		A* objx1 = (A*)x;
		x += sizeof(A);
		A* objx2 = (A*)x;

		objx1->_x = 100;
		objx2->_x = 200;

		cout << objx1->_x << endl;
		cout << objx2->_x << endl;

		cout << ((A*)x)->_x << endl;
		cout << ((A*)(x - sizeof(A)))->_x << endl;

		cout << (*x) << endl;

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

		void* operator new (size_t size, int i,void* head) {
			return head;
		}
	};

	void func()
	{

		void* a = (void*)new char[sizeof(A)];

		A* obja = new (100,a) A();//实际上调用operator new(size_t size,void *)()

		delete obja;


		/*void* b = (void*)new char[sizeof(A) * 10];

		A* objb = new (b)A[10]();

		delete[] objb;*/
		//objb->~A();
		//delete b;

	}
}
int main()
{

	test2::func();

	return 0;
}