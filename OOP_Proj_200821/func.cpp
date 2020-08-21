#include "header.h"

void AccountHandler::create_client() 
{
	int ID_temp;
	char name_temp[NAMELEN];
	int bal_temp = 0;

	cout << "[���� ����]\n";
	cout << "���� ID: ";
	cin >> ID_temp;
	cout << "�̸�: ";
	cin >> name_temp;
	cout << "�Աݾ�: ";
	cin >> bal_temp;

	list[list_cnt++] = new client(ID_temp, name_temp, bal_temp);
	return;
}

void AccountHandler::deposit()
{
	int ID_temp;
	int dep;

	cout << "[�Ա�]\n" << "���� ID: ";
	cin >> ID_temp;
	cout << "�Աݾ�: ";
	cin >> dep;


	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i]->return_ID()) {
			list[i]->dealing(dep, DEPOSIT);
			cout << "�ԱݿϷ�\n";
			return;
		}
	}	
		cout << "�ش� ID�� ���¸� ã�� �� �����ϴ�.\n";
		return;
}

void AccountHandler::withdrawal()
{
	int ID_temp;
	int dep;

	cout << "[���]\n" << "���� ID: ";
	cin >> ID_temp;
	cout << "��ݾ�: ";
	cin >> dep;

	for (int i = 0; i < list_cnt; i++) {
		if (ID_temp == list[i]->return_ID()) {
			if (dep > list[i]->return_bal())
				cout << "�ܾ׺���\n";

			else {
				list[i]->dealing(dep, WITHDRAWAL);
				cout << "��ݿϷ�\n";
			}
			return;
		}
	}
	cout << "�ش� ID�� ���¸� ã�� �� �����ϴ�.\n";
	return;
}

void AccountHandler::print_all_client()
{
	for (int i = 0; i < list_cnt; i++)
		list[i]->print_all_client();
	return;
}

void AccountHandler::free_list()
{
	for (int i = 0; i < list_cnt; i++)
		delete list[i];
	return;
}

////////////////////////////////////////////////////////////////////////////////////////////

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
	cout << endl << "���� ID: " << accID << endl << "�̸�: " << name << endl << "�ܾ�: " << bal<< endl << endl;
	return;
}