#include <iostream> 
#include <string>


//shared_ptr 类模板的使用|智能指针：共享式  引用计数
using namespace std;

void testSharedPtr(shared_ptr<int> p)
{
	*p = 100;
	return;
}

template<typename t>
class A {
public:
	A(t a) {
		
		cout <<"constructor "<< a << endl;
	}
	~A() {
		cout << "A destrcutor " << endl;
	}

	
};

void myDelete(int* p)
{
	cout << "自己的删除器" << endl;
	delete p;
}
int main()
{
	//1、引用计数  这块内存由p1和p2共同指向
	/*shared_ptr<int> p1 = make_shared<int>(666);

	auto p2 = p1;


	testSharedPtr(p2);

	cout << *p1 << *p2 << endl;*/


	//引用计数的减少
	//p2 = make_shared<int>(888);

	/*shared_ptr<A<int>> p1 = make_shared<A<int>>(100);

	auto p2 = p1;


	p2 = make_shared<A<int>>(6);

	p1 = make_shared<A<int>>(1);*/

	//2、获取引用计数
	//shared_ptr<A<int>> p1 = make_shared<A<int>>(100);

	//3、是否只有一个引用【独享】
	/*if (p1.unique()) {
		cout << "p1 is unique ref" << endl;
	}
	else {
		cout << "p1 is not unique ref" << endl;
	}
	auto p2 = p1;

	if (p1.unique()) {
		cout << "p1 is unique ref" << endl;
	}
	else {
		cout << "p1 is not unique ref" << endl;
	}

	cout << p1.use_count() << p2.use_count() << endl;*/

	//4、reset()  
	//a、不带参数时，若对象是唯一一个指向内存的，则释放该对象的内容
	//b、若该有多个对象同时指向同一个内存地址，则是不释放，仅仅减少引用次数-1

	/*shared_ptr<A<int>> pi(new A<int>(100));

	auto p1 = pi;
	pi.reset();

	cout << pi.use_count() << endl;*/

	//reset有参数时
	//a、如果pi 是唯一一个指向内存地址的，使用reset时，将释放原来指向的内存，并使pi重新指向新的内存地址
	//b、如果pi不是唯一的，有多个的，则是pi重新指向新的内存地址，但原来的引用计数减1
	/*shared_ptr<A<int>> pi(new A<int>(1));

	auto p2 = pi;


	pi.reset(new A<int>(100));*/

	//4、get() 返回裸指针（小心 使用）

	/*shared_ptr<int> pi(new int(100));

	int* p = pi.get();

	*p = 1;

	cout << *p << *pi << endl;*/

	//shared_ptr<A<int>> pi = make_shared<A<int>>(100);

	//A<int>* p = pi.get();

	//delete p;//出错

	//5、swap交换
	/*shared_ptr<int> p1 = make_shared<int>(100);

	shared_ptr<int> p2(new int(200));

	std::swap(p1, p2);

	cout << *p1 << *p2 << endl;

	p2.swap(p1);
	cout << *p1 << *p2 << endl;*/

	//6、nullptr 【使用和reset一样】

	/*shared_ptr<int> p1 = make_shared<int>(100);

	auto p2 = p1;

	p1 = nullptr;*/

	//7、作为if判断语句

	/*shared_ptr<int> p1 = make_shared<int>(100);
	p1 = nullptr;
	if (p1) {
		cout << "p1 not nullptr" << endl;
	}
	else {
		cout << "p1 is nullptr" << endl;
	}*/
	//8、指定删除器及数组
	
	//shared_ptr<int> p1(new int(100),myDelete);
	//删除器可以是lambda表达
	shared_ptr<int> p1(new int(100), [](int* p) {
		delete p;
		cout << 2 << endl;
	});

	auto p2 = p1;

	cout << 1 << endl;
	
	p1 = nullptr;

	p2.reset();
	return 0;
}