#include <iostream>
#include <string> 

using namespace std;
//����ת������

class Y
{
public:
	int _i;
	Y(const Y& obj):_i(obj._i)
	{
		cout << "copy constructo run" << endl;
	}
	Y()
	{
		_i = 0;
		cout << "consturctor run" << endl;
	}
	~Y()
	{
		cout << "destructor run" << endl;
	}
};

void test(Y tmp)
{
	return;
}
int main()
{

	//Y obj;
	//obj._i = 10;
	//Y obj1 = obj;

	//Y obj2(obj);

	//Y obj3 = (obj);//��������obj5�ڱ������Ƕ��ϣ����ֳ�2�䣬�������˿������캯��

	//cout << "**************" << endl;

	//Y obj5;
	//obj5.Y::Y(obj);
	//return 0;

	//�����ĳ�ʼ��

	Y obj;
	test(obj);
}