#include <iostream> 
#include <string>

using namespace std;

class A {
public:
	A() {
		cout << "constructor" << endl;
	}
	/*~A()
	{
		cout << "destructor" << endl;
	}*/
};
int main()
{
	//new/delete����� [malloc/free�Ǻ���]
	//new/free����һЩ��ʼ����������
	//A* obj = new A();//operator new() 
	//delete obj;

	//A* d = (A*)operator new(100);
	//delete d;

	A* obj = new A();
	delete[] obj;//���������ᱻ�������޴�

	//����ָ�� 
	int* ob = new int;
	//obj��Ϊ��ָ�� 
	//����ָ��:��ָ����ָ����а�װ���ܹ��Զ��ͷ���ָ��Ķ����ڴ棬���ڱ�д�͵���
	//c++����ָ�������� ��std::
	//auto_ptr unique_ptr shared_ptr,weak_ptr
	//shared_ptr:����ʽָ��  ���ָ�빲ָ��ͬһ���������һ��ָ�뱻����ʱ������ᱻ�ͷ�
	//weak_ptr ����shared_ptr
	return 0;
}