#include <iostream>
#include <string> 
#include "ca.h"

using namespace std;
//ģ����ʾʵ��������
template A<float>;
template void test(int a, int b);

void ptfunc()
{
	A<float> obj(1, 2);
}