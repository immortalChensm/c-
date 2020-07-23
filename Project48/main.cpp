#include <iostream>
#include <string> 

using namespace std;

class A
{
public:
	int _i;
};
int main()
{
	size_t size = 100;
	size_t blockSize = sizeof(A);

	A* obj1 = (A*)malloc(size);
	obj1->_i = 100;

	//cout << obj1->_i << endl;

	A* obj2 = (A*)((char*)(obj1+blockSize));

	obj2->_i = 200;

	


	A* obj3 = (A*)((char*)(obj1 + blockSize*2));

	obj3->_i = 300;
	cout << obj1->_i << endl;
	cout << obj2->_i << endl;
	cout << obj3->_i << endl;

	return 0;
}