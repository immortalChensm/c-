#include <iostream>
#include <string>
#include <vector>

#include "Stu.h"
using namespace std;
//static inline const mutable this 
//inline 内联成员函数
//const 成员函数  const对象只能调用这种函数 
//mutable 易变，不稳定 与const 相反
//this 隐式传递参数给类的成员函数【方法】 如果类实例化的对象是const 类名 对象变量名  则：this= const 类名  * const this
//如果是：类名  对象名  则this= 类名  * const this

//构造函数
//=default,=delete 类成员变量初始化
int main()
{
	/*Stu s = { 1,(char*)"jack",100 };

	s.addNum(2);

	s.display();

	s.addScore(20);

	s.display();

	cout << s.getNum() << endl;*/

	const Stu s;//只能调用const 成员  此类中的成员this 默认会传递const Stu *const this

	//s.addScore(1);//const 对象不可以调用
	cout<<s.getNum()<<endl;
	
	Stu s1;//默认会隐式传递Stu *const this对象
	cout<<s1.getNum() << endl;
	return 0;
}