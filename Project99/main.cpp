#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

//��̬�ֲ�����||��̬�������
// ��̬����ֻ��ִ��һ�Σ�������������¼�����˳�mainʱ������
// ��̬�������������ȥ��һЩ������Ĳ����Ż�����ڴ�
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
	void myfunc()
	{
		static A objx;
		//static A objy;
		printf("objx:%#x\n",&objx);
		//printf("objy:%#x\n",&objy);
	}
	void func()
	{
	
		myfunc();
		myfunc();
	}
}
namespace test2
{
	class A {
	public:
		A()
		{
			//cout << "A" << endl;
		}
		~A()
		{
			//cout << "~A" << endl;
		}
		int _x;
	};
	void myfunc()
	{
		static A objx[1000'10000];
		for (int i = 0; i < 1000'0000; i++) {
			objx[i]._x = i;
		}
		printf("objx:%#x\n", &objx);
		
	}
	void func()
	{

		myfunc();
		myfunc();
	}
}
int main()
{
	test2::func();
	while (1) {

	}
	return 0;
}