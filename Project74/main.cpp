#include <iostream> 
#include <string> 
#include <time.h>

//������Ż�
using namespace std;

class A {
public:
	int _v1;
	//int _v2;
	int* pv;
public:
	/*A(int v1=0, int v2=0) :_v1(v1), _v2(v2) {
		cout << "constructor run" << endl;
		cout << _v1 << endl;
		cout << _v2 << endl;
	}*/
	A()
	{
		pv = new int(100);
		cout << "call default constructor " << endl;
	}
	A(const A& obj)  {
		//���
		//���û������������캯���Ļ�������֮����и�ֵʱ�ͻᰴλcopy�������ָ���Ա���ͻ����2��������ָ���Ա����ָ����ڴ�ռ���һ����
		//�ᵼ��free2���ڴ棬���³���
		_v1 = obj._v1;
		pv = new int;
		memcpy(pv,obj.pv,sizeof(int));

		cout << "call copy constructor" << endl;
	}
	~A()
	{
		delete pv;
		cout << "call destructor " << endl;
	}

	A(int v) {
		_v1 = v;
		pv = new int(100);
		cout << "call <int>constructor " << endl;
	}
};

//A test(A& obj)
//{
//	/*A objx;
//	objx._v1 = obj._v1 * 2;
//	objx._v2 = obj._v2 * 3;
//	return objx;*/
//	//������ʱ�����ڲ�ͬ�ı������£�������Ż�����
//	//win�¿���ѡ����Ŀ����--���Ż������ֵ��/�������ɡ���������ʱ��飬Ĭ��ֵ��
//}
int main()
{

	/*clock_t start, end;
	start = clock();
	cout << "start:"<<start << endl;
	A obj(10, 20);
	test(obj);
	
	end = clock();

	cout << "end:" << end << endl;*/

	/*A obj1 = 1;
	A obj2 = A(1);
	A obj3 = (A)100;
	A obj4(10);*/

	//�����ǳ����
	A obj;
	obj._v1 = 1;
	A obj2(obj);

	cout << obj2._v1 << endl;

	return 0;
}