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
		//1����������һ�������һ��ʹ�ã���ʵ�Ǹ��ڴ������
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
		int* p = alloc.allocate(3);//������3������Ϊint(12���ֽڣ����ڴ�

		int* q = p;
		*q = 1; q++;
		*q = 2; q++;
		*q = 3;

		alloc.deallocate(p, 3);//�ͷ��ڴ�
	}
}
//������
int main()
{
	test2::func();
	return 0;
}