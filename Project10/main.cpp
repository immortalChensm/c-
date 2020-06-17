#include "Human.h"
#include "Men.h"
#include <iostream> 
/**

继承方式：public 
如果父类是public 在子类里面可以访问  子类外也可以访问
如果父类是protected 在子类里可以访问 不可以访问

如果父类是private 子类里外都不可以访问

继承方式：proteced  
如果父类是public 在子类里可以访问，子类外不可以访问
如果父类是proteced 在子类里可以访问，子类外不可以访问

继承方式：private
如果父类是public,proteced 在子类里可以访问，子类外不可以访问
**/

//继承|成员遮蔽|继承方式|using
/**
mutable
const
static

const
auto
inline
operator
析构函数
构造函数
	默认构造函数 =default,=delete
	带一个参数的类型转换构造函数
	带一个参数的拷贝构造函数
	带多个参数的构造函数
	explcit
成员函数重载|成员函数遮蔽【继承时】
**/
int main()
{
	Men jack;

	//jack.say();


	//成员函数遮蔽访问 通过using修改
	jack.talk(2);
	jack.talk(1);

	jack.talk();

	jack.setPwd();
	
	return 0;
}