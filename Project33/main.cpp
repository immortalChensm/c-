#include <iostream> 
#include <string> 
#include <thread>
#include <fstream>
using namespace std;

//进程：正在运行的程序  
//一个进程：必然会默默启动一个主线程 【一个进程包含一个主线程】 
//线程：用来执行代码的
//多个线程：每个线程都需要一个独立的堆栈空间，线程之间的切换会保留中间状态，切换的时间会耗费程序的运行时间

//cpu单核时：运行多任务时是“上下文切换”切换时会保存各个线程的运行状态，进度等数据

//多线程：
//每个线程有自己的独立运行路径，但是一个进程中所有线程共享一个内存空间【内存地址】可以跨线程间互相访问，开销小
//变量，指针，引用可以在线程间互相传递
//优点：启动速度快，多线程间通信通过共享内存实现 ，开销小
//缺点：数据一致性问题

//进程执行完毕的标志是：主线程是否执行完，主线程执行完，就代表整个进程执行完毕
//程序启动，创建一个进程，进程的主线程运行main主函数，如果我们创建一个线程，也要从一个函数开始运行（初始函数）
//当这个函数运行结束后，就代表这个线程运行结束。


//一般情况：如果这个函数运行完毕了,如果其它子线程还没有执行完毕，会被操作系统强行终止
//要想保持子线程的运行状态：主线程就要一直运行

void myshow()
{
	cout << "thread begin" << endl;

	cout << "thread end1" << endl;
	cout << "thread end2" << endl;
	cout << "thread end3" << endl;
	cout << "thread end4" << endl;
	cout << "thread end5" << endl;
	cout << "thread end6" << endl;
	cout << "thread end7" << endl;
	cout << "thread end8" << endl;
	cout << "thread end9" << endl;
}

class Ta
{
public:
	int &_i;
	Ta(int &i) :_i(i) {
		cout<<"Ta(int &i)"<<endl;
	}
	Ta(const Ta &obj):_i(obj._i){
		cout<<"Ta(const Ta &obj)"<<endl;
	}
	~Ta(){
		cout<<"~Ta()"<<endl;
	}
	void operator()()
	{
		cout << "operator begin" << endl;
		cout << "_i=" << _i << endl;
		cout << "_i=" << _i << endl;
		cout << "_i=" << _i << endl;
		cout << "_i=" << _i << endl;
		cout << "_i=" << _i << endl;
		cout << "_i=" << _i << endl;
		cout << "_i=" << _i << endl;
		//ofstream destFile("./test.txt",ios::out);
		//o.open("./test.txt",ios::out);
		//destFile<<_i<<" ";
		//destFile.close();
	}
};
int main()
{

	//1、普通函数
	//thread t(myshow);
	//t.join();
	//join 加入，汇合  阻塞主线程，让主线程等待子线程执行完毕，然后子线程和主线程汇合，然后主线程再往下执行

	/*if (t.joinable()) {
		cout << "1 true" << endl;
	}
	else {
		cout << "2 false" << endl;
	}
	t.detach();*///子线程和主线程将分离，主线程结束后，子线程在后台独立运行，直到结束，不在有任何关联
	//子线程将被系统或是c++运行时库接管，当该子线程运行结束，由运行时库来清理资源（变成了守护线程）

	/*if (t.joinable()) {
		cout << "1 true" << endl;
	}
	else {
		cout << "2 false" << endl;
	}*/

	//2、其它方式创建子线程 类函数对象
	int j = 10;
	Ta obj(j);//主线程运行结束，整个进程停止，obj对象不存在了，分离出去的线程得到的数据是复制过来的数据
	thread t(obj);

	//t.join();
	t.detach();


//	cout << "main thread" << endl;
//	cout << "main thread" << endl;
//	cout << "main thread" << endl;
//	cout << "main thread" << endl;
//	cout << "main thread" << endl;
//	cout << "main thread" << endl;
//	cout << "main thread" << endl;

	//getchar();
	//3、匿名函数
	//thread t([](){
	//	cout<<"begin"<<endl;
	//	//;;
	//	cout<<"end"<<endl;
	//});
	////t.join();
	//t.detach();

	cout<<"main end"<<endl;
	return 0;
}