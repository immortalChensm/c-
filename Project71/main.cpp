#include <iostream> 
#include <string>

using namespace std;

class A {
public:
	A()
	{
		cout << "AHAHA" << endl;
	}
};
class K {
public:
	K()
	{
		cout << "KHAHA" << endl;
	}
};
class B {
public:
	int _a;
	int _b;

	/*K obj1;
	A obj;*/
	void show()
	{
		cout << "IamChinese" << endl;
	}
	virtual void display()
	{
		cout << "display" << endl;
	}
};
int main()
{
	B b;//B ��û�й��캯����������A,K���Ա���󣬱�����Ϊ��B����Ӻϳɵ�Ĭ�Ϲ��캯��������A,K��Ĺ��캯��

	//1�����Ա�й��캯����������û�й��캯������������ϳɼ���
	//2�������й��캯��������û�У���������Ҳ��ȫ�ɼ���
	//3��һ�������麯�����ͻ���һ���麯����-��ָ��ָ���麯����vftable��ַ
	b.display();
	return 0;
}