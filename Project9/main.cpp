#include <iostream>
#include "Stu.h"
/**
��Ĺ��캯��
1��û�в����Ľ�Ĭ�Ϲ��캯��
	��ʹû�ж��壬������Ҳ���Զ����ɺϳɵ�Ĭ�Ϲ��캯��
	Ĭ�Ϲ��캯���Ķ��壺xxx(){} xxx()=default;������Ĭ�Ϲ��캯�� xxx()=delete;
2��ֻ��һ�������Ĺ��캯��
	2��1�����һ���������Ǳ����������Ϊ����ת�����캯��
	2��2�����һ�������Ǳ�������á�����е���������������Ĭ��ֵ����Ͳ��Ǹ��ƹ��캯�����򹹳ɿ������캯��
	�������캯����һ�������ɼ���const ǰ׺���� ��ʾ���ݲ����޸�
	�������캯�����ɼ��Ͻ�����ʽexplicit�ֶ� 
3������������Ĺ��캯��

���캯��һ����ϵͳ�Զ����ã���ʵ�������ʱ��
���캯�����ڳ�Ա���������⺯��


**/

//void func(Stu stu)
//{
//	return;
//}

Stu func() {
	Stu s;
	return s;
}
int main()
{
	//Stu s;//����Ĭ�Ϲ��캯��
	//Stu s1{ 1,2,3 };//����3�������Ĺ��캯��
	//s1.display();
	//����������������ʵ��Ҳ�ᷢ�����ÿ������캯��
	//func(s1);

	func
	();

	//Stu s2 = 10;//��������ת�����캯��
	//s2.display();

	//Stu s3{ 100 };//��������ת�����캯��
	//s3.display();
	//���󿽱�
	//Stu s21 = s1;
	//Stu s2 = { s1 };
	//Stu s3 = (s1);
	//Stu s4 = { {s1} };
	//Stu s5 = ((s1));
	//Stu s6 = { (s1) };
	//////Stu s7 = ({ s1 });
	//Stu s8{ s1 };
	//Stu s9(s1);
	//Stu s10{ {s1} };
	//Stu s11((s1));
	//Stu s12{ (s1) };
	//Stu s13({ s1 });
	////Stu s14{ {{s1}} };
	//Stu s15(((s1)));
	//Stu s16(((((((s1)))))));

	//s16.display();



	return 0;
}