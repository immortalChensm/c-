#include <iostream> 
#include <string>


//shared_ptr ��ģ���ʹ��|����ָ�룺����ʽ  ���ü���
using namespace std;

void testSharedPtr(shared_ptr<int> p)
{
	*p = 100;
	return;
}

template<typename t>
class A {
public:
	A(t a) {
		
		cout <<"constructor "<< a << endl;
	}
	~A() {
		cout << "A destrcutor " << endl;
	}

	
};

void myDelete(int* p)
{
	cout << "�Լ���ɾ����" << endl;
	delete p;
}
int main()
{
	//1�����ü���  ����ڴ���p1��p2��ָͬ��
	/*shared_ptr<int> p1 = make_shared<int>(666);

	auto p2 = p1;


	testSharedPtr(p2);

	cout << *p1 << *p2 << endl;*/


	//���ü����ļ���
	//p2 = make_shared<int>(888);

	/*shared_ptr<A<int>> p1 = make_shared<A<int>>(100);

	auto p2 = p1;


	p2 = make_shared<A<int>>(6);

	p1 = make_shared<A<int>>(1);*/

	//2����ȡ���ü���
	//shared_ptr<A<int>> p1 = make_shared<A<int>>(100);

	//3���Ƿ�ֻ��һ�����á�����
	/*if (p1.unique()) {
		cout << "p1 is unique ref" << endl;
	}
	else {
		cout << "p1 is not unique ref" << endl;
	}
	auto p2 = p1;

	if (p1.unique()) {
		cout << "p1 is unique ref" << endl;
	}
	else {
		cout << "p1 is not unique ref" << endl;
	}

	cout << p1.use_count() << p2.use_count() << endl;*/

	//4��reset()  
	//a����������ʱ����������Ψһһ��ָ���ڴ�ģ����ͷŸö��������
	//b�������ж������ͬʱָ��ͬһ���ڴ��ַ�����ǲ��ͷţ������������ô���-1

	/*shared_ptr<A<int>> pi(new A<int>(100));

	auto p1 = pi;
	pi.reset();

	cout << pi.use_count() << endl;*/

	//reset�в���ʱ
	//a�����pi ��Ψһһ��ָ���ڴ��ַ�ģ�ʹ��resetʱ�����ͷ�ԭ��ָ����ڴ棬��ʹpi����ָ���µ��ڴ��ַ
	//b�����pi����Ψһ�ģ��ж���ģ�����pi����ָ���µ��ڴ��ַ����ԭ�������ü�����1
	/*shared_ptr<A<int>> pi(new A<int>(1));

	auto p2 = pi;


	pi.reset(new A<int>(100));*/

	//4��get() ������ָ�루С�� ʹ�ã�

	/*shared_ptr<int> pi(new int(100));

	int* p = pi.get();

	*p = 1;

	cout << *p << *pi << endl;*/

	//shared_ptr<A<int>> pi = make_shared<A<int>>(100);

	//A<int>* p = pi.get();

	//delete p;//����

	//5��swap����
	/*shared_ptr<int> p1 = make_shared<int>(100);

	shared_ptr<int> p2(new int(200));

	std::swap(p1, p2);

	cout << *p1 << *p2 << endl;

	p2.swap(p1);
	cout << *p1 << *p2 << endl;*/

	//6��nullptr ��ʹ�ú�resetһ����

	/*shared_ptr<int> p1 = make_shared<int>(100);

	auto p2 = p1;

	p1 = nullptr;*/

	//7����Ϊif�ж����

	/*shared_ptr<int> p1 = make_shared<int>(100);
	p1 = nullptr;
	if (p1) {
		cout << "p1 not nullptr" << endl;
	}
	else {
		cout << "p1 is nullptr" << endl;
	}*/
	//8��ָ��ɾ����������
	
	//shared_ptr<int> p1(new int(100),myDelete);
	//ɾ����������lambda���
	shared_ptr<int> p1(new int(100), [](int* p) {
		delete p;
		cout << 2 << endl;
	});

	auto p2 = p1;

	cout << 1 << endl;
	
	p1 = nullptr;

	p2.reset();
	return 0;
}