#include "Human.h"
#include <iostream>
using namespace std;
Human::Human()
{
	//cout << "call Human::Human()" << endl;
}

Human::Human(int age)
{
	//cout << "call Human::Human(int age)" << endl;
}

void Human::talk()
{
	cout << "call void Human::talk()" << endl;
}

void Human::talk(int num)
{
	cout << "call void Human::talk(int num)" << endl;
}