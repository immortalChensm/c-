#include<iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <list>
#include <atomic>

using namespace std;
std::atomic<int > g = 0;

void mytest1()
{
	for (int i = 0; i < 1000'00; i++) {
		cout << "g=" << g << endl;
	}
}
void mytest()
{
	for (int i = 0; i < 1000'00; i++) {
		g++;
		auto m(g.load());
	}
}
int main()
{

	std::thread t1(mytest);
	std::thread t2(mytest1);
	t1.join();
	t2.join();
	cout << "g=" << g << endl;
	return 0;
}