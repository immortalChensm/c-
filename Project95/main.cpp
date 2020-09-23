#include <iostream>
#include <string>
#include <vector> 

using namespace std;

namespace test
{
	class A {
	public:
	};

	//inline 内联函数  需要设置项目属性的“优化--》内联函数扩展"
	// 开启inline内联函数后，它是直接函数内的代码
	inline int my(int x)
	{

		return 100 * x;
	}
	void func()
	{

		int x = my(10);
		cout << x << endl;
	}
}
int main()
{
	test::func();
	return 0;
}