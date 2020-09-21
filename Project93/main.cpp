#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

namespace test
{
	//编译器在release之下做了循环优化
	__int64 myf(int v)
	{
		__int64 ic = 0;
		for (int i = 0; i < 1000000; i++) {
			ic += 1;
		}
		return ic;
	}
	void func()
	{
		clock_t start, end;
		start = clock();
		__int64 inc = 0;
		for (int x = 0; x < 100; x++) {
			inc += myf(x);
		}
		end = clock();

		cout << "time:" << end - start << endl;
		cout << "inc=" << inc << endl;

	}
}

int main()
{
	test::func();
	return 0;
}