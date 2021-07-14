#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;
std::mutex my_mutex;
std::once_flag g_flag;
class MyCas {
private:
	MyCas() {

	}
private:
	static void createInstace() {

		std::chrono::microseconds dura(2000);
		std::this_thread::sleep_for(dura);
		cout << "运行实例" << endl;
		m_instance = new MyCas();
		cout << "申请的内存地址是：" << m_instance << endl;
		static GC gc;
		
	}
public:
	static MyCas* m_instance;
	static MyCas* getInstance()
	{
		/*if (m_instance == NULL)
		{
			std::unique_lock<std::mutex> lock(my_mutex);
			if (m_instance == NULL) {
				cout << "单例执行" << endl;
				m_instance = new MyCas();
				static GC gc;
			}
		}*/
		std::call_once(g_flag,createInstace);
		return m_instance;
	}
	class GC {
	public:
		~GC() {
			if (MyCas::m_instance != NULL) {
				delete MyCas::m_instance;
				cout << "释放内存" << endl;
				MyCas::m_instance = NULL;
			}
		}
	};
	void func()
	{
		cout << "func" << endl;
	}
};

MyCas*  MyCas::m_instance = NULL;

void mythread()
{
	cout << "线程开始执行了" << endl;
	MyCas* m = MyCas::getInstance();
	m->func();
	cout << "thread_id=" << std::this_thread::get_id() <<"m内存地址= "<<m<< endl;
	cout << "线程执行结束 了" << endl;
	return;
}
int main()
{

	/*std::thread my1(mythread);
	std::thread my2(mythread);

	my1.join();
	my2.join();*/

	cout << "main thread over" << endl;

	int a = 10;
	int* b = &a;

	printf("b的地址:#%x,b的内容:#%x,a的地址：#%x,a的内容:%d\n",&b,b,&a,a);
	return 0;
}