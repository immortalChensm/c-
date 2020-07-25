#include <iostream> 
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <forward_list>
#include <map>
#include <set>


using namespace std;
namespace test
{
	void func()
	{

		//1、标准库 c++ standard library
		//2、标准模板库 c++ standard template library
		//3、泛型编程：generic programming 使用模板template来编程的一种手段
		//4、标准模板库：就是使用泛型编程实现的一套库，包含在标准库中

		//5、STL模板库历史和版本
		//1998年出现
		//a、hp 惠普STL，是始祖
		//b、SGI 参考始祖实现 的 linux[g++,gccc]用的就是这个
		//c、P J P STL

		//6、标准库的使用
		//所有标准库都在std命名空间里
		//7、stl的组成部分
		//容器，迭代器，算法，分配器，其它，适配器，仿函数
	}
}

namespace test1
{
	//1 容器分类
	//a (sequence container) 顺序容器 list forward_list array vector dequee
	//b (associative container) 关联容器  【关联数组】 map ,set 适合查找
	//c (Unordered container) 无序容器[也是一种关联容器] 插入的数据顺序不重要，重要的是这个数据是否在容器里

	class A {
	public:
		int _i;
		A(int j):_i(j) {

			cout << "A::A()"<<j <<_i<< endl;
		}
		A(const A& obj):_i(obj._i) {
			cout << "拷贝构造函数" << endl;
		}
		~A()
		{
			cout << "析构函数" << endl;
		}
		void t()
		{
			cout << _i << "t" << endl;
		}
	};
	void func()
	{
		//array<string, 5> data = {};
		vector<A> obj;//它是一块连续的内存空间，每次插入数据，都是一次拷贝
		//但是多次插入后，会多次生成新的连续的内存空间，并把旧的数据再次拷贝，然后析构掉
		//会运行多次的拷贝和析构
		for (int i = 0; i < 5; i++) {

			cout << "---------begin---------" << endl;
			obj.push_back(A(i));
			cout << "---------end-----------" << endl;
		}

		cout << "---------finish---------" << endl;
		//obj.begin()->t();
		cout << obj.size() << obj.capacity() << endl;
		for (int i = 0; i < obj.size(); i++) {

			printf("%#x--%d\n",&obj[i],obj[i]._i);
		}

		vector<A> tmp;
		for (auto iter :obj) {
			printf("%#x--%d\n", &iter, iter._i);
			if (iter._i == 2) {
				//auto oldIter = iter;
				//obj.erase(oldIter);
				//break;
				auto d = obj.begin() + 2;
				obj.erase(d);
			}
		}
	
		for (int i = 0; i < obj.size(); i++) {

			printf("%#x--%d\n", &obj[i], obj[i]._i);
		}

	}
}

namespace test2
{
	class A {
	public:
		int _i;
		A(int j) :_i(j) {

			cout << "A::A()"  << endl;
		}
		A(const A& obj) :_i(obj._i) {
			cout << "拷贝构造函数" << endl;
		}
		~A()
		{
			cout << "析构函数" << endl;
		}
		void t()
		{
			cout << _i << "t" << endl;
		}
	};
	void func()
	{
		deque<A> obj;//内部存储是使用分段存储【部分内存是连续的，部分不是连续的】
		for (int i = 0; i < 5; i++) {
			obj.push_front(A(i));
		}

		for (int i = 0; i < 5; i++) {
			//cout << obj[i]._i << endl;
			printf("obj[%d],%#x\n",obj[i]._i,&obj[i]);
		}
	}
}
namespace test3
{
	void func()
	{

		/*list<int> a;
		a.push_front(1);
		a.push_front(2);
		a.push_front(3);
		a.pop_front();
	
		for (auto i : a) {
			cout << i << endl;
		}*/
		/*forward_list<int> b;
		b.push_front(1);
		b.push_front(2);

		b.remove(2);
		b.push_front(3);
		for (auto i : b) {
			cout << i << endl;
		}*/
		//map<int, string> obj;

		//obj.insert(std::make_pair(1,"test"));
		//obj[2] = "lycy";

		////obj.erase(1);

		//cout << obj[1] << endl;

		//auto iter = obj.find(2);
		//cout << iter->first << iter->second << endl;

	
		set<int> obj;
		obj.insert(1);
		obj.insert(1);
		obj.insert(2);

		for (auto x : obj) {
			cout << x << endl;
		}

	}
}
int main()
{
	test3::func();
	return 0;
}