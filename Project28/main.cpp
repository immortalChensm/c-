#include <iostream> 
#include <string>
#include <tr1/memory>//win7 mingcc得加上这头文件


//shared_ptr 类模板的使用|智能指针：共享式  引用计数
/**
 * 1、shared_ptr 智能指针创建方式
 *    shared_ptr<int> obj(new int(1));
 *    shared_ptr<int> obj(new int[10]);
 *
 *    shared_ptr<int> obj = make_shared<int>(100);
 *
 * 2、shared_ptr 模板类的成员
 *    use_count() 引用次数
 *    unique() 是否只有一个引用
 *    reset() 将当前对象指向的内存地址重置，并将原内存地址的引用养1
 *            如果内存地址有多个对象指向，则不会删除
 *    reset(参数) 只有一个对象指向时，会释放到该对象原来指向的内存地址，同时指向新的参数
 *    			有多个时，原对象所指向的内存计数减1
 *    nullptr = reset 同理
 *
 * 3、指定删除器
 * 		中括号删除器：shared_ptr<int[]) obj(new int[10]);
 * 		普通函数删除器：shared_ptr<int> obj(new int[10],函数名);
 * 		匿名函数删除器【lambda】:shared_ptr<int> obj(new int[10],[](int *p){delete [] p});
 * 		std::default_delete 类模板删除器：shared_ptr<int> obj(new int[10],std::default_delete<int>[]());
 *
 * **/
using namespace std;

void testSharedPtr(shared_ptr<int> p)
{
	*p = 100;
	return;
}

class B{
public:
	B() {

		cout <<"B constructor " << endl;
	}
	~B() {
		cout << "B destrcutor " << endl;
	}
};
template<typename t>
class A {
public:
	A(t a) {
		
		cout <<"A constructor "<< a << endl;
	}
	~A() {
		cout << "A destrcutor " << endl;
	}

	B _obj;
	
};



void myDelete(int* p)
{
	cout << "自己的删除器" << endl;
	delete p;
}

template<typename t>
shared_ptr<t> make_shared_array(size_t size)
{
	return shared_ptr<t>(new t[size],std::default_delete<t[]>());
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
//	shared_ptr<int> p1(new int(100), [](int* p) {
//		delete p;
//		cout << 2 << endl;
//	});
//
//	auto p2 = p1;
//
//	cout << 1 << endl;
//
//	p1 = nullptr;
//
//	p2.reset();

//	shared_ptr<A<int>> obj(new A<int>[4]{0,0,0,0},[](A<int> *p){
//		delete [] p;
//	});
	//default_delete模板删除器
	//shared_ptr<A<int>> obj(new A<int>[4]{0,0,0,0},std::default_delete<A<int>[]>());
	//c++17 []删除器
//	shared_ptr<A<int>[]> obj(new A<int>[4]{0,1,2,3});
//	shared_ptr<int[]> obj1(new int[100]);
//	obj1[0] = 10;
//	obj1[1] = 20;
//
//	cout<<obj1[0]<<endl;

	//shared_ptr<int[]> piArr = make_shared_array<int>(5);
//	auto func = [](int a,int b){
//		cout<<a<<b<<endl;
//	};
//
//	func(10,20);

	//auto func1 = [](int *p){

	//	cout<<"func1 called"<<endl;
	//	delete p;
	//};

	//auto func2 = [](int *p){
	//	cout<<"func2 called"<<endl;
	//	delete p;
	//};

	//shared_ptr<int> obj1(new int(1),func1);
	//shared_ptr<int> obj2(new int(2),func2);

	//obj2 = obj1;//obj2 离开原来指向的内容了，obj1所指向的内存引用就会计数为2

	//cout<<obj1.use_count()<<endl;
	//cout<<obj2.use_count()<<endl;

	//piArr[0] = 1;

//	shared_ptr<int> obj(new int[10],[](int *p){
//		//内置类型 无析构函数可以这样
//		delete p;
//	});

//	int *p = new int[10];
//	p[0]=1;
//	p[1] = 2;
//
//	cout<<p[1]<<endl;

	




	return 0;
}