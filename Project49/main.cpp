#include <iostream> 
#include <string> 

//ȫ��new,delete����||��λplacement new
//��λnew:���������Ѿ�������ڴ��ϳ�ʼ��һ�����󣬱����������ڴ棬��Ҫ��ǰ������ڴ�
//�����ǣ����Ѿ�Ԥ�ȷ���õ��ڴ��ַ�Ϲ���һ������
using namespace std;

//void* operator new(size_t size)
//{
//	return malloc(size);
//}
//void* operator new[](size_t size)
//{
//	return malloc(size);
//}
//
//void operator delete(void* p)
//{
//	free(p);
//}
//
//void operator delete[](void* p)
//{
//	free(p);
//}
namespace test
{
	class A {
	public:
		A()
		{
			cout << "A::A()" << endl;
		}

		~A()
		{
			cout << "~A::A()" << endl;
		}
	};
	void func()
	{
		int* p = new int{ 10 };
		delete p;

		char* a = new char[10];
		delete[] a;

		A* obja = new A();
		delete obja;

		A* objb = new A[2]();

		delete[] objb;


	}
}
namespace test1
{
	class A {
	public:
		int m_i;
		A():m_i(0)
		{
			int i = 100;
		}
		A(int v) :m_i(v) {

		}

		~A()
		{
			int a=10;
		}
	};
	void func()
	{

		void* tmp = (void*)new char[sizeof(A)];//Ԥ�ȷ����ڴ�
		A* obj = new (tmp) A();//��λnew ����A�Ĺ��캯��  �������·����µ��ڴ�

		void* tmp1 = (void*)new char[sizeof(A)];
		A* obj1 = new (tmp1) A(100);

		//delete obj;
		//delete obj1;

		obj->~A();
		obj1->~A();

		delete[](void*)tmp;
		delete[](void*)tmp1;

		void* ints = (void*)new int;

		int* t = new (ints) int(100);
		cout << *t << endl;

		//delete t;
		delete (void*)ints;

	}
}
int main()
{
	test1::func();
	return 0;
}