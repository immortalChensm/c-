#include <iostream>

using namespace std;
class B;
class A {
private:
	int data{ 0 };
	friend void func(const A& obj);
	friend class B;
	//friend void B::test(int x, A& obj);
};
class B {
public:
	void test(int x, A&obj) {

		obj.data = x;
		cout << obj.data << endl;
	}
};
void func(const A& obj) {
	cout << obj.data << endl;
}
int main() {

	const A obj;
	func(obj);

	B x;
	A objx;
	x.test(200,objx);
	return 0;
}