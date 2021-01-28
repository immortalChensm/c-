#include <iostream>
#include <thread>
#include <list>
#include <vector>
#include <mutex>
//多线程单例
using namespace std;
std::once_flag g_flag;

std::mutex _mutext;
class MyCas
{
private:
	MyCas(){}
private:
	static MyCas* m_instance;
public:
	static void createInstance()
	{
		cout << "new 一次" << endl;
		m_instance = new MyCas();
		static GC gc;
	}
	static MyCas* getInstance()
	{

		/*if (m_instance == NULL)
		{
			std::unique_lock<std::mutex> lock(_mutext);
			if (m_instance == NULL)
			{
				cout << "new 一次" << endl;
				m_instance = new MyCas();
				static GC gc;
			}
		}*/
		std::call_once(g_flag,createInstance);
		return m_instance;
	}
	class GC {
	public:
		~GC()
		{
			if (MyCas::m_instance) {

				delete MyCas::m_instance;
				MyCas::m_instance = NULL;

				cout << "delete m_instance" << endl;
			}
		}
	};
	void show()
	{
		cout << this << "show test" << endl;
	}
};

MyCas* MyCas::m_instance = NULL;

void mythread()
{
	cout << "mythread start" << endl;
	MyCas* p_a = MyCas::getInstance();
	p_a->show();
	cout << "mythread end" << endl;
}
int main()
{

	/* MyCas* p_a = MyCas::getInstance();
	 MyCas* p_b = MyCas::getInstance();

	 p_a->show();
	 p_b->show();*/

	std::thread obj1(mythread);
	std::thread obj2(mythread);

	obj1.join();
	obj2.join();

	return 0;
}