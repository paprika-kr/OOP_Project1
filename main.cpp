#include "header.h"

int main() {
	int menu;

	while (1) {
		cout << endl <<"----- MENU -----\n";
		cout << "1. 계좌 개설\n" << "2. 입금\n" << "3. 출금\n" << "4. 계좌정보 전체 출력\n" << "5. 프로그램 종료\n" << "선택: ";
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
				cout << "에러\n";
		}
	}
	return 0;
}