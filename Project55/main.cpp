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
		for_each(iv.begin(),iv.end(),myfunc);
		
	}
}

int main()
{

	test1::func();
	return 0;
}