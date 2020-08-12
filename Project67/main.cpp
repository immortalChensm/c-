#include <iostream>
using namespace std;
//lambda,for_each find_if
//格式：[捕获列表](参数列表)->返回类型{函数体}
//(参数列表) 可以省略  
//->返回类型  可以省略
//捕获列表：通过捕获一定范围内的变量
//a：[] 不捕获任何变量
//b:[&] 捕获外部作用域所有变量，并作为引用在函数体内使用
//c:[=] 捕获外部作用域内所有变量，并作为副本【按值】在函数体内使用
//d:[变量名1,..] 按值捕获
//e:[=,&变量名] 默认按值捕获所有外部变量，后面的参数则按引用捕获
//f:[&,变量名] 默认按引用捕获所有外部变量，后面的变量名则按值捕获

//mutable 

class A {
public:
	int _j;
	void show(int x)
	{
		_j = x;
		//[this] {
		//[=] {
		[&] {
			cout << _j << endl;
		}();
	}
};
int main()
{

	//[](int x,int y)->void {
	//
	//	cout << x << y << endl;

	//}(100,200);

	//[]() {cout << 1 << endl; }();
	//[] {cout << 2 << endl; }();

	//static int i = 10;

	////
	//[]() {
	//	cout << i << endl;
	//}();

	//int j = 10;
	//[&]() {
	//	
	//	j = 101;
	//}();


	//cout << j << endl;

	//[=]() {
	//	cout << j << endl;
	//}();

	//A obj;
	//obj.show(188);

	//int x = 1, y = 2;
	//[x,y]{
	//	cout << x << y << endl;
	//}();

	//int k1 = 10;
	//auto f1 = [&] {
	//	
	//	return k1;
	//};
	//k1 = 101;
	//cout << f1() << endl;

	//mutable  

	int x = 10;
	auto y = [=]() mutable {
		
		x = 101; cout << x << endl;
	};
	y();
	cout << x << endl;

	[]() {
		
		[] {
			cout << "he" << endl;
		}();
	}();

	return 0;
}