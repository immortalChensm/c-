#include <iostream> 
#include <string> 

using namespace std;

//类型转换构造函数||类型转换运算符（类型转换函数）
class TestInt
{
public:
	//explict 只能显示调用，不可以隐式调用
	//explicit TestInt(int i) :_num(i)
	 TestInt(int i) :_num(i)
	{
		if (i < 0)i = 0;
		if (i > 100)i = 100;
	}

	//类型转换函数
	//operator int()const {
	explicit operator int()const {
		cout << "调用了类型转换函数" << endl;
		return _num;
	}

public:
	int _num;
};
int main()
{

	//类型转换构造函数示例
	//TestInt x = 10;
	/*TestInt y1(10);
	TestInt y2{ 10 };
	TestInt y3 = TestInt(1);*/

	//类型转换运算符（类型转换函数）
	/**
	operator type() const 
	type 数据类型
	const 可有可无
	()内无参数


	**/

	TestInt a = 10;
	
	//printf("%d\n",a);

	//int k = a;

	//int j = 10 + a;//隐式调用
	int m = 100 + a.operator int();//显示调用
	return 0;
}