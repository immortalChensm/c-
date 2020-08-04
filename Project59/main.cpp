#include <iostream> 
#include <string> 

using namespace std;
class A;

void haha(class A &b)
{

}
//对象的结构发展和演化
class A final{
public:
	//char* data = (char*)"中";
	//char data[100];
	static int a;
	static int b;

	/*void test()
	{
		int c = 100;
	}

	void operator[](int a) {

	}*/

	virtual void bb()
	{

	}
	//A() = default;
	//A() = delete;
	//A()
	//{

	//}
	///*virtual ~A()
	//{

	//}*/
	//operator int() {
	//	int j = 10;
	//	return j;
	//}

	//A(int a) {

	//}
	//friend void haha(class A);
};
int main()
{
	A obj;

	//strcpy(obj.data,(char*)"中");

	//cout << obj.data << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(obj) << endl;

	//类中存在虚函数时，系统 将会给类对象添加一个4个字节的内存指针指向“虚函数表”这指针成员为vtpr virtual table

	
	//类对象所占用的空间：普通类成员变量+虚函数

	//类中的所有函数跟类对象没有关系，只有类对象会有一个虚函数指针指向虚拟表[vtpr->vtpr]
	return 0;
}