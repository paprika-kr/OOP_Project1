#pragma once
#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__
#include "Client.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountArray list;
	int list_cnt;
	int account_type_n;

public:
	AccountHandler() : list_cnt(0) {}
	void account_type();
	void create_client();
	void deposit();
	void withdrawal();
	void print_all_client();
	void free_list();
};

#endif