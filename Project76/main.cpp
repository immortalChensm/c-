#include <iostream> 
#include <string> 
//�麯����ָ��λ��
//�麯����ָ��λ�������Ŀ�ͷ����F9���Բ鿴
using namespace std;

class A
{
public:
	int _i = 0;
	char _b;
	
	int _j = 0;
	/*virtual void test()
	{

	}*/
};
int main()
{

	A obj;
	cout << sizeof(obj) << endl;

	char* p1 = reinterpret_cast<char*>(&obj);
	char* p2 = reinterpret_cast<char*>(&(obj._i));

	if (p1 == p2) {
		cout << "ok" << endl;
	}
	

	return 0;
}