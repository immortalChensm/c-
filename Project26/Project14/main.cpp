#include <iostream> 
#include <string> 

using namespace std;
//临时对象产生的场景
//1 将对象作为函数的参数传递【值传递】
//2 函数返回一个临时对象
//3 类的类型转换构造函数
// 应该尽量避免产生临时对象
class A {
public:

	A(int v1 = 0, int v2 = 0):_v1(v1),_v2(v2) {
		cout << "构造函数被调用"<<endl;
	}

	A(const A& t) {
		cout << "拷贝构造函数被调用" << endl;
	}

	A& operator=(A t) {
		cout << "赋值运算函数被调用" << endl;
		return *this;
	}

	~A() {
		cout << "析构函数被调用" << endl;
	}
public:
	int _v1;
	int _v2;
};

A Double(A t) {
	A a;
	a._v1 = t._v1 * 2;
	a._v2 = t._v2 * 2;
	return a;
}

class Num
{
public:
	Num(int x, int y) :a(x), b(y) {};
public:
	int a;
	int b;
};

Num operator+(Num& a, Num& b)
{

	return Num(a.a + b.a, a.b + b.b);
}
int main()
{
	//A a;

	//a = 1;//产生临时对象

	//A b = a;//产生临时对象

	//A b = Double(a);

	//A&& b = Double(a);//右值引用

	Num a{ 10,20 };
	Num b{ 100,200 };
	
	Num c= a+b;

	return 0;
}