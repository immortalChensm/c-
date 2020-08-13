#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
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

int x(int a) {
	return a;
}
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

	/*int x = 10;
	auto y = [=]() mutable {
		
		x = 101; cout << x << endl;
	};
	y();
	cout << x << endl;

	[]() {
		
		[] {
			cout << "he" << endl;
		}();
	}();*/

	std::function<int(int)> f1 = [](int v) {return v + 1; };
	std::function<int(int)> f2 = std::bind([](int a, int b)->int {return a + b; }, 100,placeholders::_1);

	cout << f1(100) << endl;

	cout << f2(101) << endl;

	typename  int(*f3)(int) ;

	f3 = [](int a) {return a; };
	cout << f3(2) << endl;

	typedef int(*fx)(int);
	typedef int y;

	//lambda ��ʹ��
	
	vector<int> data = { 1,2,3 };

	std::for_each(data.begin(), data.end(), [](int v) {
		
		cout << v << endl;
	});


	auto vd = find_if(data.begin(), data.end(), [](int v) {
		
		if (v == 2)return true;
		return false;
	});

	cout << *vd << endl;

	return 0;
}