#pragma once
#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Client.h"

template <typename T>
class BoundCheckAccountArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckAccountArray(const BoundCheckAccountArray& arr){ }
	BoundCheckAccountArray& operator=(const BoundCheckAccountArray& arr) { }

public:
	BoundCheckAccountArray(int len = 100)
	{
		arrlen = len;
		arr = new T [arrlen];
	}

	T& operator[](int idx);
	T operator[](int idx) const;

	inline int GetArrLen() const
	{
		return arrlen;
	}

	~BoundCheckAccountArray()
	{
		delete[] arr;
	}
};

template <typename T>
T& BoundCheckAccountArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckAccountArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

#endif