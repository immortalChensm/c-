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
	
	K obj1;
	A obj;
	void show()
	{
		cout << "IamChinese" << endl;
	}
};
int main()
{
	B b;//B ��û�й��캯����������A,K���Ա���󣬱�����Ϊ��B����Ӻϳɵ�Ĭ�Ϲ��캯��������A,K��Ĺ��캯��
	return 0;
}