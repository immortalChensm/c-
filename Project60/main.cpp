#include <iostream> 
#include <string>
#include <boost/type_index.hpp>

//理解模板类型推断|查看类型推断结果
using namespace std;

void test(int a) {

}
template<typename t>
//void func(const t &v)
//void func(t*v)
void func(t v)
{
	cout << "------begin----------" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T="<< type_id_with_cvr<t>().pretty_name()<<endl;
	cout << "v="<< type_id_with_cvr<decltype(v)>().pretty_name()<<endl;
	cout << "------end----------" << endl;
}
int main()
{
	/*int a = 10;
	func(a);*/

	int i = 10;
	const int j = 100;
	const int& k = i;

	//func(i);//t=int v=int &
	//func(j);//t=int const v=int const &
	//func(k);//t=int const v=int const &

	//func(199);//右值  t=int v=int &&

	func(test);
	return 0;
}