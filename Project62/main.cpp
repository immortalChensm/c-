#include <iostream> 
#include <string>
#include <boost/type_index.hpp>

//引用折叠
using namespace std;
//
//void test(int & &&a) { 引用的引用非法
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

//转发测试
template<typename F,typename T1,typename T2 >
void myFuncTmp(F f, T1 &&t1, T2 &&t2) { //t1,t2 本身是左值，类型是右值引用

	//t1,t2为万能引用：引用折叠规则：有左值就是左值引用，全是右值时就是右值引用
	//T1 = int t1 = int &&
	//T2 = int & t2 = int &

	//t1 目前为左值，类型为右值引用  t1=20 t2 目前为左值 类型为左值引用
	f(t1,t2);//给myfunc时，v1要接右值，v2要接左值  ，但t1是左值了
}
void myfunc(int &&v1, int &v2) {
	v2++;
	cout << v1 + v2 << endl;

}
int main()
{
	//不管左值引用，右值引用，万能引用  反正都是个变量  

	//int i = 10;
	//
	////万能引用
	//func(100);//可以给右值
	//func(i);//可以给左值  

	//int& a = i;
	//a = 102;
	//cout << a << i << endl;

	//int&& b = std::move(i);
	//b = 1000;


	//cout << a << b << i << endl;
	//printf("a=%#x,b=%#x,i=%#x\n",&a,&b,&i);

	//1 引用折叠  
	//1、左值  左值  & &
	//2、左值  右值  & && 
	//3、右值  左值  && &
	//4、右值  右值  && &&

	//折叠规则：只要含有左值，一律是左值引用，否则为右值引用

	//2 引用的引用  

	/*int ab = 10;
	int& cc = ab;
	int & &d = cc;*/


	//3 转发
	//int j = 100;
	//myFuncTmp(myfunc,20,j);//正常

	int j = 100;
	myFuncTmp(myfunc, 20, j);//20右值  j左值

	int&& k = 20;//k本身是左值（有自己的内存地址）  但类型是右值引用
	int& m = k;//证明在此：可以证明k是左值|m是左值，类型是左值引用
	int& h = m;
	return 0;
}