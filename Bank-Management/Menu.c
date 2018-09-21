#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bank_Actions.h"
#include "costumer.h"
#include "io_Actions.h"
#include "File_Actions.h"



int main() {
	menu();
	int choice;
	read_int(&choice);
	while (choice != 6)
	{
		if (choice == 1)
		{
			new_acc();
		}
		else if (choice == 2)
		{
			edit();
		}
		else if (choice == 3)
		{
			transact();
		}
		else if (choice == 4)
		{
			show();
		}
		else if (choice == 5)
		{
			delete_file();
		}
		

		menu();
		printf("\nWhat do you want to do? \n \n");
		read_int(&choice);
		}

	exit(0);

	
}










