#include <iostream>
using namespace std;
//lambda,for_each find_if
//��ʽ��[�����б�](�����б�)->��������{������}
//(�����б�) ����ʡ��  
//->��������  ����ʡ��
//�����б�ͨ������һ����Χ�ڵı���
//a��[] �������κα���
//b:[&] �����ⲿ���������б���������Ϊ�����ں�������ʹ��
//c:[=] �����ⲿ�����������б���������Ϊ��������ֵ���ں�������ʹ��
//d:[������1,..] ��ֵ����
//e:[=,&������] Ĭ�ϰ�ֵ���������ⲿ����������Ĳ��������ò���
//f:[&,������] Ĭ�ϰ����ò��������ⲿ����������ı�������ֵ����

//mutable 

class A {
public:
	int _j;
	void show(int x)
	{
		_j = x;
		//[this] {
		//[=] {
		[&] {
			cout << _j << endl;
		}();
	}
};
int main()
{

	//[](int x,int y)->void {
	//
	//	cout << x << y << endl;

	//}(100,200);

	//[]() {cout << 1 << endl; }();
	//[] {cout << 2 << endl; }();

	//static int i = 10;

	////
	//[]() {
	//	cout << i << endl;
	//}();

	//int j = 10;
	//[&]() {
	//	
	//	j = 101;
	//}();


	//cout << j << endl;

	//[=]() {
	//	cout << j << endl;
	//}();

	//A obj;
	//obj.show(188);

	//int x = 1, y = 2;
	//[x,y]{
	//	cout << x << y << endl;
	//}();

	//int k1 = 10;
	//auto f1 = [&] {
	//	
	//	return k1;
	//};
	//k1 = 101;
	//cout << f1() << endl;

	//mutable  

	int x = 10;
	auto y = [=]() mutable {
		
		x = 101; cout << x << endl;
	};
	y();
	cout << x << endl;

	[]() {
		
		[] {
			cout << "he" << endl;
		}();
	}();

	return 0;
}