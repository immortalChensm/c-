#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <future>

using namespace std;

class A {
public:
	int mythread(int num)
	{
		cout << "num=" << num << endl;

		cout << "thread start" << std::this_thread::get_id() << endl;
		std::chrono::microseconds dura(5000);
		std::this_thread::sleep_for(dura);

		cout << "thread end" << std::this_thread::get_id() << endl;

		return 888888;
	}
};
int mythread(int num)
{
	cout << "num=" << num << endl;

	cout << "thread start" << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);

	cout << "thread end" << std::this_thread::get_id() << endl;

	return 888888;
}

std::vector<std::packaged_task<int(int)>> mytasks;

void myshow(std::promise<int>& tmp,int v)
{
	v++;
	v *= 10;
	cout << "thread start " << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);
	cout << "thread end " << std::this_thread::get_id() << endl;

	tmp.set_value(v);

	return;
}

void myshow1(std::future<int>& tmp)
{
	auto result = tmp.get();
	cout << "thread start " << std::this_thread::get_id() << endl;
	cout << result << endl;
	cout << "thread end " << std::this_thread::get_id() << endl;
	return;
}
int main()
{

	cout << "main thread " << std::this_thread::get_id() << endl;


	//std::future<int> result = std::async(std::launch::async,mythread, 100);
	//std::future<int> result = std::async(std::launch::deferred,mythread, 100);
	//A obj;
	//std::future<int> result = std::async(std::launch::async,&A::mythread, &obj,100);
	////std::launch::deferred  不会启动新线程，不调用get,wait就不会执行
	//int def;
	//def = 100;
	//cout << "i like money1" << endl;
	//cout << "i like money2" << endl;
	//cout << "i like money3" << endl;


	//cout << result.get() << endl;
	////result.wait();
	//cout << "i like money8" << endl;

	/*std::packaged_task<int(int)> mypt(mythread);

	std::thread runx(std::ref(mypt),191);

	runx.join();

	cout << "i like money1" << endl;
	cout << "i like money2" << endl;
	cout << "i like money3" << endl;

	std::future<int> result = mypt.get_future();
	cout << result.get() << endl;*/

	//std::packaged_task<int(int)> mypt(mythread);

	//mytasks.push_back(std::move(mypt));//不拷贝
	////mypt(888);


	//auto itr = mytasks.begin();

	//std::packaged_task<int(int)> task1;
	//task1 = std::move(*itr);//迭代器  本身是个指针

	//task1(818);
	//std::future<int> result = task1.get_future();
	//cout << result.get() << endl;


	//std::packaged_task<int(int)> task([](int num) {
	//	cout << "num=" << num << endl;

	//	cout << "thread start" << std::this_thread::get_id() << endl;
	//	//std::chrono::microseconds dura(5000);
	//	std::chrono::milliseconds dura(5000);
	//	std::this_thread::sleep_for(dura);

	//	cout << "thread end" << std::this_thread::get_id() << endl;

	//	return 888888;

	//});

	/*task(1000);*/



	//std::future<int> result = task.get_future();
	//std::future<int> result = std::async(std::launch::async,mythread,100);

	//cout << result.get() << endl;


	std::promise<int> mp;
	std::thread t1(myshow, std::ref(mp), 100);
	t1.join();

	std::future<int> result = mp.get_future();

	//cout << result.get() << endl;

	std::thread t2(myshow1, std::ref(result));
	t2.join();

	cout << "i love money" << endl;

	return 0;
}