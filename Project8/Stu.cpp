#include "Stu.h"
#include <iostream>
#include <string>
using namespace std;
Stu::Stu(int num, string name, float score) :_num(num), _name(name), _score(score)
{

}
Stu::Stu()//Ĭ����ʽ�Ĵ���Stu * const this ����  ��thisָ����ڴ��ַ�������޸�
//this ��ָ���const �����const ָ��
//�����const ������ָ��const�����constָ��
{
	_num = 0;
	_score = 0;
	_name = "";

	this->_num = 888;
}
void Stu::display() {
	cout << _name << _num << _score << endl;
}

int Stu::getNum()const
{
	_num = 100; //���޸ĵ������Ǵ˳�Աǰ׺������mutable�ؼ���
	return _num;
}

