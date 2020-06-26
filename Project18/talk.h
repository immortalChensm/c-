#pragma once
#ifndef __TALK__H 
#define __TALK_H 

#include <iostream>
using namespace std;
template <typename T,int a>
void talks(T name) {
	cout << name << " is " << a << endl;
}
#endif // !__TALK__H 
