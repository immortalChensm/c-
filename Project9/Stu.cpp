#include "Stu.h"
#include <iostream> 
using namespace std;
Stu::Stu(int age, int num, int sex):_age(age),_num(num),_sex(sex)
{

}

void Stu::display()
{
	cout <<"_age="<< _age <<"_num="<< _num << "_sex="<<_sex << endl;
}

Stu::Stu(int age)
{
	_age = age;
}

Stu::Stu(Stu& s, int a , int b)
{
	cout << "������Stu::Stu(Stu& s, int a, int b)�������캯��" << endl;
}