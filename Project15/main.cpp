#include <iostream> 
#include <string> 

using namespace std;
//对象移动
//移动构造函数||移动赋值运算符
//总结：可在适当的场景下给类添加移动构造函数和移动赋值函数
//对象移动之后，尽量斩断源对象所关联【指向】的内存
//尽量给 移动函数加上禁止抛出noexecpt关键字异常

class B {
public:
	B() :_a(100) {
		//cout << "B构造函数被执行" << endl;
	}

	B(const B& t) :_a(t._a) {
		//cout << "B拷贝函数被执行" << endl;
	}

	~B() {
		//cout << "B析构函数被执行" << endl;
	}
	int _a;
};

class A {
public:
	//默认构造函数
	A(int d=0) :_obj(new B), _data(d) {
		cout << "A构造函数被执行" <<"data="<<_data<< endl;
	}
	//拷贝构造函数
	A(const A& tmp) :_obj(new B(*(tmp._obj))) {
		cout << "A拷贝函数:tmp.data=" << tmp._data << endl;
		_data = tmp._data;
		cout << "A拷贝函数被执行" << "data=" << _data<< endl;
	}
	//移动构造函数
	//告诉标准库：不抛出任何异常
	A(A&& tmp)noexcept :_obj(tmp._obj), _data(tmp._data) {


		cout << "A移动函数:tmp.data=" << tmp._data << endl;
		printf("A移动函数之tmp对象地址：%#X\n", &tmp);

		tmp._obj = nullptr;
		tmp._data = 1000;

		cout << "A移动函数被执行" << "data=" << _data<< endl;
	}

	//拷贝赋值运算符
	A& operator=(const A& src)
	{
		
		if (&src == this) {
			return *this;
		}
		delete _obj;
		_obj = new B(*(src._obj));
		_data = src._data;
		cout << "类A的拷贝赋值运算符函数"<<endl;
		return *this;
	}
	//移动赋值运算
	A& operator=( A&& src) noexcept
	{
		if (&src == this) {
			return *this;
		}
		delete _obj;
		_obj = src._obj;
		src._obj = nullptr;
		_data = src._data;
		cout << "类A的移动赋值运算符函数" << endl;
		return *this;
	}

	virtual ~A() {
		delete _obj;
		cout << "A析构函数被执行" << "data=" << _data << endl;
	}
public:
	B* _obj;
	int _data;
};

static A getA()
{
	A x(1);//生成临时对象
	printf("内部对象地址：%#x\n", &x);
	return x;//返回 左值 返回时  会析构  
}

//拷贝构造函数：只是内存间数据的拷贝
//移动构造函数：内存所有者的转让
int main()
{
	//移动构造函数
	//1：A移动给B,A就不能再使用了
	//2: 移动不是把另一个地址的数据弄到另一个地址，只是所有者变更
	//拷贝构造函数：类  类名(const 类 &x) {} &x 是左值引用 调用时得传递左值
	//移动构造函数：类  类名(const 类 &&x) {} &xx是右值引用  调用时给右值


	//左值：有内存空间 ，调用时只能给右值
	//左值引用：同理有内存空间  调用时只能传递左值
	//const 的左值引用  可以给右值【特殊性】
	//右值：大部分是常量值
	//右值引用：只能给右值 也可以将左值转换为右值 std::move(左值)

	//移动构造函数和移动赋值运算的功能
	//1、完成必要的内存移动，斩断原对象与内存的关系
	//2、确保源对象处于一种“即使被销毁也没有问题的”一种状态,确认不在使用原对象，而是使用移动后的对象

	/*int a = 1;
	int& b = a;
	const int& c = a;
	const int& d = 100;

	int&& e = std::move(a);

	cout << e << a << endl;

	a = 100;
	cout << e << a << endl;
	e = 1000;
	cout << e << a << endl;*/

	/*A* a = new A;
	a->_a= 10;
	A* b = new A(*a);*/

	//A a = getA();//此处会调用a对象的移动构造函数
	//getA内部变量x的地址就是变量a的内存地址，共指向同一块内存
	//a._data = 100;
	
	//cout <<"外部："<< a._data << endl;
	
	//printf("外部对象地址：%#x\n", &a);

	//A b(a);//调用的拷贝构造函数，变量a的内存地址和变量b的内存地址完全不一样，拷贝只是数据的拷贝
	//b._data = 123;
	//a._data = 456;
	//cout <<"a::" <<a._data <<"b::"<<b._data<< endl;

	//printf("%#x,%#x\n",&a,&b);

	//A c(std::move(a));
	//cout << "a::" << a._data << "c::" << c._data << endl;
	//A&& d(std::move(a));//变量d和a指向同一块内存地址
	//d._data = 666;
	//cout <<"d::"<< d._data <<"a::"<<a._data<< endl;
	//a._data = 888;
	//cout << "d::" << d._data << "a::" << a._data << endl;

	A y = getA();//调用移动构造函数

	A j;
	j = std::move(y);//调用移动赋值运算函数

	return 0;
}