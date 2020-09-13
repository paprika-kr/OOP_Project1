#pragma once
#include "BankingCommonDecl.h"
#include "Client.h"

int client::return_ID() const
{
	return accID;
}

int client::return_bal() const
{
	return bal;
}

void client::dealing(int money, bool flag)
{
	if (flag == true)
		bal += money;
	else
		bal -= money;
	return;
}

void client::print_all_client() const
{
	cout << endl << "°èÁÂ ID: " << accID << endl << "ÀÌ¸§: " << name << endl << "ÀÜ¾×: " << bal << endl << endl;
	return;
}