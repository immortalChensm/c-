#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <future>

using namespace std;

std::atomic<int> g_count = 0;

void mythread()
{
	for (int i = 0; i < 100000; i++)
	{
		g_count++;
		g_count += 1;
	
	}
}

int myshow(int x)
{
	cout << "thread start " << std::this_thread::get_id() << endl;
	cout << x << endl;

	//std::this_thread::sleep_for(std::chrono::milliseconds(2s));
	cout << "thread end " << std::this_thread::get_id() << endl;
	return x + 10;
}
int main()
{

	/*std::thread t1(mythread);
	std::thread t2(mythread);
	t1.join();
	t2.join();

	cout << "g_count=" << g_count << endl;*/

	std::future<int> result = std::async(myshow,10);

	std::future_status st = result.wait_for(std::chrono::milliseconds(0s));

	if (st == std::future_status::deferred)
	{
		cout << "thread deferred" << endl;

	}
	else if (st == std::future_status::ready)
	{
		cout << "thread ready" << endl;
		cout << result.get() << endl;
	}
	else if(st==std::future_status::timeout) {
		cout << "thread timeout" << endl;
	}
	return 0;
}