#include <iostream>
#include <string>
#include <vector>
#include "Stu.h"
using namespace std;

//类，对象拷贝，私有成员

void initStu(stu& s, int number, char* name)
{
	s._number = number;
	strcpy_s(s._name,sizeof(s._name),name);
}
extern void test();
int main()
{

	/*stu s1;
	s1.number = 100;
	stu* s2 = &s1;
	s2->number = 200;
	cout << s1.number << endl;*/


	stu s;
	
	s.initStu(200,(char*)"tom");
	//initStu(s,100,(char*)"jack");
	/*s.initStu(200,(char*)"tom");
	cout << s._number << s._name << endl;*/
	
	
	//test();

	/*stu s1 = s;
	cout << s._number << s._name << endl;
	stu s2(s);
	cout << s2._number << s2._name << endl;
	stu s3{ s };
	cout << s3._number << s3._name << endl;

	stu s4 = { s };
	stu s5 = (s);
	cout << s5._number << s5._name << endl;
	for (auto x : { s1,s2,s3,s }) {
		cout << x._number << x._name << endl;
	}

	stu s6{ (s) };
	cout << "*******************" << endl;
	cout << s6._name << s6._number << endl;

	stu s7({ s });
	cout << "-------------------------" << endl;
	cout << s6._name << s6._number << endl;

	stu s8((s));
	cout << "++++++++++++++++++++++" << endl;
	cout << s6._name << s6._number << endl;
	stu s9[]{ (s),(s),(s),{s},{(s)}};
	for (auto x : s9) {
		cout << x._name << endl;
	}*/
	return 0;
}