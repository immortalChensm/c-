#include <iostream> 
#include <string>
#include <vector>

using namespace std;

//ջ�Ϸ��䣬��ϵͳ����
void talk(){
	int a = 10;
static int b = 100;
}


int main()
{
	//�Լ�ͨ��new�ڶ��Ϸ��䣺��Ϊֱ���ڴ����[new,delete]
	//�����ڴ沢����ʼֵ
	//int* a = new int(100);

	//string *s = new string(5,'j');

	//vector<int>* obj = new vector<int>{ 1,2,3 };

	////��ֵ��ʼ���� �ÿ����ų�ʼ��
	//string* s1 = new string();

	//int* b = new int;//û��ȷ����ֵ
	//int* c = new int();//��Ĭ�ϵ�0ֵ


	//auto��new
	string* s1 = new string(3, 'b');
	auto s2 = new auto(s1);

	printf("%p,%p\n",s1,s2);

	auto a = "hello,world";
	auto b = 100;
	auto c = new vector<int>{ 1,2 };
	auto d = new string("hi");

	const int* p = new const int(100);
	*p = 200;
	
	return 0;
}