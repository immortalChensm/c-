#include <iostream> 
#include <string> 
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

//算法使用
using namespace std;

namespace test1
{
	//算法跟容器的迭代器种类有关，不同种类的迭代器，有不同的算法代码实现 
	void myfunc(int i)
	{
		cout << i << endl;
	}
	void func()
	{

		//1、for_each

		vector<int> iv = { 1,2,3,4,5 };
		for_each(iv.begin(),iv.end(),myfunc);
		
	}
}

int main()
{

	test1::func();
	return 0;
}