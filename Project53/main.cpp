#include <iostream>
#include <vector>
#include <string>
using namespace std;

/***
vector<int> iv{1,2,3};
vector<类*> iv;
迭代器作用：	
	用于遍历容器中的元素，类似指针
如何获取迭代器
	vector<int>::iterator iter = iv.begin();/iv.end();
迭代器分类
	vector<int>::const_iterator  vector<int>::reverse_iterator iter
	cbegin() cend() rbegin() rend()
迭代器失效
	在操作容器【迭代器】时，突然使容器容量发生了改变【如增加，删除】，则会发生异常
迭代器中的数据元素指针释放
	for(auto iter=iv.begin();iter!=iv.end();iter++){delete (*iter)}
**/
struct stu
{
	int num;
};
//迭代器
namespace test1
{
	void func()
	{
		//迭代器：是一种遍历容器内元素的，数据类型，有点像指针，用来指向容器中的某个元素

		/*vector<int> iv = { 1,2,3 };
		vector<int>::iterator iter;*/

		//iter = iv.begin();//可以返回一个迭代器 可看作返回一块内存的首地址[指针]
		//cout << *iter << endl;
		//iter++;
		//cout << *iter << endl;

		//for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); iter++)
		//{
		//	cout << *iter << endl;
		//}

		////反向迭代器
		//for (vector<int>::reverse_iterator iter=iv.rbegin(); iter!=iv.rend(); iter++) {
		//	cout << *iter << endl;
		//}

		//迭代器运算符
		/*iter = iv.begin();
		iter++;
		cout << *iter << endl;
		iter--;
		cout << *iter << endl;*/

		/*vector<stu> stus;
		vector<stu>::iterator iter1;
		stu obj;
		obj.num = 100;
		stus.push_back(obj);

		iter1 = stus.begin();
		cout << (*iter1).num << endl;*/

		//const_iterator 迭代器  
		

		/*const vector<int> iv = { 1,2,3 };
		vector<int>::const_iterator iter;
		for (iter = iv.begin(); iter != iv.end(); iter++) {
			cout << *iter << endl;
		}*/

		//cbegin,cend c=const常量 常量迭代器

		/*const vector<int> iv = { 1,2,3 };
		
		for (auto iter = iv.cbegin(); iter != iv.cend();iter++) {
			cout << *iter << endl;
		}*/

		//迭代器失效
		//vector<int> iv = { 1,2,3,4,5 };
		//for (auto iter : iv) {

		//	iv.push_back(233);//出现数据错乱
		//	cout << iter << endl;
		//}
		//for (auto beg = iv.begin(),end = iv.end(); beg != end; beg++) {
		//	iv.push_back(233);//
		//	cout << *beg << endl;
		//}
		//在操作迭代器过程，不要去增加或是删除容器中的元素

		//灾难程序1
		//vector<int> iv{ 1,2,3,4,5 };

		//auto beg = iv.begin();
		//auto end = iv.end();

		//while (beg != end) {

		//	cout << *beg << endl;

		//	iv.insert(beg,100);//出错
		//	break;//只能这样处理
		//	

		//}

		// beg = iv.begin();
		// end = iv.end();

		/*while (beg != end) {

			cout << *beg << endl;

			beg++;

		}*/

		/*vector<int> iv{ 1,2,3,4,5 };
		auto beg= iv.begin();
		while (beg!=iv.end()) {

			
			cout << *beg << endl;

			iv.push_back(100);
			beg = iv.begin();
			
			beg++;

		}*/

		/*vector<int> iv{ 1,2,3,4,5 };

		auto beg = iv.begin();
		int icount = 0;
		while (beg != iv.end()) {

			beg = iv.insert(beg,icount+100);
			if (icount > 10) {
				break;
			}
			icount++;
			beg++;
		}
		beg = iv.begin();
		auto end = iv.end();
		while (beg != end) {

			cout << *beg << endl;
			beg++;
		}*/

		//演示2
		vector<int> iv{ 1,2,3,4,5 };

		//for (auto iter = iv.begin(); iter != iv.end(); iter++) {
		//	iv.erase(iter);//出错
		//}

		//begin,end 要随时更新，才不会出错
		/*auto beg = iv.begin();
		while (beg != iv.end()) {

			beg = iv.erase(beg);
			
		}*/
		
		/*while (!iv.empty()) {

			auto iter = iv.begin();
			iv.erase(iter);
		}*/

		//范例
		/*string str("love php");
		for (auto iter = str.begin(); iter != str.end(); iter++) {

			*iter = toupper(*iter);
		}

		cout << str << endl;*/

		stu *s1 = new stu();
		s1->num = 100;

		stu* s2 = new stu();
		s2->num = 100;

		vector<stu*> objs;
		objs.push_back(s1);
		objs.push_back(s2);

		vector<stu*>::iterator iter;
		for (iter = objs.begin(); iter != objs.end(); iter++) {

			delete (*iter);
		}

		cout << objs.size() << endl;

		objs.clear();
		
	}
}

int main()
{
	test1::func();
	return 0;
}