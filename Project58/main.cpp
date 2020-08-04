#include <iostream> 
#include <string> 

using namespace std;


//void func(int&& a) {
template<typename T=int>
void func(T&& a) {
	cout << 1 << endl;
	cout << a << endl;

	//T && a 是万能引用 ，单独的T不是
	// 万能引用会根据传递进来的参数决定 是左值引用还是右值引用
	//a是右值传递进来时：是 T && a
	//a是左值传递进来时是：T &a
}
//template<>
//void func(int&& a) {
//	cout << 2 << endl;
//	cout << a << endl;
//}

template<typename t>
class A {
public:
	void show(t&& x) {
	
	}
};
int main()
{

	//1 类型区别基本概念

	func(100);

	int a = 10;
	func(a);//不允许左值传递 模板函数可以了

	//2 万能引用 universe referrence   
	// 必须是函数模板，必须是T && ，必须产生类型推断
	//func 可传递右值，也可以传递左值  

	//右值引用 和万能引用的区别
	//右值引用：只能传递右值
	//万能引用：左值，右值都可以

	A<int> obj;//【类模板调用时，都给类型了，并没有让编译器自行推断】
	obj.show(a);//不可以了  

	//万能引用：总之能给左值，能给右值的就是万能引用，否则不是[右值引用+编译器类型推断】
	return 0;
}