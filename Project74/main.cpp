#include <iostream> 
#include <string> 
#include <time.h>

//������Ż�
using namespace std;

class A {
public:
	int _v1;
	int _v2;
public:
	A(int v1=0, int v2=0) :_v1(v1), _v2(v2) {
		cout << "constructor run" << endl;
		cout << _v1 << endl;
		cout << _v2 << endl;
	}
	A(const A& obj) :_v1(obj._v1), _v2(obj._v2) {
		cout << "call copy constructor" << endl;
	}
	~A()
	{
		cout << "call destructor " << endl;
	}
};

A test(A& obj)
{
	A objx;
	objx._v1 = obj._v1 * 2;
	objx._v2 = obj._v2 * 3;
	return objx;
	//������ʱ�����ڲ�ͬ�ı������£�������Ż�����
	//win�¿���ѡ����Ŀ����--���Ż������ֵ��/�������ɡ���������ʱ��飬Ĭ��ֵ��
}
int main()
{

	clock_t start, end;
	start = clock();
	cout << "start:"<<start << endl;
	A obj(10, 20);
	test(obj);
	
	end = clock();

	cout << "end:" << end << endl;
	return 0;
}