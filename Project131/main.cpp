#include<iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

using namespace std;

std::atomic<int> g = 0;

void mythread()
{
	for (int i = 0; i < 10000; i++) {
		//g += 1;
		g = g + 1;
	}
}

int mythread1(int x) {
	cout << "x=" << x<<endl;
	return x;
}

int main()
{

	//std::thread t1(mythread);
	//std::thread t2(mythread);
	//t1.join();
	//t2.join();

	//cout << "g=" << g << endl;

	std::future<int> res = std::async(std::launch::async | std::launch::deferred, mythread1,1);


	std::future_status status = res.wait_for(10s);

	if (std::future_status::deferred == status) {
		cout << "deferred=" << endl;
		cout << res.get() << endl;
	}
	else if
		(std::future_status::timeout == status) {
		cout << "timeout=" << endl;
		cout << res.get() << endl;
	}
	else {
		cout << "ready=" << endl;
		cout << res.get() << endl;
	}

	//cout << res.get() << endl;
}