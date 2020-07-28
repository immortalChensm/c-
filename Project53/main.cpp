#include <iostream>
#include <vector>
using namespace std;
//迭代器
namespace test1
{
	void func()
	{
		//迭代器：是一种遍历容器内元素的，数据类型，有点像指针，用来指向容器中的某个元素

		vector<int> iv = { 1,2,3 };
		vector<int>::iterator iter;

		iter = iv.begin();//可以返回一个迭代器 可看作返回一块内存的首地址[指针]
		cout << *iter << endl;
		iter++;
		cout << *iter << endl;

		for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); iter++)
		{
			cout << *iter << endl;
		}

		//反向迭代器
		for (vector<int>::reverse_iterator iter=iv.rbegin(); iter!=iv.rend(); iter++) {
			cout << *iter << endl;
		}
	}
}

int main()
{
	test1::func();
	return 0;
}