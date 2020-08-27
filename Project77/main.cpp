#include <iostream> 
#include <string> 
//�麯���ֹ�����
//�����麯�����࣬����һ���麯����ָ��vptr��4�ֽڻ���8�ֽڡ�ָ��һ�������vtbl
using namespace std;

class Base
{
public:
	virtual void a() {
		cout << "a" << endl;
	}
	virtual void b() {
		cout << "Base::b" << endl;
	}
	virtual void c() {
		cout << "c" << endl;
	}
};
class B :public Base
{
public:
	/*virtual void b() {
		cout << "B::b" << endl;
	}*/
};
int main() {


	cout << sizeof(Base) << endl;
	cout << sizeof(B) << endl;

	//��������obj
	//������ַ��0x01
	//�������ݣ�new B  ������һ���ڴ��ַ��ָ�롿����ַ����Ȼ�����ݣ����麯����ָ��
	B* obj = new B();

	printf("obj���ڴ��ַ��%#x\n",&obj);
	printf("obj���ڴ��ַ�����ݣ�%#x\n",obj);

	printf("obj���ڴ��ַ�����ݡ�ָ�롿�ϵ����ݣ�%#x\n",*obj);

	long* x = (long*)obj;

	long* vptr = (long*)(*x);

	printf("obj���ڴ��ַ�����ݡ�ָ�롿�ϵ����ݣ�%#x\n", vptr);
	for (int i = 0; i < 4; i++) {
		printf("vptr[%d]��%#x\n",i, vptr[i]);
		
	}

	typedef void(*Func)(void);

	Func f1 = (Func)vptr[0];
	Func f2 = (Func)vptr[1];
	Func f3 = (Func)vptr[2];
	
	f1();
	f2();
	f3();

	cout << "*******************" << endl;
	Base* objx = new Base();
	long* x1 = (long*)objx;
	long* x2 = (long*)*x1;

	for (int i = 0; i < 4; i++) {
		printf("vptrparent[%d]��%#x\n", i, x2[i]);

	}
	printf("obj��%#x\n", *vptr);
	printf("x2��%#x\n", *x2);
	Func f11 = (Func)x2[0];
	Func f22 = (Func)x2[1];
	Func f33 = (Func)x2[2];

	f11();
	f22();
	f33();

	//1���������麯�����ͻ����麯����ͬ����һ����Ķ�����󣬻���һ���麯��ָ��vptrָ���麯������׵�ַ
	int a = 0;
	return 0;
}