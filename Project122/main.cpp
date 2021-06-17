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
		//obj->china();//不可以

		//B& objx = (B*)(*obj);
		//B* objx = dynamic_cast<B *> (obj);
		B* objx = (B*)(obj);
		objx->china();

		const std::type_info& info = typeid(*obj);

		cout << info.name() << endl;
		cout << info.raw_name() << endl;


		if (typeid(*obj) == typeid(B)) {
			cout << "obj 是B类型" << endl;
		}

		//try {

		//	//C* obj = dynamic_cast<C*>(*obj);

		//}
		//catch (std::bad_cast) {

		//	cout << "obj无法转换为C类型" << endl;
		//}

	}
}
namespace test1
{
	void func() {

		int a = 100;//a 左值  100右值  左值：一般是内存地址  右值一般是数据
		int& b = a;//b左值引用  a左值
		int&& c = 100;//c右值引用  本身是左值  

		const int& d = 100;//d虽然是左值引用，但它可以引用右值

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
			cout << "构造函数" << this<<endl;
		}
		CTempValue(const CTempValue& obj) :a(obj.a), b(obj.b) {
			cout << "拷贝构造函数" << this << endl;
		}
		CTempValue& operator=(const CTempValue& obj) {

			a = obj.a;
			b = obj.b;
			cout << "拷贝赋值" << endl;
			return *this;
			
		}
		int Add(CTempValue obj) {

			int ret = obj.a + obj.b;
			return ret;
		}
		~CTempValue() {
			cout << "析构函数" << this << endl;
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
		}
		A& operator=(A&& obj) {

			if (this == &obj) {
				return *this;
			}
			m_b = nullptr;
			m_b = obj.m_b;
			obj.m_b = nullptr;
			cout << "A move copy" << endl;
			return *this;
		}
		A(A&& obj) {

			m_b = nullptr;
			m_b = obj.m_b;
			obj.m_b = nullptr;
			cout << "A move  copy const" << endl;
			
		}
		//A(const A& obj) :m_b(obj.m_b) {//这样会导致 obj成员m_b和当前this.m_b共同指向同一块内存，delete释放出错
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
		//A& a2 = a;
	}
}

using namespace test;
int main() {

	/*const A obj;
	func(obj);

	B x;
	A objx;
	x.test(200,objx);*/
	test3::func();

	return 0;
}