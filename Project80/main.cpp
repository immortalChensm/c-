#include <iostream>
#include <string>
#include <vector>

//���ݳ�Ա�İ�ʱ��
using namespace std;

string vx="200";

typedef string mytype;
class A {
public:
	int getX();//�ó�Ա���������ڱ����Ѿ�������ɲŽ�����
	/*{
		return vx;
	}*/
	//void myfunc(mytype b) {//std::string

	//}
	
public:
	int vx;//vx
	typedef int mytype;
	mytype xy;
public:
	/*void myfunc(mytype b) {

	}*/
	void myfunc(mytype b);
};
void A::myfunc(mytype b)
{
	xy = b;
}
int A::getX()
{
	cout << vx << endl;
	cout << ::vx << endl;
	return vx;
}
int main()
{

	A obj;
	obj.vx = 100;
	obj.getX();
	return 0;
}