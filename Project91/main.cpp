#include <iostream>
#include <string>
#include <vector>

using namespace std;
//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f" << endl;
//	}
//	virtual void g() {
//		cout << "Base::g" << endl;
//	}
//	virtual void h() {
//		cout << "Base::h" << endl;
//	}
//
//	virtual ~Base()
//	{
//
//	}
//};
//class Base2 {
//public:
//	virtual void hBase2()
//	{
//		cout << "Base2::hBase2" << endl;
//	}
//	virtual ~Base2()
//	{
//
//	}
//};
//class Derive :public Base, public Base2 {
//public:
//	virtual void i() {
//		cout << "Derive::i" << endl;
//	}
//	virtual void g() {
//		cout << "Derive::g" << endl;
//	}
//
//	void test()
//	{
//		cout << "Derive::test" << endl;
//	}
//
//	virtual ~Derive()
//	{
//
//	}
//};

class Base {
public:
	int _x;
	virtual void f()
	{

	}
	virtual ~Base()
	{

	}
};
class Dervie :public virtual Base {
public:
	virtual ~Dervie()
	{

	}
	int _y;
};
int main()
{

	/*cout << sizeof(Base) << endl;
	cout << sizeof(Base2) << endl;
	cout << sizeof(Derive) << endl;*/

	//1 ����̳м������࣬���м����麯����
	//���ؼ̳�֮�£��м���������ڶ�������������Ļ������麯����֧�ֲ���Ӱ��
	//thisָ�������������Ŀ�ľ�������ȷ���ҵ�������׵�ַ���Ӷ�����ȷ��ȷ�����ݳ�Ա�Ĵ洢λ��

	//a
	/*Base2* obj1 = new Derive();
	delete obj1;*/
	//obj1 ��̬����������Base2 ������ָ�����һ���������������ַ�����ͷŵ�ʱ�򣬻����thisָ��������ҵ�Derive
	//���׵�ַ�����ͷţ��������ͷ�һ����

	//b 
	/*Derive* obj2 = new Derive();
	obj2->hBase2();*/
	//obj2 ���õ��ǻ���ĳ�Ա��ͬ��������thisָ��ƫ�Ƶ���

	cout << sizeof(Dervie) << endl;

	Dervie obj;
	obj._x = 2;
	obj._y = 6;

	Dervie* pobj = new Dervie();
	pobj->f();

	//obj�����ڴ沼�֣�������ָ��4bytes+Dervie::_y��Ա����4bytes+�麯����ָ��4bytes+Base::_x��Ա����

	return 0;
}