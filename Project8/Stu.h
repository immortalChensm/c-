#ifndef __STU__H__
#define __STU_H__ 
#include <string>
using namespace std;
class Stu
{
private:
	mutable int _num;//��ʾ�˱��������޸�  �ر��Ǵ���ʵ��Ϊconst ����ʱ
	string _name;
public:
	float _score;
public:
	Stu(int num, string name, float score);
	Stu();
	void display();
	void addNum(int num)//Ĭ�ϵ�����������
	{
		_num += num;
	}
	auto addScore(int score)->int {//Ĭ��Ҳ����������  ��Ҫ������֧��
		_score += score;
		return 1;
	}

	int getNum()const;//const ��Ա����  ��ʾ����ĳ�Ա����ֵ���ᱻ�޸�
};
#endif // !__STU__H__

