#include <iostream>
#include <string> 
#include <thread>
#include <mutex>
using namespace std;
//单例模式  共享数据分析 |std::once_call

std::mutex _mutex;
std::once_flag g_flag;

class MY
{

	static void createInstace()
	{
		_instance = new MY();
		cout << "once time" << endl;
		static CG cg;
	}
private:
	MY(){}
private:
	static MY* _instance;
public:
	static MY* getInstance()
	{
		//if (_instance == NULL) {//双向检查  第一次运行时，只有一个线程锁定了资源，其它线程阻塞，解锁后，后面的运行全是return 了，高效做法

		//	std::unique_lock<std::mutex> lock(_mutex);//没有双重检查时，多个线程运行，每次运行都要锁，性能低
		//	if (_instance == NULL) {
		//		_instance = new MY();

		//		static CG cg;
		//	}
		//}
		
		std::call_once(g_flag,createInstace);
		return _instance;
	}

	class CG {
	public:
		~CG()
		{
			if (MY::_instance) {
				delete MY::_instance;
				MY::_instance = nullptr;
			}
		}
	};

	void show()
	{
		cout << "test" << endl;
	}
};

MY *MY::_instance = nullptr;


void func()
{
	cout << "start" << endl;

	MY* inst = MY::getInstance();

	inst->show();

	cout << "end" << endl;
}
int main()
{

	//MY* inst = MY::getInstance();

	//inst->show();

	std::thread t1(func);
	std::thread t2(func);

	t1.join();
	t2.join();

	//4、std::call_once()

	return 0;
}