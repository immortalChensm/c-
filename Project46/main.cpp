#include <iostream>

namespace test
{
	
	void func()
	{
		//new delete [malloc,free] �����ڴ�ʱ�������������������ڴ�����¼����ڴ��������Ϣ���������ֽڴ�С��
		//�����η��䣬����ɴ����ڴ��˷ѣ���Ϊÿ�������ڴ棬��Ҫ���������ڴ�����¼һ����Ϣ
		//�ر���Ƶ��������С���ڴ�
		int* a = new int(255);
		
		delete a;
	}
}
namespace test1 {

	class A {
	public:
		static void* operator new(size_t size);
		static void operator delete(void* p);

		A()
		{
			std::cout << "A" << std::endl;
		}
		~A()
		{
			std::cout << "~A" << std::endl;
		}
	};

	void *A::operator new(size_t size) {

		A* p = (A*)malloc(size);
		return p;
	}
	void A::operator delete(void* p)
	{
		free(p);
		return;
	}
	void func()
	{

		//A* p = new A();
		//delete p;

		A* p = ::new A();//::ȫ�ֲ�����  ���ڵ������ص�new,delete
		::delete p;
	}
}

namespace test2 {

	class A {
	public:
		static void* operator new[](size_t size);
		static void operator delete[](void* p);

		A()
		{
			std::cout << "A" << std::endl;
		}
		~A()
		{
			std::cout << "~A" << std::endl;
		}
	};

	void* A::operator new[](size_t size) {

		A* p = (A*)malloc(size);
		return p;
	}
	void A::operator delete[](void* p)
	{
		free(p);
		return;
	}
	void func()
	{

		//�����ڴ�ʱ�����������4���ֽ��ڴ�����¼����2�����鳤�ȡ�
		//�ڴ��ַ�����4bytes|1bytes|1bytes
		//��Ӧ��ַ���ݣ�2|A�����|A�����
		A* p = new A[2]();
		delete[] p;
	}
}

int main()
{
	test2::func();
	
	return 0;
}