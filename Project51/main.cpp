#include <iostream> 
#include <string> 
#include <list>
#include <map>
#include <vector> 

using namespace std;
namespace test1
{

	void func()
	{
		//1、分配器，一般和容器一起使用，其实是个内存分配器
		vector<int, std::allocator<int>> obj;

		obj.push_back(1);

		cout << obj[0] << endl;

	}
}
namespace test2
{
	void func()
	{

		std::allocator<int> alloc;
		int* p = alloc.allocate(3);//分配了3个类型为int(12个字节）的内存

		int* q = p;
		*q = 1; q++;
		*q = 2; q++;
		*q = 3;

		alloc.deallocate(p, 3);//释放内存
	}
}
//分配器
int main()
{
	test2::func();
	return 0;
}