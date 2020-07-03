#include <iostream> 
#include <string>
//����ָ�� ��ģ��shared_ptr ����ģ��make_shared
using namespace std;

template<typename t>
class A {
public:
	A(t a) {
		cout << "constructor" <<a<< endl;
	}
	~A()
	{
		cout << "destructor" << endl;
	}
};

A<int> getA(int *b)
{
	return A<int>(*b);
}

shared_ptr<int> getPtr(int v)
{
	return shared_ptr<int>(new int(v));
}
int main()
{
	//new/delete����� [malloc/free�Ǻ���]
	//new/free����һЩ��ʼ����������
	//A* obj = new A();//operator new() 
	//delete obj;

	//A* d = (A*)operator new(100);
	//delete d;

	//A* obj = new A();
	//delete[] obj;//���������ᱻ�������޴�

	//����ָ�� 
	//int* ob = new int;
	//obj��Ϊ��ָ�� 
	//����ָ��:��ָ����ָ����а�װ���ܹ��Զ��ͷ���ָ��Ķ����ڴ棬���ڱ�д�͵���
	//c++����ָ�������� ��std::
	//auto_ptr unique_ptr shared_ptr,weak_ptr
	//shared_ptr:����ʽָ��  ���ָ�빲ָ��ͬһ���������һ��ָ�뱻����ʱ������ᱻ�ͷ�
	//weak_ptr ����shared_ptr
	//unique_ptr:��ռʽָ��  ֻ��һ��ָ��ָ��

	/*shared_ptr<int> pi(new int(100));

	cout << *pi << endl;

	getA(new int(10));

	shared_ptr<int> p = getPtr(1000);
	cout << *p << endl;*/

	//��ָ�벻Ҫ������ָ����ʹ��

	//shared_ptr<A<int>> obja(new A<int>(666));

	////make_shared������������ָ��
	//shared_ptr<int> p3 = make_shared<int>(888);

	//cout << *p3 << endl;

	//cout << "********************" << endl;

	//shared_ptr<A<char>> p5 = make_shared<A<char>>('a');


	shared_ptr<int > p = make_shared<int>();

	p = make_shared<int>(100);

	cout << *p << endl;

	auto p1 = make_shared<int>(666);

	return 0;
}