#include <iostream> 
#include <string> 
#include <map>
#include <functional>

//�������ö���|�������ռ�õ��ڴ�ռ�
using namespace std;

class A {
public:
	int operator()(int v) {
		return v > 0 ? v : 0;
	}
};

int ma(int v)
{
	return v + 10;
}

class B {
public:
	void func() {}
	//char a;
	int a;
	int b;
};
int main()
{

	//int t = A()(1);
	//cout << t << endl;

	//map<string, int(*)(int)> obj;
	/*map<string, std::function<int(int)>> obj;

	std::function<int(int)> a = ma;
	std::function<int(int)> b = A();

	obj.insert({"a",a});
	obj.insert({"b",b});

	cout << obj["a"](2) << endl;
	cout << obj["b"](100) << endl;*/

	//B* obj = new B(); //�ڶ��� 32λ��4���ֽ�  64λ��8���ֽ�
	B obj;//ջ����1���ֽ�
	cout << sizeof(obj) << endl;

	obj.a = 10;

	obj.b = 100;

	//�ܽ᣺�������ռ�õ��ڴ��ַ���׵�ַһ������ڵĳ�Ա��������һ��������ȵģ����������� ַ��������һ���ڴ�ռ�

	printf("%#x\n",&obj);
	printf("%#x\n",&(obj.a));

	return 0;
}