#include <iostream>
#include <vector>


using namespace std;

namespace test
{
	class A {
	public:
		int _x;
		A()
		{
			cout << "Ĭ�Ϲ��캯��a" << endl;
		}
		A(const A& obj) {
			this->_x = obj._x;
			cout << "�������캯��copy a" << endl;
		}
		void operator=(const A& obj) {
			this->_x = obj._x;
			cout << "��ֵ���캯��copy = a" << endl;
			
		}
		~A()
		{
			cout << "��������~a" << endl;
		}
	};

	A operator+(const A& obj1, const A& obj2) {

		A tempobj;
		tempobj._x = obj1._x + obj2._x;
		return tempobj;
	}

	void func()
	{
		A obj1;
		obj1._x = 10;
		A obj2;
		obj2._x = 20;

		//A obj3 = obj1 + obj2;
		A obj3;
		obj3 = obj1 + obj2;
		cout << obj3._x << endl;
	}
}
int main()
{


	test::func();
	return 0;
}