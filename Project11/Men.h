#ifndef __MAN__H
#define __MAN__H 

#include "Human.h"
#include "A.h"
//class Men:public Human
//class Men:protected Human
class Men :public Human
{
public:
	Men();
public:
	void eat() {
		cout << "men eat " << endl;
	}
public:
	
private:
	void worker()const {
		cout << "men is worker" << endl;
		//cout << "�����������A��Ķ���" << A::_d << endl;
	}
	void sleep() const;
	friend void func(const Men& p);//��Ԫ���� ��������Ѻ���func
	friend class Jack;//��Ԫ��  �����������A
};
#endif 
