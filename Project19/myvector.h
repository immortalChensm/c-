#pragma once
#ifndef __MYVECTOR__H
#define __MYVECTOR__H


template <typename T>

class myvector
{
public:
	typedef T* myiterator;//��������ͳ�Ա
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

//������ͳ�Ա
template <typename T>
//typename�ĵڶ���ʹ�ó�������::��Ա  �󲿷���� ��ʹ����ľ�̬��Ա ���ǵ�����ĳ�Ա����
//typename ��Ҫ�Ĺ����ǽ��ࣺ�����ͳ�Ա����Ϊ�������͡����Ͳ�����
//typename ���߱�����myiterator��һ�����ͣ�������ľ�̬��Ա
//��������class
typename myvector<T>::myiterator myvector<T>::mybegin()
{

}
#endif 