#include <iostream>
#include <vector>
using namespace std;
//������
namespace test1
{
	void func()
	{
		//����������һ�ֱ���������Ԫ�صģ��������ͣ��е���ָ�룬����ָ�������е�ĳ��Ԫ��

		vector<int> iv = { 1,2,3 };
		vector<int>::iterator iter;

		iter = iv.begin();//���Է���һ�������� �ɿ�������һ���ڴ���׵�ַ[ָ��]
		cout << *iter << endl;
		iter++;
		cout << *iter << endl;

		for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); iter++)
		{
			cout << *iter << endl;
		}

		//���������
		for (vector<int>::reverse_iterator iter=iv.rbegin(); iter!=iv.rend(); iter++) {
			cout << *iter << endl;
		}
	}
}

int main()
{
	test1::func();
	return 0;
}