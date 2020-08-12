#include <iostream>
#include <string> 
#include <functional>

using namespace std;

class TC
{
public:
	using func = void(*)(int v);
	static void funcs(int v) {
		cout << "Tc::func run,v=" << v << endl;
	}
	//将本类转换为函数
	operator func()
	{
		return funcs;
	}

	void show(int j) {
		cout << "Tc::show run,j=" << j << endl;
	}

	static void display(double x) {
		cout << "Tc::display run,x=" << x << endl;
	}
};

class A {
public:
	int _i;
	A(int i){
		_i = i;
	}
	operator int()
	{
		return _i;
	}
};

void myfunc(int v) {
	cout << "myfunc run,v=" << v << endl;
}

class CB
{
	std::function<void()> fcallback;
public:
	CB(const std::function<void()>& f) :fcallback(f) {
		int i = 1;
	}
	void runcallback()
	{
		fcallback();
	}
};
class CBT
{
public:
	void operator ()(void)
	{
		cout << "CBT operator() run" << endl;
	}
};

void mycallback(int c, const std::function<void(int)>& f) {

	f(c);
}

void callback(int &v,int &y)
{
	v++;
	y++;
	cout << "callback run" <<v<<y<< endl;
}

class B {
public:
	void show(int x, int y) {
		_i = x;
		cout << "x=" << x << ",y=" << y << endl;
	}
	int _i;
};
int main()
{
	//可调用对象：函数指针，仿函数（类重载operator()())  operator type 类型转换函数，将类转换为指定的type值如函数
	// 类成员函数指针
	/*TC obj;
	obj(3);

	obj.operator TC::func()(33);

	A obj1(10);
	A obj2(20);
	int ret = obj1 + obj2;
	cout << ret << endl;

	TC objx;
	void (TC:: * x)(int v) = &TC::show;
	(objx.*x)(100);

	void ( * y)(double x) = &TC::display;
	y(100);*/

	//2 function 模板装函数对象

	//绑定普通函数
	//std::function<void(int)> f1 = myfunc;
	//f1(2);

	//绑定类的静态成员函数
	//std::function<void(double)> f2 = &TC::display;
	//f2(100);

	//绑定仿函数
	//TC obj;
	//std::function<void(int)> f3 = obj;
	//f3(111);

	/*CBT obj;
	CB objx(obj);
	objx.runcallback();*/

	/*for (int i = 0; i < 10; i++) {
		mycallback(i,callback);
	}*/


	//std::bind 将可调用对象和参数绑定在一起
	//auto f1 = std::bind(callback,101);
	//f1();

	//auto f2 = std::bind(callback,placeholders::_1,202);
	//f2(101);
	// 绑普通函数
	//std::bind(callback,placeholders::_1,303)(999,666);
	/*int a = 2, b = 3;
	auto f3 = std::bind(callback,a,placeholders::_1);
	f3(b);
	cout << "a=" << a <<",b="<<b << endl;*/

	//绑类成员函数
	/*B obj;
	auto f5 = std::bind(&B::show,&obj,100,200);
	f5();*/

	B obj;
	//std::function<void(int, int)> f = std::bind(&B::show,&obj,placeholders::_1,placeholders::_2);

	//f(10,101);

	// 绑定类成员变量
	std::function<int& ()> ix = std::bind(&B::_i,&obj);
	ix() = 101;

	cout << obj._i << endl;//并没有赋值

	//总结
	//可调用对象：函数指针  operator() operator type() 类成员函数指针
	//std::function 绑定
	//std::bind 用于绑定函数和参数，有点位符placeholders::_1~20
	//std::bind 也能绑定类成员函数和类成员变量  


	return 0;
}