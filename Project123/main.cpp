#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

//class A final {
class A  {
public:
	A(int x): j(x){
		cout << "A" << endl;
	}
	A(const A& obj) {
		j = obj.j;
		cout << "A copy" << endl;
	}
	A& operator=(const A& obj) {
		j = obj.j;
		cout << "A == copy" << endl;
		return *this;
	}
	virtual void show() {
		cout << "a show" << endl;
	}
	~A() {

	}
protected:
	int j;
};
class B :public A {
public:
	B(int a, int b):A(a),x(a),y(b) {
		cout << "B" << endl;
	}
	virtual void show() override {
		cout << "b show" << endl;
	}
	~B() {

	}
private:
	int x;
	int y;
};

namespace test {

	class A {
	public:
		A(int a, int b) :x(a), y(b) {}
		int x;
		int y;
	};
	class B {
	public:
		B(int a, int b) :x(a), y(b) {}
		int x;
		int y;
	};
	struct C {
		int j{ 888 };
		void china(C &obj) {
			cout << "china" <<obj.j<<endl;
		}
		void tom() {
			cout << "tom" << endl;
		}
	};
	void func() {

		char* a = new char[100];
		int len = 0;
		memcpy(a , (char*)new A{ 100,200 }, sizeof(A));
		len += sizeof(A);
		memcpy(a + len, (char*)new B{300,400}, sizeof(B));
		len += sizeof(B);
		char names[] = "beifeng\0";
		memcpy(a + len, names, sizeof(names));
		len += sizeof(names);
		memcpy(a + len, (char*)new C{}, sizeof(C));
		char* s=new char[sizeof(names)];
		memcpy(s, (a + len-sizeof(names)),sizeof(names));
		cout << *(int*)a << *((int*)a+1) << *((int*)a + 3) << s <<endl;
		using Func = void(C::* )(C &obj);
		C obj;
		Func f1 = &C::china;
		(obj.*f1)(*&*(C*)(a+len));
		delete []a;

		int y = 100;
		int& z = y;

		
	}
}
namespace test2
{

	void func() {

		std::mutex mut;
		std::thread t1([&]() {

			while (1) {

				//std::chrono::microseconds sec(1);
				//std::this_thread::sleep_for(sec);
				//std::lock_guard<std::mutex> lock(mut);
				cout << std::this_thread::get_id() << "doing..."<<endl;
			}
			});
		std::thread t2([&]() {

			while (1) {

				//std::chrono::microseconds sec(1);
				//std::this_thread::sleep_for(sec);
				//std::lock_guard<std::mutex> lock(mut);
				cout << std::this_thread::get_id() << "speaing..." << endl;
			}
			});
		t1.join();
		t2.join();
	}
}
namespace test3
{
	void func() {


	}
}
int main() {

	//B b(1, 2);

	////A x(b);
	//A x(0);
	//x = b;

	//A* objx = new B(2,3);
	//objx->show();
	//objx->A::show();

	//A* objy = dynamic_cast<A*>(objx);
	//objy->show();

	//delete objx;
	//delete objy;


	test2::func();

	return 0;
}