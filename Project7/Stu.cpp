#include "Stu.h"
#include <iostream>
#include <string>
using namespace std;
Stu::Stu(int num, char* name)
{
	_num = num;
	strcpy_s(_name,sizeof(_name),name);
}
Stu::Stu(float c) {
	_score = c;
}

Stu::Stu() {
	cout << "Stu::Stu()µ÷ÓÃ" << endl;
	_score = 0;
}
void Stu::display() {
	cout << _name << _num << endl;
}

