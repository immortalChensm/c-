#include <iostream> 
#include <string> 

using namespace std;
class A;

void haha(class A &b)
{

}
//����Ľṹ��չ���ݻ�
class A final{
public:
	//char* data = (char*)"��";
	//char data[100];
	static int a;
	static int b;

	/*void test()
	{
		int c = 100;
	}

	void operator[](int a) {

	}*/

	virtual void bb()
	{

	}
	//A() = default;
	//A() = delete;
	//A()
	//{

	//}
	///*virtual ~A()
	//{

	//}*/
	//operator int() {
	//	int j = 10;
	//	return j;
	//}

	//A(int a) {

	//}
	//friend void haha(class A);
};
int main()
{
	A obj;

	//strcpy(obj.data,(char*)"��");

	//cout << obj.data << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(obj) << endl;

	//���д����麯��ʱ��ϵͳ �������������һ��4���ֽڵ��ڴ�ָ��ָ���麯������ָ���ԱΪvtpr virtual table

	
	//�������ռ�õĿռ䣺��ͨ���Ա����+�麯��

	//���е����к����������û�й�ϵ��ֻ����������һ���麯��ָ��ָ�������[vtpr->vtpr]
	return 0;
}