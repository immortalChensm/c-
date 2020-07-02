/**

new和delete是operator重载的运算符函数
内置数据类型
1、new数组时，释放时可以不用delete [] 释放 new int[2] 字节大小=4+4=8个字节

自定义类
1、new数组时，如果类有析构函数时 释放时必须用delete [] 释放，否则内存泄露
自定义类 new class[2] 字节大小=class字节大小*2+【x86平台则是4个字节，x64则是8个字节，多出的用于记录中括号里的元素个数】
                     字节大小【如果类没有析构函数时】=class字节大小*2

int *p = new int;//4 Bytes
int *p = new int[2];//8 Bytes
delete p;delete [] p//都可以

class A{}

A *obj = new A();//1Bytes
A *obj = new A[2]();//2Bytes

delete obj;//正确，因为没有析构函数
class B{
    public:
        B(){}
        ~B(){}
}

B *obj = new B[2]();//x86=6Bytes,x64=10Bytes 多出的用于记录2
B *obj1 = new B();//1bytes
delete [] obj;//delete obj 错误


**/