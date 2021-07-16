#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <future>

using namespace std;

int mythread(int my) {


	cout << "子线程 start threaid =" << std::this_thread::get_id() << endl;
	cout << "子线程  my=" << my << endl;
	std::chrono::milliseconds dura(1000);

	std::this_thread::sleep_for(dura);

	cout << "子线程  end threaid =" << std::this_thread::get_id() << endl;

	return 50;

}

void mythread1(std::promise<int>& tmpp, int x) {

	int p = x + 100;
	cout << "thread1 p=" << p << endl;
	tmpp.set_value(p);
}

void mythread2(std::future<int>& result) {

	int t = result.get();
	cout << "thread2 result=" << t << endl;
}
int main()
{
	cout << "main  threaid =" << std::this_thread::get_id() << endl;

	//std::future<int> result = std::async(mythread,100);
	//std::future<int> result = std::async(std::launch::async,mythread,100);
	//std::future<int> result = std::async(std::launch::deferred,mythread,100);
	//1 std::launch::async 会启动新线程并执行
	//2 std::launch::deferred 不会启动新线程，必须调用wait/get才会执行


	//cout <<"result="<< result.get() << endl;
	//cout <<"result="<< result.get() << endl;
	//result.wait();


	//std::packaged_task<int(int)> myp(mythread);

	//std::vector< std::packaged_task<int(int)>> my_tasks;

	//my_tasks.push_back(std::move(myp));


	//auto itr = my_tasks.begin();

	//std::packaged_task<int(int)> myp1 = std::move(*itr);

	//my_tasks.erase(itr);

	////myp(101);
	//std::thread t1(std::ref(myp1), 102);
	//t1.join();

	//std::future<int> result = myp1.get_future();
	//cout << "result=" << result.get() << endl;
	//cout << "main over" << endl;

	std::promise<int> p;
	std::thread t1(mythread1, std::ref(p), 102);
	t1.join();

	std::future<int> result = p.get_future();
	std::thread t2(mythread2, std::ref(result));
	t2.join();

	//std::future<int> result = p.get_future();
	//cout << "result=" << result.get() << endl;

	return 0;
}