#include <iostream> 

#include <string> 

#include "talk.h"

//模板定义|模板使用（也叫模板实例化）||模板参数（类型参数，非类型参数）
using namespace std;

//int adds(int v1, int v2) {
//	return v1 + v2;
//}
//double adds(double v1, double v2)
//{
//	return v1 + v2;
//}
//模板  类型参数 将类型作为一个参数
template <typename T>

T adds(T v1, T v2)
{
	T sum = v1 + v2;
	return sum;
}
//调用模板之后，编译会自己推断模板参数的数据类型，编译器会实例化一个特定类型的函数
template <class T1>

void show(T1 v) {
	cout << v << endl;
}
//模板非类型参数
template <int a,int b>
int adds2() {
	int c = a + b;
	return c;
}



class B {
	
public:
	using obj = void(*)();
	static void getObj()
	{
		cout << "getObj" << endl;
	}
	operator obj() {

		return getObj;
	}

	
};

template <typename T,int a>
void talk(T name) {
	cout << name << " is " << a << endl;
}

template<unsigned int l1,unsigned int l2>//模板非类型参数
int charstrcmp(const char(&p1)[l1], const char(&p2)[l2])
{
	return strcmp(p1,p2);
}

template<int a,int b>
void sums(int arr1[a], int arr2[b]) {
	
	int result[a] = {};
	for (int i = 0; i < a; i++) {
		result[i] = arr1[i] + arr2[i];
	}
	//return result;
}
extern void tom();
int main()
{

	/*int a = adds(1, 2);
	cout << a << endl;

	double b = adds(1.12, 3.21);
	cout << b << endl;

	show(100);
	show("china");*/

	//模板定义：template <typename T>T 是类型参数  表示类型
	//非类型参数  表示一个值

	//模板非类型参数的函数调用
	//int d = adds2<100,200>();//template <int a,int b> 显示的指明非类型参数的值a=100,b=200
	//显示的指定模板参数【非类型参数的值】
	//cout << d << endl;

	//template<typename T> 显示的指明T的类型值为int
	//int e = adds<int>(1, 2);
	//cout << e << endl;

	//template <typename T>
	//int f = adds(1, 5);//编译自己推断T的类型值为int
	//cout << f << endl;

	//B b;
	//b();

	//int dd = 1;
	//int g = adds2(dd++, 10);不可以

	//talk<string,100>("jack");

	//template<unsigned int l1,unsigned int l2>//模板非类型参数
	//int charstrcmp(const char(&p1)[l1], const char(&p2)[l2])
	//int result = charstrcmp("jack", "tom");//在调用的时候并没有指定l1,l2的长度
	//编译器会自己推断长度生成特定的模板函数
	//int charstrcmp(const char(&p1)[5], const char(&p2)[4]){}

	//int result1 = charstrcmp<5, 5>("jack", "lucy");

	//int nums[] = {1,2,3,4,5};
	//sums<6,6>(nums,nums);

	talks<string,100>("lucy");

	tom();
	return 0;
}