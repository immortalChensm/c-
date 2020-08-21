#include <iostream> 
#include <string> 
#include <time.h>

//程序的优化
using namespace std;

class A {
public:
	int _v1;
	//int _v2;
	int* pv;
public:
	/*A(int v1=0, int v2=0) :_v1(v1), _v2(v2) {
		cout << "constructor run" << endl;
		cout << _v1 << endl;
		cout << _v2 << endl;
	}*/
	A()
	{
		pv = new int(100);
		cout << "call default constructor " << endl;
	}
	A(const A& obj)  {
		//深拷贝
		//如果没有这个拷贝构造函数的话，对象之间进行赋值时就会按位copy，如果有指针成员，就会出现2个对象间的指针成员变量指向的内存空间是一样的
		//会导致free2次内存，导致出错
		_v1 = obj._v1;
		pv = new int;
		memcpy(pv,obj.pv,sizeof(int));

		cout << "call copy constructor" << endl;
	}
	~A()
	{
		delete pv;
		cout << "call destructor " << endl;
	}

	A(int v) {
		_v1 = v;
		pv = new int(100);
		cout << "call <int>constructor " << endl;
	}
};

//A test(A& obj)
//{
//	/*A objx;
//	objx._v1 = obj._v1 * 2;
//	objx._v2 = obj._v2 * 3;
//	return objx;*/
//	//返回临时对象，在不同的编译器下，会进行优化处理
//	//win下可以选择项目属性--》优化【最大值】/代码生成【基本运行时检查，默认值】
//}
int main()
{

	/*clock_t start, end;
	start = clock();
	cout << "start:"<<start << endl;
	A obj(10, 20);
	test(obj);
	
	end = clock();

	cout << "end:" << end << endl;*/

	/*A obj1 = 1;
	A obj2 = A(1);
	A obj3 = (A)100;
	A obj4(10);*/

	//深拷贝和浅拷贝
	A obj;
	obj._v1 = 1;
	A obj2(obj);

	cout << obj2._v1 << endl;

	return 0;
}