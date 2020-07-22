#include <iostream>
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

		(static_cast<A*>(p))->_next = _freePosi;

	}
	void func()
	{
		
	}
}



int main()
{
	test::func();

	return 0;
}