#include "header.h"

client list[100];
int list_cnt = 0;

void create_client() {
	client temp;
	int ID_temp;
	char name_temp[20];
	int bal_temp = 0;

	cout << "[계좌 개설]\n";

	cout << "계좌 ID: ";
	cin >> ID_temp;
	cout << "이름: ";
	cin >> name_temp;
	cout << "입금액: ";
	cin >> bal_temp;

	temp.accID = ID_temp;
	strcpy_s(temp.name, name_temp);
	temp.bal = bal_temp;
	list[list_cnt++] = temp;

	return;
}

void deposit() {
	int ID_temp;
	int dep;

	cout << "[입금]\n" << "계좌 ID: ";
	cin >> ID_temp;
	cout << "입금액: ";
	cin >> dep;

	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i].accID) {
			list[i].bal += dep;
			cout << "입금완료\n";
			return;
		}
	}
		cout << "해당 ID의 계좌를 찾을 수 없습니다.\n";
		return;
}

void withdrawal() {
	int ID_temp;
	int dep;

	cout << "[출금]\n" << "계좌 ID: ";
	cin >> ID_temp;
	cout << "출금액: ";
	cin >> dep;

	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i].accID) {
			if (dep > list[i].bal)
				cout << "잔액부족\n";

			else {
				list[i].bal -= dep;
				cout << "출금완료\n";
			}

			return;
		}
	}
		cout << "해당 ID의 계좌를 찾을 수 없습니다.\n";
		return;
}

void print_all_client() {

	for (int i = 0; i < list_cnt; i++) 
		cout << endl << "계좌 ID: " << list[i].accID << endl << "이름: " <<list[i].name << endl << "잔액: " << list[i].bal<< endl;

	return;
}