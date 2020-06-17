#ifndef __HUMAN__H
#define __HUMAN__H 

#include <iostream>
using namespace std;
class Human
{
public:
	Human();
	Human(int age);
public:
	int _age;
	char _name[100];
	void say(){}
public:
	void talk();
	void talk(int num);
private:
	int _money;
	void account(){
	
		cout << "account:12" << endl;
	}
protected:
	int _pwd;
	void setPwd(){
		cout << "account:12" << endl;
	}
};
#endif 
