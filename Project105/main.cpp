#include <iostream>
#include <thread> 

using namespace std;

void show()
{
	cout << "thread1 start" << endl;
	cout << "thread1 end" << endl;
}

class Ta
{
public:
	int& x;
	Ta(int &a) :x(a)
	{
		cout << a << endl;
		cout << x << endl;
		cout << "thread=[" << std::this_thread::get_id() << "]" << this << endl;
	}
	void operator()()
	{
		cout << "thread1 " << x << endl;
		cout << "thread1 " << x << endl;
		cout << "thread1 " << x << endl;
		cout << "thread1 " << x << endl;
		cout << "thread1 " << x << endl;
		cout << "thread=[" << std::this_thread::get_id() << "]"<<this << endl;
	}
};
int main()
{

	//int j = 10;
	//Ta obj(j);

	//thread my(obj);
	////my.join();
	//if (my.joinable()) {

	//	//my.join();
	//	my.join();
	//}

	thread my([] {

		cout << "thread1 run" << endl;


		});
	my.join();


	cout << "thread=" << std::this_thread::get_id() << "main this" << endl;
	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	cout << "main thread end" << endl;
	return 0;
}