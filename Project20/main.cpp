#include <iostream> 
#include <string> 
#include <map>
#include <functional>
//δ���ࣺ���������������function��ģ��
//����������������()
//��׼��function
using namespace std;
void talk(int a)
{
	cout << a << endl;
}

class thanZero {
public:
	thanZero(int v) {
		cout << "than Zero constructo called" << endl;
	}
	int operator()(int v) {
		if (v == 0)return 0;
		return v;
	}
	int operator()(int v,int j) {
		if (v == 0)return 0;
		return v;
	}
	int operator_(int v) {
		return v + 10;
	}
};
//��Ԫ����
//����ת�����㺯��
//��������غ���

int echo(int v) {
	return v;
}
int echo() {
	return 1;
}
int main()
{

	talk(1);//()Ϊ�������õı�� ��Ϊ���������������"
	//���ء����������������
	//thanZero a;
	//cout << a(100) << endl;


	thanZero b(10);
	b(100);

	//��ͬ���ö������ͬ������ʽ
	//�ɵ��ö���
	//echo ������ ����������ֻҪ�����ˡ�����������������ͳ�Ϊ�������� ���ǿ��ǿɵ��ö���

	/*map<string, int (*)(int)> my;
	my["ev"] = echo;

	cout << my["ev"](166)<<endl;*/

	//["evs"] = b; ��֧��


	/*function<int(int)> func = echo;
	function<int(int)> obj = b;
	function<int(int)> cl = thanZero(1);

	
	cout << func(100) << endl;
	cout << obj(200) << endl;
	cout << cl(300) << endl;*/
	//����֮��function����
	/*map<string, function<int(int)>> my = {
		{"f1",echo},
		{"f2",b},
		{"fc3",thanZero(2)}
	};

	my["f1"](22);
	cout << my["f1"](22) << endl;*/


	//����ָ�봦�������ص�����
	int (*p)(int) = echo;
	int (*p1)(void) = echo;

	int (*p2)(int b) = echo;

	function<int(int)> f1 = p;//��ͨ��������  ����ͨ��ָ�뼴�ɽ���������ص�����
	return 0;
}