#include <iostream> 
#include <string> 
#include <map>
using namespace std;
//using定义模板别名
//定义模板的关键字：template typename class using
template <typename st>
struct map_s
{
	typedef std::map<std::string, st> _type;
};

//定义模板别名
template<typename st>
using str_map = std::map<std::string, st>;//给“类型模板”起别名


typedef unsigned int uin_t;
using uin_t = unsigned int;

typedef int (*Func)(int, int);

using Func = int(*)(int, int);


template<typename T>
using my_Func = int(*)(T a, T b);

template<typename T>
int talk(T a, T b) {
	return a + b;
}

template<typename t1,typename t2,typename t3>
t1 sums(t2 a, t2 b) {
	
	t1 result = a + b;
	return result;
}
int main()
{
	//函数模板，类模板，普通类成员函数模板，类模板成员函数模板，模板实例化

	/*typedef std::map<string, int> map_s_i;


	map_s_i obj;
	obj["func"] = 1;
	obj["name"] = 2;
	obj["sex"] = 0;

	for (auto o : obj) {
		cout << o.first <<o.second<< endl;
	}

	map_s<int>::_type obj1;

	obj1["lucy"] = 1;

	cout << obj1["lucy"] << endl;

	str_map<char> obj2;
	obj2["name"] = 'a';
	cout << obj2["name"] << endl;*/

	//my_Func<int> func = talk<int>;
	
	//cout<<func(1, 2)<<endl;

	//函数参数  要给2个  模板参数要给3个的，这里编译推断只是推断了2个
	//显示的指定模板参数
	auto result = sums<double,double,double>(1, 2);
	cout << result << endl;
	return 0;
}