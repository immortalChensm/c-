#pragma once
#ifndef __CA__H
#define __CA__H 
#include <iostream>
#include <string> 

using namespace std;
template<typename C>
class A {
public:

	/*A(T1 a, T1 b) {
		cout << "call constructor" << endl;
	}*/
	template<typename T1>
	A(T1 a, T1 b);

	template<typename T>
	void show(T data) {
		cout << data << endl;
	}

	void func()
	{
		cout << _data << endl;
	}
	C _data;
};

template<typename C>
template<typename T1>
A<C>::A(T1 a, T1 b)
{

}

template<typename T>
void test(T a, T b)
{
	cout << a + b << endl;
}
#endif // !__CA__H
