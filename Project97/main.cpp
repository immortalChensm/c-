#include <iostream>
#include <string>
#include <vector>


using namespace std;
namespace test
{ 
	
	// �����Ĭ�ϸ�����Ϊ
	// ���������캯���Ϳ�����ֵ����˽��֮�󣬾��޷��ڶ���֮����п�����
	class A {
	public:
		int _x,  y;

		A& operator= (const A& obj) {
			this->_x = obj._x;
			this->y = obj.y;
			return *this;
		}

		A(const A& obj) {
			this->_x = obj._x;
			this->y = obj.y;
		}
		A() {
			this->y = 0;
			this->_x = 0;
		}
	};

	void func()
	{
		A obj;
		obj._x = -1;
		obj.y = 2;

		A obj2 = obj;

		A obj3;
		obj3 = obj2;

	}
}
namespace test2
{
	// ���������ϳ�
	class Base {
	public:
		~Base()
		{
			cout << "Base::~Base" << endl;
		}
	};
	class A :public Base {

	};
	void func()
	{
		A obj;
	}
}
int main()
{

	test2::func();
	return 0;
}