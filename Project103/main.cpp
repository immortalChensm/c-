#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace test1
{

	template <typename T>
	T adds(T& a, T& b)
	{
		T x = a + b;
		return x;
	}
	void func()
	{
		int x = 10, y = 20;
		cout << adds(x,y) << endl;
	}
}
namespace test2
{

	template<class T>
	class Test
	{
	public:
		enum status
		{
			ok=1,
			no
		};
	public:
		T x;
		T y;
		Test(T i, T j)
		{
			x = i;
			y = j;
		}
		static int m_i;
		void show(T a);
	};
	template Test<int>;//Ä£°åÊµÀý»¯
	template void Test<int>::show(int a);


	template<class T> int Test<T>::m_i = 0;
	template<class T> void Test<T>::show(T a)
	{
		cout << a << endl;
	}
	
	void func()
	{
		Test<int>::status st;
		st = Test<int>::ok;
		cout << st << endl;

		Test<double> obj(1, 2);
		obj.show(10);

	}
}
int main()
{
	test2::func();
	return 0;
}