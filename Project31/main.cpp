#include <iostream>
#include <string>

using namespace std;
//unique_ptr 类模板智能指针
//独占式智能指针 同一时刻只能有一个变量指向本块内存地址

//1、创建方法 unique_ptr<int> pi(new int(10)); make_unique

void test(int *a)
{
	cout << *a << endl;
}

class A {
public:
	A() {
		cout << "a constructor" << endl;
	}

	~A()
	{
		cout << "a destructor" << endl;
	}
};

auto geta()
{
	return unique_ptr<string>(new string("china!"));
}

int main()
{

	/*unique_ptr<int> pi;

	unique_ptr<int> pi2(new int(10));

	auto pi3 = make_unique<int>(33);*/

	
	//test(new int(10));

	//unique_ptr 常用的操作
	//1、不支持的操作
	/*unique_ptr<int> pi = make_unique<int>(100);*/
	//unique_ptr<int> pi1(pi);

	//pi1 = pi;

	//2、移动语义

	/*unique_ptr<int> pi2 = std::move(pi);

	int a = 10;
	int&& b = std::move(a);*/
	//3、release 放弃对指针的控制权 返回裸指针 必须自行delete释放

	/*unique_ptr<int> pi = make_unique<int>(100);

	unique_ptr<int> pi2(pi.release());

	if (pi == nullptr) {
		cout << "pi is null" << endl;
	}


	auto p = pi2.release();

	delete p;*/

	//4、reset 不带参数释放原来指向的内存地址，自己置空
	//unique_ptr<int> pi = make_unique<int>(100);

	/*pi.reset();

	if (pi == nullptr) {
		cout << "pi is nullptr" << endl;
	}*/
	// reset 带参数 ，释放原来指向的内存，自己重新指向新的内存地址
	//unique_ptr<int> pi2(new int(200));

	//pi.reset(pi2.release());//pi2 与原对象不在关联，它置空 pi原对象释放，指向新

	//if (pi2 == nullptr) {
	//	cout << "pi2 is nullptr" << endl;
	//}

	//unique_ptr<A> pi(new A());

	//A* pa = pi.release();

	//delete pa;

	//unique_ptr<A> pi2(new A());

	//pi2.reset();

	//pi2.reset(pi.release());

	//5、nullptr 
	/*unique_ptr<A> p(new A());

	p = nullptr;*/

	//6、指向一个数组
	/*unique_ptr<int[]> pi(new int[10]);
	pi[0] = 1;
	pi[1] = 2;

	cout << pi[0] << endl;*/

	//7、get返回裸指针

	/*unique_ptr<string> pi(new string("hello"));

	string* pis = pi.get();

	*pis = "test";*/

	//unique_ptr<A> pi(new A());

	//A* a = pi.get();

	//delete a;//不可以

	//8、*解引用

	/*unique_ptr<int> pi(new int(100));

	*pi = 400;

	cout << *pi << endl;*/

	//9、swap

	/*unique_ptr<int> pi1(new int(10));
	unique_ptr<int> pi2(new int(20));

	std::swap(pi1, pi2);

	cout << *pi1 << *pi2 << endl;

	pi1.swap(pi2);
	cout << *pi1 << *pi2 << endl;*/

	//10、智能指针名作为判断条件 
	//unique_ptr<int> pi1(new int(10));

	//pi1.release();
	//pi1.reset();
	/*pi1 = nullptr;
	if (pi1) {
		cout << "pi1" << endl;
	}*/

	//11、转换为shared_ptr 类型
	shared_ptr<string> p(geta());

	*p = "test";

	shared_ptr<string> pi(p);

	
	return 0;
}