#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define NAMELEN 20
#define DEPOSIT true
#define WITHDRAWAL false
using namespace std;

class client;

class AccountHandler
{
private:
	client* list[100];
	int list_cnt;

public:
	AccountHandler() : list_cnt(0){}
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
	void dealing(int money, bool flag);
	
	void print_all_client() const;

	~client() {
		delete []name;
	}
};



