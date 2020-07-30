#include <iostream> 
#include <string> 
#include <vector>
//迭代器
using namespace std;

namespace test1
{
	void func()
	{

		vector<int> obj{ 1,2,3 };
		/*for (vector<int>::iterator iter = obj.begin(); iter != obj.end(); iter++) {
			cout << *iter << endl;
		}*/
		/*for (vector<int>::reverse_iterator iter = obj.rbegin(); iter != obj.rend(); iter++) {
			cout << *iter << endl;
		}*/
		for (vector<int>::const_iterator iter = obj.cbegin(); iter != obj.cend(); iter++) {
			cout << *iter << endl;
		}

		while (!obj.empty()) {

			vector<int>::iterator iter = obj.begin();
			obj.erase(iter);
		}
	}
}
namespace test2
{
	void func()
	{
		/**
		struct input_iterator_tag {};

		struct output_iterator_tag {};

		struct forward_iterator_tag : input_iterator_tag {};

		struct bidirectional_iterator_tag : forward_iterator_tag {};

		struct random_access_iterator_tag : bidirectional_iterator_tag {};

		**/
		//迭代器分类：依据特性和操作
		//输出型迭代器：Output Iterator struct output_iterator_tag
		//struct output_iterator_tag;
		//输入型迭代器：Input Iterator
		//前向迭代器：Forward Iterator
		//双向迭代器：Bidirectional Iteraor
		//随机访问迭代器：Random-access Iterator
		struct random_access_iterator_tag b;
	}
}
int main()
{
	test1::func();
	return 0;
}