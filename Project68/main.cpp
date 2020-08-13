#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <ctime>

//lambda 的陷进
using namespace std;

std::vector<std::function<bool(int)>> gv;

void myfunc()
{

	srand((unsigned)time(NULL));
	int t = rand() % 6;

	gv.push_back([&](int v)->bool {
		
		if (v % t == 0) {
			return true;
		}
		return false;
	});
}

class CA {
public:
	int m_i = 9;
	void func()
	{
		/*gv.push_back([=](int v)->bool {//[=] 相等于 [this] 了

			if (v % m_i == 0) {
				return true;
			}
			return false;
		});*/

		//c++14 广义捕获
		gv.push_back([abc=m_i](int v)->bool { 

			if (v % abc == 0) {
				return true;
			}
			return false;
			});
	}
};
int main()
{

	//func();

	CA obj;
	obj.func();

	cout << gv[0](9) << endl;

	return 0;
}