//
// Created by Administrator on 2020/6/30.
//

#include <iostream>
#include <string>
using namespace std;
//template<typename a,typename b>
//void show(a x,b y){
//    cout<<x<<y<<endl;
//}
void show()
{
    cout<<"over"<<endl;
}
template <typename T,typename ...U>//U是无限个类型参数  typename T,typename A,typename B ....
void show(T a,U ...args){//T a | A a | B b | C c

    cout<<a<<endl;
    show(args...);
}
int main()
{
    show<int,char,double>(100,'a',100.00f);
    return 0;
}