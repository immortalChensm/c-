#include <iostream>
#include <map>
#include <vector>
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
namespace test6
{

	template <typename a,typename b>
	a adds(a x, b y) {
		a j = x + y;
		return j;
	}

	template<class T,int x>
	T addhe(T a, T b) {

		T j = a + b + x;
		return j;
	}

	void func() {


		int k = adds(100, 200);//�������Լ��ƶ�

		cout << k << endl;
		//�ֶ��Ƶ�
		cout << addhe<int,100>(100, 200) << endl;

	}
}
namespace test7
{
	template<typename T,int size=10>
	class A {
	public:
		A();
		A& operator=(const A& obj);
		void show();
	};
	template<typename T, int size>
	A<T, size>::A() {
		cout << "constructor" << endl;
	}

	template<typename T, int size>
	A<T,size>& A<T, size>::operator=(const A<T,size>& obj) {

		return *this;
	}
	template<typename T, int size>
	void A<T, size>::show() {
		cout << "show" << size << endl;
	}
	
	//template<typename T,char b='c'>
	//template<typename T, double b=100.323>
	//template<typename T, string b="tom">
	class x {};
	//template<typename T, x b>
	template<typename T, char b = 'c'>
	void show(T x) {
		cout << x << b << endl;
	}
	void func() {

		A<int> obj;
		A<int, 100>* objx = new A<int,100>();

		obj.show();
		objx->show();

		show(100);

	}
}
namespace test8
{
	//typename �������������
	template<typename T>
	typename T::size_type getLength(T o) {

		if (o.empty()) {
			return 0;
		}
		return o.size();
	}
	typedef int (*Func)(int,int);

	int mf(int v1, int v2) {
		return v1 + v2;
	}

	void funcx(int a, int b, Func fx) {
		int result = fx(a,b);
		cout << "result=" << result << endl;
	}
	template<typename T>
	class myiterator {
	public:
		//int *p
		typedef T *iterator;
	public:
		iterator begin();
	};

	template<typename T>
	typename myiterator<T>::iterator myiterator<T>::begin() {

		myiterator i;
		return &i;
	}
	class tc {
	public:
		tc() {
			cout << "tc" << endl;
		}
		tc(const tc& obj) {
			cout << "tc copy" << endl;
		}
		int operator()(int x,int y) {
			return x + y;
		}
	};
	//template<typename T,typename F=tc>
	
	//void funcj(const T& a, const T& b, F fun=tc()) {
	template<typename T, typename F = Func>
	void funcj(const T& a, const T& b, F fun=mf) {
		T result = fun(a, b);
		cout << "result=" << result << endl;
	}
	void func() {


		string name = "tom";
		string::size_type s = getLength(name);
		cout << s << endl;

		funcx(100,200,mf);

		funcj(300,500,mf);

		funcj(200,200,tc());

		funcj(1,1);
	}
}
namespace test9
{
	template<typename C>
	class Te {
	public:
		template<typename T2>
		Te(T2 a, T2 b);

		template<typename T>
		void test(T o);
	public:
		void show() {

		}

		C m_i;
	};

	template<typename C>
	template<typename T2>
	Te<C>::Te(T2 a,T2 b) {
		cout << "Te" << a << b << endl;
	}
	template<typename C>
	template<typename T>
	void Te<C>::test(T o) {
		cout << "test" << o << endl;
	}

	//template void jj(int o);
	template<typename T>
	void jj(T o) {
		cout << "jj" << o << endl;
	}
	
	//��ʾʵ���� 
	extern template Te<char>;

	//extern template void jj(int o);
	

	void func() {

		Te<float> a(1, 2);
		a.test(10);

		jj(100);

		std::map<std::string, int> map;
		map["a"] = 1;
		map["b"] = 2;

		for (auto itr: map) {

			printf("%d\n",itr.second);
		}
	}
}
namespace test10
{
	//����ģ��  ��ģ��  ��ģ���Ա����ģ�� ����ģ��
	template<typename T>
	struct map {
		typedef std::map<std::string, T> type;
	};

	template<typename T>
	using types = std::map<std::string, T>;

	void show(int x) {
		cout << x << endl;
	}
	template<typename T>
	using fun = void(*)(int);

	template<typename T1,typename T2,typename T3>
	void ok(T1 a, T2 b, T3 c) {
		cout << a + b + c << endl;
	}
	void func() {

		map<int>::type maps;
		maps["a"] = { 1 };
		maps["b"] = { 2 };
		types<int> jj;
		jj["ok"] = 10;
		for (auto itr : maps) {
			cout << itr.second << endl;
		}
		cout << jj["ok"] << endl;

		fun<int> fx = show;
		fx(22);

		ok(1,2,3);
		ok<int, int, int>(10,20,30);

	}
}
namespace test11
{
	class A {};
	void funcxxx() {

	}
	void func() {

		auto k = 100;
		auto m = 100.22;
		auto l = "china";
		auto n = {"i like china"};
		auto x = new A();
		int lucy = 1;
		auto y = &lucy;
		int&& tom = 122;
		auto z = tom;
		auto p = funcxxx;

		p();


	}
}
namespace test12
{
	template<typename T>
	class A {
	public:
		A(T o) {
			cout << "ģ�淺���汾"<<o << endl;
		}
	};
	template<>
	class A<float> {
	public:
		A(float o) {
			cout << "ģ��ȫ�ػ��汾" << o << endl;
		}
	};

	template<typename T,typename U>
	class TC {
	public:
		TC() {
			cout << "ģ�淺���汾" << endl;
		}
	};

	template<>
	class TC<int , char> {
	public:
		TC() {
			cout << "ģ��int,char�ػ��汾" << endl;
		}
	};
	template<typename T>
	class TC<T, double> {
	public:
		TC() {
			cout << "ģ��T,double�ֲ�֮���������ػ��汾" << endl;
		}
	};

	template<typename T,typename U>
	class TC<const T, const U>
	{
	public:
		TC() {
			cout << "ģ��const T,const U�ֲ�֮������Χ�ػ��汾" << endl;
		}
	};

	template<typename T, typename U>
	class TC< T*, U*>
	{
	public:
		TC() {
			cout << "ģ��T*, U*�ֲ�֮������Χ�ػ��汾" << endl;
		}
	};
	template<typename T, typename U>
	class TC< T &, U&>
	{
	public:
		TC(T &a,U &b) {
			cout << "ģ�� T &, U&�ֲ�֮������Χ�ػ��汾" << endl;
		}
	};
	
	template<typename T>
	void test(T o) {
		cout << "����ģ�巺��" << endl;
	}
	template<>
	void test(int o) {
		cout << "����ģ��ȫ�ػ�" << endl;
	}
	void func() {

		//A<int > ob(100);
		//A<float> ok(100.2);
		TC<int, int> j;
		TC<int, char> x;
		TC<string, double> m;
		int a1 = 10;
		char b2 = 'c';
		TC<int*, char*> z1;
		TC<const int, const char> z2;
		TC<int&, char&> z3(a1,b2);

		test("china");
		test(100);
	}
}
namespace test13
{
	template<typename ...T>
	void test(T...args) {
		cout << sizeof...(T) << endl;
		cout << sizeof...(args) << endl;
	}

	void ok() {
		cout << "������ֹ�ݹ�" << endl;
	}
	template<typename First,typename ...Second>
	void ok(First a,Second...b) {

		cout << "a=" << a << endl;
		ok(b...);
	}

	template<typename ...Second>class A {};

	template<typename First,typename ...Second>
	class A<First, Second...>:private A<Second...> {
	public:
		A():m_i(0) {
			printf("A(),this=%p\n",this);
		}
		A(First a, Second ...args) :m_i(a), A<Second...>(args...) {
			cout << "a=" << a << endl;
		}
		First m_i;
	};
	void func() {

		//test();
		//test(1,2,3,"china");

		//ok(1,2,3,"ok","lucy",12.2);
		A<char, double, int> o('a',12.12,100);

	}
}
namespace test14 {

	//ģ��ģ�����
	//template<typename ����ģ�������int �����Ͳ���,template xx ģ�����>
	//template<typename T,typename U>
	template<
		typename T,
		//template<class> class Container
		template<typename W> typename Container
	>
	class myclass {
	public:
		myclass() {
			cout << "myclass T,U" << endl;

			for (int i = 0; i < 10; i++) {

				my.push_back(i);
			}

			for (auto itr : my) {
				cout << itr << endl;
			}
		}

		T ok;
		Container<T> my;
	};
	template<typename T> using myvec = std::vector<T,allocator<T>>;
	void func() {

		//myclass<int, char> obj;
		myclass<int, myvec> obj;

		std::vector<int> j;
	
	}
}
namespace test15
{

	class A {};
	void func() {

		int* a = new int(10);
		A b;
		A* c = new A();

		const int* d = new const int(100);

		auto f = new auto(b);

		delete f;

		//int j = 100;
		//int* x = &j;
		//delete x;

		int* j = new int(10);
		int* m = j;
		delete j; 
		delete m;
	}

	void kk() {

		int m[] = { 1,2 };
		printf("%d\n",*m);
	}
}
namespace test16
{
	class A {
	public:
		A() {
			cout << "A" << endl;
		}
		~A() {
			cout << "~A" << endl;
		}
	};
	void func()
	{
		//A* obj = new A[2]();
		//delete obj;
		//printf("size=%d\n",sizeof(*obj));
		//delete[]obj;

		//int* x = (int*)operator new(100);
		//cout << *x << endl;
		//delete x;

		//shared_ptr<int> x(new int(100));
		//cout << *x << endl;

		//auto y = make_shared<int>(101);
		//auto z = make_shared<string>(5,'b');
		//cout << *y << *z << endl;

		//uint8_t a = 10;
		char* x = (char*)malloc(sizeof(char)*100);;

		memcpy(x,"GET /index HTTP/1.1\r\nContent-Length: 10\r\n\r\nhelloworld",100);
		//0x00ce5340 "GET /index HTTP/1.1\r\nContent-Length: 10\r\n\r\nhelloworld"
		//cout << x << endl;
		//0x00ce5343 " /index HTTP/1.1\r\nContent-Length: 10\r\n\r\nhelloworld"
		char* temp = strstr(x," ");
		//cout << x[0] << endl;
		
		temp[0] = '\0';

		cout << x << endl;

		x = temp+1;

		temp = strstr(x," ");
		temp[0] = '\0';

		cout << x << endl;

		x = temp + 1;

		temp = strstr(x,"\r\n");
		temp[0] = '\0';

		cout << x << endl;


		x = temp + 2;



	}
}
namespace test17
{
	template<typename T>
	shared_ptr<T[]> make_shared_array(size_t size) {
		return shared_ptr<T[]>(new T[size]);
	}

	void func()
	{
		shared_ptr<int> p1(new int(100));
		shared_ptr<int> p2(p1);

		cout << p1.use_count() << endl;
		cout << p2.use_count() << endl;

		p1.reset();

		if (p1 == nullptr) {
			cout << "p1 nullptr" << endl;
		}
		if (p2.unique()) {
			cout << "unique" << endl;
		}
		cout << *p2 << endl;

		p2.reset(new int(20));

		auto p3 = make_shared<int>(101);
		std::swap(p3, p2);

		p2.swap(p3);

		cout << "p2="<<*p2 << "p3="<<*p3.get() << endl;

		shared_ptr<int> p5(new int(1), [=](int *p) {
			cout << "�Լ�����ɾ����" << endl;
			delete p;

			});

		shared_ptr<int[]> p6(new int[10]());
		p6[0] = 101;
		p6[1] = 202;

		shared_ptr<int> p7(new int[10](), [](int* p) {

			delete[]p;
			});
		shared_ptr<int> p8(new int[10](), std::default_delete<int[]>());

		cout << *p8 << endl;


		shared_ptr<int[]> p9 = make_shared_array<int>(10);

		p9[0] = 1;

		cout << "p9[0]=" << p9[0] << endl;


	}
}
namespace test18
{
	void func() {

		auto p1 = make_shared<int>(100);

		weak_ptr<int> p2(p1);

		cout << p2.use_count() << endl;


		auto p3 = p2;
		
		p3.reset();
		p1.reset();
		p2.reset();

		if (!p2.expired()) {

			auto p4 = p2.lock();
		}
		else {

			cout << "expired" << endl;
		}


		int* len1;
		cout << sizeof(len1) << endl;
		weak_ptr<int> p;
		cout << sizeof(p) << endl;
	}
}
namespace test19
{
	class A {
	public:
		A() {
			cout << "A ()" << endl;
		}
		~A() {
			cout << "~A()" << endl;
		}
	};
	auto makes() {
		return unique_ptr<A>(new A());
	}
	void func()
	{
		
		unique_ptr<int> p2(new int(100));
		int* p = p2.get();
		*p = 200;

		cout << *p2 << *p2 << p2 << p << endl;

		//unique_ptr<A> p3 = make_unique<A>(A());
		//unique_ptr<A[]> p2(new A[4]());
		//shared_ptr<A> p2 = makes();

		//p2.reset();
		//p2.release();

		//if (p2 == nullptr) {
		//	cout << "p2 nullptr" << endl;
		//}

		//unique_ptr<int> p2(new int(100));

		//cout << *p2 << endl;

		//if (p2 == nullptr) {
		//	cout << "p2 nullptr" << endl;

		//}
		//else {

		//	//p2.reset();
		//	p2.reset(p2.release());
		//}

		//if (p2 == nullptr) {
		//	cout << "now p2 nullptr" << endl;
		//}
		//else {
		//	cout << "now p2=" << *p2.get() << endl;
		//}

		//unique_ptr<int>p3 = p2;
		//unique_ptr<int>p3;
		//p3 = p2;
	}
}
using namespace test;
int main() {

	/*const A obj;
	func(obj);

	B x;
	A objx;
	x.test(200,objx);*/
	//test15::func();
	test19::func();

	return 0;
}