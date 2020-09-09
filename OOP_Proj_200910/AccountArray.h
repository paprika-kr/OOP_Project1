#pragma once
#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Client.h"
typedef client* client_PTR;

class BoundCheckAccountArray
{
private:
	client_PTR* arr;
	int arrlen;
	BoundCheckAccountArray(const BoundCheckAccountArray& arr){ }
	BoundCheckAccountArray& operator=(const BoundCheckAccountArray& arr) { }

public:
	BoundCheckAccountArray(int len = 100)
	{
		arrlen = len;
		arr = new client_PTR[arrlen];
	}

	client_PTR& operator[](int idx);
	client_PTR operator[](int idx) const;

	inline int GetArrLen() const
	{
		return arrlen;
	}

	~BoundCheckAccountArray()
	{
		delete[] arr;
	}
};
#endif