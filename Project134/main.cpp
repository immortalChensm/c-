#include <iostream>
#include <string>
#include <ctime>
#include <array>
#include <vector>

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
		cout << "分配次数:" << A::count << "mallo次数：" << A::mallocCount << "，用时：" << end - start << endl;
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

		//重载定位new
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

		//placement new 定位new  在已经分配好的内存地址空间调用对象
		void* my1 = (void*)new char[sizeof(A)];

		A* obj1 = new(my1,1,2) A();

		//obj1->~A();

		//delete [](void*)obj1;

		delete obj1;
	}
}
namespace test3
{
	void func()
	{

		array<string, 5> obj = { "china","japanese" };

		obj[2] = "test";
		obj[3] = "lucylucylucylucylucylucylucylucylucylucy";


		obj[4] = "i";
		
		cout << "string size=" << sizeof(string) << endl;

		for (int i = 0; i < obj.size(); i++) {

			printf("i=%d,obj[%d]=%s,obj[%d]=%p\r\n",i,i,obj[i].c_str(),i,&obj[i]);

			const char* p = obj[i].c_str();

			printf("p=%p,%s\r\n",p,p);
		}
	}
}
namespace test4
{

	class A {
	public:
		int i;
		A(int a):i(a) {
			cout << "A构造函数" << endl;
		}
		A(const A&obj) :i(obj.i) {
			cout << "A拷贝构造函数" << endl;
		}
		~A()  {
			cout << "A析构函数" << endl;
		}
	};
	void func()
	{

		vector<A> obj;
		//如果不预先分配内存，那么每次插入数据，都会重新分配新的内容，并把旧内存上的数据拷贝到新连续的内存中
		//性能会下降，建议先分配好内存
		obj.reserve(10);
		for (int i = 0; i < 5; i++) {

			cout << "start 时，size" <<obj.size()<< endl;
			cout << "start 时，capacity" <<obj.capacity()<< endl;

			obj.push_back(A(i));

			cout << "start 后，size" << obj.size() << endl;
			cout << "start 后，capacity" << obj.capacity() << endl;
		}
		cout << "尝试删除元素" << endl;
		for (int i = 0; i < 5; i++) {

			if (i == 2) {

				auto itr = obj.begin() + 2;
				obj.erase(itr);
				break;
			}
		}

		for (auto itr = obj.begin(); itr != obj.end(); itr++) {

			cout << itr->i << endl;
		}

		cout << "尝试添加元素" << endl;
		for (int i = 0; i < 5; i++) {

			if (i == 2) {

				//obj.push_back(A(100));
				obj[1] = A(100);
				break;
			}
		}
		for (auto itr = obj.begin(); itr != obj.end(); itr++) {

			cout << itr->i << endl;
		}
	}
}
int main()
{

	test4::func();
}