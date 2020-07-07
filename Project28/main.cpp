#include <iostream> 
#include <string>
#include <tr1/memory>//win7 mingcc�ü�����ͷ�ļ�


//shared_ptr ��ģ���ʹ��|����ָ�룺����ʽ  ���ü���
/**
 * 1��shared_ptr ����ָ�봴����ʽ
 *    shared_ptr<int> obj(new int(1));
 *    shared_ptr<int> obj(new int[10]);
 *
 *    shared_ptr<int> obj = make_shared<int>(100);
 *
 * 2��shared_ptr ģ����ĳ�Ա
 *    use_count() ���ô���
 *    unique() �Ƿ�ֻ��һ������
 *    reset() ����ǰ����ָ����ڴ��ַ���ã�����ԭ�ڴ��ַ��������1
 *            ����ڴ��ַ�ж������ָ���򲻻�ɾ��
 *    reset(����) ֻ��һ������ָ��ʱ�����ͷŵ��ö���ԭ��ָ����ڴ��ַ��ͬʱָ���µĲ���
 *    			�ж��ʱ��ԭ������ָ����ڴ������1
 *    nullptr = reset ͬ��
 *
 * 3��ָ��ɾ����
 * 		������ɾ������shared_ptr<int[]) obj(new int[10]);
 * 		��ͨ����ɾ������shared_ptr<int> obj(new int[10],������);
 * 		��������ɾ������lambda��:shared_ptr<int> obj(new int[10],[](int *p){delete [] p});
 * 		std::default_delete ��ģ��ɾ������shared_ptr<int[]> obj(new int[10],std::default_delete<int>[]());
 *
 * **/
using namespace std;

void testSharedPtr(shared_ptr<int> p)
{
	*p = 100;
	return;
}

class B{
public:
	B() {

		cout <<"B constructor " << endl;
	}
	~B() {
		cout << "B destrcutor " << endl;
	}
};
template<typename t>
class A {
public:
	A(t a) {
		
		cout <<"A constructor "<< a << endl;
	}
	~A() {
		cout << "A destrcutor " << endl;
	}

	B _obj;
	
};



void myDelete(int* p)
{
	cout << "�Լ���ɾ����" << endl;
	delete p;
}

template<typename t>
shared_ptr<t> make_shared_array(size_t size)
{
	return shared_ptr<t>(new t[size],std::default_delete<t[]>());
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
//	shared_ptr<int> p1(new int(100), [](int* p) {
//		delete p;
//		cout << 2 << endl;
//	});
//
//	auto p2 = p1;
//
//	cout << 1 << endl;
//
//	p1 = nullptr;
//
//	p2.reset();

//	shared_ptr<A<int>> obj(new A<int>[4]{0,0,0,0},[](A<int> *p){
//		delete [] p;
//	});
	//default_deleteģ��ɾ����
	//shared_ptr<A<int>> obj(new A<int>[4]{0,0,0,0},std::default_delete<A<int>[]>());
	//c++17 []ɾ����
//	shared_ptr<A<int>[]> obj(new A<int>[4]{0,1,2,3});
//	shared_ptr<int[]> obj1(new int[100]);
//	obj1[0] = 10;
//	obj1[1] = 20;
//
//	cout<<obj1[0]<<endl;

	//shared_ptr<int[]> piArr = make_shared_array<int>(5);
//	auto func = [](int a,int b){
//		cout<<a<<b<<endl;
//	};
//
//	func(10,20);

	//auto func1 = [](int *p){

	//	cout<<"func1 called"<<endl;
	//	delete p;
	//};

	//auto func2 = [](int *p){
	//	cout<<"func2 called"<<endl;
	//	delete p;
	//};

	//shared_ptr<int> obj1(new int(1),func1);
	//shared_ptr<int> obj2(new int(2),func2);

	//obj2 = obj1;//obj2 �뿪ԭ��ָ��������ˣ�obj1��ָ����ڴ����þͻ����Ϊ2

	//cout<<obj1.use_count()<<endl;
	//cout<<obj2.use_count()<<endl;

	//piArr[0] = 1;

//	shared_ptr<int> obj(new int[10],[](int *p){
//		//�������� ������������������
//		delete p;
//	});

//	int *p = new int[10];
//	p[0]=1;
//	p[1] = 2;
//
//	cout<<p[1]<<endl;

	




	return 0;
}