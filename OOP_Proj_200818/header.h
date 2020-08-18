#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define NAMELEN 20
#define DEPOSIT true
#define WITHDRAWAL false
using namespace std;

class client {
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

	int return_ID();
	int return_bal();
	void dealing(int money, bool flag);
	
	void print_all_client();

	~client() {
		delete []name;
	}
};

void create_client();
void deposit();
void withdrawal();
void print_all_client();
void free_list();

