#include <iostream> 
#include <string> 

using namespace std;
//��ʱ��������ĳ���
//1 ��������Ϊ�����Ĳ������ݡ�ֵ���ݡ�
//2 ��������һ����ʱ����
//3 �������ת�����캯��
// Ӧ�þ������������ʱ����
class A {
public:

	A(int v1 = 0, int v2 = 0):_v1(v1),_v2(v2) {
		cout << "���캯��������"<<endl;
	}

	A(const A& t) {
		cout << "�������캯��������" << endl;
	}

	A& operator=(A t) {
		cout << "��ֵ���㺯��������" << endl;
		return *this;
	}

	~A() {
		cout << "��������������" << endl;
	}
public:
	int _v1;
	int _v2;
};

A Double(A t) {
	A a;
	a._v1 = t._v1 * 2;
	a._v2 = t._v2 * 2;
	return a;
}

class Num
{
public:
	Num(int x, int y) :a(x), b(y) {};
public:
	int a;
	int b;
};

Num operator+(Num& a, Num& b)
{

	return Num(a.a + b.a, a.b + b.b);
}
int main()
{
	//A a;

	//a = 1;//������ʱ����

	//A b = a;//������ʱ����

	//A b = Double(a);

	//A&& b = Double(a);//��ֵ����

	Num a{ 10,20 };
	Num b{ 100,200 };
	
	Num c= a+b;

	return 0;
}