#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Base {
public:
	void test()
	{
		cout << "Base" << 11 << endl;
	}
	virtual void talk(int v=1)
	{
		cout << "Base::talk" <<v<< endl;
	}
};
class Derive :public Base {
public:
	void test()
	{
		cout << "Derive"<<11 << endl;
	}
	virtual void talk(int v=2)
	{
		cout << "Derive::talk" <<v<< endl;
	}
};
class Dervie2 :public Base {
public:
};


int main()
{
	//1 ��̬���ͺͶ�̬���� 
	//������ʱ����������
	/*Base obj1;
	Base* obj2;
	Derive* obj3 = new Derive();

	Base* obj4 = new Derive();*///obj4 ��̬������Base * ����̬������Dervie *

	//��̬����  ��ָ����������ʱ�ž������������� �����й����п��Զ�̬���޸ģ�ָ��������ò���
	//obj2 = obj3;
	

	//2 ��̬�󶨺Ͷ�̬��  
	// ��̬��  ���ǵľ�̬���ͣ�����Ӧ�ĺ����������������ڶ���ľ�̬����  �����ڱ�����
	// ��̬��  �󶨵��Ƕ�̬���ͣ�����Ӧ�ĺ����������������ڶ���Ķ�̬����  ������������
	// ��ͨ��Ա�����Ǿ�̬�󶨣��麯���Ƕ�̬��
	//3�̳еķ��麯��
	/*
	Derive objx;
	Derive* objx1 = &objx;

	objx1->test();

	Base* objx2 = &objx;
	objx2->test();*/

	cout << "00000000000000000000000000000" << endl;

	Base* obj1 = new Base();
	Derive* obj2 = new Derive();
	obj1->talk();
	obj2->talk();

	obj1 = obj2;
	obj1->talk();//obj1 ��̬������Base������̬���ͷ����˱仯�������˶�̬��

	//�麯����̬�󶨣�����Ĭ�ϲ���ʱ�Ŀ�

	//6 ��̬��  
	//1 �Ӵ���ʵ����
	//�����麯��������ʱ��������麯�����������ʱ�������麯��������ҵ�������ڵ�ַ��Ȼ����ִ��������������Ƕ�̬
	//��֮���Ƕ�̬

	//2 �ӱ�����ʽ��

	return 0;
}