#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>
#include <atomic>
//std::future 类的其它成员||std::shared_future || 原子操作
/**
获取线程执行的返回结果
1、可用std::future<T> f 类模板来接收
	a、获取执行的结果 f.get()
	b、获取执行的状态 std::future_status r = f.wait_for(time)
2、std::async函数 启动新线程
3、std::packaged_task<> obj(函数)
4、std::promise<T> 作为线程的参数  通过 std::promise<T>::set_value

std::packaged_task std::promise 支持get_future 成员方法
**/
using namespace std;
int func(int a)
{
	cout << "thread id=" << std::this_thread::get_id() << "start "<<endl;

	std::chrono::milliseconds t(5000);
	std::this_thread::sleep_for(t);

	cout << "thread arg=" << a << endl;

	cout << "thread id=" << std::this_thread::get_id() << "end " << endl;

	return 666;
}


//void say(std::future<int>& arg)
void say(std::shared_future<int>& arg)
{
	auto ret = arg.get();
	cout <<"say:"<< ret << endl;
}


//int _counter = 0;
std::atomic<int> _counter = 0;//原子操作  它的代码【一个片断】 要么执行成功，要么执行失败，不会出现只执行一半

std::mutex _mutex;
std::condition_variable _cond;

void addSum()
{
	for (int i = 0; i < 10000000; i++) {
		//_mutex.lock();
		_counter++;
		//_mutex.unlock();
	}
	return;
}

std::atomic<bool> g_if=false;
void test()
{
	std::chrono::milliseconds t(1000);
	while (g_if == false) {

		cout << "thread id " << std::this_thread::get_id() << "running..." << endl;
		std::this_thread::sleep_for(t);
		cout << "thread id " << std::this_thread::get_id() << "over" << endl;
	}
}
int main()
{
	/*std::packaged_task<int(int)> o(func);
	thread t(std::ref(o), 999);
	t.join();

	std::future<int> tret = o.get_future();
	cout << "package_task result=" << tret.get() << endl;*/

	//1、std::future 类的成员方法
	//std::future<int> result = std::async(std::launch::deferred,func, 10);

	//cout << "main start" << endl;

	////cout << "thread result=" << result.get() << endl;
	////2、枚举类型
	//std::future_status ret = result.wait_for(std::chrono::seconds(6));//等待1秒

	////线程执行超时
	//if (ret == std::future_status::timeout) {

	//	cout << "线程执行超时了" << endl;


	//}
	//else if (ret == std::future_status::ready) {
	//	cout << "线程执行完成 " << result.get() << endl;
	//}
	//else if (ret == std::future_status::deferred) {
	//	cout << " deferred" << endl;

	//	cout << result.get() << endl;
	//}

	//2、std::shared_future

	/*std::packaged_task<int(int)> fun(func);
	std::thread t(std::ref(fun), 1);
	t.join();*/

	//对象变量名称 ret 
	//对象变量内存 0x01
	//对象变量内容 666
	//std::future<int> ret = fun.get_future();
	//转换为右值之后
	//对象变量名称 ret_
	//对象变量内存 0x01
	//std::shared_future<int> ret_s(std::move(ret));//转换为右值
	/*if (ret.valid()) {
		cout << "future 类对象有值" << endl;
	}
	std::shared_future<int> ret_s(ret.share());
	cout << "shared_future:" << ret_s.get() << endl;*/

	/*shared_future<int> ret_s(fun.get_future());
	std::thread st(say, std::ref(ret_s));
	st.join();

	cout << "main over" << endl;*/

	//原子操作atomic 
	//1、不需要互斥量加锁的多线程并发编程技术
	//2、原子操作：是在多线程中，不会被打断的 “程序执行片断”

	/*std::thread t1(addSum);
	std::thread t2(addSum);

	t1.join();
	t2.join();

	cout << "_counter=" << _counter << endl;*/

	std::thread t1(test);
	std::thread t2(test);

	std::chrono::milliseconds t(5000);
	std::this_thread::sleep_for(t);

	g_if = true;//原子操作  

	t1.join();
	t2.join();

	cout << "main over" << endl;
	return 0;
}