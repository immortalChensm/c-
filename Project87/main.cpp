#include <iostream>
#include <string>
#include <vector>

using namespace std;
class A {
public:
	int _x;
	void show()
	{
		;
	}
	virtual void display()
	{
		printf("display called:%p\n",this);
	}

	static void talk()
	{
		cout << "call talk func" << endl;
	}
};

class B {
public:
	virtual void test1()
	{
		cout << 1 << endl;
	}
	virtual void test2()
	{
		cout << 2 << endl;
	}
};
int main()
{

	printf("%p\n",&B::test1);
	printf("%p\n",&B::test2);

	printf("size=%d\n",sizeof(B));

	B* obj = new B();

	printf("obj���ڴ��ַ�ǣ�%#x\n",&obj);
	printf("obj���ڴ��ַ�ǵ����ݣ�%#x\n",obj);//��vfptr��Ա���ó�Ա���麯����ָ�룬Ҳ�Ǹ���ַ


	long* x = (long*)obj;//��ȡ��obj���ݣ�������һ��vfptrָ��
	long* y = (long*)*x;//��ȡvfptr�ڴ�ָ���ϵ�����

	using func = void(*)(void);

	//func a = (func)y[0];
	//a();
	printf("vfptr=%#x\n",y);
	printf("obj->vfptr[0]��ַ������:%#x\n",y[0]);
	printf("obj->vfptr[1]��ַ������:%#x\n",y[1]);


	int xy = 0;
	//A obj;
	//obj.display();

	//A* objx = new A();
	//objx->display();


	//void (A::*xdisplay)() = &A::display;

	//(objx->*xdisplay)();

	////printf("%p\n",(void*)&(objx->*xdisplay));
	//printf("%p\n",xdisplay);

	//cout << "**************" << endl;
	//((A*)0)->display();
	////((A*)objx)->show();

	/*bj.talk();
	objx->talk();

	A::talk();

	((A*)0)->talk();
	((A*)1)->talk();
	((A*)(200))->talk();*/

	return 0;
}