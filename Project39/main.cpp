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

	//һ��std::async | std::futured ������̨���񲢷���ֵ

	//1�����Ը�std::async ����һ��std::launch::deferred �ӳ٣�ֱ������wait get��ִ��
	//std::launc::deferred ��û���������߳�

	//2��std::launch::async Ĭ�Ͼ��Ǵ˲���  ���������߳�ִ��  ������û�е���get ,wait
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


	////.... �ҿ������ö�����
	//cout << "hello,world" << endl;
	////��ȡ����������
	////cout << "async result=" << result.get() << endl;
	////result.wait();

	//cout << "hello,world1" << endl;

	cout << "main thread start" << std::this_thread::get_id() << endl;

	//����std::packaged_task
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

	//std::future<int> result = my.get_future();//��ȡ�߳���ں���ִ�еĽ��

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
	//����std::promise
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