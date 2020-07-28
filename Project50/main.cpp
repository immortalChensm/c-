#include <iostream> 
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <list>//˫������
#include <forward_list>//��������
#include <map>//��������  �����
#include <set>
#include <unordered_set>//hash ��

//����
using namespace std;
namespace test
{
	void func()
	{

		//1����׼�� c++ standard library
		//2����׼ģ��� c++ standard template library
		//3�����ͱ�̣�generic programming ʹ��ģ��template����̵�һ���ֶ�
		//4����׼ģ��⣺����ʹ�÷��ͱ��ʵ�ֵ�һ�׿⣬�����ڱ�׼����

		//5��STLģ�����ʷ�Ͱ汾
		//1998�����
		//a��hp ����STL����ʼ��
		//b��SGI �ο�ʼ��ʵ�� �� linux[g++,gccc]�õľ������
		//c��P J P STL

		//6����׼���ʹ��
		//���б�׼�ⶼ��std�����ռ���
		//7��stl����ɲ���
		//���������������㷨�������������������������º���
	}
}

namespace test1
{
	//1 ��������
	//a (sequence container) ˳������ list forward_list array vector dequee
	//b (associative container) ��������  ���������顿 map ,set �ʺϲ���
	//c (Unordered container) ��������[Ҳ��һ�ֹ�������] ���������˳����Ҫ����Ҫ������������Ƿ���������

	class A {
	public:
		int _i;
		A(int j):_i(j) {

			cout << "A::A()"<<j <<_i<< endl;
		}
		A(const A& obj):_i(obj._i) {
			cout << "�������캯��" << endl;
		}
		~A()
		{
			cout << "��������" << endl;
		}
		void t()
		{
			cout << _i << "t" << endl;
		}
	};
	void func()
	{
		//array<string, 5> data = {};
		vector<A> obj;//����һ���������ڴ�ռ䣬ÿ�β������ݣ�����һ�ο���
		//���Ƕ�β���󣬻��������µ��������ڴ�ռ䣬���Ѿɵ������ٴο�����Ȼ��������
		//�����ж�εĿ���������
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
			cout << "�������캯��" << endl;
		}
		~A()
		{
			cout << "��������" << endl;
		}
		void t()
		{
			cout << _i << "t" << endl;
		}
	};
	void func()
	{
		deque<A> obj;//�ڲ��洢��ʹ�÷ֶδ洢�������ڴ��������ģ����ֲ��������ġ�
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
namespace test4
{
	void func()
	{

		unordered_set<int> sets;
		cout << sets.bucket_count() << endl;
		for (int i = 0; i < 8; i++) {
			sets.insert(i);
		}
		cout << sets.bucket_count() << endl;
		sets.insert(9);
		cout << sets.bucket_count() << endl;
		cout << sets.max_bucket_count() << endl;

		cout << sets.size() << endl;
		for (int i = 0; i < sets.bucket_count(); i++) {
			cout << "bucket_size=" << sets.bucket_size(i) << endl;
		}


		auto f = sets.find(5);
		if (f != sets.end()) {
			cout << "find 5" << endl;
		}

		if (find(sets.begin(), sets.end(), 5) != sets.end()) {
			cout << "find function find 5" << endl;
		}

	}
}
int main()
{
	test4::func();
	return 0;
}