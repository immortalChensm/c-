#include <iostream> 
#include <string> 

#include "myvector.h"
#include "myarray.h"
//��ģ��
//��ģ������|��ģ�嶨��|��ģ��ʵ���������ã�||typename��ʹ�ó���||����ָ��||����ģ���ʹ��ʾ��||Ĭ��ģ�����
//��ģ����ʹ�õ�ʱ���������Ͳ���ֵ�����벻���Լ��ƶϵ�
//ģ��ķǲ���������֧��float,double,string,��

//typenameʹ�ó���
//��ģ�壬����ģ��  ������ͳ�Ա

//ģ��Ĭ�ϲ���
//��ģ�壺���壬������ʹ�á�ʵ����ʱ�������ģ��ʵ������������ȱʡֵ��
//����ģ�壺���壬����ʱ��ģ��������ͺ�������������ȱʡֵ��
using namespace std;
typedef int* test;

//typename ���߱���T::size_type ��һ����������
template <typename T>
typename T::size_type getLength(const T& c) {

	if (c.empty()) {
		return 0;
	}
	return c.size();
}
/**

string::size_type getLength(const string &c){
	
	if(c.empty(){
	
	}
}
**/ 

class A {
public:
	int _a;
};


//��ģ������
template <typename T>
class B {
public:
	typedef T* uint;
public:
	uint getSize(int a);
};

//��ģ�嶨��
template <typename T>
typename B<T>::uint B<T>::getSize(int a)
{
	uint obj = new T;
	obj->_a = a;
	return obj;
}

//����ָ����Ϊ�����Ĳ���
int testa(int a, int b)
{
	return a + b;
}
typedef int (*Func)(int, int);

class c {
public:
	c() {

	}
	int operator()(int a, int b) {

		//cout << (a + b) << endl;
		return a + b;
	}
};
void testaa(int a, int b, Func function) {

	cout << function(a,b) << endl;
}

//ģ��Ĭ�ϲ���
//template <typename T,typename F=c>
//void testfunc(const T& a, const T& b, F function=F()) {

template <typename T, typename F = Func>
void testfunc(const T & a, const T & b, F function = testa) {


	cout << function(a, b) << endl;
}


int main()
{
	//������ָ����Ϊ��������
	//testfunc<int,Func>(1,2,testa);
	testfunc<>(1,2);

	//������������Ϊ������֧�������Ǵ��������˺��������������Ϊ�˿ɵ��ö���
	//c obj;
	//testfunc(10, 20,obj);

	//ģ��Ĭ�ϲ�������
	//myarray<> my;//����ģ��ʱ��ʵ����ģ�塿��û���ṩ ģ�����������ʹ������Ĭ�ϲ�����
	//ģ�������ʵ�ε���ʱ  �û���ִ��ʵ�λ����ɱ�����ָ����

	//testaa(100, 200,testa);

	//��ģ��ʹ�á�ʵ������
	/*B<A> obj;
	A *obja;
	obja = obj.getSize(10);

	cout << obja->_a << endl;*/


	/*test a;
	int b = 10;
	a = &b;*/

	//ģ��ʵ����
	//myvector<int> a;
	//myvector<float> b;
	//myvector<string> c;

	//myarray<int, 100> a1;
	//myarray<char> b;

	//b.myfunc();
	//a1.myfunc();

	//string str = "china";
	//string::size_type size = getLength<string>(str);

	//cout << size << endl;
	return 0;
}