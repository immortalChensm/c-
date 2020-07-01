#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <list>

using namespace std;

namespace test {

    //1、可变参函数模板
    template<typename ...T>//...T 一堆类型 或叫一包类型
    void pfunc(T ... args)//...args  一堆参数 或叫一包参数
    {
        cout << sizeof...(args) << endl;
        cout << sizeof...(T) << endl;
    }

    //递归终止
    void pfunc2()
    {
        cout << "递归终止pfunc2..." << endl;
    }

    //2、一包参数的展开 函数递归
    template<typename T,typename ...U>
    void pfunc2(const T& firstArgs, const U& ... args)
    {
        cout << "第一个参数的值：" << firstArgs << endl;
        pfunc2(args...);
    }

    /****************************************************/
    //3、类继承递归 包类型参数展开
    template<typename ...args>
    class demo {

    };

    //0 个参数的特化版本
    template<>class demo<> {
    public:
        demo() {

            cout << "demo<> class constructor" << endl;
            printf("demo<>::demo=%p\n", this);
        }
    };
    //通过组合递归方式实现模板参数包和构造函数参数包的展开
    //包参数展开
    template<typename First,typename ...Others>
    class demo<First, Others...>/*:private demo<Others...>*/{

    public:
        demo():_i(0) {

            cout << "demo class constructor" << endl;
            printf("demo::demo=%p\n",this);
        }

        demo(First parf, Others...paro) :_i(parf), m_o(paro...)/*demo<Others...>::demo(paro...) */{
            cout << "demo(First parf, Others...paro) class constructor" << endl;
            printf("demo::demo=%p\n", this);
            cout << "i==" << _i << endl;
        }

        First _i;

        demo <Others ...> m_o;
    };
    /****************************************************/

    void func()
    {

        demo<int, double, char> obj(1,2.34f,'a');
    }
}

namespace test2{

    //模板可变参数包展开
    //1、通过tuple展开

    template<int mycount,int mymaxcount,typename...T>
    class myclass{
    public:
        static void myfuncs(const tuple<T...>&t){
            cout << "value=" << get<mycount>(t) << endl;
            myclass<mycount + 1, mymaxcount, T...>::myfuncs(t);
        }
    };

    template<int mymaxcount,typename...T>
    class myclass<mymaxcount, mymaxcount,T...> {
    public:
        static void myfuncs(const tuple<T...>& t) {

        }
    };
    template<typename ...T>
    void myfunc(const tuple<T...>&t){

        myclass<0, sizeof...(T), T...>::myfuncs(t);
    }
    void func()
    {
        tuple<float,int,int> obj(12.5f,1,2);
//        cout<<get<0>(obj)<<endl;
//        cout<<get<1>(obj)<<endl;
//        cout<<get<2>(obj)<<endl;
        myfunc(obj);
    }
}

namespace test3 {

    //模板 模板参数
    template<
        typename T,//类型模板参数
        //template<class> class Container//模板  模板参数
        template<typename W> typename Container
    >
    class myclass {
    public:
        T _i;
        Container<T> mycon;
        myclass()
        {
            for (int i = 0; i < 10; i++) {
                mycon.push_back(i);
            }
        }
    };
    template<typename T> using myvector = std::vector<T, allocator<T>>;
    template<typename T>
    using mylist = std::list<T, allocator<T>>;
    void func()
    {
        myclass<int, myvector> obj;
        myclass<int, mylist> obj2;
    }
}
int main()
{
    test2::func();
    return 0;
}