#include <iostream> 
#include <string>
//智能指针 类模板shared_ptr 函数模板make_shared
using namespace std;

template<typename t>
class A {
public:
	A(t a) {
		cout << "constructor" <<a<< endl;
	}
	~A()
	{
		cout << "destructor" << endl;
	}
};

A<int> getA(int *b)
{
	return A<int>(*b);
}

shared_ptr<int> getPtr(int v)
{
	return shared_ptr<int>(new int(v));
}
int main()
{
	//new/delete运算符 [malloc/free是函数]
	//new/free能做一些初始化和清理工作
	//A* obj = new A();//operator new() 
	//delete obj;

	//A* d = (A*)operator new(100);
	//delete d;

	//A* obj = new A();
	//delete[] obj;//析构函数会被调用无限次

	//智能指针 
	//int* ob = new int;
	//obj称为裸指针 
	//智能指针:是指对裸指针进行包装，能够自动释放所指向的对象内存，便于编写和调试
	//c++智能指针有四种 ：std::
	//auto_ptr unique_ptr shared_ptr,weak_ptr
	//shared_ptr:共享式指针  多个指针共指向同一个对象，最后一个指针被销毁时，对象会被释放
	//weak_ptr 辅助shared_ptr
	//unique_ptr:独占式指针  只有一个指针指向

	/*shared_ptr<int> pi(new int(100));

	cout << *pi << endl;

	getA(new int(10));

	shared_ptr<int> p = getPtr(1000);
	cout << *p << endl;*/

	//裸指针不要和智能指针混合使用

	//shared_ptr<A<int>> obja(new A<int>(666));

	////make_shared函数创建智能指针
	//shared_ptr<int> p3 = make_shared<int>(888);

	//cout << *p3 << endl;

	//cout << "********************" << endl;

	//shared_ptr<A<char>> p5 = make_shared<A<char>>('a');


	shared_ptr<int > p = make_shared<int>();

	p = make_shared<int>(100);

	cout << *p << endl;

	auto p1 = make_shared<int>(666);

	return 0;
}