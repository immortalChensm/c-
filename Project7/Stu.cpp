#include "Stu.h"
#include <iostream>
#include <string>
using namespace std;
Stu::Stu(int num, string name,float score) :_num(num), _name(name), _score(score)
{
	/*_num = num;
	_score = score;
	strcpy_s(_name,sizeof(_name),name);*/
}
Stu::Stu(int num)
{
	cout << "Stu::Stu(int num)调用" << endl;
	_num = num;
	_score = 0;
	//strcpy_s(_name, sizeof(_name), "");
}
//Stu::Stu(int num, char* name)
//{
//	_num = num;
//	_score = 0;
//	strcpy_s(_name, sizeof(_name), name);
//}
//Stu::Stu(float c) {
//	_score = c;
//}

Stu::Stu() {
	cout << "Stu::Stu()调用" << endl;
	_score = 0;
}
void Stu::display() {
	cout << _name << _num <<_score<< endl;
}

