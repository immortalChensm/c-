#include <iostream>
#include <string> 

using namespace std;
//for ��Χ���� new /delete �ڴ����,nullptr �յ�ַ NULLֻ��0
//�������ڴ�ģ��

class demo
{
public:
	int m_a;
	int m_b;
};
int main()
{
	//int a[]{ 1,2,3,4,5 };

	////for (auto x : a) {
	//for(auto &x:a){
	//	cout << x << endl;
	//}

	/*for (auto x : { 100,200,400,600 }) {
		cout << x << endl;
	}

	demo a1, b1, c1;
	a1.m_a = 1; a1.m_b = 2; b1.m_a = 3; b1.m_b = 4; c1.m_a = 5; c1.m_b = 6;
	for (auto x : { a1,b1,c1 }) {
		cout << x.m_a << x.m_b << endl;
	}*/


	//int* p = 0;
	//p = (int*)malloc(sizeof(int));//�ڶ�������4���ֽڵ��ڴ�
	//if (p != NULL) {

	//	*p = 100;
	//	cout << *p << endl;
	//	free(p);
	//}

	//char* p = NULL;

	//p = (char*)malloc(50 * sizeof(char));
	//if (p != NULL) {
	//	//strcpy(p,"hi,world");
	//	strcpy_s(p,5,"hi,world");
	//	cout << p << endl;
	//	free(p);
	//}

	//int* p = (int*)malloc(100 * sizeof(int));
	////�ڴ�ͼ��|4bytes|4bytes|4bytes|...99
	//if (p != NULL) {

	//	int* q = p;
	//	*q++ = 1;//q=q+1 *q=1
	//	*q++ = 5;//q=q+1 *q=5
	//	cout << *p << endl;
	//	cout << *p++ << endl;
	//	cout << *p++ << endl;

	//	free(p);
	//}

	/*int* p = new int;
	if (p != NULL) {
		*p = 88;
		cout << *p << endl;
		delete p;
	}*/

	//int* p = new int(100);//����ռ䲢��ʼ��
	//if (p != NULL) {

	//	cout << *p << endl;
	//	delete p;
	//}


	//int *p = new���ͱ�ʶ��
	//int *p = new���ͱ�ʶ��(��ʼֵ��
	//int *p = new���ͱ�ʶ��[��Ա����]
	//int *p = new���ͱ�ʶ��[��Ա����]{������Ա��ʼֵ}
	
	
	//int* p = new int[100]{ 1,2,3 };
	//if (p != NULL) {

	//	cout << *p << endl;
	//	cout << *(p++) << endl;
	//	cout << *(p++) << endl;
	//	cout << *(p++) << endl;

	//	delete[100] p;//���һ��
	//	delete[] p;
	//	delete p;//������
	//}

	/*int* p = new int{ 100 };
	if (p != NULL) {
		cout << *p << endl;
		cout << sizeof(p) << endl;

		delete p;
	}*/

	/*int* p = NULL;
	int* a = nullptr;

	if (p == a) {
		cout << "same" << endl;
	}
	int c = nullptr;
	int d = NULL;
	cout << c << d << endl;*/

int* p = new int{ 100 };
if (p != nullptr) {
	cout << *p << endl;
	delete p;
}
	return 0;
}