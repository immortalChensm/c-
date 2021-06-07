#include<iostream>

using namespace std;


class Human {
public:
	Human() {
		cout << "Human" << endl;
	}
	virtual ~Human() {
		cout << "~Human" << endl;
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

	//virtual void china() final{  表示子类不可以覆盖重写
	/*virtual void china() {
		cout << "Human::china" << endl;
	}*/
	virtual void china() = 0;
};
class Men :public Human {
public:
	Men() {
		cout << "Men" << endl;
	}
	~Men() {
		cout << "~Men" << endl;
	}
	Men(int) {
		cout << "Men(int)" << endl;
	}

	void test(int a) {
		cout << "Men::test(int a)" << endl;
	}
	virtual void china() override {  //override 表示已经重写父类的方法
	//virtual void china()  {  //override 表示已经重写父类的方法
		cout << "Men::china" << endl;
	}
public:
	using Human::test;//重载父类的方法
};
int main() {

	/*Men obj;

	obj.test(1);
	obj.test();*/
	//obj.Human::test();

	Human* obj = new Men;
	obj->china();
	//obj->Human::china();


	delete obj;


	return 0;
}