#include <iostream>

using namespace std;

namespace test1
{
	class A {
	public:
		int x;
	public:
		A() {

		}
		~A() {

		}
	};
	void func()
	{

		A* a = new A;
		A* b = new A();

		delete a;
		delete b;

		//std::shared_ptr<A> c(new A(), [=](void* p) {delete p; cout << "delete" << endl; });

	}
}
namespace test2
{
	class A {
	public:
		A()
		{
			cout << "a" << endl;
		}
		~A()
		{
			cout << "~a" << endl;
		}
		static void* operator new(size_t size) {
			A* a = (A*)malloc(size);
			return a;
		}
		static void operator delete(void* p) {
			free(p);
		}
		static void* operator new[](size_t size) {
			A* a = (A*)malloc(size);
			return a;
		}
		static void operator delete[](void* p) {
			free(p);
		}
	};
	void func()
	{

		//A* o = new A();
		//delete o;

		//A* o = new A[3]();//����ʱ���ö����4�ֽڴ洢����Ԫ�ظ���
		//delete[]o;

		//����ײ㲢����ֻ�򵥷�����10���ֽڣ����Ƿ�����һ��Ƭ�����ݣ�����ͨ���ͷ�ʱ�۲��ڴ��ַ֪��
		char* p = new char[10];
		memset(p,0,10);
		delete []p;
	}
}
int main()
{

	test2::func();
	return 0;
}