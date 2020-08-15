#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_set>
#include <functional>
#include <queue>

using namespace std;
//��ȡ��[��������һЩ��Ϣ]
namespace _nmsp1
{
	//һ��������ȡ������type traits��:���ͱ�̣���stl��ʵ��Դ���У�����������ȡ�����õıȽ϶ࣻ
	//�ڰ��£���� ����������ȡ��������ȡ����ȡһЩ��Ϣ������ 
	//c++11 ����׼�����ṩ�˺ܶ�������ȡ�Ľӿ� ����Щ�ӿ���ʵ����һЩ��ģ�壻
	//https://en.cppreference.com/w/cpp/types  //

	//����������ȡ����
	//ͨ����ȡ�ӿ� �е�valueֵΪtrue ,false���Ǿ��ܹ���ȡ���ܶ�������Ϣ��

	//������������ȡ������iterators traits)
	//���� STL��׼ģ����ֹ� ��5�ڣ� ���������� ���ܹ���ȡ�������������ࣻ

	//�ģ��ܽ᣺
	//c++�У�ģ���뷺�ͱ�� ��ģ��Ԫ��̣� �����ڿ�����׼�⣬�ӿڿ�ȵȣ�


	template <typename T>
	void printTraitsInfo(const T& t)
	{
		cout << "--------------begin-----------" << endl;

		cout << "����Ҫ��ȡ�����������ǣ�" << typeid(T).name() << endl;

		cout << "is_void = " << is_void<T>::value << endl;                                    //�����Ƿ���void
		cout << "is_class = " << is_class<T>::value << endl;                                  //�����Ƿ���һ��class
		cout << "is_object = " << is_object<T>::value << endl;                                //�����Ƿ��� һ����������
		cout << "is_pod = " << is_pod<T>::value << endl;                                      //�Ƿ���ͨ�ֻࣨ������Ա��������������Ա��������   POD(plain old data)
		cout << "is_default_constructible = " << is_default_constructible<T>::value << endl;  //�Ƿ���ȱʡ���캯��
		cout << "is_copy_constructible = " << is_copy_constructible<T>::value << endl;        //�Ƿ��п������캯��
		cout << "is_move_constructible = " << is_move_constructible<T>::value << endl;        //�Ƿ����ƶ����캯��
		cout << "is_destructible = " << is_destructible<T>::value << endl;                    //�Ƿ�����������
		cout << "is_polymorphic = " << is_polymorphic<T>::value << endl;                      //�Ƿ����麯��
		cout << "is_trivially_default_constructible = " << is_trivially_default_constructible<T>::value << endl;      //ȱʡ�������캯���Ƿ��ǿ��п��޵�(û��Ҳ�е�),����1��ʾȷʵ���п���

		cout << "has_virtual_destructor = " << has_virtual_destructor<T>::value << endl;      //�Ƿ�������������

		cout << "--------------end-------------" << endl;

	}

	class A
	{
	public:
		A() = default;
		A(A&& ta) = delete;           //�ƶ����죺��Ҫ��дdelete��ϵͳһ��ͻ���Ϊ���������Ա������
		A(const A& ta) = delete;      //�������� 
		virtual ~A() {}
	};
	class B
	{
	public:
		int m_i;
		int m_j;
	};
	class C
	{
	public:
		C(int t) {} //���Լ��Ĺ��캯������������������ṩȱʡ���캯��
	};

	void func()
	{
		printTraitsInfo(int());     //��һ����ʱ�����ȥ
		printTraitsInfo(string());
		printTraitsInfo(A());
		printTraitsInfo(B());
		printTraitsInfo(C(1));
		printTraitsInfo(list<int>());
	}
}
class R
{

};
int main()
{
	R obj;
	cout << is_object<R>::value << endl;
	//cout << is_object<R>::type << endl;
	//cout << is_object<R>::value_type << endl;
	
	/**
	oop����
	ģ��
	����ָ��
	�߼��ڴ�
	��������߳�
	���ͱ��
	��������
	����
	�����ƶ�
	lambda

	**/
	return 0;
}