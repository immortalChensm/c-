#include <iostream> 
#include <string> 

using namespace std;


//void func(int&& a) {
template<typename T=int>
void func(T&& a) {
	cout << 1 << endl;
	cout << a << endl;

	//T && a ���������� ��������T����
	// �������û���ݴ��ݽ����Ĳ������� ����ֵ���û�����ֵ����
	//a����ֵ���ݽ���ʱ���� T && a
	//a����ֵ���ݽ���ʱ�ǣ�T &a
}
//template<>
//void func(int&& a) {
//	cout << 2 << endl;
//	cout << a << endl;
//}

template<typename t>
class A {
public:
	void show(t&& x) {
	
	}
};
int main()
{

	//1 ���������������

	func(100);

	int a = 10;
	func(a);//��������ֵ���� ģ�庯��������

	//2 �������� universe referrence   
	// �����Ǻ���ģ�壬������T && ��������������ƶ�
	//func �ɴ�����ֵ��Ҳ���Դ�����ֵ  

	//��ֵ���� ���������õ�����
	//��ֵ���ã�ֻ�ܴ�����ֵ
	//�������ã���ֵ����ֵ������

	A<int> obj;//����ģ�����ʱ�����������ˣ���û���ñ����������ƶϡ�
	obj.show(a);//��������  

	//�������ã���֮�ܸ���ֵ���ܸ���ֵ�ľ����������ã�������[��ֵ����+�����������ƶϡ�
	return 0;
}