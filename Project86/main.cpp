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

	//���Ա��������|c++��������ԭ�� 

	A obj;
	obj._i = 10;
	obj.test();
	//�����������Ϊvoid new_function_name(const A &this){cout<<this->_i<<endl;}
	//this �ǵ�ǰ����
	//�������ڴ���ռ�õ��ڴ��������ģ����ʶ����еĳ�Ա��������ͨ��ƫ����ʵ��

	printf("obj=%#x\n",&obj);
	printf("test=%#x\n",&A::test);

	return 0;
}