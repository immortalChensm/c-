#include <iostream> 
#include <string> 
#include <map>
#include <functional>

//函数调用对象|类对象所占用的内存空间
using namespace std;

class A {
public:
	int operator()(int v) {
		return v > 0 ? v : 0;
	}
};

int ma(int v)
{
	return v + 10;
}

class B {
public:
	void func() {}
	//char a;
	int a;
	int b;
};
int main()
{

	//int t = A()(1);
	//cout << t << endl;

	//map<string, int(*)(int)> obj;
	/*map<string, std::function<int(int)>> obj;

	std::function<int(int)> a = ma;
	std::function<int(int)> b = A();

	obj.insert({"a",a});
	obj.insert({"b",b});

	cout << obj["a"](2) << endl;
	cout << obj["b"](100) << endl;*/

	//B* obj = new B(); //在堆上 32位是4个字节  64位是8个字节
	B obj;//栈上是1个字节
	cout << sizeof(obj) << endl;

	obj.a = 10;

	obj.b = 100;

	//总结：类对象所占用的内存地址，首地址一般和类内的成员变量【第一个】是相等的，并且类对象地 址是连续的一块内存空间

	printf("%#x\n",&obj);
	printf("%#x\n",&(obj.a));

	return 0;
}