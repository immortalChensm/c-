#include <iostream>
#include <string>
#include <vector> 

using namespace std;

namespace test
{
	class A {
	public:
	};

	//inline ��������  ��Ҫ������Ŀ���Եġ��Ż�--������������չ"
	// ����inline��������������ֱ�Ӻ����ڵĴ���
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