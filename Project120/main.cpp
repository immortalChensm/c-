#include <iostream>
#include <thread>

using namespace std;

class Tmp {
public:
	Tmp() {
		cout << "tmp���캯��" << endl;
	}
	Tmp(const Tmp& obj) {
		cout << "tmp�������캯��" << endl;
	}
};
class Time
{
public:
	int hour;
	int minute;
	int second;
	Tmp c1;
	//const int jk{ 0 };
	char* p;
	Time& operator=(const Time& obj) {
		hour = obj.hour;
		minute = obj.minute;
		second = obj.second;
		c1 = obj.c1;
		p = new char[100];
		cout << "Time���� ��ֵ���캯��" << endl;
		return *this;
	}
	void initTIme() {
		
	}
	~Time() {
		cout << "Time��������" << endl;
		delete[]p;
	}
	Time() {
		cout << "Time���캯��" << endl;

	}

	Time(const Time& obj):hour(obj.hour),minute(obj.minute),second(obj.second),c1(obj.c1) {
		cout << "Time���� ���캯��" << endl;
	}
	//Time() = default;
	//Time() = delete;
	//Time(int h, int m, int s):hour(h),minute(m),second(s) {
	//	/*hour = h;
	//	minute = m;
	//	second = s;*/
	//	cout << "Time(int h, int m, int s) ���캯��" << endl;
	//}
	////explicit Time(int h) {
	// Time(int h) {
	//	hour = h;
	//	minute = 10;
	//	second = 20;
	//	cout << "Time(int h) ���캯��" << endl;
	//}
	//Time() {
	//	hour = 10;
	//	minute = 10;
	//	second = 10;
	//	cout << "Time() ���캯��" << endl;
	//}

	/*inline void test()
	{
		cout << "inline func" <<ok<< endl;
	}
	mutable int ok;
	 int ok1;

	Time& jack(int v)const {
		ok = v;
	}

	static int staticv1;
	static void tom();*/

	

};

//
//int Time::staticv1 = 1;
//void Time::tom() {
//	cout << staticv1 << endl;
//	//cout << ok << endl;
//}
//
//void func(Time t) {
//	return;
//}
void main()
{
	cout << "thread id:" << std::this_thread::get_id() << "start" << endl;
	thread my1([=]() {
		
		while (1) {
			cout << "thread id:" << std::this_thread::get_id() << "start" << endl;
			//std::chrono::microseconds t(2);
			//std::this_thread::sleep_for(t);
		}
		
	});

	thread my2([=]() {

		while (1) {
			cout << "thread id:" << std::this_thread::get_id() << "start" << endl;
			//std::chrono::microseconds t(3);
			//std::this_thread::sleep_for(t);
		}

		});

	my1.join();
	my2.join();


	cout << "thread id:" << std::this_thread::get_id() << "end" << endl;

	/*Time time;
	Time time1 = time;
	Time time2;
	time2 = time;

	Time* timex = new Time();
	delete timex;*/

	/*Time time2(time);
	Time time3{ time };
	Time time4 = { time };
	Time time5;
	time5 = time;*/
	

	/*Time time;
	time.test();
	time.ok = 100;
	time.staticv1 = 200;
	time.tom();
	Time::staticv1 = 333;
	time.tom();*/


	/*Time time;
	Time time1 = {};
	Time time2 = 1;
	Time time3 = (10);
	Time time4(10);
	Time time5 = { 10 };
	Time time6 = { {100} };


	Time time7 = { 1,2,3 };
	Time time8 = (1, 2, 3, 4, 5, 6);


	func({ 100 });
	func((200));
	func(300);
	func({(2002)});*/

}