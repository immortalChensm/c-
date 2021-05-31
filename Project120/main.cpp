#include <iostream>

using namespace std;

class Time
{
public:
	int hour;
	int minute;
	int second;
	void initTIme() {

	}
	Time(int h, int m, int s):hour(h),minute(m),second(s) {
		/*hour = h;
		minute = m;
		second = s;*/
		cout << "Time(int h, int m, int s) 构造函数" << endl;
	}
	//explicit Time(int h) {
	 Time(int h) {
		hour = h;
		minute = 10;
		second = 20;
		cout << "Time(int h) 构造函数" << endl;
	}
	Time() {
		hour = 10;
		minute = 10;
		second = 10;
		cout << "Time() 构造函数" << endl;
	}
};

void func(Time t) {
	return;
}
void main()
{
	Time time;
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
	func({(2002)});

}