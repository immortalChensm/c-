#include <iostream>
#include <string>
#include <vector>

namespace test
{
	void func()
	{
		//malloc ����0���ֽڣ���������ȥ��д�޸����ݣ����򱨴�
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