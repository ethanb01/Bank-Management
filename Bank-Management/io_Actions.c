#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "costumer.h"

// fgets without reading newline character
char* read_line(char *str, int n, FILE *stream)
{
	char *ans = fgets(str, n, stream);
	if (ans == NULL)
		return NULL;
	int newlineIndex = strcspn(str, "\n");
	str[newlineIndex] = 0;
	return str;
}


int read_int(int *num)
{
	scanf("%d", num);
	getchar(); // remove newline from stdin
	return *num;
}

Costumer* print_and_scan_new_acc_messages()
{

	Costumer *person = (Costumer*)malloc(sizeof(Costumer));

	
	printf("Enter the name : ");
	read_line(person-> user_name, 20, stdin);
	printf("Enter the ID : ");
	read_int(&person->user_id);
	printf("Enter the mobile : ");
	read_line(person->user_mobile, 20, stdin);
	printf("Enter the city : ");
	read_line(person->user_city, 20, stdin);
	printf("Enter the money : ");
	read_int(&person->user_money);


	return person;
}

