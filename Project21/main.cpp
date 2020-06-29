#include <iostream>
#include <string> 

#include "ca.h"
using namespace std;

extern template A<float>;

int main()
{
	//普通类的成员函数模板

	//A obj;
	//obj.show<int>(3);

	//obj.show("china");

	//类模板的成员函数模板

	A<float> obj(1,2);
	//obj._data = 12.3f;
	//obj.func();

	//A<char>* obj1 = new A<char><int>(100,200);

	//模板显示实例化，模板声明

	return 0;
}