#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "costumer.h"
#include "io_Actions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <ctype.h>
#include "File_Actions.h"


#define ID_LEN 20
#define FILE_SIZE 150


char* get_name_file(int);

int struct2file(Costumer *person)
{
	const char* write_format = "%s\n%d\n%s\n%s\n%d";
	char *path = get_name_file(person->user_id);
	FILE *costumer_file = fopen(path, "w+");
	if (costumer_file != NULL)
	{
		fprintf(costumer_file, write_format, person->user_name, person->user_id, person->user_mobile, person->user_city, person->user_money);
		fclose(costumer_file);
		printf("Have a great day sir!\n \n \n");
		return 1;
	}
	else
	{
		printf("Error: cannot open file %s.txt!\n", person->user_id);
		return 0;
	}
	free(path);
	free(person);
}


char* get_name_file(int user_id) {
	char *path = (char*)malloc(100 * sizeof(char));
	strcpy(path, "");
	char file_name[ID_LEN] = "";
	itoa(user_id, file_name, 10);
	strcat(file_name, ".txt");
	strcat(path, file_name);
	return path;
}




Costumer* file2struct(int user_id)
{
	Costumer *existing_person = (Costumer*)malloc(sizeof(Costumer));
	char *file_name = get_name_file(user_id);
	FILE *costumer_file = fopen(file_name, "r");
	if (costumer_file == NULL)
	{
		printf("Error: the id doesn't exist!\n");
		exit(0);
	}
	char buffer[100] = "";
	int line_num = 0;
	while (read_line(buffer, sizeof(buffer), costumer_file) != NULL) /* read a line */
	{
		switch (line_num)
		{
		case 0:
			strcpy(existing_person->user_name, buffer);
			break;
		case 1:
			existing_person->user_id = atoi(buffer);
			break;
		case 2:
			strcpy(existing_person->user_mobile, buffer);
			break;
		case 3:
			strcpy(existing_person->user_city, buffer);
			break;
		case 4:
			existing_person->user_money = atoi(buffer);
			break;
		
		}
		line_num++;
		strcpy(buffer, "");
	}
	free(file_name);
	return existing_person;
}


void show_file(int user_id)
{
	const char* show_file_format = "Name : %s\nID : %d\nMobile : %s\nCity : %s\nMoney : %d\n";
	Costumer *person = NULL;
	char *file_name = get_name_file(user_id);
	FILE* person_file = fopen(file_name, "r");
	if (person_file != NULL)
	{
		person = file2struct(user_id);
		printf(show_file_format, person->user_name, person->user_id, person->user_mobile, person->user_city, person->user_money);
	}
	else
		printf("You entered wrong id!\n");
	free(person);
}



void file2struct_V2(Costumer *c){

    FILE *reads;

    char filename[40];
    int temp;

    printf("Write the ID :  ");
	read_int
	reads=fopen(filename, "r");
    if (reads==NULL) {
        perror("Error");
        return 1;
    }
    else { 
        while(!feof(reads)) {
            struct element *n= (struct element*)malloc(sizeof(struct element));             
            fscanf(reads,"%d %d %d %d %lf", n->id, n->sign, n->year, n->month, n->amount);                  
            n->next=NULL;                   

            if(queue->head ==NULL) {
                queue->head=n;
            }
            else {
                queue->tail->next=n;
            }

            queue->tail=n;
            queue->size++;                  

        }           
    }
}