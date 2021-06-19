#include <iostream>

using namespace std;
//class B;
//class A {
//private:
//	int data{ 0 };
//	friend void func(const A& obj);
//	friend class B;
//	//friend void B::test(int x, A& obj);
//};
//class B {
//public:
//	void test(int x, A&obj) {
//
//		obj.data = x;
//		cout << obj.data << endl;
//	}
//};
//void func(const A& obj) {
//	cout << obj.data << endl;
//}

namespace test {

	class A {
	public:
		A() {

		}
		virtual void test() {
			cout << "A::test" << endl;
		}
		virtual ~A() {

		}
	};
	class B :public A {
	public:
		virtual void test() override {
			cout << "B::test" << endl;
		}
		void china() {
			cout << "B::china" << endl;
		}
	};
	class C :public A {
	public:
		virtual void test() override {
			cout << "C::test" << endl;
		}
	};
	void func() {


		A* obj = new B();
		obj->test();
		//obj->china();//������

		//B& objx = (B*)(*obj);
		//B* objx = dynamic_cast<B *> (obj);
		B* objx = (B*)(obj);
		objx->china();

		const std::type_info& info = typeid(*obj);

		cout << info.name() << endl;
		cout << info.raw_name() << endl;


		if (typeid(*obj) == typeid(B)) {
			cout << "obj ��B����" << endl;
		}

		//try {

		//	//C* obj = dynamic_cast<C*>(*obj);

		//}
		//catch (std::bad_cast) {

		//	cout << "obj�޷�ת��ΪC����" << endl;
		//}

	}
}
namespace test1
{
	void func() {

		int a = 100;//a ��ֵ  100��ֵ  ��ֵ��һ�����ڴ��ַ  ��ֵһ��������
		int& b = a;//b��ֵ����  a��ֵ
		int&& c = 100;//c��ֵ����  ��������ֵ  

		const int& d = 100;//d��Ȼ����ֵ���ã���������������ֵ

		string df{ "ilikechina" };
		string& cf = df;

		df = "iam tony";

		cout << df << cf << endl;

		int&& k = std::move(a);
		
		a = 888;
		k = 101;
		cout << k << a << endl;

	}
}
namespace test2
{
	class CTempValue {
	public:
		int a;
		int b;
		CTempValue(int x=0, int y=0) :a(x), b(y) {
			cout << "���캯��" << this<<endl;
		}
		CTempValue(const CTempValue& obj) :a(obj.a), b(obj.b) {
			cout << "�������캯��" << this << endl;
		}
		CTempValue& operator=(const CTempValue& obj) {

			a = obj.a;
			b = obj.b;
			cout << "������ֵ" << endl;
			return *this;
			
		}
		int Add(CTempValue obj) {

			int ret = obj.a + obj.b;
			return ret;
		}
		~CTempValue() {
			cout << "��������" << this << endl;
		}
	};
	CTempValue  test(CTempValue obj) {

		CTempValue result;
		result.a = obj.a + 100;
		result.b = obj.b + 200;
		return result;
	}
	void func() {

		/*CTempValue obj(100, 20);

		int ret = obj.Add(obj);

		cout << "ret=" << ret << endl;*/
		CTempValue obj;
		obj = 100;
		//CTempValue x = obj;

		//CTempValue ret = test(100);

		//cout << ret.a << ret.b << endl;

	}

	
}
namespace test3
{
	class B {
	public:
		int a;
		B() :a(100) {
			cout << "B" << endl;
		}
		B(const B& obj) :a(obj.a) {
			cout << "B copy" << endl;
		}
		virtual ~B() {
			cout << "~B" << endl;
		}
	};
	class A {
	public:
		A() :m_b(new B()) {
			cout << "A" << endl;
		}
		A(const A& obj) :m_b(new B(*(obj.m_b))) {
			cout << "A copy" << endl;
		}
		A& operator=(const A& obj)  {
			m_b = (new B(*(obj.m_b)));
			cout << "A == copy" << endl;
			return *this;
		}
		A& operator=(A&& obj)noexcept {

			if (this == &obj) {
				return *this;
			}
			m_b = nullptr;
			m_b = obj.m_b;
			obj.m_b = nullptr;
			cout << "A move copy" << endl;
			return *this;
		}
		A(A&& obj) noexcept{

			m_b = nullptr;
			m_b = obj.m_b;
			obj.m_b = nullptr;
			cout << "A move  copy const" << endl;
			
		}
		//A(const A& obj) :m_b(obj.m_b) {//�����ᵼ�� obj��Աm_b�͵�ǰthis.m_b��ָͬ��ͬһ���ڴ棬delete�ͷų���
		//	cout << "A copy" << endl;
		//}
	private:
		B* m_b;
	};
	static A getA() {
		A a;
		return a;
	}
	void func() {

		//B obj;
		//B obj1 = obj;

		//A obj2;
		//A obj3 = obj2;
		/*A* obj = new A();
		A* obj2 = new A();
		obj2 = obj;

		delete obj;*/
		//delete obj2;

		A a = getA();

		A&& a1 = std::move(a);

		
		A& a2 = a;
	}
}
namespace test4
{
	class Grand {
	public:
		Grand(int x) :grand(x) {
			cout << "Grand ���캯��" << endl;
		}
		virtual ~Grand() {
			cout << "Grand ��������" << endl;
		}
		void myinfo() {

			cout << "Grand grand" << grand << endl;
		}
	public:
		int grand;
	};
	class A:virtual public Grand {
	public:
		A(int x) :Grand(x),a(x) {
			cout << "A ���캯��" << endl;
		}
		virtual ~A() {
			cout << "A ��������" << endl;
		}
		void myinfo() {

			cout << "A a==" << a << endl;
		}
	public:
		int a;
	};
	//��̳л���  �������  �������
	class A2 :public virtual  Grand {
	public:
		A2(int x) :Grand(x), a2(x) {
			cout << "A2 ���캯��" << endl;
		}
		virtual ~A2() {
			cout << "A2 ��������" << endl;
		}
		void myinfo() {

			cout << "A a2" << a2 << endl;
		}
	public:
		int a2;
	};
	class B {
	public:
		B(int x) : b(x) {
			cout << "B ���캯��" << endl;
		}
		virtual ~B() {
			cout << "B ��������" << endl;
		}
		void myinfo() {

			cout << "B b" << b << endl;
		}
	public:
		int b;
	};
	class C :public A,public A2, public B {//�����б�

	public:
		C(int x,int y,int z) :A(x),A2(x),B(y),Grand(x), c(z) {
			cout << "C ���캯��" << endl;
		}
		virtual ~C() {
			cout << "C ��������" << endl;
		}
		void myinfoC() {

			cout << "C c" << c << endl;
		}
	public:
		int c;

	};
	class X {
	public:
		//X(){}
		X(int x=0) {}
	};
	class Y1 {
	public:
		//Y() {}
		Y1(int x=0){}
	};
	class Z :public X, public Y1 {
	public:
		//using Y1::Y1;
		using X::X;
		//using Y::Y;//�̳л���Ĺ��캯��  �������дһ���Լ��Ĺ��캯��
		/*Z(int x) :X(x) {

		}
		Z(int x) :Y(x) {

		}*/
	};
	void func() {

		C obj(1,2,3);
		obj.myinfoC();

		//obj.myinfo();
		obj.A::myinfo();

	}
}
namespace test5
{
	class A {
	public:
		A(int x = 0) :a(x) {
			cout << "A x" << x << endl;
		}
		int a;
	public:
		//typedef void(*func)(int);
		using Func = void(*)(int);
		operator int() {
			return a;
		}
		static void myshow(int x){
			cout << "myshow" << x<<endl;
		}
		operator Func() {
			return myshow;
		}
	};
	class CT1 {
	public:
		CT1(int x=0){}
	};
	class CT2 {
	public:
		CT2(int x=0) {}
	};
	void test(CT1 obj){}
	void test(CT2 obj) {}

	class TestInt {
	public:
		void ptfunc() {
			cout << "ptfunc" << endl;
		}
		static void staticfunc() {
			cout << "staticfunc" << endl;
		}
		virtual void virfunc() {
			cout << "virfunc" << endl;
		}
		int x{ 0 };
		static int y;
	};
	int TestInt::y = 0;

	void func() {

		TestInt obj;

		void(TestInt:: * pt)() = &TestInt::ptfunc;

		(obj.*pt)();

		void (TestInt:: * vir)() = &TestInt::virfunc;

		(obj.*vir)();


		void (*stat)() = &TestInt::staticfunc;

		stat();

		int TestInt::* px = &TestInt::x;

		(obj.*px) = 100;

		cout << (obj.*px) << endl;

		int* py = &TestInt::y;
		*py = 101;
		cout << *py << endl;

		printf("x=%d,x=%#x\n",&TestInt::x, &obj.x);
		printf("y=%d,y=%#x\n",&TestInt::y, &obj.y);

		/*A obj = 1;
		A obj2{ 2 };
		obj(22);
		int k = static_cast<int>(obj)+100;
		obj.operator test5::A::Func()(222);

		test(CT1{22});*/

		/*int k = obj;
		int j = obj.operator int();

		int m = obj + 100;
		cout << "m=" << m << endl;*/

	}
}

using namespace test;
int main() {

	/*const A obj;
	func(obj);

	B x;
	A objx;
	x.test(200,objx);*/
	test5::func();

	return 0;
}