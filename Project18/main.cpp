#include <iostream> 

#include <string> 

#include "talk.h"

//ģ�嶨��|ģ��ʹ�ã�Ҳ��ģ��ʵ������||ģ����������Ͳ����������Ͳ�����
using namespace std;

//int adds(int v1, int v2) {
//	return v1 + v2;
//}
//double adds(double v1, double v2)
//{
//	return v1 + v2;
//}
//ģ��  ���Ͳ��� ��������Ϊһ������
template <typename T>

T adds(T v1, T v2)
{
	T sum = v1 + v2;
	return sum;
}
//����ģ��֮�󣬱�����Լ��ƶ�ģ��������������ͣ���������ʵ����һ���ض����͵ĺ���
template <class T1>

void show(T1 v) {
	cout << v << endl;
}
//ģ������Ͳ���
template <int a,int b>
int adds2() {
	int c = a + b;
	return c;
}



class B {
	
public:
	using obj = void(*)();
	static void getObj()
	{
		cout << "getObj" << endl;
	}
	operator obj() {

		return getObj;
	}

	
};

template <typename T,int a>
void talk(T name) {
	cout << name << " is " << a << endl;
}

template<unsigned int l1,unsigned int l2>//ģ������Ͳ���
int charstrcmp(const char(&p1)[l1], const char(&p2)[l2])
{
	return strcmp(p1,p2);
}

template<int a,int b>
void sums(int arr1[a], int arr2[b]) {
	
	int result[a] = {};
	for (int i = 0; i < a; i++) {
		result[i] = arr1[i] + arr2[i];
	}
	//return result;
}
extern void tom();
int main()
{

	/*int a = adds(1, 2);
	cout << a << endl;

	double b = adds(1.12, 3.21);
	cout << b << endl;

	show(100);
	show("china");*/

	//ģ�嶨�壺template <typename T>T �����Ͳ���  ��ʾ����
	//�����Ͳ���  ��ʾһ��ֵ

	//ģ������Ͳ����ĺ�������
	//int d = adds2<100,200>();//template <int a,int b> ��ʾ��ָ�������Ͳ�����ֵa=100,b=200
	//��ʾ��ָ��ģ������������Ͳ�����ֵ��
	//cout << d << endl;

	//template<typename T> ��ʾ��ָ��T������ֵΪint
	//int e = adds<int>(1, 2);
	//cout << e << endl;

	//template <typename T>
	//int f = adds(1, 5);//�����Լ��ƶ�T������ֵΪint
	//cout << f << endl;

	//B b;
	//b();

	//int dd = 1;
	//int g = adds2(dd++, 10);������

	//talk<string,100>("jack");

	//template<unsigned int l1,unsigned int l2>//ģ������Ͳ���
	//int charstrcmp(const char(&p1)[l1], const char(&p2)[l2])
	//int result = charstrcmp("jack", "tom");//�ڵ��õ�ʱ��û��ָ��l1,l2�ĳ���
	//���������Լ��ƶϳ��������ض���ģ�庯��
	//int charstrcmp(const char(&p1)[5], const char(&p2)[4]){}

	//int result1 = charstrcmp<5, 5>("jack", "lucy");

	//int nums[] = {1,2,3,4,5};
	//sums<6,6>(nums,nums);

	talks<string,100>("lucy");

	tom();
	return 0;
}