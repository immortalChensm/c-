#include <iostream> 
#include <string> 

#include "myvector.h"
#include "myarray.h"
//类模板
//类模板声明|类模板定义|类模板实例化（调用）||typename的使用场景||函数指针||函数模板的使用示例
//类模板在使用的时候必须给类型参数值，编译不会自己推断的
//模板的非参数参数不支持float,double,string,类

//typename使用场景
//类模板，函数模板  类的类型成员
using namespace std;
typedef int* test;

//typename 告诉编译T::size_type 是一个数据类型
template <typename T>
typename T::size_type getLength(const T& c) {

	if (c.empty()) {
		return 0;
	}
	return c.size();
}
/**

string::size_type getLength(const string &c){
	
	if(c.empty(){
	
	}
}
**/ 

class A {
public:
	int _a;
};


//类模板声明
template <typename T>
class B {
public:
	typedef T* uint;
public:
	uint getSize(int a);
};

//类模板定义
template <typename T>
typename B<T>::uint B<T>::getSize(int a)
{
	uint obj = new T;
	obj->_a = a;
	return obj;
}

//函数指针作为函数的参数
int testa(int a, int b)
{
	return a + b;
}
typedef int (*Func)(int, int);

void testaa(int a, int b, Func function) {

	cout << function(a,b) << endl;
}

template <typename T,typename F>
void testfunc(const T& a, const T& b, F function) {

	cout << function(a, b) << endl;
}
int main()
{

	testfunc<int,Func>(1,2,testa);

	testaa(100, 200,testa);

	//类模板使用【实例化】
	B<A> obj;
	A *obja;
	obja = obj.getSize(10);

	cout << obja->_a << endl;


	/*test a;
	int b = 10;
	a = &b;*/

	//模板实例化
	myvector<int> a;
	//myvector<float> b;
	//myvector<string> c;

	//myarray<int, 100> a1;
	//myarray<char> b;

	//b.myfunc();
	//a1.myfunc();

	string str = "china";
	string::size_type size = getLength<string>(str);

	cout << size << endl;
	return 0;
}