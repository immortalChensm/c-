#include <iostream> 
#include <string> 

using namespace std;
//���������ԣ�����������const,const char * char const * char * const������
auto show()->void {
	cout << "show" << endl;
}

auto test()->int {
	return 12;
}
inline void hello() {//��������  �ڵ���ʱ���滻Ϊ�����壬�����ջ��������������������ѡ���Ƿ�֧��
	//���������岻�׹���
	cout << "hello" << endl;
}

#define HI \
cout << "ok" << endl;\
\


int* funca() {
	int temp = 8;
	return &temp;
}

int* funca(int i) {

	return &i;
}
int main()
{

	/*show();
	cout << test();
	hello();

	HI;*/

	/*int* p = funca();
	*p = 100;


	cout << *p << endl;*/

	//char str[] = "php is best!";

	//const char* p = str;
	//char const* p = str;
	/*char* const p = str;
	char strs[] = "javascript is the best!";*/
	//p = strs;

	//*p = 'J';

	////*p = 'Y';

	//cout << p << endl;

	//�ڴ��ַ:|1byte|1byte|1byte
	//�ڴ�ֵ�� |p|h|p
	//�±����ƣ�|str[0]|str[1]|str[2]|
	//const char* p = str;
	//char const* p = str;
	//const char *p == char const *p

	//char* p = str;
	//p++;//�ڴ��ַ�ƶ�
	//p++;
	//*p = 'y';//��3���ڴ��ַ�����޸�  ������
	//cout << p << endl;

	//char* const p = str;
	//�������� p
	//�����ڴ��ַ 0x0a
	//�������ݣ�str[0]���ڴ��ַ


	//p++;//pָ����ڴ治�����޸�
	//*p = 'Y';//�ڴ��ϵ����ݿ����޸�

	//cout << p << endl;

	//����
	/**
	const char *p
	char const *p
	pָ����ڴ��ַ�ƶ������޸ġ������ڴ��ϵ����ݲ������޸�


	char * const p
	pָ����ڴ治�����޸ģ����ڴ��ϵ����ݿ����޸�

	**/
	char str[] = "php is best";
	//const const const char const* const const p  = str;
	const char * const p  = str;

	//str++;
	//*str = 'Y';

	//p++;
	//*p = 'Y';
	cout << str << endl;
	return 0;
}