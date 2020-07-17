#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>
#include <atomic>
//std::future ���������Ա||std::shared_future || ԭ�Ӳ���
/**
��ȡ�߳�ִ�еķ��ؽ��
1������std::future<T> f ��ģ��������
	a����ȡִ�еĽ�� f.get()
	b����ȡִ�е�״̬ std::future_status r = f.wait_for(time)
2��std::async���� �������߳�
3��std::packaged_task<> obj(����)
4��std::promise<T> ��Ϊ�̵߳Ĳ���  ͨ�� std::promise<T>::set_value

std::packaged_task std::promise ֧��get_future ��Ա����
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
std::atomic<int> _counter = 0;//ԭ�Ӳ���  ���Ĵ��롾һ��Ƭ�ϡ� Ҫôִ�гɹ���Ҫôִ��ʧ�ܣ��������ִֻ��һ��

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

	//1��std::future ��ĳ�Ա����
	//std::future<int> result = std::async(std::launch::deferred,func, 10);

	//cout << "main start" << endl;

	////cout << "thread result=" << result.get() << endl;
	////2��ö������
	//std::future_status ret = result.wait_for(std::chrono::seconds(6));//�ȴ�1��

	////�߳�ִ�г�ʱ
	//if (ret == std::future_status::timeout) {

	//	cout << "�߳�ִ�г�ʱ��" << endl;


	//}
	//else if (ret == std::future_status::ready) {
	//	cout << "�߳�ִ����� " << result.get() << endl;
	//}
	//else if (ret == std::future_status::deferred) {
	//	cout << " deferred" << endl;

	//	cout << result.get() << endl;
	//}

	//2��std::shared_future

	/*std::packaged_task<int(int)> fun(func);
	std::thread t(std::ref(fun), 1);
	t.join();*/

	//����������� ret 
	//��������ڴ� 0x01
	//����������� 666
	//std::future<int> ret = fun.get_future();
	//ת��Ϊ��ֵ֮��
	//����������� ret_
	//��������ڴ� 0x01
	//std::shared_future<int> ret_s(std::move(ret));//ת��Ϊ��ֵ
	/*if (ret.valid()) {
		cout << "future �������ֵ" << endl;
	}
	std::shared_future<int> ret_s(ret.share());
	cout << "shared_future:" << ret_s.get() << endl;*/

	/*shared_future<int> ret_s(fun.get_future());
	std::thread st(say, std::ref(ret_s));
	st.join();

	cout << "main over" << endl;*/

	//ԭ�Ӳ���atomic 
	//1������Ҫ�����������Ķ��̲߳�����̼���
	//2��ԭ�Ӳ��������ڶ��߳��У����ᱻ��ϵ� ������ִ��Ƭ�ϡ�

	/*std::thread t1(addSum);
	std::thread t2(addSum);

	t1.join();
	t2.join();

	cout << "_counter=" << _counter << endl;*/

	std::thread t1(test);
	std::thread t2(test);

	std::chrono::milliseconds t(5000);
	std::this_thread::sleep_for(t);

	g_if = true;//ԭ�Ӳ���  

	t1.join();
	t2.join();

	cout << "main over" << endl;
	return 0;
}