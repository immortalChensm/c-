#include <iostream> 
#include <string> 
#include <map>
using namespace std;
//using����ģ�����
//����ģ��Ĺؼ��֣�template typename class using
template <typename st>
struct map_s
{
	typedef std::map<std::string, st> _type;
};

//����ģ�����
template<typename st>
using str_map = std::map<std::string, st>;//��������ģ�塱�����


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
	//����ģ�壬��ģ�壬��ͨ���Ա����ģ�壬��ģ���Ա����ģ�壬ģ��ʵ����

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

	//��������  Ҫ��2��  ģ�����Ҫ��3���ģ���������ƶ�ֻ���ƶ���2��
	//��ʾ��ָ��ģ�����
	auto result = sums<double,double,double>(1, 2);
	cout << result << endl;
	return 0;
}