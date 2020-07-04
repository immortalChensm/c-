#include <iostream> 
#include <string> 

using namespace std;
//weak_ptr 类模板
/**
弱指针依赖于强指针shared_ptr ，起点监视作用

reset() 不影响强引用，只是弱引用计数减1
lock() 如果没有过期，则返回shared_ptr 对象
expire() 是否过期
use_count() 返回强引用计数


**/
int main()
{

	//weak_ptr 弱指针  弱引用  用于补充shared_ptr 强指针
	/*auto pi = make_shared<int>(100);

	weak_ptr<int> piw(pi);*/

	//weak_ptr<int> piw2;

	//piw2 = piw;//pi,piw,piw2 的内存地址有1个强引用，和2个弱引用指向
	/**
	
		pi----->[一段内存，值100]
		piw---->[]
		piw2--->[]
	**/

	//pi.reset();
	//auto pi2 = piw.lock();//会返回一个shared_ptr 类对象  如果pi指向的内存存在的话，同时强引用计数加1 否则返回空

	//if (pi2 != nullptr) {
	//	*pi2 = 200;
	//}

	//cout << *pi2 << *pi << endl;
	//weak_ptr 的常用 操作


	//auto pi1 = make_shared<int>(100);
	//auto pi2(pi1);

	//weak_ptr<int> piw(pi2);

	//int c = piw.use_count();//返回强引用计数

	//cout << c << endl;

	//printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n",&pi1,pi1, &pi2,pi2, &piw,piw);

	//pi1.reset();
	//printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n", &pi1, pi1, &pi2, pi2, &piw, piw);
	//pi2.reset();
	//printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n", &pi1, pi1, &pi2, pi2, &piw, piw);

	//if (piw.expired()) {
	//	cout << "原对象内存过期 " << endl;
	//	printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n", &pi1, pi1, &pi2, pi2, &piw, piw);

	//}
	weak_ptr<int> pw;
	{
		auto pi1 = make_shared<int>(100);

		pw = pi1;//出这个范围将过期
	}
	

	//pw.reset();//pw 不在指向原对象

	if (!pw.expired()) {


		auto pi2 = pw.lock();
		if (pi2 != nullptr) {

			int t = 1;
		}
		//pi2 过了  {}  范围后引用计数减1
	}
	else {
		cout << "expire" << endl;
		//cout << *pi1 << endl;
	}


	return 0;
}