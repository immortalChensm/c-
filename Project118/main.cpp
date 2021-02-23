#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <array>
#include <queue>
#include <cstdlib>

using namespace std;
//stl��ɲ��֣�����  ������  ������  �㷨����������
//������sequenence container ˳������  �ڴ��ַ����
//     associative container ��������  set map multiset multimap ���ṹ 
//     unordered container ��������
// ˳��������array vector list queue 
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
			cout << "���캯��A::A()" << endl;
		}
		A(const A& obj):m_i(obj.m_i)
		{
			cout << "�������캯��A::A(const A& obj)" << endl;
		}
		~A()
		{
			cout << "~A��������" << endl;
		}
	};
	void func()
	{
		vector<A> obj;
		cout << obj.capacity() << endl;
		cout << obj.size() << endl;

		obj.reserve(10);//Ԥ������10��Ԫ�صĵ�ַ�ռ�  ����������ο������������� 
		cout << obj.capacity() << endl;
		cout << obj.size() << endl;

		for (int i = 0; i < 5; i++)
		{
			//�ڴ�ռ��������ģ�ÿ�β�����Ԫ��ʱ������Ѿɿռ�����ݸ��ͷŵ�
			//�����µ������ڴ�ռ俽�����ͻᵼ�¶�ο���������
			obj.push_back(A(i));
		}

		for (int i = 0; i < 5; i++)
		{
			printf("�±�Ϊ%d��Ԫ�ص�ַ��%p��������%d\n",i,&obj[i],obj[i].m_i);
		}
		int count = 0;
		cout << "ɾ��һ��Ԫ��" << endl;
		for (auto pos = obj.begin(); pos != obj.end(); pos++) {

			count++;
			if (count == 2) {
				obj.erase(pos);
				break;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			printf("�±�Ϊ%d��Ԫ�ص�ַ��%p��������%d\n", i, &obj[i], obj[i].m_i);
		}

		{
			int count = 0;
			cout << "����һ��Ԫ��" << endl;
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
			printf("�±�Ϊ%d��Ԫ�ص�ַ��%p��������%d\n", i, &obj[i], obj[i].m_i);
		}
	}
}
int main()
{
	test2::func();
	return 0;
}