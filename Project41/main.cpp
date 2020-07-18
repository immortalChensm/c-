#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <mutex> 
#include <atomic>
//std::atomic || std::async 细说
//std::thread 创建太多的线程，可能崩溃，但是使用std::async 不加参数的一般不会崩溃，而是谁调用了get就在所在的线程上运行，并不启动新线程
//std::async 不加参数，有可能创建新线程，也有可能不创建
/**
1、std::async 不给参数时  == std::launch::async | std::launch::deferred 让系统自己选择
	//系统在资源紧张时，会自己选择
	a、可能创建新线程运行  可以用std::future_status s = std::future<t>::wait_for(0s) future_status == timeout||ready
	b、也有可能不创建新线程运行  可以用 std::future_status 来接受，是deferred时表示没有创建新线程
2、强制以新线程运行
	std::async(std::launch::async,func)
3、强制以延迟方式运行
	std::async(std::launch::defered,func)
**/
void b(std::promise<char>& p, int t) {

	char a = 'a';
	p.set_value(a);
}

std::atomic<int> g_counter = 0;
void func()
{
	for (int i = 0; i < 10000000; i++) {

		//g_counter++;
		g_counter = g_counter + 1;//atomic 不支持这样玩
	}
}

int mythread()
{
	std::cout << "mythread() start " << std::this_thread::get_id() << std::endl;
	return 88888;
}
int main()
{
	std::cout << "main() start " << std::this_thread::get_id() << std::endl;

	//std::future<int> ret = std::async(std::launch::async,mythread);
	//std::future<int> ret = std::async(std::launch::deferred,mythread);
	std::future<int> ret = std::async(std::launch::deferred|std::launch::async,mythread);

	std::cout << "future result=" << ret.get() << std::endl;

	/*std::thread t1(func);
	std::thread t2(func);

	t1.join();
	t2.join();

	std::cout << "rest=" << g_counter << std::endl;*/

	/*std::future<int> ret = std::async([]()->int {
		
		return 100;
	});

	std::cout << ret.get() << std::endl;*/

	/*std::packaged_task<int(int)> obj([](int a)->int {

		int b = 10;
		b += a;
		return b;
	});

	obj(100);

	std::shared_future<int> result = obj.get_future();

	std::cout << result.get() << std::endl;*/
	/*std::promise<char> d;
	std::thread t1([](std::promise<char> & p, int t) {

		char a = 'a';
		p.set_value(a);
	},std::ref(d),100);

	t1.join();

	std::future<char> ret = d.get_future();

	std::cout << ret.get() << std::endl;*/

	return 0;
}