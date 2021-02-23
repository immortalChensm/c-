#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <array>
#include <queue>
#include <cstdlib>

using namespace std;
//stl组成部分：容器  迭代器  分配器  算法函数，其它
//容器：sequenence container 顺序容器  内存地址连续
//     associative container 关联容器  set map multiset multimap 树结构 
//     unordered container 无序容器
// 顺序容器：array vector list queue 
namespace test1
{
	void func()
	{
		array<string, 5> obj = { "china","ok","nice" };
		obj[0] = "ilikemoney";
		obj[4] = "testtest";
		cout << obj.size() << endl;
		for (size_t i = 0; i < obj.size(); i++)
		{
			const char* p = obj[i].c_str();
			cout << p << obj[i] << endl;
		}
		
	}
}
namespace test2
{
	class A {
	public:
		int m_i;
		A(int x) :m_i(x)
		{
			cout << "构造函数A::A()" << endl;
		}
		A(const A& obj):m_i(obj.m_i)
		{
			cout << "拷贝构造函数A::A(const A& obj)" << endl;
		}
		~A()
		{
			cout << "~A析构函数" << endl;
		}
	};
	void func()
	{
		vector<A> obj;
		cout << obj.capacity() << endl;
		cout << obj.size() << endl;

		obj.reserve(10);//预先申请10个元素的地址空间  可以提升多次拷贝，提升性能 
		cout << obj.capacity() << endl;
		cout << obj.size() << endl;

		for (int i = 0; i < 5; i++)
		{
			//内存空间是连续的，每次插入新元素时，都会把旧空间的数据给释放掉
			//再找新的连续内存空间拷贝，就会导致多次拷贝和析构
			obj.push_back(A(i));
		}

		for (int i = 0; i < 5; i++)
		{
			printf("下标为%d的元素地址是%p，数据是%d\n",i,&obj[i],obj[i].m_i);
		}
		int count = 0;
		cout << "删除一个元素" << endl;
		for (auto pos = obj.begin(); pos != obj.end(); pos++) {

			count++;
			if (count == 2) {
				obj.erase(pos);
				break;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			printf("下标为%d的元素地址是%p，数据是%d\n", i, &obj[i], obj[i].m_i);
		}

		{
			int count = 0;
			cout << "插入一个元素" << endl;
			for (auto pos = obj.begin(); pos != obj.end(); pos++) {

				count++;
				if (count == 2) {
					obj.insert(pos,A(100));
					break;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			printf("下标为%d的元素地址是%p，数据是%d\n", i, &obj[i], obj[i].m_i);
		}
	}
}
int main()
{
	test2::func();
	return 0;
}