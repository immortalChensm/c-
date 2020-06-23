//
// Created by Administrator on 2020/6/23.
//

#include <iostream>
#include <string>

using namespace std;
//构造函数的继承||多重继承||静态成员||显示的初始化基类和隐匿的初始化基类
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
class A:public Grand
{
public:
    A(int value,int a):Grand(value),_a(a){

    }
    virtual ~A(){

    }
    void info()
    {
        cout<<_a<<endl;
    }
public:
    int _a;
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
class C:public A,public B{//派生列表

public:
    //C(int i,int j,int k,int m):A(i,j),B(k),_c(m){
    C(int i,int j,int k,int m):A(i,j),_c(m){//隐匿的调用B构造默认构造函数
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
};
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
    C ctest(10,20,30,50);//基类构造先运行，析构后运行
    //哪个构造先运行，跟派生列表的顺序有关

    //显示的初始化基类和隐匿的初始化基类
    return 0;
}