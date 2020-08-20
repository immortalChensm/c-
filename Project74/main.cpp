#include <iostream> 
#include <string> 
#include <time.h>

//程序的优化
using namespace std;

class A {
public:
	int _v1;
	int _v2;
public:
	A(int v1=0, int v2=0) :_v1(v1), _v2(v2) {
		cout << "constructor run" << endl;
		cout << _v1 << endl;
		cout << _v2 << endl;
	}
	A(const A& obj) :_v1(obj._v1), _v2(obj._v2) {
		cout << "call copy constructor" << endl;
	}
	~A()
	{
		cout << "call destructor " << endl;
	}
};

A test(A& obj)
{
	A objx;
	objx._v1 = obj._v1 * 2;
	objx._v2 = obj._v2 * 3;
	return objx;
	//返回临时对象，在不同的编译器下，会进行优化处理
	//win下可以选择项目属性--》优化【最大值】/代码生成【基本运行时检查，默认值】
}
int main()
{

	clock_t start, end;
	start = clock();
	cout << "start:"<<start << endl;
	A obj(10, 20);
	test(obj);
	
	end = clock();

	cout << "end:" << end << endl;
	return 0;
}