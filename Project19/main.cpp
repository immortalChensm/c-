#include <iostream> 
#include <string> 

#include "myvector.h"
#include "myarray.h"
//��ģ��
//��ģ������|��ģ�嶨��|��ģ��ʵ���������ã�
//��ģ����ʹ�õ�ʱ���������Ͳ���ֵ�����벻���Լ��ƶϵ�
//ģ��ķǲ���������֧��float,double,string,��

using namespace std;
typedef int* test;
int main()
{

	/*test a;
	int b = 10;
	a = &b;*/

	//ģ��ʵ����
	myvector<int> a;
	//myvector<float> b;
	//myvector<string> c;

	myarray<int, 100> a1;
	myarray<char> b;

	b.myfunc();
	a1.myfunc();

	return 0;
}