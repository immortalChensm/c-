#include "Human.h"
#include "Men.h"
#include <iostream> 
/**

�̳з�ʽ��public 
���������public ������������Է���  ������Ҳ���Է���
���������protected ����������Է��� �����Է���

���������private �������ⶼ�����Է���

�̳з�ʽ��proteced  
���������public ����������Է��ʣ������ⲻ���Է���
���������proteced ����������Է��ʣ������ⲻ���Է���

�̳з�ʽ��private
���������public,proteced ����������Է��ʣ������ⲻ���Է���
**/

//�̳�|��Ա�ڱ�|�̳з�ʽ|using
/**
mutable
const
static

const
auto
inline
operator
��������
���캯��
	Ĭ�Ϲ��캯�� =default,=delete
	��һ������������ת�����캯��
	��һ�������Ŀ������캯��
	����������Ĺ��캯��
	explcit
��Ա��������|��Ա�����ڱΡ��̳�ʱ��
**/
int main()
{
	Men jack;

	//jack.say();


	//��Ա�����ڱη��� ͨ��using�޸�
	jack.talk(2);
	jack.talk(1);

	jack.talk();

	jack.setPwd();
	
	return 0;
}