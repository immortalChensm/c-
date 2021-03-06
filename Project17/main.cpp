﻿#include <iostream> 
#include <string> 

using namespace std;

//类型转换构造函数||类型转换运算符（类型转换函数）||类成员函数指针(普通函数，静态函数，虚函数)||类成员变量指针
//类型转换运算函数（将类对象转换函数指针）
//类成员函数指针（除了静态类，基它调用都要绑定一个对象才能调用）
class TestInt
{
public:
	//定义一个函数指针
	//typedef void(*tfpoint)(int);
	using tfpoint = void(*)(int);
public:
	static void myfunc(int v1){

		cout<<"v1="<<v1<<endl;
	}
	//tfpoint就上面定义的using或是typedef上面定义的数据类型
	operator tfpoint()
	{
		return myfunc;
	}
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
		cout << "call operator type function" << endl;
		return _num;
	}

	operator float(){
		return _num;
	}

	operator short int(){
		return _num;
	}

public:
	int _num;
};

class CT1{
public:
	CT1(int v){}
};
class CT2{
public:
	CT2(int v){}
};

void testfunc(const CT1 &c){};
void testfunc(const CT2 &c){};

class CT
{
public:
	void ptfunc(int value){cout<<"ptfunc called,value="<<value<<endl;}
	virtual void virtualptfunc(int value){cout<<"virtualptfunc called,value="<<value<<endl;}
	static void staticptfunc(int value){cout<<"staticptfunc called,value="<<value<<endl;}

	virtual void test(char a)
	{
		cout << "test" << a << endl;
	}

	int _a;
	static int _b;

};

int CT::_b = 0;

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

	//TestInt a = 10;
	
	//printf("%d\n",a);

	//int k = a;

	//int j = 10 + a;//隐式调用
	//int m = 100 + a.operator int();//显示调用

	//int k = static_cast<int>(a)+1000;//显示的调用

	//类对象转换为函数指针
	//TestInt jack(10);
	//jack(1000);//隐式的调用operator tfpoint 返回的函数

	//jack.myfunc(1);
	//jack.operator TestInt::tfpoint()(666);

	//类型转换函数的二义性
	//TestInt a(10);

	//int k = a+10;
	//testfunc(100);
	//testfunc(CT1(100));

	//类成员函数指针
	//1/类的普通成员函数
	//定义格式：类型  类名::*指针变量名;
	//获取类成员函数指针格式：&类名::成员函数名
	void (CT::*ptfunc)(int);//类成员普通函数指针变量定义
	ptfunc = &CT::ptfunc;
	//类的成员函数属于类，不属于类对象，只要有类存在，就有类成员函数的地址
	//但是要使用这个类成员函数指针，必须要把它绑定到一个对象上才能使用

	//调用格式：对象名.*函数指针变量名(参数) 如果对象是指针则是：对象指针->*函数指针变量名(参数)
	//ptfunc(100);
	CT a,*b;
	b = &a;
	(a.*ptfunc)(1);
	(b->*ptfunc)(2);

	//2、类的虚成员函数
	void (CT::*virtualfunc)(int) = &CT::virtualptfunc;

	(a.*virtualfunc)(10);

	//3、获取类静态成员函数指针
	//*指针变量名声明
	//获取类静态成员函数指针  &类名：：成员函数名

	void (*staticfunc)(int) = &CT::staticptfunc;
	(staticfunc)(1000);

	void (CT:: * test)(char) = &CT::test;

	(a.*test)('a');

	//类成员变量指针
	int CT::*jj = &CT::_a;

	CT obj;

	obj.* jj = 100;

	cout << obj.*jj << endl;
	//类的静态成员变量地址

	int* testa = &CT::_b;

	*testa = 10;
	cout << *testa << endl;
	cout << CT::_b << endl;

	//获取类的成员函数指针  &类名::成员函数名
	//获取类的成员变量指针   &类名::成员变量名
	//定义类的成员函数指针  数据类型 (类名::*指针变量名)(参数列表) = &类名::成员函数名

	//定义类的静态成员函数指针   数据类型(*指针变量名)(参数列表) = &类名::静态成员函数名

	//定义类的普通成员变量指针  数据类型 类名::*指针变量名 = &类名::普通变量名


	//静态和非静态的区别
	//静态定义指针变量时：没有类名 如 int *test = &class::xxx // void (*test)(int) = &class:xxx
	//非静态：有类名  如 int class::*test = &class:xxx // void (class::*test)(int) = &class:xxx
	return 0;
}