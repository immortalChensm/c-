#ifndef __STU__H__
#define __STU__H__

#include <iostream> 
using namespace std;

class Score
{
public:
	Score() {
		cout << "������Score()Ĭ�Ϲ��캯��" << endl;
	}
	Score(Score& s) {
		cout << "������Score(Score& s)���ƹ��캯��" << endl;
	}
};
class Stu
{
public:
	Stu(int age,int num,int sex);//��ͨ�Ĺ��캯��
	//Stu() {};//Ĭ�ϵĹ��캯��  Stu()=default;
	//Stu() = default;
	Stu() {
		cout << "������Stu()Ĭ�Ϲ��캯��" << endl;
	}
	//Stu() = delete;
	void display();

	//����ת�����캯��
	Stu(int age);

	//�������캯��
	//explicit Stu(Stu& s,int a=10,int b=100);//�����Ĭ��ֵ������Ͳ��ǿ������캯�� �����Լ�explicti 
	 Stu(Stu& s,int a=10,int b=100);//�����Ĭ��ֵ������Ͳ��ǿ������캯��
	Score s;//��Stu��ʵ����ʱ���˳�ԱҲ��ʵ��������������Ĭ�Ϲ��캯���ᱻϵͳ���ã��������Stu�����˶��󿽱�����
			//Ҳ�����Score��Ա�Ŀ������ƹ��캯��

private:
	mutable int _age{ 1 };
	mutable int _num{ 0 };
	mutable int _sex{ 0 };
};
#endif 