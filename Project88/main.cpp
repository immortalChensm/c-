#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Base {
public:
	void test()
	{
		cout << "Base" << 11 << endl;
	}
	virtual void talk(int v=1)
	{
		cout << "Base::talk" <<v<< endl;
	}
};
class Derive :public Base {
public:
	void test()
	{
		cout << "Derive"<<11 << endl;
	}
	virtual void talk(int v=2)
	{
		cout << "Derive::talk" <<v<< endl;
	}
};
class Dervie2 :public Base {
public:
};


int main()
{
	//1 静态类型和动态类型 
	//对象定义时的数据类型
	/*Base obj1;
	Base* obj2;
	Derive* obj3 = new Derive();

	Base* obj4 = new Derive();*///obj4 静态类型是Base * ，动态类型是Dervie *

	//动态类型  是指对象在运行时才决定的数据类型 在运行过程中可以动态的修改，指针或是引用才有
	//obj2 = obj3;
	

	//2 静态绑定和动态绑定  
	// 静态绑定  绑定是的静态类型，所对应的函数或是属于依赖于对象的静态类型  发生在编译期
	// 动态绑定  绑定的是动态类型，所对应的函数或是属性依赖于对象的动态类型  发生在运行期
	// 普通成员函数是静态绑定，虚函数是动态绑定
	//3继承的非虚函数
	/*
	Derive objx;
	Derive* objx1 = &objx;

	objx1->test();

	Base* objx2 = &objx;
	objx2->test();*/

	cout << "00000000000000000000000000000" << endl;

	Base* obj1 = new Base();
	Derive* obj2 = new Derive();
	obj1->talk();
	obj2->talk();

	obj1 = obj2;
	obj1->talk();//obj1 静态类型是Base，但动态类型发生了变化，发生了动态绑定

	//虚函数动态绑定，带有默认参数时的坑

	//6 多态性  
	//1 从代码实现上
	//类有虚函数，调用时必须调用虚函数，如果调用时，是在虚函数表里查找到函数入口地址，然后再执行这个函数，就是多态
	//反之则不是多态

	//2 从表现形式上

	return 0;
}