#include <iostream> 
#include <string>
#include <tr1/memory>

using namespace std;


void mydelete(string* p)
{
	delete p;
	p = nullptr;
	cout << "pp" << endl;
}
class A{
public:
	A()
	{
		cout<<"constructor"<<endl;
	}
	~A()
	{
		cout<<"destructor"<<endl;
	}
	int _a;
};
void show(shared_ptr<A> p)
{
	cout<<p->_a<<endl;
}

int main()
{
	/*cout<<[](int a, int b) {
		return [](int c) {return c; };
	}(10,20)(10)<<endl;*/

	//1��unique_ptr<string��ɾ������������> p(new string(),������);
	//typedef void (*fp)(string *);
	//using fp = void(*)(string *);
	//typedef decltype(mydelete)* fp;//���� void(string *) ��* ��ʾ���غ���ָ��

	//unique_ptr<string, decltype(mydelete)*> p(new string("test"), mydelete);

	/*int a = 100;
	decltype(a) *b = &a;
	cout << a << b << endl;*/

	/*auto mydeletes = [](string *p) {
		delete p;
		p = nullptr;
		cout << "auto delte" << endl;
	};

	unique_ptr<string, decltype(mydeletes)> p(new string("hi"),mydeletes);*/

	//�ߴ�����
	//shared_ptr ����ռ��8���ֽ�  unique_ptr ռ��4���ֽ�
	/*int a0 = 19;
	int *a = &a0;
	int a1 = sizeof(a);

	shared_ptr<int> b(new int(10));
	shared_ptr<string>c (new string("tdsfdsfdsest"));

	int a2 = sizeof(c);*/

	/*unique_ptr<string> c(new string("sdfdsfsdf"));
	int a = sizeof(c);*/

//	string* a ;
//	int a0 = sizeof(a);
//
//	shared_ptr<string> c(a);
//	int a1 = sizeof(c);
//
//	unique_ptr<string> d(a);
//
//	int a2 = sizeof(d);

	//����ָ���ܽ᣺
	//1�������ͷ��ڴ棬��ֹ��дʱ�����ͷ�delete
	//unique_ptr<int> p(new int(10));
	//cout<<*p<<endl;

	//unique_ptr<int> p1(p);

	shared_ptr<A> p(new A());
	show(p);

	return 0;
}