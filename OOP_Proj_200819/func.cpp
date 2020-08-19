#include "header.h"

client* list[100];
int list_cnt = 0;

void create_client() 
{
	int ID_temp;
	char name_temp[NAMELEN];
	int bal_temp = 0;

	cout << "[계좌 개설]\n";
	cout << "계좌 ID: ";
	cin >> ID_temp;
	cout << "이름: ";
	cin >> name_temp;
	cout << "입금액: ";
	cin >> bal_temp;

	list[list_cnt++] = new client(ID_temp, name_temp, bal_temp);
	return;
}

void deposit() 
{
	int ID_temp;
	int dep;

	cout << "[입금]\n" << "계좌 ID: ";
	cin >> ID_temp;
	cout << "입금액: ";
	cin >> dep;


	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i]->return_ID()) {
			list[i]->dealing(dep, DEPOSIT);
			cout << "입금완료\n";
			return;
		}
	}	
		cout << "해당 ID의 계좌를 찾을 수 없습니다.\n";
		return;
}

void withdrawal()
{
	int ID_temp;
	int dep;

	cout << "[출금]\n" << "계좌 ID: ";
	cin >> ID_temp;
	cout << "출금액: ";
	cin >> dep;

	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i]->return_ID()) {
			if (dep > list[i]->return_bal())
				cout << "잔액부족\n";

			else {
				list[i]->dealing(dep, WITHDRAWAL);
				cout << "출금완료\n";
			}
			return;
		}
	}
	cout << "해당 ID의 계좌를 찾을 수 없습니다.\n";
	return;
}

void print_all_client()
{
	for (int i = 0; i < list_cnt; i++)
		list[i]->print_all_client();
	return;
}

void free_list()
{
	for (int i = 0; i < list_cnt; i++)
		delete list[i];
	return;
}

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
	cout << endl << "계좌 ID: " << accID << endl << "이름: " << name << endl << "잔액: " << bal<< endl << endl;
	return;
}