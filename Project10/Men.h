#ifndef __MAN__H
#define __MAN__H 

#include "Human.h"
//class Men:public Human
class Men:protected Human
class Men:public Human
{
public:
	Men();
public:
	void talk(int num);
public:
	using Human::talk;
	using Human::setPwd;
};
#endif 
