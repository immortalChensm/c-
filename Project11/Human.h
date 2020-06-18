#ifndef __HUMAN__H
#define __HUMAN__H 

#include <iostream>
using namespace std;
class Human
{
public:
	Human();
public:
	virtual void eat() {
		cout << "human eat " << endl;
	}

};
#endif 
