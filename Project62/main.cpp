#include <iostream> 
#include <string>
#include <boost/type_index.hpp>

//�����۵�
using namespace std;
//
//void test(int & &&a) { ���õ����÷Ƿ�
//
//}
template<typename t>
void func(t &&v)
{
	cout << "------begin----------" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<t>().pretty_name() << endl;
	cout << "v=" << type_id_with_cvr<decltype(v)>().pretty_name() << endl;
	cout << "------end----------" << endl;
}

//ת������
template<typename F,typename T1,typename T2 >
void myFuncTmp(F f, T1 &&t1, T2 &&t2) { //t1,t2 ��������ֵ����������ֵ����

	//t1,t2Ϊ�������ã������۵���������ֵ������ֵ���ã�ȫ����ֵʱ������ֵ����
	//T1 = int t1 = int &&
	//T2 = int & t2 = int &

	//t1 ĿǰΪ��ֵ������Ϊ��ֵ����  t1=20 t2 ĿǰΪ��ֵ ����Ϊ��ֵ����
	f(t1,t2);//��myfuncʱ��v1Ҫ����ֵ��v2Ҫ����ֵ  ����t1����ֵ��
}
void myfunc(int &&v1, int &v2) {
	v2++;
	cout << v1 + v2 << endl;

}
int main()
{
	//������ֵ���ã���ֵ���ã���������  �������Ǹ�����  

	//int i = 10;
	//
	////��������
	//func(100);//���Ը���ֵ
	//func(i);//���Ը���ֵ  

	//int& a = i;
	//a = 102;
	//cout << a << i << endl;

	//int&& b = std::move(i);
	//b = 1000;


	//cout << a << b << i << endl;
	//printf("a=%#x,b=%#x,i=%#x\n",&a,&b,&i);

	//1 �����۵�  
	//1����ֵ  ��ֵ  & &
	//2����ֵ  ��ֵ  & && 
	//3����ֵ  ��ֵ  && &
	//4����ֵ  ��ֵ  && &&

	//�۵�����ֻҪ������ֵ��һ������ֵ���ã�����Ϊ��ֵ����

	//2 ���õ�����  

	/*int ab = 10;
	int& cc = ab;
	int & &d = cc;*/


	//3 ת��
	//int j = 100;
	//myFuncTmp(myfunc,20,j);//����

	int j = 100;
	myFuncTmp(myfunc, 20, j);//20��ֵ  j��ֵ

	int&& k = 20;//k��������ֵ�����Լ����ڴ��ַ��  ����������ֵ����
	int& m = k;//֤���ڴˣ�����֤��k����ֵ|m����ֵ����������ֵ����
	int& h = m;
	return 0;
}