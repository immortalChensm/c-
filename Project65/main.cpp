#include <iostream> 
#include <string>
#include <functional>
#include <vector>
#include <boost/type_index.hpp>

//decltype 
//1、delctype(*p) 推出来的类型是 引用 int&
//2、delctype((i)) 也是引用 int &
using namespace std;


template<typename t>
void func(t v)
{
	cout << "------begin----------" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<t>().pretty_name() << endl;
	cout << "v=" << type_id_with_cvr<decltype(v)>().pretty_name() << endl;
	cout << "------end----------" << endl;
}
class A {
public:
	int i;
};
auto test()
{
	//return 0;
	cout << 12 << endl;
	return A();
}

template<typename T>
class CT
{
public:
	//typename T::iterator iter;
	decltype(T().begin()) iter;//返回迭代器
	void begin(T& beg) {

		iter = beg.begin();
	}
};
//template<typename T>
//class CT<const T>
//{
//public:
//	typename T::const_iterator iter;
//	void begin(const T& beg) {
//
//		iter = beg.begin();
//	}
//};
//
//auto adds(int a, int b)->decltype(a + b) {
//	return a + b;
//}
int &as(int a) {
	return a;
}
double as(double a) {
	return a;
}
template<typename T>
auto xas(T& tv)->decltype(as(tv)) {
	return as(tv);
}
int main()
{

	//const int i = 10;
	//const int& iy = i;
	//auto k = i;//k=int


	//decltype(i) j = 100;
	//cout << j << endl;
	//decltype(iy) j3 = j;


	using boost::typeindex::type_id_with_cvr;
	
	//cout << "j3=" << type_id_with_cvr<decltype(j)>().pretty_name() << endl;

	//decltype(A::i) i1 = 100;
	//A obj;
	//decltype(obj) objt;

	//auto&& i2 = i1;//i1是左值  推断出来后是i2=int &

	//decltype(i2) && i3 = i2;//int & &&i3 引用折叠  推断出来也是int &

	//int i = 3;
	//int* p = &i;
	//*p = 100;
	//decltype(*p) k = i;//p = int &
	//

	//decltype((i)) i5 = i;

	//delctype 参数是函数
	//decltype(test()) i;
	/*decltype(test) *i = test;
	cout << "j3=" << type_id_with_cvr<decltype(i)>().pretty_name() << endl;
	A obj = i();*/
	
	//std::function<decltype(test)> t = test;
	//A obj = t();

	/*using consts = const std::vector<int>;
	consts tt = { 1,2,3,4 };

	CT<consts> obj;
	obj.begin(tt); 

	cout << *(obj.iter) << endl;
	cout << *(obj.iter+1) << endl;*/

	/*vector<int> a = { 1,2,3 };
	vector<int>::size_type t = a.size();


	decltype(a)::size_type b = t;
	cout << b << endl;*/

	//auto x = adds(10,20);
	/*int b = 100;
	auto x = xas(b);*/

	int x = 1;
	const int& y = 10;
	//auto z = y;
	decltype(auto) z = y;
	cout << "x=" << type_id_with_cvr<decltype(z)>().pretty_name() << endl;
	return 0;
}