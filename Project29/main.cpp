#include <iostream> 
#include <string> 

using namespace std;
//weak_ptr ��ģ��
/**
��ָ��������ǿָ��shared_ptr ������������

reset() ��Ӱ��ǿ���ã�ֻ�������ü�����1
lock() ���û�й��ڣ��򷵻�shared_ptr ����
expire() �Ƿ����
use_count() ����ǿ���ü���


**/
int main()
{

	//weak_ptr ��ָ��  ������  ���ڲ���shared_ptr ǿָ��
	/*auto pi = make_shared<int>(100);

	weak_ptr<int> piw(pi);*/

	//weak_ptr<int> piw2;

	//piw2 = piw;//pi,piw,piw2 ���ڴ��ַ��1��ǿ���ã���2��������ָ��
	/**
	
		pi----->[һ���ڴ棬ֵ100]
		piw---->[]
		piw2--->[]
	**/

	//pi.reset();
	//auto pi2 = piw.lock();//�᷵��һ��shared_ptr �����  ���piָ����ڴ���ڵĻ���ͬʱǿ���ü�����1 ���򷵻ؿ�

	//if (pi2 != nullptr) {
	//	*pi2 = 200;
	//}

	//cout << *pi2 << *pi << endl;
	//weak_ptr �ĳ��� ����


	//auto pi1 = make_shared<int>(100);
	//auto pi2(pi1);

	//weak_ptr<int> piw(pi2);

	//int c = piw.use_count();//����ǿ���ü���

	//cout << c << endl;

	//printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n",&pi1,pi1, &pi2,pi2, &piw,piw);

	//pi1.reset();
	//printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n", &pi1, pi1, &pi2, pi2, &piw, piw);
	//pi2.reset();
	//printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n", &pi1, pi1, &pi2, pi2, &piw, piw);

	//if (piw.expired()) {
	//	cout << "ԭ�����ڴ���� " << endl;
	//	printf("pi1=%#x|%#x,pi2=%#x|%#x,piw=%#x|%#x\n", &pi1, pi1, &pi2, pi2, &piw, piw);

	//}
	weak_ptr<int> pw;
	{
		auto pi1 = make_shared<int>(100);

		pw = pi1;//�������Χ������
	}
	

	//pw.reset();//pw ����ָ��ԭ����

	if (!pw.expired()) {


		auto pi2 = pw.lock();
		if (pi2 != nullptr) {

			int t = 1;
		}
		//pi2 ����  {}  ��Χ�����ü�����1
	}
	else {
		cout << "expire" << endl;
		//cout << *pi1 << endl;
	}


	return 0;
}