#pragma once

#ifndef __MYARRAY__H
#define __MYARRAY__H  
#include <iostream>
using namespace std;

template <typename T, string size=10>

class myarray {
private:
	T array[size];
public:
	void myfunc();
};

template <typename T, string size>
void myarray<T,size>::myfunc()
{
	cout << size << endl;

}
#endif  
