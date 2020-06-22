#include <iostream> 
#include <string> 

using namespace std;
//对象移动
//移动构造函数||移动赋值运算符

class B {
public:
	B() :_a(100) {
		//cout << "B构造函数被执行" << endl;
	}

	B(const B& t) :_a(t._a) {
		//cout << "B拷贝函数被执行" << endl;
	}

	~B() {
		//cout << "B析构函数被执行" << endl;
	}
	int _a;
};

class A {
public:
	//默认构造函数
	A() :_obj(new B) {
		cout << "A构造函数被执行" << endl;
	}
	//拷贝构造函数
	A(const A& tmp) :_obj(new B(*(tmp._obj))) {
		cout << "A拷贝函数被执行" << endl;
	}
	//移动构造函数
	A(A&& tmp) {
	
		cout << "A移动函数被执行" << endl;
	}
	virtual ~A() {
		delete _obj;
		cout << "A析构函数被执行" << endl;
	}
public:
	B* _obj;
};

static A getA()
{
	A a;
	return a;
}

int main()
{
	//移动构造函数
	//1：A移动给B,A就不能再使用了
	//2: 移动不是把另一个地址的数据弄到另一个地址，只是所有者变更
	//拷贝构造函数：类  类名(const 类 &x) {} &x 是左值引用 调用时得传递左值
	//移动构造函数：类  类名(const 类 &&x) {} &xx是右值引用  调用时给右值


	//左值：有内存空间 ，调用时只能给右值
	//左值引用：同理有内存空间  调用时只能传递左值
	//const 的左值引用  可以给右值【特殊性】
	//右值：大部分是常量值
	//右值引用：只能给右值 也可以将左值转换为右值 std::move(左值)

	//移动构造函数和移动赋值运算的功能
	//1、完成必要的内存移动，斩断原对象与内存的关系
	//2、确保源对象处于一种“即使被销毁也没有问题的”一种状态,确认不在使用原对象，而是使用移动后的对象

	/*int a = 1;
	int& b = a;
	const int& c = a;
	const int& d = 100;

	int&& e = std::move(a);

	cout << e << a << endl;

	a = 100;
	cout << e << a << endl;
	e = 1000;
	cout << e << a << endl;*/

	/*A* a = new A;
	a->_a= 10;
	A* b = new A(*a);*/

	A a = getA();
	return 0;
}