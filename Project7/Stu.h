#ifndef __STU__H__
#define __STU_H__ 
#include <string>
using namespace std;
class Stu
{
private:
	int _num;
	string _name;
public:
	float _score;
public:
	//Stu(int num=10, char* name=(char*)"");
	explicit Stu(int num, string name,float score=100);
	//Stu(int num, char* name,float score=100);
	//Stu(int num, char* name);
	Stu();
	Stu(int anum);
	//Stu(int a,int b);
	//Stu(float c);
	//Stu(auto b);
	void display();
};
#endif // !__STU__H__

