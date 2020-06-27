#include <iostream> 
#include <string> 

#include "myvector.h"
#include "myarray.h"
//类模板
//类模板声明|类模板定义|类模板实例化（调用）
//类模板在使用的时候必须给类型参数值，编译不会自己推断的
//模板的非参数参数不支持float,double,string,类

using namespace std;
typedef int* test;
int main()
{

	/*test a;
	int b = 10;
	a = &b;*/

	//模板实例化
	myvector<int> a;
	//myvector<float> b;
	//myvector<string> c;

	myarray<int, 100> a1;
	myarray<char> b;

	b.myfunc();
	a1.myfunc();

	return 0;
}