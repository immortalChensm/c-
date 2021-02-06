#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace test1
{
	class A {
	public:
		static void *operator new (size_t size)
		{
			A* pa = (A*)malloc(size);
			return pa;
		}
		static void operator delete(void* ptr)
		{
			free(ptr);
		}
		static void* operator new[] (size_t size)
		{
			A* pa = (A*)malloc(size);
			return pa;
		}
		static void operator delete[](void* ptr)
		{
			free(ptr);
		}
		A()
		{
			cout << "a" << endl;
		}
		~A()
		{
			cout << "~a" << endl;
		}
	};
	void func()
	{

		//int* pa = new int(10);
		//delete pa;

		//A* obj = new A();
		//delete obj;
		A* obj = new A[3]();//������ռ��3���ֽڵ��ڴ棬���ǻ�ʹ��4���ֽڵĿռ����洢����Ԫ�س���
		//�ͻ�ռ��7���ֽ�
		//new/delete �ڷ����ڴ���ͷ��ڴ�ʱ���ڴ�Ĺ������¼ռ�ö��ٸ��ֽڣ������������ڴ�
		//���洢 �������ݵ�
		delete[] obj;
	}
}
int main()
{

	test1::func();
	return 0;
}