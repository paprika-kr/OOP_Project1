#include "header.h"

client list[100];
int list_cnt = 0;

void create_client() {
	client temp;
	int ID_temp;
	char name_temp[20];
	int bal_temp = 0;

	cout << "[���� ����]\n";

	cout << "���� ID: ";
	cin >> ID_temp;
	cout << "�̸�: ";
	cin >> name_temp;
	cout << "�Աݾ�: ";
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

	cout << "[�Ա�]\n" << "���� ID: ";
	cin >> ID_temp;
	cout << "�Աݾ�: ";
	cin >> dep;

	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i].accID) {
			list[i].bal += dep;
			cout << "�ԱݿϷ�\n";
			return;
		}
	}
		cout << "�ش� ID�� ���¸� ã�� �� �����ϴ�.\n";
		return;
}

void withdrawal() {
	int ID_temp;
	int dep;

	cout << "[���]\n" << "���� ID: ";
	cin >> ID_temp;
	cout << "��ݾ�: ";
	cin >> dep;

	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i].accID) {
			if (dep > list[i].bal)
				cout << "�ܾ׺���\n";

			else {
				list[i].bal -= dep;
				cout << "��ݿϷ�\n";
			}

			return;
		}
	}
		cout << "�ش� ID�� ���¸� ã�� �� �����ϴ�.\n";
		return;
}

void print_all_client() {

	for (int i = 0; i < list_cnt; i++) 
		cout << endl << "���� ID: " << list[i].accID << endl << "�̸�: " <<list[i].name << endl << "�ܾ�: " << list[i].bal<< endl;

	return;
}