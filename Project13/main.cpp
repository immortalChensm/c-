#include <iostream>
#include <string>

using namespace std;

//��ֵ|��ֵ����|��ֵ|��ֵ����|std::moveǿ��ת����ֵΪ��ֵ
//std::move û���ƶ��Ĳ�����ֻ�ǽ���ֵǿ��ת��Ϊ��ֵ�Ĺ���

int main()
{

	//int i = 10;
	////int&& b{ i };//������
	//int&& b{ i++ };
	//
	//int&& c{ std::move(i) };//��ֵ���ð�ǿ��ת������ֵ

	//int&& d = 100;
	////int&& e = d;//������
	//int&& f = std::move(d);

	//d = 1000;
	//cout << d << f << endl;
	//f = 2000;
	//cout << d << f << endl;

	string s = "test";
	string f = std::move(s);
	string&& d = std::move(s);

	cout << s << endl;
	cout << d << endl;
	cout << f << endl;

	return 0;
}