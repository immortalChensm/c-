#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

//����ȫ�֣��ֲ�����������
using namespace std;
namespace test
{

	class A {
	public:
		A()
		{
			cout << "A" << endl;
		}
		~A()
		{
			cout << "~A" << endl;
		}
		int _x;
	};
	void func()
	{
		//A ���������� �ᱻ�������ڶദ�������
			A obj;
		
			
		int a = 10;
		if (a == 100) {
			return;
		}
		else if (a == 102) {
			return;
		}
		int b = 3;
	}
}
int main()
{
	test::func();
	return 0;
}