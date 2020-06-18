#ifndef __C__H__
#define __C__H__ 
//#include "C.h"
#include "A.h"

//class A;
class C
{
private:
	void display()const;
private:
	friend class A;
	//friend void A::display(int a, C& c);//c类的朋友是A类的display函数
	friend void A::display(int a, C& c);
};

#endif
