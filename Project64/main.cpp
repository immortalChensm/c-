#include <iostream>
#include <string>
#include <boost/type_index.hpp>

//auto ¿‡–ÕÕ∆∂œ
using namespace std;
template<typename t>
void func(const t &v)
{
	cout << "------begin----------" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<t>().pretty_name() << endl;
	cout << "v=" << type_id_with_cvr<decltype(v)>().pretty_name() << endl;
	cout << "------end----------" << endl;
}

void dtx(double x, int y) {
	cout << x << y << endl;
};
void dtx1(int x, int y) {
	cout << x << y << endl;
};

template<typename t>
void autof(std::initializer_list<t> x) {

}

class A {
public:
	static const auto show()
	{
		return 100;
	}
};
class V {
public:
	static const auto show()
	{
		return "china";
	}
};

template<typename T>
auto calls()
{
	auto v = T::show();
	return v;
}
int main()
{
	using boost::typeindex::type_id_with_cvr;
	/*int x = 10;
	int&& y = std::forward<int>(x);

	int i = 10;
	const int j = 100;
	const int& k = 10;


	func(i);
	func(j);
	func(k);*/

	//auto x = 10;//auto = int x=int
	//cout << "x=" << type_id_with_cvr<decltype(x)>().pretty_name() << endl;

	//const auto y = 100;//auto = const int y = const int

	//cout << "y=" << type_id_with_cvr<decltype(y)>().pretty_name() << endl;

	//const auto& k = y;//auto = const int ,k=const int &
	//cout << "k=" << type_id_with_cvr<decltype(k)>().pretty_name() << endl;


	//auto* z = &y;//auto = int *,z=int *
	//cout << "k=" << type_id_with_cvr<decltype(z)>().pretty_name() << endl;


	//auto&& m = 100;//auto = int,m=int &&
	//cout << "k=" << type_id_with_cvr<decltype(m)>().pretty_name() << endl;


	//auto a1 = new auto(100);//auto = int *,a1 = int *
	//cout << "a1=" << type_id_with_cvr<decltype(a1)>().pretty_name() << endl;

	//int x1[] = { 1,2 };
	//auto a2 = x1;
	//cout << "a2=" << type_id_with_cvr<decltype(a2)>().pretty_name() << endl;


	//auto a3 = dtx;//a3 = void(*)(double,int)
	//cout << "a3=" << type_id_with_cvr<decltype(a3)>().pretty_name() << endl;

	//

	//auto& a4 = dtx;
	//auto&& a5 = dtx;

	//auto* a6 = dtx;

	//a3(1, 2);
	//a4(10, 2);
	//a5(100, 2);
	//a6(1000, 2);



	//auto x = 10;
	//auto y(10);
	//auto y{ 10 };
	//auto y = (10);
	//auto y = { 10 };//y=class std::initializer_list<int>
	//auto y = { (10) };
	//auto y = ((10));
	//auto y = { 'a','b' };
	//auto y = { 1,2,3 };
	//auto y = { dtx };
	//auto y = { dtx1 };
	/*auto y = { 1,2 };

	cout << "y=" << type_id_with_cvr<decltype(y)>().pretty_name() << endl;

	autof({1});*/

	cout << calls<A>() << endl;
	cout << calls<V>() << endl;
	return 0;
}