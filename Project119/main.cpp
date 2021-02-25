#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//https://zh.cppreference.com/w/cpp/container#.E9.A1.BA.E5.BA.8F.E5.AE.B9.E5.99.A8 
//各种容器类模板相关成员函数
using namespace std;

class A {
public:
	int m_i;
	A(int x) :m_i(x)
	{
		cout << "A()" << endl;
	}
	A(const A& obj):m_i(obj.m_i)
	{
		cout << "A(const A&obj)" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
	bool operator <(A o) const {
		//return true;
		return m_i < o.m_i;
	}
};
namespace test1
{
	void func()
	{

		queue<A> obj;
		obj.push(A(1));
		obj.push(A(2));
		obj.push(A(3));

		cout << obj.size() << endl;

		cout << obj.front().m_i << endl;
		cout << obj.front().m_i << endl;

		A obj1 = obj.front();
		cout << obj1.m_i << endl;

		/*for (int i = 0; i < obj.size(); i++)
		{
			obj.pop();
			cout << "数据："<<obj.front().m_i << endl;
		}*/
	}
}
namespace test2
{
	
	
	void func()
	{
		list<A> obj;
		obj.push_front(A(1));
		obj.push_front(A(2));
		obj.push_front(A(3));


		//obj.pop_front();
		//obj.pop_back();
		auto itr = obj.begin();
		itr++;
		obj.erase(itr);

		for (auto itr = obj.begin(); itr != obj.end(); itr++)
		{
			cout << itr->m_i << endl;
		}
	}
}
namespace test3
{
	void func()
	{
		set<A> obj;
		obj.insert(A(1));
		obj.insert(A(2));
		obj.insert(A(3));
		obj.insert(A(3));

		for (auto itr = obj.begin(); itr != obj.end(); itr++) {
			cout << itr->m_i << endl;
		}
	}
}
namespace test4
{
	void func()
	{
		//分配器  内存分配
		std::allocator<int> alloc;
		int* p = alloc.allocate(3);
		int* q = p;
		*q = 1; q++;
		*q = 2; q++;
		*q = 3;
		cout << *p << *(p + 1) << *(p + 2) << endl;

		alloc.deallocate(p,3);

		list<int, std::allocator<int>> obj;
		obj.push_back(1);
		obj.push_back(2);
		obj.push_back(3);

		for (auto itr = obj.begin(); itr != obj.end(); itr++)
		{
			cout << *itr << endl;
			printf("%p\n",&(*itr));
		}
		
	}
}
int main()
{
	test4::func();
	return 0;
}