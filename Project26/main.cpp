#include <iostream> 
#include <string>
#include <vector>

using namespace std;

//栈上分配，由系统分配
void talk(){
	int a = 10;
static int b = 100;
}


int main()
{
	//自己通过new在堆上分配：称为直接内存管理[new,delete]
	//分配内存并给初始值
	//int* a = new int(100);

	//string *s = new string(5,'j');

	//vector<int>* obj = new vector<int>{ 1,2,3 };

	////“值初始化” 用空括号初始化
	//string* s1 = new string();

	//int* b = new int;//没有确定的值
	//int* c = new int();//有默认的0值


	//auto和new
	string* s1 = new string(3, 'b');
	auto s2 = new auto(s1);

	printf("%p,%p\n",s1,s2);

	auto a = "hello,world";
	auto b = 100;
	auto c = new vector<int>{ 1,2 };
	auto d = new string("hi");

	const int* p = new const int(100);
	*p = 200;
	
	return 0;
}