#include <iostream> 
#include <string> 

using namespace std;
//�����ƶ�
//�ƶ����캯��||�ƶ���ֵ�����

class B {
public:
	B() :_a(100) {
		//cout << "B���캯����ִ��" << endl;
	}

	B(const B& t) :_a(t._a) {
		//cout << "B����������ִ��" << endl;
	}

	~B() {
		//cout << "B����������ִ��" << endl;
	}
	int _a;
};

class A {
public:
	//Ĭ�Ϲ��캯��
	A() :_obj(new B) {
		cout << "A���캯����ִ��" << endl;
	}
	//�������캯��
	A(const A& tmp) :_obj(new B(*(tmp._obj))) {
		cout << "A����������ִ��" << endl;
	}
	//�ƶ����캯��
	A(A&& tmp) {
	
		cout << "A�ƶ�������ִ��" << endl;
	}
	virtual ~A() {
		delete _obj;
		cout << "A����������ִ��" << endl;
	}
public:
	B* _obj;
};

static A getA()
{
	A a;
	return a;
}

int main()
{
	//�ƶ����캯��
	//1��A�ƶ���B,A�Ͳ�����ʹ����
	//2: �ƶ����ǰ���һ����ַ������Ū����һ����ַ��ֻ�������߱��
	//�������캯������  ����(const �� &x) {} &x ����ֵ���� ����ʱ�ô�����ֵ
	//�ƶ����캯������  ����(const �� &&x) {} &xx����ֵ����  ����ʱ����ֵ


	//��ֵ�����ڴ�ռ� ������ʱֻ�ܸ���ֵ
	//��ֵ���ã�ͬ�����ڴ�ռ�  ����ʱֻ�ܴ�����ֵ
	//const ����ֵ����  ���Ը���ֵ�������ԡ�
	//��ֵ���󲿷��ǳ���ֵ
	//��ֵ���ã�ֻ�ܸ���ֵ Ҳ���Խ���ֵת��Ϊ��ֵ std::move(��ֵ)

	//�ƶ����캯�����ƶ���ֵ����Ĺ���
	//1����ɱ�Ҫ���ڴ��ƶ���ն��ԭ�������ڴ�Ĺ�ϵ
	//2��ȷ��Դ������һ�֡���ʹ������Ҳû������ġ�һ��״̬,ȷ�ϲ���ʹ��ԭ���󣬶���ʹ���ƶ���Ķ���

	/*int a = 1;
	int& b = a;
	const int& c = a;
	const int& d = 100;

	int&& e = std::move(a);

	cout << e << a << endl;

	a = 100;
	cout << e << a << endl;
	e = 1000;
	cout << e << a << endl;*/

	/*A* a = new A;
	a->_a= 10;
	A* b = new A(*a);*/

	A a = getA();
	return 0;
}