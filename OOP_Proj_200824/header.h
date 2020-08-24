#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define NAMELEN 20
#define DEPOSIT true
#define WITHDRAWAL false
using namespace std;

namespace credit { enum { A = 7, B = 4, C = 2 }; };

class client;

class AccountHandler
{
private:
	client* list[100];
	int list_cnt;
	int account_type_n;

public:
	AccountHandler() : list_cnt(0){}
	void account_type();
	void create_client();
	void deposit();
	void withdrawal();
	void print_all_client();
	void free_list();
};

class client : public AccountHandler
{
	int accID;
	char* name;
	int bal;

public:
	client() 
	{
		accID = 0;
		name = NULL;
		bal = 0;
	};

	client(int a, char* n, int b) :accID(a), bal(b) 
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	};

	client(const client& copy) :accID(copy.accID), bal(copy.bal)
	{
		name = new char[strlen(copy.name)+1];
		strcpy_s(name, strlen(copy.name)+1, copy.name);
	}

	int return_ID() const;
	int return_bal() const;
	virtual void dealing(int money, bool flag);
	
	void print_all_client() const;

	~client() {
		delete []name;
	}
};

class NormalAccount : public client
{
private:
	int rate;

public:
	NormalAccount(int i, char* n, int b, int r) : client(i, n, b), rate(r){}
	virtual void dealing(int money, bool flag);
};

class HighCreditAccount : public NormalAccount
{
private:
	int credit_rate;

public:
	HighCreditAccount(int i, char* n, int b, int r, int c) : NormalAccount(i, n, b, r), credit_rate(c) {}
	virtual void dealing(int money, bool flag);
};



