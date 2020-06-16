#include "Stu.h"
#include <iostream>
#include <string>
using namespace std;
Stu::Stu(int num, string name, float score) :_num(num), _name(name), _score(score)
{

}
Stu::Stu()//默认隐式的传递Stu * const this 参数  此this指向的内存地址不可以修改
//this 会指向非const 对象的const 指针
//如果是const 对象，则指向const对象的const指针
{
	_num = 0;
	_score = 0;
	_name = "";

	this->_num = 888;
}
void Stu::display() {
	cout << _name << _num << _score << endl;
}

int Stu::getNum()const
{
	_num = 100; //能修改的理由是此成员前缀加上了mutable关键字
	return _num;
}

