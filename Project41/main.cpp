#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <mutex> 
#include <atomic>
//std::atomic || std::async ϸ˵
//std::thread ����̫����̣߳����ܱ���������ʹ��std::async ���Ӳ�����һ�㲻�����������˭������get�������ڵ��߳������У������������߳�
//std::async ���Ӳ������п��ܴ������̣߳�Ҳ�п��ܲ�����
/**
1��std::async ��������ʱ  == std::launch::async | std::launch::deferred ��ϵͳ�Լ�ѡ��
	//ϵͳ����Դ����ʱ�����Լ�ѡ��
	a�����ܴ������߳�����  ������std::future_status s = std::future<t>::wait_for(0s) future_status == timeout||ready
	b��Ҳ�п��ܲ��������߳�����  ������ std::future_status �����ܣ���deferredʱ��ʾû�д������߳�
2��ǿ�������߳�����
	std::async(std::launch::async,func)
3��ǿ�����ӳٷ�ʽ����
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
		g_counter = g_counter + 1;//atomic ��֧��������
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