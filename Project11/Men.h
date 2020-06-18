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
		//cout << "我想访问朋友A类的东西" << A::_d << endl;
	}
	void sleep() const;
	friend void func(const Men& p);//友元函数 此类的朋友函数func
	friend class Jack;//友元类  此类的朋友类A
};
#endif 
