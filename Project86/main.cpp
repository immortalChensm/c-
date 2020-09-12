#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A {
public:
	int _i;
	int _j;
	int _k;
	void test()
	{
		cout << 10<< endl;
		cout << _i << endl;
	}
};

int main()
{
	//A obj;
	//obj._i = obj._j = obj._k = 0;

	//int A::* x = &A::_i;
	//obj.*x = 100;

	//void (A:: * y)() = &A::test;

	//(obj.*y)();

	//int A::* z = &A::_j;

	////z = new int{ 10 };
	//z = 0;
	//z = nullptr;
	//z = NULL;
	////z = new int{ 0 };
	//printf("%d\n",z);

	//obj.*z = 100;
	//obj.z = new int{ 100 };

	//类成员函数调用|c++函数编译原理 

	A obj;
	obj._i = 10;
	obj.test();
	//编译器会编译为void new_function_name(const A &this){cout<<this->_i<<endl;}
	//this 是当前对象
	//对象在内存中占用的内存是连续的，访问对象中的成员变量就是通过偏移来实现

	printf("obj=%#x\n",&obj);
	printf("test=%#x\n",&A::test);

	return 0;
}