#include <iostream>
#include <string>
#include <vector>
#include <thread>

using namespace std;
void test(int x,const string &t) {

	cout << "start" << endl;
	cout << "start" << endl;
	cout << "start" << endl;
	cout << "start" << endl;
	cout << "start" << endl;
	cout << x << t.c_str() << endl;

	cout << "end" << endl;

}
class Ta {
public:
	int m;
	Ta(int x=0):m(x) {
		cout << "ta" << endl;
	}
	Ta(const Ta& obj) :m(obj.m) {
		cout << "ta copy" << endl;
	}
	~Ta() {
		cout << "~Ta" << endl;
	}
	void operator()() {

		cout << "child thread start" << endl;
		cout << "child thread start" << endl;
		cout << "child thread start" << endl;
		cout << "child thread start" << endl;
	}
};
int main() {

	int x = 100;
	char b[] = "test cccc";
	thread t1(test,x,string(b));
	//thread t1(test,x,b);
	//Ta obj;
	//thread t1(obj);
	/*thread t1([] {
			
		cout << "child thread start" << endl;
		cout << "child thread start" << endl;
		cout << "child thread start" << endl;
		cout << "child thread start" << endl;
		});*/

	if (t1.joinable()) {

		t1.detach();
		//t1.join();
	}

	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	return 0;
}