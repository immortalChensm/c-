#pragma once

#ifndef __MYARRAY__H
#define __MYARRAY__H  
#include <iostream>
using namespace std;
//ģ��Ĭ�ϲ���
template <typename T=string, int size=10>

class myarray {
private:
	T array[size];
public:
	void myfunc();
};

template <typename T, int size>
void myarray<T,size>::myfunc()
{
	cout << size << endl;

}
#endif  
