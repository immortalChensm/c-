#include <iostream>
#include <string>
#include <vector>

namespace test
{
	void func()
	{
		//malloc 分配0个字节，不可以再去读写修改数据，否则报错
		void* p = malloc(0);
		strcpy((char*)p,"testbb");
		free(p);
	}
}
int main()
{
	test::func();
	return 0;
}