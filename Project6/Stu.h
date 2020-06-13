#ifndef __STU__H__
#define __STU__H__

//int number; 不可以，但是c可以

class stu
{
private:
	int score;
	void initScore(int s);
public:
	int _number;
	char _name[100];

	void initStu(int number, char* name);
};

#endif 
