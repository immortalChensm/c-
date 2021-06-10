#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class A final {
class A  {
public:
	A(int x): j(x){
		cout << "A" << endl;
	}
	A(const A& obj) {
		j = obj.j;
		cout << "A copy" << endl;
	}
	A& operator=(const A& obj) {
		j = obj.j;
		cout << "A == copy" << endl;
		return *this;
	}
	virtual void show() {
		cout << "a show" << endl;
	}
	~A() {

	}
protected:
	int j;
};
class B :public A {
public:
	B(int a, int b):A(a),x(a),y(b) {
		cout << "B" << endl;
	}
	virtual void show() override {
		cout << "b show" << endl;
	}
	~B() {

	}
private:
	int x;
	int y;
};
int main() {

	B b(1, 2);

	//A x(b);
	A x(0);
	x = b;

	A* objx = new B(2,3);
	objx->show();
	objx->A::show();

	A* objy = dynamic_cast<A*>(objx);
	objy->show();

	delete objx;
	//delete objy;

	return 0;
}