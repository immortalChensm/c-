#ifndef __STU__H__
#define __STU_H__ 
#include <string>
using namespace std;
class Stu
{
private:
	mutable int _num;//表示此变量可以修改  特别是此类实例为const 对象时
	string _name;
public:
	float _score;
public:
	Stu(int num, string name, float score);
	Stu();
	void display();
	void addNum(int num)//默认当作内联函数
	{
		_num += num;
	}
	auto addScore(int score)->int {//默认也是内联函数  需要编译器支持
		_score += score;
		return 1;
	}

	int getNum()const;//const 成员函数  表示类里的成员变量值不会被修改
};
#endif // !__STU__H__

