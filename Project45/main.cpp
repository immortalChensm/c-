#include <iostream> 

//���new ,delete ����ʲô��
namespace test
{
	class A {
	public:
		int _i;

		A()
		{

		}
		~A()
		{

		}
	};
	void func()
	{
		//1��new ������ʱ���ʼ���Ա�ı��������򲻻��ʼ��
		//2��������ʱ����Ա�����Ͳ�����0�ˣ��������ֵ��
		//3��new����ɶ
		A* a = new A();
		//����˳��
		//1 operator new (0FF1348h)
		//1.1	_malloc (0FF128Ah) 
		//2 call        test::A::A (0FF12B7h)
		
		delete a;
		//1 test::A::~A (0CB142Eh)  
		//1 operator delete (0FA1267h)  
		//A* b = new A;

		//void* d = malloc(100);
		//int c = 1;

	}
}
int main()
{
	//new ��ͷ˵��

	test::func();
	return 0;
}