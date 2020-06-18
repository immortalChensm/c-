#ifndef __WOMEN__H
#define __WOMEN__H 
#include "Human.h"
#include <iostream>
using namespace std;
class Women:public Human
{
public:
	Women() = default;
public:
	void eat() {
		cout << "women eat " << endl;
	}
};
#endif 
