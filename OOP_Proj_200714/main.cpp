#include "header.h"

int main() {
	int menu;

	while (1) {
		cout << endl <<"----- MENU -----\n";
		cout << "1. ���� ����\n" << "2. �Ա�\n" << "3. ���\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
		cin >> menu;
		cout << endl;

		switch (menu) {
			case 1:
				create_client();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdrawal();
				break;
			case 4:
				print_all_client();
				break;
			case 5:
				return 0;
			default:
				cout << "����\n";
		}
	}
	return 0;
}