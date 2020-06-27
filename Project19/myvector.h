#pragma once
#ifndef __MYVECTOR__H
#define __MYVECTOR__H


template <typename T>

class myvector
{
public:
	typedef T* myiterator;
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
#endif 