#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef struct client {
	int accID;
	char name[20];
	int bal;
}client;



void create_client();
void deposit();
void withdrawal();
void print_all_client();
