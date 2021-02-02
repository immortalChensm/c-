#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <thread>
#include <condition_variable>
#include <thread>
#include <atomic>
#include <future>
using namespace std;

int mythread(int x)
{
	cout << "threadId start=" << std::this_thread::get_id() << endl;

	cout << "dodo..l." << endl;
	cout << x << endl;
	std::chrono::milliseconds dura(2000);
	std::this_thread::sleep_for(dura);

	cout << "threadId end=" << std::this_thread::get_id() << endl;
	return 888;
}
//int g_count = 0;
std::atomic<int> g_count = 0;
std::mutex _mutext;

void mythread1()
{
	for (int i = 0; i < 10000000; i++)
	{
		//_mutext.lock();
		g_count++;
		//_mutext.unlock();
	}
}
std::atomic<bool> g_flag = false;
void myshow()
{
	while (!g_flag) {

		cout << "threadId=" << std::this_thread::get_id() << endl;

		cout << "to do someting..." << endl;

		cout << "threadId=" << std::this_thread::get_id() << endl;

		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);
	}
	return;
}
int main()
{


	std::packaged_task<int(int)> fun1([](int x) {

		cout << "threadId start=" << std::this_thread::get_id() << endl;

		cout << "dodo..l." << endl;
		cout << x << endl;
		std::chrono::milliseconds dura(2000);
		std::this_thread::sleep_for(dura);

		cout << "threadId end=" << std::this_thread::get_id() << endl;
		return 888;

	});

	std::packaged_task<void(std::shared_future<int>)> func2([](std::shared_future<int> r) {
		
		cout << "threadId start=" << std::this_thread::get_id() << endl;

		auto result = r.get();
		//r.get();
		cout << "跨线程的参数值 是："<<result << endl;

		cout << "threadId end=" << std::this_thread::get_id() << endl;
	});

	//std::thread x1(std::ref(fun1), 100);

	//std::future<int> result = fun1.get_future();

	//bool f1 = result.valid();
	//cout << result.get() << endl;
	//std::shared_future<int> result_s(std::move(result));
	//std::shared_future<int> result_s = result.share();
	//std::shared_future<int> result_s = fun1.get_future();
	 //f1 = result.valid();
	//cout << result_s.get() << endl;
	//std::thread x2(std::ref(func2),std::move(result_s) );
	//std::thread x2(std::ref(func2),result_s);
	//std::thread x2(func2,result_s);

	//x1.join();
	//x2.join();


	/*std::future<int> result = std::async(std::launch::deferred,mythread,100);

	
	cout << "i like money" << endl;
	std::chrono::milliseconds dura(1000);
	std::future_status st = result.wait_for(dura);


	if (std::future_status::ready ==  st) {
		cout << "ok" << endl;
		cout << result.get() << endl;
	}
	else if (std::future_status::timeout == st) {
		cout << "timeout" << endl;
	}
	else if (std::future_status::deferred == st) {
		cout << "deferred" << endl;
	}*/

	/*std::thread t1(mythread1);
	std::thread t2(mythread1); 

	t1.join();
	t2.join();

	cout << "g_count=" << g_count << endl;*/

	std::thread t1(myshow);
	std::thread t2(myshow);

	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);


	g_flag = true;

	cout << "ok" << endl;

	t1.join();
	t2.join();



	return 0;
}