#include "header.h"

int main() {
	AccountHandler A;
	int menu;

	while (1) {
		cout << endl <<"----- MENU -----\n";
		cout << "1. ���� ����\n" << "2. �Ա�\n" << "3. ���\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
		cin >> menu;
		cout << endl;

		switch (menu) {
			case 1:
				A.create_client();
				break;
			case 2:
				A.deposit();
				break;
			case 3:
				A.withdrawal();
				break;
			case 4:
				A.print_all_client();
				break;
			case 5:
			{
				A.free_list();
				return 0;
			}				
			default:
				cout << "����\n";
		}
	}
	return 0;
}