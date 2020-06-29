//
// Created by Administrator on 2020/6/29.
//

#include <iostream>
#include <string>

using namespace std;

template<typename t,class n,int age=100>
void talk(t name,n word){
    cout<<name<<" says " << word<< age<<endl;
}
//泛化版本
//template <typename t,typename u>
//struct TI
//{
//    TI()
//    {
//        cout<<"generic constructor"<<endl;
//    }
//    void show()
//    {
//        cout<<"generic show"<<endl;
//    }
//};

//特化int,int版本
//template<>
//struct TI<int,int>
//{
//    TI()
//    {
//        cout<<"int,int constructor"<<endl;
//    }
//    void show()
//    {
//        cout<<"i,i special"<<endl;
//    }
//};
//特化int,char版本
//template<>
//struct TI<int,char>
//{
//    TI()
//    {
//        cout<<"int,char constructor"<<endl;
//    }
//    void show()
//    {
//        cout<<"i,char special"<<endl;
//    }
//    void talk(int a)
//    {
//        cout<<"talk"<<endl;
//    }
//};

//特化成员函数
//template<>
//void TI<double,double>::show()
//{
//    cout<<"double,dobule special"<<endl;
//}

//template<>
//void TI<double,double>::talk(int a)
//{
//    cout<<"talk"<<endl;
//}

//template <typename t> 模板声明或定义
//template class<int> 模板显示实例化定义
//template void show(int a,int b)模板显示实例化定义
//template <> xxx 模板特化

//泛化模板
//template<typename x,typename y,typename z>
//struct TC{
//    void show()
//    {
//        cout<<"generic show"<<endl;//泛化
//    }
//};
////从模板参数数量上偏特化
//template<typename y>
//struct TC<int,y,double>//特化  说白了就是确定了模板参数的值【值是数据类型】
//{
//    void show()
//    {
//        cout<<"half show"<<endl;//局部特化  也叫偏特化
//    }
//};

//从模板参数类型范围上【范围缩小】
template <typename y>
struct TI{
    void show()
    {
        cout<<"generic show"<<endl;
    }
};

template<typename y>
struct TI<const y>//const 特化版本
{
    void show()
    {
        cout<<"const y show"<<endl;//参数类型范围缩小
    }
};

template<typename y>
struct TI<y *>
{
    void show()
    {
        cout<<"y * sepcial show"<<endl;//y *特化版本
    }
};

template<typename y>
struct TI<y &>
{
    void show()
    {
        cout<<"y & special show"<<endl;//左值引用特化版本
    }
};

template<typename y>
struct TI<y &&>
{
    void show()
    {
        cout<<"y && special show"<<endl;//右值引用特化版本
    }
};
int main()
{
    talk<string,string,5000>("jack","hello,world");

    //类模板特化[全特化】

    //TI<float,int> obj;
    //obj.show();//调用泛化版本

    //TI<int,char> obj2;
    //obj2.show();//调用特化版本

    //特化成员函数
    //TI<double,double> obj3;
    //obj3.show();

    //类模板偏特化【局部特化】
    //1、从模板参数数量上
    //TC<int,int,int> obj;
    //obj.show();

    //TC<int,int,double> obj2;//调用局部特化版本

    //2、从模板参数类型范围上如 int到const int
    //T到T *指针
    //obj2.show();

    TI<int> obj1;
    obj1.show();

    TI<int *> obj2;
    obj2.show();

    TI<int &> obj3;
    obj3.show();

    TI<int &&> obj4;
    obj4.show();

    TI<const int> obj5;
    obj5.show();

    //总结
    //类模板全特化：定义的时候，不在指定模板参数，模板参数的值【数据类型】直接定义
    //格式：template <> class<具体数据类型>
    //类成员函数全特化：template<> class<数据类型>::成员函数名()

    //局部特化：
    // 参数数量上：template<typename x,typename y,typename z> class<int,y,double>
    // 数据类型上：template<typenamt x> class<const x> 或 class<x *>或 class<x &> 或class<x &&>


    return 0;
}