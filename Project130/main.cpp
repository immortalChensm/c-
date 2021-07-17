#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <future>

using namespace std;

int mythread1(int x)
{
	cout << "thread id=" << std::this_thread::get_id() << " start" << endl;
	cout << "x=" << x << endl;

	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);

	cout << "thread id=" << std::this_thread::get_id() << " end" << endl;

	return 888;
}

void mythread(std::shared_future<int>& pp)
{
	cout << "thread id=" << std::this_thread::get_id() << " start" << endl;
	int result = pp.get();
	result = pp.get();
	cout << "pp=" << result << endl;
	cout << "thread id=" << std::this_thread::get_id() << " end" << endl;
	return;
}

//int g_count = 0;
std::atomic<int> g_count = 0;
//std::mutex my_mutex;
std::atomic<bool> flag = false;
void mythreadA()
{
	for (int i = 0; i < 100'0000; i++) {
		//my_mutex.lock();
		g_count++;
		//my_mutex.unlock();
	}
}

void mythreadX()
{

	while (flag == false) {

		std::chrono::milliseconds dura(1000);
		std::this_thread::sleep_for(dura);

		cout << "test" << endl;
	}
}
int main()
{

	std::thread t1(mythreadX);

	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);

	flag = true;


	t1.join();


	/*std::thread t1(mythreadA);
	std::thread t2(mythreadA);

	t1.join();
	t2.join();

	cout << "g_count=" << g_count << endl;*/


	/*std::packaged_task<int(int)> task1([](int x)->int {

		cout << "thread id=" << std::this_thread::get_id() <<" start"<< endl;
		cout << "x=" << x << endl;

		std::chrono::milliseconds dura(5000);
		std::this_thread::sleep_for(dura);

		cout << "thread id=" << std::this_thread::get_id() << " end" << endl;

		return 888;
	});*/
	
	//std::thread t1(std::ref(task1), 100);
	//t1.join();


	//std::future<int> result = task1.get_future();
	//std::future<int> result = std::async(std::launch::deferred,mythread1, 100);
	//std::future<int> result = std::async(mythread1, 100);
	//std::shared_future<int> res = std::async(mythread1, 100);


	/*std::future_status status = result.wait_for(std::chrono::milliseconds(6000));

	if (std::future_status::timeout == status) {

		cout << "超时，线程没有执行" << endl;
	}
	else if (std::future_status::ready == status) {
		cout << "线程执行完成" << result.get()<<endl;
	}
	else if (std::future_status::deferred == status) {
		cout << "线程延迟" << result.get() << endl;
	}*/

	//if (result.valid()) {
	//	cout << "ok" << endl;
	//}

	//std::shared_future<int> res = std::move(result);
	//std::thread t2(mythread, std::ref(res));

	//t2.join();

	return 0;
}