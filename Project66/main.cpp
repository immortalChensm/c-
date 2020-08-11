#include <iostream>
#include <string> 
#include <functional>

using namespace std;

class TC
{
public:
	using func = void(*)(int v);
	static void funcs(int v) {
		cout << "Tc::func run,v=" << v << endl;
	}
	//������ת��Ϊ����
	operator func()
	{
		return funcs;
	}

	void show(int j) {
		cout << "Tc::show run,j=" << j << endl;
	}

	static void display(double x) {
		cout << "Tc::display run,x=" << x << endl;
	}
};

class A {
public:
	int _i;
	A(int i){
		_i = i;
	}
	operator int()
	{
		return _i;
	}
};

void myfunc(int v) {
	cout << "myfunc run,v=" << v << endl;
}

class CB
{
	std::function<void()> fcallback;
public:
	CB(const std::function<void()>& f) :fcallback(f) {
		int i = 1;
	}
	void runcallback()
	{
		fcallback();
	}
};
class CBT
{
public:
	void operator ()(void)
	{
		cout << "CBT operator() run" << endl;
	}
};

void mycallback(int c, const std::function<void(int)>& f) {

	f(c);
}

void callback(int &v,int &y)
{
	v++;
	y++;
	cout << "callback run" <<v<<y<< endl;
}

class B {
public:
	void show(int x, int y) {
		_i = x;
		cout << "x=" << x << ",y=" << y << endl;
	}
	int _i;
};
int main()
{
	//�ɵ��ö��󣺺���ָ�룬�º�����������operator()())  operator type ����ת������������ת��Ϊָ����typeֵ�纯��
	// ���Ա����ָ��
	/*TC obj;
	obj(3);

	obj.operator TC::func()(33);

	A obj1(10);
	A obj2(20);
	int ret = obj1 + obj2;
	cout << ret << endl;

	TC objx;
	void (TC:: * x)(int v) = &TC::show;
	(objx.*x)(100);

	void ( * y)(double x) = &TC::display;
	y(100);*/

	//2 function ģ��װ��������

	//����ͨ����
	//std::function<void(int)> f1 = myfunc;
	//f1(2);

	//����ľ�̬��Ա����
	//std::function<void(double)> f2 = &TC::display;
	//f2(100);

	//�󶨷º���
	//TC obj;
	//std::function<void(int)> f3 = obj;
	//f3(111);

	/*CBT obj;
	CB objx(obj);
	objx.runcallback();*/

	/*for (int i = 0; i < 10; i++) {
		mycallback(i,callback);
	}*/


	//std::bind ���ɵ��ö���Ͳ�������һ��
	//auto f1 = std::bind(callback,101);
	//f1();

	//auto f2 = std::bind(callback,placeholders::_1,202);
	//f2(101);
	// ����ͨ����
	//std::bind(callback,placeholders::_1,303)(999,666);
	/*int a = 2, b = 3;
	auto f3 = std::bind(callback,a,placeholders::_1);
	f3(b);
	cout << "a=" << a <<",b="<<b << endl;*/

	//�����Ա����
	B obj;
	auto f5 = std::bind(&B::show,obj,100,200);
	f5();

	cout << obj._i << endl;//��û�и�ֵ
	return 0;
}