#include <iostream>
#include <string> 
#include <thread>
#include <mutex>
using namespace std;
//����ģʽ  �������ݷ��� |std::once_call

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
		//if (_instance == NULL) {//˫����  ��һ������ʱ��ֻ��һ���߳���������Դ�������߳������������󣬺��������ȫ��return �ˣ���Ч����

		//	std::unique_lock<std::mutex> lock(_mutex);//û��˫�ؼ��ʱ������߳����У�ÿ�����ж�Ҫ�������ܵ�
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

	//4��std::call_once()

	return 0;
}