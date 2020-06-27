#pragma once
#ifndef __MYVECTOR__H
#define __MYVECTOR__H


template <typename T>

class myvector
{
public:
	typedef T* myiterator;//本类的类型成员
public:
	myvector();
	myvector& operator=(const myvector&);

public:
	myiterator mybegin();
	myiterator myend();
public:
	void test();
};

template <typename T>
void myvector<T>::test()
{
	return;
}

template <typename T>
myvector<T>::myvector()
{
	;
}

template <typename T>
myvector<T>& myvector<T>::operator=(const myvector<T>&)
{
	return *this;
}

//类的类型成员
template <typename T>
//typename的第二种使用场景：类::成员  大部分情况 是使用类的静态成员 或是调用类的成员函数
//typename 主要的功能是将类：：类型成员声明为数据类型【类型参数】
//typename 告诉编译器myiterator是一个类型，不是类的静态成员
//不可以用class
typename myvector<T>::myiterator myvector<T>::mybegin()
{

}
#endif 