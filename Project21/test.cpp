#include <iostream>
#include <string> 
#include "ca.h"

using namespace std;
//模板显示实例化定义
template A<float>;
template void test(int a, int b);

void ptfunc()
{
	A<float> obj(1, 2);
}