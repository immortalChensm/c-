#include <iostream>
#include <string>
//string¿‡ π”√
using namespace std;

class demo
{
public:
	demo(int a) {
		_a = a;
	}
	/*void operator=(int arg) {
		_a = arg;
	}*/
	
public:
	int _a;
};

int main()
{

	string s1("hello,world");
	string s2{ "hi,world" };

	string s3 = (char*)"hi,php";

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	string s4(10, 'b');
	cout << s4 << endl;

	if (s4.empty()) {
		cout << "empty\n";
	}
	else {
		cout << "not empty\n";
	}

	cout << s4.length() << endl;
	cout << s4.size() << endl;


	for (size_t i = 0; i < s4.size(); i++)
	{
		cout << s4[i] << endl;
	}


	string s5 = "abc";
	string s6 = "def";
	string s7;
	s7 = s5 + s6;
	cout << s7 << endl;

	if (s5 == s6) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal\n";
	}

	string s8 = "abc";
	string s9 = "abc";

	const char *p = s9.c_str();
	char str[100];

	strcpy_s(str,sizeof(str),p);

	cout << str << endl;


	/*demo a(100);
	demo b{ 200 };
	demo c = 300;
	cout << a._a << endl;
	cout << b._a << endl;
	cout << c._a << endl;*/
	return 0;
}