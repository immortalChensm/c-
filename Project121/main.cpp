#include<iostream>

using namespace std;


class Human {
public:
	Human() {
		cout << "Human" << endl;
	}
	Human(int) {
		cout << "Human(int)" << endl;
	}

	void test() {
		cout << "Human::test" << endl;
	}
	void test(int a) {
		cout << "Human::test(int a)" << endl;
	}
};
class Men :public Human {
public:
	Men() {
		cout << "Men" << endl;
	}
	Men(int) {
		cout << "Men(int)" << endl;
	}

	void test(int a) {
		cout << "Men::test(int a)" << endl;
	}
public:
	using Human::test;//重载父类的方法
};
int main() {

	Men obj;

	obj.test(1);
	obj.test();
	//obj.Human::test();

	return 0;
}