#include <iostream>
#include <string>
#include <vector> 

using namespace std;
class X {

public:
	int _x, _y, _z;
	//X(int x = 0, int y = 0, int z = 0) :_x(x), _y(y), _z(z) {
	X(){
		//�������ڱ����Դ��ʱ������ִ�й���֮ǰ���һЩ���룬���������麯����ָ��__vptr == vtable
		//�����memset  ���ڴ�����ˣ�����ɴ���
		memset(this,0,sizeof(X));
		cout << "constructor " << endl;
	}
	//X(const X& obj):_x(obj._x),_y(obj._y),_z(obj._z) {
	X(const X &obj)
	{
		memcpy(this,&obj,sizeof(X));
		cout << "copy constructor" << endl;
	}
	/*virtual ~X()
	{
		cout << "destructor" << endl;
	}*/
	virtual void xxb()
	{
		cout << "xbb" << endl;
	}
};
int main()
{
	/*X obj1;
	obj1._x = 100;
	obj1._y = 200;
	obj1._z = 300;

	X obj2(obj1);

	cout << obj1._x << obj2._y << obj2._z << endl;*/

	
	/*printf("%#x\n",&obj1);
	


	printf("%d\n",sizeof(obj1));

	void* d = (void*)&obj1;

	int* a = (int*)(d)+2;
	cout << *a << endl;*/

	//int* j = (int*)&obj1;

	//cout << *(j+1) << endl;
	//cout << j[0] << endl;
	//cout << j[1] << endl;
	//cout << j[2] << endl;

	
	//X* objx = new X();
	//objx->xxb();//������

	X objx;//����
	objx.xxb();


	/*objx->_x = 7;
	objx->_y = 8;
	objx->_z = 9;

	int* xb = (int*)objx;

	cout << *(xb + 1) << endl;
	cout << xb[0] << endl;

	typedef void(*Func)(void);
	Func yz = (Func)xb[0];
	yz();

	cout << xb[1] << endl;
	cout << xb[2] << endl;
	cout << xb[3] << endl;*/



	return 0;
}