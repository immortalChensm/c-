#include <iostream>
#include <string>

//�����̳еĶ����ڴ沼��
using namespace std;

class Grand {
public:
	//int _x;
	Grand()
	{
		cout << "grand" << endl;
	}
};
class A1 :virtual public Grand
{
public:
	A1()
	{
		cout << "A1" << endl;
	}
};
class A2 :virtual public Grand
{
public:
	A2()
	{
		cout << "A2" << endl;
	}
};
class C :public A1, public A2 {
public:
	C()
	{
		cout << "c" << endl;
	}
};
int main()
{

	C obj;
	//C obj ������ڴ沼�֣�A1->Grand ��4���ֽڵ�vbptr A2->Grand Ҳ��4���ֽڵ�vbptr 

	cout << sizeof(Grand) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(C) << endl;

	//obj._x = 10;//��������ʾ ����ȷ
	/*obj.A1::_x = 10;
	obj.A2::_x = 18;

	cout << obj.A1::_x << endl;
	cout << obj.A2::_x << endl;*/
	//��̳��Ժ�  
	//A1,A2 �ᱻ����������һ��������ָ�루virtual base table pointer) ָ�������� (virtual base table)


	return 0;
}