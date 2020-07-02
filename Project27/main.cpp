#include <iostream> 
#include <string>

using namespace std;

class A {
public:
	A() {
		cout << "constructor" << endl;
	}
	/*~A()
	{
		cout << "destructor" << endl;
	}*/
};
int main()
{
	//new/delete运算符 [malloc/free是函数]
	//new/free能做一些初始化和清理工作
	//A* obj = new A();//operator new() 
	//delete obj;

	//A* d = (A*)operator new(100);
	//delete d;

	A* obj = new A();
	delete[] obj;//析构函数会被调用无限次

	//智能指针 
	int* ob = new int;
	//obj称为裸指针 
	//智能指针:是指对裸指针进行包装，能够自动释放所指向的对象内存，便于编写和调试
	//c++智能指针有四种 ：std::
	//auto_ptr unique_ptr shared_ptr,weak_ptr
	//shared_ptr:共享式指针  多个指针共指向同一个对象，最后一个指针被销毁时，对象会被释放
	//weak_ptr 辅助shared_ptr
	return 0;
}