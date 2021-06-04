#include <iostream>

using namespace std;

class Tmp {
public:
	Tmp() {
		cout << "tmp构造函数" << endl;
	}
	Tmp(const Tmp& obj) {
		cout << "tmp拷贝构造函数" << endl;
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
		cout << "Time拷贝 赋值构造函数" << endl;
		return *this;
	}
	void initTIme() {
		
	}
	~Time() {
		cout << "Time析构函数" << endl;
		delete[]p;
	}
	Time() {
		cout << "Time构造函数" << endl;

	}

	Time(const Time& obj):hour(obj.hour),minute(obj.minute),second(obj.second),c1(obj.c1) {
		cout << "Time拷贝 构造函数" << endl;
	}
	//Time() = default;
	//Time() = delete;
	//Time(int h, int m, int s):hour(h),minute(m),second(s) {
	//	/*hour = h;
	//	minute = m;
	//	second = s;*/
	//	cout << "Time(int h, int m, int s) 构造函数" << endl;
	//}
	////explicit Time(int h) {
	// Time(int h) {
	//	hour = h;
	//	minute = 10;
	//	second = 20;
	//	cout << "Time(int h) 构造函数" << endl;
	//}
	//Time() {
	//	hour = 10;
	//	minute = 10;
	//	second = 10;
	//	cout << "Time() 构造函数" << endl;
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

	Time time;
	Time time1 = time;
	Time time2;
	time2 = time;

	Time* timex = new Time();
	delete timex;

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