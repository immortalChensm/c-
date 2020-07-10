#include <iostream> 
#include <string>
#include <thread> 
#include <vector>
#include <list>

//创建多个线程|共享数据
using namespace std;

vector<char> g_s{ 'a','b','c' };

void func(int num)
{
	//cout << "begin:" <<num<< endl;

	//cout << "end:" <<num<< endl;
	cout << "thread_id=" << std::this_thread::get_id() << endl;
	for (auto iter = g_s.begin(); iter != g_s.end(); iter++) {
		cout << *iter << endl;
	}
}

class T {
public:
	T(int a) :_i(a) {};
	int _i;
};

class A
{
public:
	void inMsgRecQueue()
	{
		for (int i = 0; i < 100000; i++)
		{
			cout << "inMsgRecQueue-insert: " << i << endl;
			msgRecQueue.push_back(i);
		}
	}

	void outMsgRecQueue()
	{
		for (int i = 0; i < 100000; i++)
		{
			if (!msgRecQueue.empty())
			{
				int cmd = msgRecQueue.front();
				msgRecQueue.pop_front();

			}
			else {
				cout << "outMsgRecQueue-empty: " << i << endl;
			}
		}
		cout << "outMsg end" << endl;
	}
public:
	list<int> msgRecQueue;
};

int main()
{
	/*vector<thread> ts;

	vector<T> objs;
	for (int i = 0; i < 10; i++) {

		ts.push_back(thread(func,i));
	}

	
	for (auto iter = ts.begin(); iter != ts.end(); iter++) {
		
		iter->join();
	}*/
	
	A msgObj;

	std::thread outMsgObj(&A::outMsgRecQueue, msgObj);
	std::thread inMsgObj(&A::inMsgRecQueue, msgObj);

	
	inMsgObj.join();
	outMsgObj.join();

	cout << "main end" << endl;
	return 0;
}