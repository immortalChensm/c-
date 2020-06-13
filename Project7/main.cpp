#include <iostream>
#include <string>
#include <vector>
#include "Stu.h"
using namespace std;


//类的构造函数 ,explicit,初始化列表
//构造函数是类中的特殊成员函数，由系统自动调用
//类  构造函数  函数的默认参数 
int main()
{

	/*Stu* s = new Stu(1,(char*)"china");
	s->display();
	delete s;
	Stu* s1 = new Stu{98.5f};
	
	cout << s1->_score << endl;

	delete s1;


	Stu s2;

	cout << s2._score << endl;*/

	Stu s1{};
	Stu s2();
	Stu s3;
	Stu s4 = {};
	Stu *s5 = new Stu;
	Stu *s6 = new Stu();
	Stu* s7 = new Stu{};
	Stu s8 = Stu();
	Stu s9 = Stu{};
	
	
	//Stu s(1000, (char*)"jack");
	//s.display();

	//Stu s1{ 100,(char*)"tom" };

	//s1.display();

	//Stu s2({ 200,(char*)"lucy" });
	//s2.display();

	////Stu s3{(300,(char*)"tony")};
	////s3.display();

	//Stu* s3 = new Stu(300, (char*)"ton");
	//s3->display();

	//Stu* s4 = new Stu{ 400,(char*)"china" };
	//s4->display();

	//Stu* s5 = new Stu({ 500,(char*)"japanese" });
	////Stu* s6 = new Stu{(500,(char*)"japanese" )};
	//s5->display();

	//Stu s6 = Stu{ 100,(char*)"korean" };
	//Stu s7 = Stu(200,(char*)"money");
	////Stu s7 = Stu{(300,(char*)"factory")};
	//Stu s78 = Stu({300,(char*)"shop"});
	//Stu s79 = Stu({ 300 }, {(char*)"top"});
	//s79.display();

	//Stu s10 = Stu{(600),((char*)"hiddeen")};
	//s10.display();
	return 0;
}