#include <iostream> 
#include <string> 
//虚函数表指针位置
//虚函数表指针位于类对象的开头，可F9调试查看
using namespace std;

class A
{
public:
	int _i = 0;
	int _j = 0;
	virtual void test()
	{

	}
};
int main()
{

	A obj;
	cout << sizeof(obj) << endl;

	char* p1 = reinterpret_cast<char*>(&obj);
	char* p2 = reinterpret_cast<char*>(&(obj._i));

	if (p1 == p2) {
		cout << "ok" << endl;
	}
	

	return 0;
}