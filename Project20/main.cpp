#include <iostream> 
#include <string> 
//δ���ࣺ���������������function��ģ��
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

	int operator_(int v) {
		return v + 10;
	}
};
//��Ԫ����
//����ת�����㺯��
//��������غ���

int main()
{

	talk(1);//()Ϊ�������õı�� ��Ϊ���������������"
	//���ء����������������
	//thanZero a;
	//cout << a(100) << endl;


	thanZero b(10);
	b(100);

	return 0;
}