#include <iostream> 
#include <string> 
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

namespace test1
{
	//自定义函数对象
	template<typename T>
	struct Aplus {
		T operator()(T a, T b)
		{
			//return a + b;
			return a > b;
		}
	};
	void func()
	{
		/*Aplus<int> a;
		cout << a(1, 2) << endl;
		cout << Aplus<float>()(1.4f,2.3f) << endl;

		cout <<"plus:"<< plus<int>()(1,20) << endl;
		cout <<"minux:"<< minus<int>()(1,20) << endl;

		cout <<"equal_to:"<< equal_to<int>()(1, 20) << endl;
		cout <<"less:"<< less<int>()(1, 20) << endl;

		cout << "logic_and:" << logical_and<int>()(1, 20) << endl;
		cout << "logic_or:" << logical_or<int>()(1, 20) << endl;

		cout << "bit_and:" << bit_and<int>()(1, 20) << endl;
		cout << "bit_or:" << bit_or<int>()(1, 20) << endl;*/

		vector<int> iv{ 5,8,3,2,1,7 };

		//sort(iv.begin(),iv.end(),less<int>());
		sort(iv.begin(),iv.end(),Aplus<int>());

		for_each(iv.begin(), iv.end(), [](int v) {
			cout << v << endl;
		});
	}
}

namespace test2
{

	class A {
	public:
		bool operator()(int i) {
			//return i > 2;
			return greater<int>()(i,2);
		}
	};
	void func()
	{
		//适配器  在原有基础上做一些添加或是修改，删除的操作
		//适配器分类：容器适配器，算法函数适配器，迭代器适配器

		//1、容器适配器  stack,queue,deque  

		//2、算法函数适配器
		vector<int> iv{ 1,2,3,4,5,3,2 };

		int c = count(iv.begin(),iv.end(),2);
		cout << c << endl;

		//int c1 = count_if(iv.begin(),iv.end(),A()); 
		int c1 = count_if(iv.begin(),iv.end(),bind(greater<int>(),2,placeholders::_1));

		cout << c1 << endl;

	}
}
int main()
{
	test2::func();
	return 0;
}