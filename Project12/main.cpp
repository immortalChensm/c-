#include <iostream>
#include <string>

using namespace std;
//struct类|class类|普通类|抽你类（含有纯虚函数的类）|final类（子类不可以继承）
//静态类型：声明变量时的类型，编译器在编译时就已知的
//动态类型：是指指针或是引用所指向的内存中的数据的数据类型
//class A final{
class A {
public:
	A(int a) :_a{ a } {};
public:
	void display() {
		cout << "A::_a="<<_a << endl;
	}
protected:
	int _a;
};

class B final :public A {
public:
	B(int a, int b) :A{ a }, _b{ b } {};
public:
	void display() {
		cout << "B::_b=" << _b << endl;
		cout << "B::_a=" << _a << endl;
	}
private:
	int _b;
};
class C :B {

};
int main()
{

	A a{ 1 };
	B b(10,20);
	B c{ 100,200 };

	a.display();
	b.display();

	c.display();
	return 0;
}