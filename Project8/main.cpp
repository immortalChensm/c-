#include <iostream>
#include <string>
#include <vector>

#include "Stu.h"
using namespace std;
//static inline const mutable this 
//inline ������Ա����
//const ��Ա����  const����ֻ�ܵ������ֺ��� 
//mutable �ױ䣬���ȶ� ��const �෴
//this ��ʽ���ݲ�������ĳ�Ա������������ �����ʵ�����Ķ�����const ���� ���������  ��this= const ����  * const this
//����ǣ�����  ������  ��this= ����  * const this

//���캯��
//=default,=delete ���Ա������ʼ��
int main()
{
	/*Stu s = { 1,(char*)"jack",100 };

	s.addNum(2);

	s.display();

	s.addScore(20);

	s.display();

	cout << s.getNum() << endl;*/

	const Stu s;//ֻ�ܵ���const ��Ա  �����еĳ�Աthis Ĭ�ϻᴫ��const Stu *const this

	//s.addScore(1);//const ���󲻿��Ե���
	cout<<s.getNum()<<endl;
	
	Stu s1;//Ĭ�ϻ���ʽ����Stu *const this����
	cout<<s1.getNum() << endl;
	return 0;
}