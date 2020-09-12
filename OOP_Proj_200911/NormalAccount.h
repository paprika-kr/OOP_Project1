#pragma once
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Client.h"
#include "String.h"

class NormalAccount : public client
{
private:
	int rate;

public:
	NormalAccount(int i, String n, int b, int r) : client(i, n, b), rate(r) {}
	virtual void dealing(int money, bool flag);
};

void NormalAccount::dealing(int money, bool flag)
{
	client::dealing(money, flag);

	if (flag == DEPOSIT)
		client::dealing((int)(money * (rate / 100.0f)), DEPOSIT);
}

#endif