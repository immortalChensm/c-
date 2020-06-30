#include <iostream>
#include <string>

using namespace std;

namespace test {

	//1、可变参函数模板
	template<typename ...T>//...T 一堆类型 或叫一包类型
	void pfunc(T ... args)//...args  一堆参数 或叫一包参数
	{
		cout << sizeof...(args) << endl;
		cout << sizeof...(T) << endl;
	}

	//递归终止
	void pfunc2()
	{
		cout << "递归终止pfunc2..." << endl;
	}

	//2、一包参数的展开 函数递归
	template<typename T,typename ...U>
	void pfunc2(const T& firstArgs, const U& ... args)
	{
		cout << "第一个参数的值：" << firstArgs << endl;
		pfunc2(args...);
	}
	
	/****************************************************/
	//3、类继承递归 包类型参数展开
	template<typename ...args>
	class demo {
	
	};

	//0 个参数的特化版本
	template<>class demo<> {
	public:
		demo() {

			cout << "demo<> class constructor" << endl;
			printf("demo<>::demo=%p\n", this);
		}
	};
	template<typename First,typename ...Others>
	class demo<First, Others...>:private demo<Others...>{
	
	public:
		demo():_i(0) {

			cout << "demo class constructor" << endl;
			printf("demo::demo=%p\n",this);
		}

		demo(First parf, Others...paro) :_i(parf), demo<Others...>::demo(paro...) {
			cout << "demo(First parf, Others...paro) class constructor" << endl;
			printf("demo::demo=%p\n", this);
			cout << "i==" << _i << endl;
		}

		First _i;
	};
	/****************************************************/

	void func()
	{
		//pfunc<int,double>(1,2,3,4,5);
		//pfunc2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

		//demo<int, double, char> obj;
		demo<int, double, char> obj(1,2.34f,'a');
	}
}
int main()
{
	test::func();
	return 0;
}