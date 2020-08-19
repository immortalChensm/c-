#include <iostream>
#include <string> 

using namespace std;

class A {
public:
	A(const A& b) {
		cout << "A copy constructor" << endl;
	}
	A()
	{
		cout << "A constructor" << endl;
	}
};

class B {
public:
	int _i;
	A obj;
};
int main()
{
	B obj1;
	obj1._i = 10;
	B obj2 = obj1;
	return 0;
}