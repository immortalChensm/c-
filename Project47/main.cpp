#include <iostream>
#include <ctime> 
using namespace std;

#define MEMORYPOOL 1
//内存池的实现 
namespace test
{
	class A
	{
	public:
		static void* operator new(size_t size);
		static void operator delete(void* p);
		static int _iCount;
		static int _iMallocCount;
	private:
		A* _next;
		static A* _freePosi;
		static int _sTrunkCount;
	};

	int A::_iCount = 0;
	int A::_iMallocCount = 0;

	A* A::_freePosi = nullptr;

	int A::_sTrunkCount = 5;

	void* A::operator new(size_t size)
	{

		A* tmplink;
#ifdef MEMORYPOOL 
		tmplink = (A*)malloc(size);
		return tmplink;
#endif 
		if (_freePosi == nullptr) {

			size_t realSize = _sTrunkCount * size;
			_freePosi = reinterpret_cast<A*>(new char[realSize]);
			//A|A|A|A|A
			tmplink = _freePosi;//tmplink=_freePosi[0] 

			for (; tmplink != &_freePosi[_sTrunkCount - 1]; tmplink++) {
				//每一块的下一块
				tmplink->_next = tmplink + 1;
			}
			tmplink->_next = nullptr;
			++_iMallocCount;
		}
		tmplink = _freePosi;
		_freePosi = _freePosi->_next;
		++_iCount;


		return tmplink;
	}

	void A::operator delete(void* p)
	{
#ifdef MEMORYPOOL 
		free(p);
#endif 
		(static_cast<A*>(p))->_next = _freePosi;
		_freePosi = static_cast<A*>(p);

	}
	void func()
	{
		
		clock_t start, end;
		start = clock();
		for (int i = 0; i < 500'0000; i++) {

			A* o = new A();
		}

		end = clock();

		cout << "分配内存次数：" << A::_iCount << "，malloc次数：" << A::_iMallocCount << "，用时（ms):" << (end-start) << endl;
	}
}

namespace test1
{
	//1、嵌入式指针
	class TestEP
	{
	public:
		int _i;
		int _j;
	public:
		struct obj
		{
			struct obj* next;
		};
	};

	void func()
	{
		TestEP mytest;//8个字节
		cout << sizeof(mytest) << endl;
		TestEP::obj* tmp;

		tmp = (TestEP::obj*)(&mytest);//tmp 指向了前4个字节

		cout << sizeof(tmp->next) << endl;
		cout << sizeof(TestEP::obj) << endl;

		tmp->next = nullptr;

	}
}

int main()
{
	test1::func();

	return 0;
}