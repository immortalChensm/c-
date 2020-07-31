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
int main()
{
	test1::func();
	return 0;
}