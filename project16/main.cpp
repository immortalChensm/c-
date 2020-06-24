//
// Created by Administrator on 2020/6/23.
//

#include <iostream>
#include <string>

using namespace std;
//构造函数的继承||多重继承||静态成员||显示的初始化基类和隐匿的初始化基类
//虚基类：无论这个类在继承体系中，出现多少次，派生类中，都中会包含唯一一个共享的虚基类（Grand)子内容
//class A{
//public:
//    A(int i,int j,int k=0):_i(i),_j(j),_k(k){
//
//    }
//    A(){}
//public:
//    int _i;
//    int _j;
//    int _k;
//};
//class B:public A{
//public:
////    B(int i,int j,int k):A(i,j,k){
//////
//////    }
//    using A::A;//继承基类的构造函数 它会生成B(int i,int j,int k):A(i,j,k) 的函数
//    //也会生成B(int i,int j):A(i,j)
//};

class Grand
{
public:
    Grand(int v):_value(v){
        cout<<"Grand constructor"<<endl;
    }
    virtual ~Grand()
    {
        cout<<"Grand destructor"<<endl;
    }

    void info()
    {
        cout<<_value<<endl;
    }
public:
    int _value;
    static int _static;//声明
};
//定义
int Grand::_static = 0;
class A2:virtual public Grand//虚继承
{
public:
    A2(int value,int a2):Grand(value),_a2(a2){
        cout << "A2 constructor" << endl;
    }
    virtual ~A2(){
        cout << "A2 destructor" << endl;
    }
    void info()
    {
        cout<<_a2<<endl;
    }
public:
    int _a2;
    int _value;
};
class A :public virtual Grand //虚继承
{
public:
    A(int value, int a) :Grand(value), _a(a) {
        cout << "A constructor" << endl;
    }
    virtual ~A() {
        cout << "A destructor" << endl;
    }
    void info()
    {
        cout << _a << endl;
    }
public:
    int _a;
    int _value;
};
class B
{
public:
    B(){
        cout<<"hidden call B constructor"<<endl;
        _b = 100;
    }
    B(int b):_b(b){

    }
    virtual ~B(){

    }
    void info()
    {
        cout<<_b<<endl;
    }
public:
    int _b;
};

//class C: A, B{ 默认继承  权限默认是private
class C:public A,public A2,public B{//派生列表  A,A2的基类是Grand 会导致Grand构造和析构会运行2次

public:
    //C(int i,int j,int k,int m):A(i,j),B(k),_c(m){
   // C(int i,int j,int k,int m):A(i,j),A2(i,j),_c(m){//隐匿的调用B构造默认构造函数
    C(int i,int j,int k,int m):A(i,j),A2(i,j),Grand(k),_c(m){//由孙子类来实现祖先类的构造初始化
        //C类只有一份Grand的成员
        cout<<"C constructor"<<endl;
    }

    virtual ~C(){
        cout<<"C destructor"<<endl;
    }

    void infoC()
    {
        //cout<<_c<<endl;
        A::info();
        B::info();
    }
    void info()
    {
        cout<<_b<<endl;
    }
public:
    int _c;
    int _value;//Grand,A,A2都有  但是C重写覆盖可以
};

//class A {
//public:
//    A(int tv){}
//};
//class B {
//public:
//    B(int tv){}
//};
//
//class C :public A, public B {
//public:
//    using A::A;//继承A的构造函数
//    using B::B;
//
//    //定义自己的构造函数
//    C(int tv) :A(tv), B(tv) {
//
//    }
//};
int main()
{

//    B ad(1,2,3);
//    cout<<ad._i<<ad._j<<ad._k<<endl;
//
//    B a(1,2);
//    B c;

    //多重继承
    //C ctest(10,20,30,50);
//    ctest.infoC();
//
//    ctest.info();//不知道调用哪个  返回ambiguous 除非C类覆盖基类的此方法
//    //增加作用域调用
//    ctest.A::info();
//    ctest.B::info();
//    A::_static = 1;
//    C::_static = 10;
//    Grand::_static = 100;

    //派生类构造函数与构构函数
    //C ctest(10,20,30,50);//基类构造先运行，析构后运行
    //哪个构造先运行，跟派生列表的顺序有关

    //显示的初始化基类和隐匿的初始化基类

    //继承多个构造函数
   // C ctest(10);

    //类型转换
    //C类派生类拥有基类的部分地址
    //Grand* pg = new C(1, 2, 3, 4);

    //A* a = new C(1, 2,3,4);

    //虚继承
    C* pg = new C(1, 2, 3, 4);

    pg->_value = 100;//此变量有2个重复的

    //虚基类：可以保证派生类继承[不管继承多少次]的共享基类成员唯一
    delete pg;
    return 0;
}