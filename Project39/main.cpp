#include <iostream> 
#include <string>
#include <thread>
#include <future>

using namespace std;

class B {
public:
	int func(int arg)
	{
		cout << "arg=" << arg << endl;

		cout << "thread start " << std::this_thread::get_id() << endl;

		std::chrono::milliseconds t(5000);

		std::this_thread::sleep_for(t);

		cout << "thread end " << std::this_thread::get_id() << endl;

		return 5;

	}
};
int func(int arg)
{
	cout << "arg=" << arg << endl;

	cout << "thread start " << std::this_thread::get_id() << endl;

	std::chrono::milliseconds t(5000);

	std::this_thread::sleep_for(t);

	cout << "thread end " << std::this_thread::get_id() << endl;

	return 5;

}

void calcs(std::promise<int>& tmp, int num)
{
	num++;
	num *= 100;


	std::chrono::milliseconds t(500);
	std::this_thread::sleep_for(t);

	int ret = num;
	tmp.set_value(ret);


}

void printCalc(std::future<int>& t)
{
	auto ret = t.get();
	cout << "calc result " << ret << endl;
	return;
}

void talk(int& a)
{
	cout << a << endl;

	a = 100;
}
int main()
{

	//一、std::async | std::futured 创建后台任务并返回值

	//1、可以给std::async 传递一个std::launch::deferred 延迟，直到调用wait get才执行
	//std::launc::deferred 并没有启动新线程

	//2、std::launch::async 默认就是此参数  会启动新线程执行  不管有没有调用get ,wait
	//cout << "main thread start" << std::this_thread::get_id() << endl;

	////std::future<int> result = std::async(func);
	//B obj;
	//int arg = 10;
	////std::future<int> result = std::async(std::launch::deferred,&B::func,&obj,arg);
	//std::future<int> result = std::async(std::launch::async,&B::func,&obj,arg);


	//cout << "continue..." << endl;

	//int a = 10;

	//

	//cout << "main thread end " << std::this_thread::get_id() << endl;


	////.... 我可以做好多事情
	//cout << "hello,world" << endl;
	////获取将来的数据
	////cout << "async result=" << result.get() << endl;
	////result.wait();

	//cout << "hello,world1" << endl;

	cout << "main thread start" << std::this_thread::get_id() << endl;

	//二、std::packaged_task
	//std::packaged_task<int(int)> my(func);
	/*int a = 888;
	std::packaged_task<int(int)> my([](int arg)->int{
		
	
		cout << "lamba thread start " << std::this_thread::get_id() << endl;

		cout << "arg " << arg << endl;

		cout << "lamba thread end " << std::this_thread::get_id() << endl;

		return 666;
	});

	using funcs = int(*)(int);*/
	//int(*p)(int) = func;
	//funcs p = func;
	//std::thread t(std::ref(my), 10);
	//std::thread t((my), 10);

	//std::future<int> result = my.get_future();//获取线程入口函数执行的结果

	//t.join();

	//p(100);

	//cout << "result=" << result.get() << endl;

	/*my(33);

	std::future<int> result = my.get_future();

	cout << "ret" << result.get() << endl;*/

	/*int i = 10;
	int& j = i;
	int&& k = std::move(i);

	k = 100;
	cout << k << i << endl;

	i = 20;
	cout << i <<k<< endl;*/
	//三、std::promise
	/*int j = 10;
	talk(std::ref(j));
	cout << j << endl;*/

	std::promise<int> ret;
	std::thread t(calcs, std::ref(ret), 8);

	t.join();

	std::future<int> obj = ret.get_future();
	//cout << obj.get() << endl;

	std::thread t1(printCalc, std::ref(obj));
	t1.join();

	cout << "main over" << endl;
	return 0;

}