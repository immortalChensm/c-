#include <iostream> 
#include <string> 

using namespace std;

shared_ptr<int> create(int v)
{
	return make_shared<int>(v);
}

void func()
{
	shared_ptr<int> tmp = create(100);
	return;
}
template<typename t>
class A {
public:
	A(t a) {
		cout << "construct " << a << endl;
	}
	~A() {
		cout << "destructor " << endl;
	}
};

void func1(shared_ptr<A<int>> ptr)
{
	return;
}
void func2(shared_ptr<int> ptr)
{
	return;
}

class Controller
{
public:
	
};

class UserController :public Controller {
public:
	void add()
	{
		cout << "add user" << endl;
	}
};

class OrderController :public Controller
{
public:
	void addOrder()
	{
		cout << "add order" << endl;
	}
};


class CT:public enable_shared_from_this<CT> {
public:
	shared_ptr<CT> getself()
	{
		//return shared_ptr<CT>(this);
		return shared_from_this();
	}
};

class CB;
class CA {
public:
	shared_ptr<CB> pb;
	~CA() {
		int t = 1;
		cout << t << endl;
	}
};

class CB {
public:
	//shared_ptr<CA> pa;
	weak_ptr<CA> pa;
	~CB() {
		int t = 2;
		cout << t << endl;
	}
};
int main()
{
	//1��shared_ptr ʹ�ó��� 
	//func();

	//2����ָ��
	//A<int>* p = new A<int>(1);

	//func1(shared_ptr<A<int>>(p));

	/*shared_ptr<int> map(new int(19));

	func2(map);

	*map = 200;


	auto fun = [](int a, int b)
	{
		cout << a << b << endl;
	};

	fun(1,2);

	[](int a, int b) {
		cout << a << b << endl;
	}(12,20);

	int result = []()->int {return 100; }();
	cout << result << endl;*/

	//shared_ptr<int> p(new int(10));

	//int* tp = p.get();//������ָ��

	//*tp = 20;

	//delete tp;//������

	//shared_ptr<int> p2(tp);//p2��p��ָͬ��ͬһ���ڴ��ַ�����ͷź󣬽�Ӱ��p

	//*p = 99;

	//Controller obj;

	//shared_ptr<CT> p1(new CT());
	//shared_ptr<CT> p2(p1);

	//shared_ptr<CT> p2 = p1->getself();//���������ͷ�2��

	//ѭ��ʵ��������û���ͷ�
	/*shared_ptr<CA> ca(new CA());
	shared_ptr<CB> cb(new CB());

	ca->pb = cb;
	cb->pa = ca;*/
	//�ƶ�����
	shared_ptr<int> p1(new int(1));

	shared_ptr<int> p2(std::move(p1));

	shared_ptr<int> p3;

	p3 = std::move(p2);


	return 0;
}