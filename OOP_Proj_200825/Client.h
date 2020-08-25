#pragma once
#ifndef __CLIENT_H__
#define __CLIENT_H__

class client
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
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
	}

	int return_ID() const;
	int return_bal() const;
	virtual void dealing(int money, bool flag);

	void print_all_client() const;

	~client() {
		delete[]name;
	}
};

#endif // !__CLIENT_H__