#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_Actions.h"
#include "costumer.h"
#include "File_Actions.h"




void menu() {
	printf("COSTUMER ACCOUNT BANKING MANAGEMENT SYSTEM \n \n");
	printf("------------ WELCOME TO THE MAIN MENU------------ \n \n");
	printf("1.  Create new account\n");
	printf("2.  Update informations of existing account\n");
	printf("3.  For transactions\n");
	printf("4.  Check the details of existing account\n");
	printf("5.  Remooving existing account\n");
	printf("6.  View costumer's list\n");
	printf("7.  Exit\n \n\n");
}

void new_acc() {
	Costumer *person = print_and_scan_new_acc_messages();
	struct2file(person);
}
static void edit_user_data(int user_id)
{
	Costumer *c1 = file2struct(user_id);
	show_file(user_id);
	printf("\n\n\n\n");
	printf("Mobile : ");
	read_line(c1->user_mobile, 20, stdin);
	printf("City : ");
	read_line(c1->user_city, 20, stdin);
	struct2file(c1);
	free(c1);
}

void edit()
{
	int user_id;
	printf("Please enter the account's id: ");
	read_int(&user_id);
	edit_user_data(user_id);

}

