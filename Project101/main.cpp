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
int main()
{

	test::func();

	return 0;
}