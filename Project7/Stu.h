#ifndef __STU__H__
#define __STU_H__ 

class Stu
{
private:
	int _num;
	char _name[100];
public:
	float _score;
public:
	//Stu(int num=10, char* name=(char*)"");
	Stu(int num, char* name);
	Stu();
	Stu(int a);
	Stu(int a,int b);
	Stu(float c);
	//Stu(auto b);
	void display();
};
#endif // !__STU__H__

