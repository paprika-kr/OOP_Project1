#pragma once
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::account_type()
{
	int n;
	cout << "[계좌 종류 선택]" << endl;
	cout << "1. 보통 예금 계좌 / 2. 신용 신뢰 계좌" << endl;
	cout << "선택: ";
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
		cout << "[보통 예금 계좌 개설]\n";
		cout << "계좌 ID: ";
		cin >> ID_temp;
		cout << "이름: ";
		cin >> name_temp;
		cout << "입금액: ";
		cin >> bal_temp;
		cout << "이자율: ";
		cin >> rate_temp;

		list[list_cnt++] = new NormalAccount(ID_temp, name_temp, bal_temp, rate_temp);
	}

	else if (account_type_n == 2)
	{
		cout << "[신용 신뢰 계좌 개설]\n";
		cout << "계좌 ID: ";
		cin >> ID_temp;
		cout << "이름: ";
		cin >> name_temp;
		cout << "입금액: ";
		cin >> bal_temp;
		cout << "이자율: ";
		cin >> rate_temp;
		cout << "신용등급(1 to A, 2 to B, 3 to C): ";
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
			cout << "잘못 입력하셨습니다";
			return;
		}

		list[list_cnt++] = new HighCreditAccount(ID_temp, name_temp, bal_temp, rate_temp, credit_rate_temp);
	}

	else
		cout << "잘못 입력하셨습니다." << endl;

	return;
}

void AccountHandler::deposit()
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

void AccountHandler::withdrawal()
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
