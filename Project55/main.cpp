#include <iostream> 
#include <string> 
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

//�㷨ʹ��
using namespace std;

namespace test1
{
	//�㷨�������ĵ����������йأ���ͬ����ĵ��������в�ͬ���㷨����ʵ�� 
	void myfunc(int i)
	{
		cout << i << endl;
	}
	void func()
	{

		//1��for_each

		vector<int> iv = { 1,2,3,4,5 };
		//for_each(iv.begin(),iv.end(),myfunc);

		vector<int>::iterator iter = find(iv.begin(),iv.end(),3);
		if (iter != iv.end()) {
			cout << *iter << endl;
		}
		else {
			cout << "not foud\n";
		}

		std::map<int, string> iv1;
		iv1.insert(std::make_pair(1, "jack"));
		iv1.insert(std::make_pair(2, "lucy"));
		
		std::map<int,string>::iterator iter1 = iv1.find(2);
		if (iter1 != iv1.end()) {

			cout << iter1->first << iter1->second << endl;
		}

		auto iter2 = find_if(iv.begin(), iv.end(), [](int v) {
			
			if (v > 1) {
				return true;
			}
			return false;
		});

		cout << *iter2 << endl;
	}
}

namespace test2
{
	int mysort(int i, int j)
	{
		return i > j;
	}
	void func()
	{

		//vector<int> iv{ 9,2,6,5,3 };

		//sort(iv.begin(),iv.end());
		//sort(iv.begin(),iv.begin()+3);
		/*sort(iv.begin(),iv.end(),mysort);
		for_each(iv.begin(), iv.end(), [](int v) {
			
			cout << v << endl;
		});*/

		list<int> iv{ 1,2,3,4,6 };
		//iv.sort(mysort);
		sort(iv.begin(),iv.end(),mysort);//ȫ��sort ��֧�֣�ֻ��ʹ�������Լ��ṩ�������㷨 

		for_each(iv.begin(), iv.end(), [](int v) {
			cout << v << endl;
		});
	}
}
int main()
{

	test2::func();
	return 0;
}