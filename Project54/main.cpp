#include <iostream> 
#include <string> 
#include <vector>
//������
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
		//���������ࣺ�������ԺͲ���
		//����͵�������Output Iterator struct output_iterator_tag
		//struct output_iterator_tag;
		//�����͵�������Input Iterator
		//ǰ���������Forward Iterator
		//˫���������Bidirectional Iteraor
		//������ʵ�������Random-access Iterator
		struct random_access_iterator_tag b;
	}
}
int main()
{
	test1::func();
	return 0;
}