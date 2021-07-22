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
int main()
{

	test1::func();
	return 0;
}