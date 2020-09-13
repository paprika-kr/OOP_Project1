#pragma once
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "String.h"

class client
{
	int accID;
	String name;
	int bal;

public:
	client()
	{
		accID = 0;
		name = NULL;
		bal = 0;
	};

	client(int a, String n, int b) :accID(a), bal(b)
	{
		name = n;
	};

	int return_ID() const;
	int return_bal() const;
	virtual void dealing(int money, bool flag);
	void print_all_client() const;

};

#endif // !__CLIENT_H__