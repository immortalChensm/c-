#include <iostream> 
#include <string> 

using namespace std;
//函数新特性，内联函数，const,const char * char const * char * const的区别
auto show()->void {
	cout << "show" << endl;
}

auto test()->int {
	return 12;
}
inline void hello() {//内联函数  在调用时会替换为函数体，不会进栈，但还是依靠编译器的选择是否支持
	//内联函数体不易过多
	cout << "hello" << endl;
}

#define HI \
cout << "ok" << endl;\
\


int* funca() {
	int temp = 8;
	return &temp;
}

int* funca(int i) {

	return &i;
}
int main()
{

	/*show();
	cout << test();
	hello();

	HI;*/

	/*int* p = funca();
	*p = 100;


	cout << *p << endl;*/

	//char str[] = "php is best!";

	//const char* p = str;
	//char const* p = str;
	/*char* const p = str;
	char strs[] = "javascript is the best!";*/
	//p = strs;

	//*p = 'J';

	////*p = 'Y';

	//cout << p << endl;

	//内存地址:|1byte|1byte|1byte
	//内存值： |p|h|p
	//下标名称：|str[0]|str[1]|str[2]|
	//const char* p = str;
	//char const* p = str;
	//const char *p == char const *p

	//char* p = str;
	//p++;//内存地址移动
	//p++;
	//*p = 'y';//第3个内存地址上做修改  不可以
	//cout << p << endl;

	//char* const p = str;
	//变量名称 p
	//变量内存地址 0x0a
	//变量内容：str[0]的内存地址


	//p++;//p指向的内存不可再修改
	//*p = 'Y';//内存上的数据可以修改

	//cout << p << endl;

	//结论
	/**
	const char *p
	char const *p
	p指向的内存地址移动【可修改】，但内存上的数据不可以修改


	char * const p
	p指向的内存不可以修改，但内存上的数据可以修改

	**/
	char str[] = "php is best";
	//const const const char const* const const p  = str;
	const char * const p  = str;

	//str++;
	//*str = 'Y';

	//p++;
	//*p = 'Y';
	cout << str << endl;
	return 0;
}