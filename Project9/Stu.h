#ifndef __STU__H__
#define __STU__H__

#include <iostream> 
using namespace std;

class Score
{
public:
	Score() {
		cout << "调用了Score()默认构造函数" << endl;
	}
	Score(Score& s) {
		cout << "调用了Score(Score& s)复制构造函数" << endl;
	}
};
class Stu
{
public:
	Stu(int age,int num,int sex);//普通的构造函数
	//Stu() {};//默认的构造函数  Stu()=default;
	//Stu() = default;
	Stu() {
		cout << "调用了Stu()默认构造函数" << endl;
	}
	//Stu() = delete;
	void display();

	//类型转换构造函数
	Stu(int age);

	//拷贝构造函数
	//explicit Stu(Stu& s,int a=10,int b=100);//必须给默认值，否则就不是拷贝构造函数 不可以加explicti 
	 Stu(Stu& s,int a=10,int b=100);//必须给默认值，否则就不是拷贝构造函数
	Score s;//当Stu类实例化时，此成员也会实例化，并且它的默认构造函数会被系统调用，如果此类Stu产生了对象拷贝操作
			//也会调用Score成员的拷贝复制构造函数

private:
	mutable int _age{ 1 };
	mutable int _num{ 0 };
	mutable int _sex{ 0 };
};
#endif 