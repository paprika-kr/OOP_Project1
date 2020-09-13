#pragma once
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::account_type()
{
	int n;
	cout << "[���� ���� ����]" << endl;
	cout << "1. ���� ���� ���� / 2. �ſ� �ŷ� ����" << endl;
	cout << "����: ";
	cin >> n;
	account_type_n = n;
}

void AccountHandler::create_client() 
{
	int ID_temp;
	String name_temp;
	int bal_temp = 0;
	int rate_temp;
	int credit_rate_temp;

	if (account_type_n == 1)
	{
		cout << "[���� ���� ���� ����]\n";
		cout << "���� ID: ";
		cin >> ID_temp;
		cout << "�̸�: ";
		cin >> name_temp;
		cout << "�Աݾ�: ";
		cin >> bal_temp;
		cout << "������: ";
		cin >> rate_temp;

		list[list_cnt++] = new NormalAccount(ID_temp, name_temp, bal_temp, rate_temp);
	}

	else if (account_type_n == 2)
	{
		cout << "[�ſ� �ŷ� ���� ����]\n";
		cout << "���� ID: ";
		cin >> ID_temp;
		cout << "�̸�: ";
		cin >> name_temp;
		cout << "�Աݾ�: ";
		cin >> bal_temp;
		cout << "������: ";
		cin >> rate_temp;
		cout << "�ſ���(1 to A, 2 to B, 3 to C): ";
		cin >> credit_rate_temp;

		switch (credit_rate_temp)
		{
		case 1:
			credit_rate_temp = credit::A;
			break;
		case 2:
			credit_rate_temp = credit::B;
			break;
		case 3:
			credit_rate_temp = credit::C;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�";
			return;
		}

		list[list_cnt++] = new HighCreditAccount(ID_temp, name_temp, bal_temp, rate_temp, credit_rate_temp);
	}

	else
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;

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
