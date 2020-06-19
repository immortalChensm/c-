#include <iostream>
#include <string>

using namespace std;
//struct��|class��|��ͨ��|�����ࣨ���д��麯�����ࣩ|final�ࣨ���಻���Լ̳У�
//��̬���ͣ���������ʱ�����ͣ��������ڱ���ʱ����֪��
//��̬���ͣ���ָָ�����������ָ����ڴ��е����ݵ���������
//class A final{
class A {
public:
	A(int a) :_a{ a } {};
public:
	void display() {
		cout << "A::_a="<<_a << endl;
	}
protected:
	int _a;
};

class B final :public A {
public:
	B(int a, int b) :A{ a }, _b{ b } {};
public:
	void display() {
		cout << "B::_b=" << _b << endl;
		cout << "B::_a=" << _a << endl;
	}
private:
	int _b;
};
class C :B {

};
int main()
{

	A a{ 1 };
	B b(10,20);
	B c{ 100,200 };

	a.display();
	b.display();

	c.display();
	return 0;
}