#include "Human.h"
#include "Men.h"
#include <iostream> 
#include "Women.h"
#include "func.h"

#include "A.h"
#include "C.h"

using namespace std;
//友元函数|友元类|友元关系不能被继承|友元关系是单向的|友元关系没有传递性|友元类成员函数
//友元的引入会破坏类的封装性和维护性，好处就是可以访问类的private,proteced成员
int main()
{
	
	
	//Men* jack = new Men;
	//jack->talk();
	
	//Human* p = new Men;
	//p->talk();

	//p->run();
	//Men* s = new Human;

	//p->eat();

	//Human* p1 = new Women;
	//p1->eat();
	//Men* p = new Men;
	
	A a;
	C c;

	a.display(1,c);
	return 0;
}