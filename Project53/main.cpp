#include <iostream>
#include <vector>
#include <string>
using namespace std;

/***
vector<int> iv{1,2,3};
vector<��*> iv;
���������ã�	
	���ڱ��������е�Ԫ�أ�����ָ��
��λ�ȡ������
	vector<int>::iterator iter = iv.begin();/iv.end();
����������
	vector<int>::const_iterator  vector<int>::reverse_iterator iter
	cbegin() cend() rbegin() rend()
������ʧЧ
	�ڲ�����������������ʱ��ͻȻʹ�������������˸ı䡾�����ӣ�ɾ��������ᷢ���쳣
�������е�����Ԫ��ָ���ͷ�
	for(auto iter=iv.begin();iter!=iv.end();iter++){delete (*iter)}
**/
struct stu
{
	int num;
};
//������
namespace test1
{
	void func()
	{
		//����������һ�ֱ���������Ԫ�صģ��������ͣ��е���ָ�룬����ָ�������е�ĳ��Ԫ��

		/*vector<int> iv = { 1,2,3 };
		vector<int>::iterator iter;*/

		//iter = iv.begin();//���Է���һ�������� �ɿ�������һ���ڴ���׵�ַ[ָ��]
		//cout << *iter << endl;
		//iter++;
		//cout << *iter << endl;

		//for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); iter++)
		//{
		//	cout << *iter << endl;
		//}

		////���������
		//for (vector<int>::reverse_iterator iter=iv.rbegin(); iter!=iv.rend(); iter++) {
		//	cout << *iter << endl;
		//}

		//�����������
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

		//const_iterator ������  
		

		/*const vector<int> iv = { 1,2,3 };
		vector<int>::const_iterator iter;
		for (iter = iv.begin(); iter != iv.end(); iter++) {
			cout << *iter << endl;
		}*/

		//cbegin,cend c=const���� ����������

		/*const vector<int> iv = { 1,2,3 };
		
		for (auto iter = iv.cbegin(); iter != iv.cend();iter++) {
			cout << *iter << endl;
		}*/

		//������ʧЧ
		//vector<int> iv = { 1,2,3,4,5 };
		//for (auto iter : iv) {

		//	iv.push_back(233);//�������ݴ���
		//	cout << iter << endl;
		//}
		//for (auto beg = iv.begin(),end = iv.end(); beg != end; beg++) {
		//	iv.push_back(233);//
		//	cout << *beg << endl;
		//}
		//�ڲ������������̣���Ҫȥ���ӻ���ɾ�������е�Ԫ��

		//���ѳ���1
		//vector<int> iv{ 1,2,3,4,5 };

		//auto beg = iv.begin();
		//auto end = iv.end();

		//while (beg != end) {

		//	cout << *beg << endl;

		//	iv.insert(beg,100);//����
		//	break;//ֻ����������
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

		//��ʾ2
		vector<int> iv{ 1,2,3,4,5 };

		//for (auto iter = iv.begin(); iter != iv.end(); iter++) {
		//	iv.erase(iter);//����
		//}

		//begin,end Ҫ��ʱ���£��Ų������
		/*auto beg = iv.begin();
		while (beg != iv.end()) {

			beg = iv.erase(beg);
			
		}*/
		
		/*while (!iv.empty()) {

			auto iter = iv.begin();
			iv.erase(iter);
		}*/

		//����
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