#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//void* operator new(size_t size) {
//
//	return malloc(size);
//}
//void* operator new[](size_t size) {
//
//	return malloc(size);
//}
//
//void operator delete(void* p) {
//
//	free(p);
//}
//void operator delete[](void* p) {
//
//	free(p);
//}


namespace test1
{
	class A {
	public:
		static void* operator new(size_t size) {

			A* templink;
			if (buffer == nullptr) {

				size_t s = size * blockSize;
				buffer = reinterpret_cast<A*>(new char[s]);

			
				templink = buffer;

				for (; templink != &buffer[blockSize - 1];templink++) {

					templink->next = templink + 1;
				}
				templink ->next = nullptr;
				mallocCount++;
			}

			templink = buffer;
			buffer = buffer->next;
			count++;
			return templink;
		}

		static void operator delete(void* p) {

			static_cast<A*>(p)->next = buffer;
			buffer = static_cast<A*>(buffer);
			return;
		}

	public:
		//static A* next;
		A* next;
		static int count;
		static int mallocCount;
		static A* buffer;
		static int blockSize;

	};
	int A::count = 0;
	int A::mallocCount = 0;
	A* A::buffer = nullptr;
	//A* A::next = nullptr;
	int A::blockSize = 50;
	void func()
	{

		clock_t start, end;

		start = clock();
		for (int i = 0; i < 500'0000; i++) {

			A* p = new A();
			//printf("%x\r\n",p);
			delete p;
		}

		end = clock();
		cout << "�������:" << A::count << "mallo������" << A::mallocCount << "����ʱ��" << end - start << endl;
	}
}
namespace test2
{

	class A {
	public:
		int i;
		int j;

		/*void* operator new(size_t size) {

			return malloc(size);
		}
		void* operator new[](size_t size) {

			return malloc(size);
		}

			void operator delete(void* p) {

			free(p);
		}
		void operator delete[](void* p) {

			free(p);
		}*/
		A() {
			cout << "A" << endl;
		}
		~A()
		{
			cout << "~A" << endl;
		}
		void* operator new(size_t size) {

			return malloc(size);
		}

		//���ض�λnew
		void* operator new (size_t size, void *p,int a, int b) {

			cout << "a=" << a << endl;
			cout << "b=" << b << endl;
			cout << "size=" << size << endl;

			return p;
		}
	};

	void func()
	{

	/*	int* a = new int();
		delete a;

		int* b = new int[3];
		delete[]b;*/

		//A* p = new A();
		//delete p;

		//placement new ��λnew  ���Ѿ�����õ��ڴ��ַ�ռ���ö���
		void* my1 = (void*)new char[sizeof(A)];

		A* obj1 = new(my1,1,2) A();

		//obj1->~A();

		//delete [](void*)obj1;

		delete obj1;
	}
}
int main()
{

	test2::func();
}