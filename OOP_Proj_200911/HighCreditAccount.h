#pragma once
#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__
#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
	int credit_rate;

public:
	HighCreditAccount(int i, String n, int b, int r, int c) : NormalAccount(i, n, b, r), credit_rate(c) {}
	virtual void dealing(int money, bool flag);
};

void HighCreditAccount::dealing(int money, bool flag)
{
	NormalAccount::dealing(money, flag);

	if (flag == DEPOSIT)
		client::dealing(money * (credit_rate / 100.0f), DEPOSIT);
}

#endif