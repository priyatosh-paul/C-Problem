#include<stdio.h>
#include"Program11_Header.h"

int menu_list(int choice, MSG message)
{
	message("\n 0. Exit");
	message("\n 1. Lenght of String");
	message("\n 2. To copy String1 into String2");
	message("\n 3. To concat two strings");
	message("\n 4. To Compare two strings (We cosider CASE here)");
	message("\n 5. To Compare two strings (Without considering CASE)");
	message("\n Enter the choice: ");
	scanf("%d",&choice);
	return choice;
}

void accept_string(const char* message,char* text)
{
	printf("\n %s",message);
	scanf("%s",text);	
}

void print_message(const char* message)
{
	printf("%s",message);
}

int main()
{
	int choice=1;
	int result;
	char text1[50];	
	char text2[50];
	
	while(choice!=0)
	{
		choice=menu_list(choice,print_message);
		switch(choice)
		{
			case 1:
				accept_string("\n Enter String: ",text1);				
				result=strlen(text1);
				printf("\n %s is of length : %d \n",text1,result);
				break;
			case 2:
				accept_string("\n Enter String1: ",text1);
				accept_string("\n Enter String2: ",text2);
				strcpy(text1,text2,print_message);
				printf("\n String1 is : %s",text1);
				print_message("\n Hence String Copied..\n");
				break;
			case 3:
				accept_string("\n Enter String1: ",text1);
				accept_string("\n Enter String2: ",text2);
				strcat(text1,text2,print_message);
				printf("\n String1 : %s\n",text1);
				print_message("\n String conacatnation complete..\n");
				break;
			case 4:
				accept_string("\n Enter String1: ",text1);
				accept_string("\n Enter String2: ",text2);
				strcmp(text1,text2,print_message);
				break;
			case 5:
				accept_string("\n Enter String1: ",text1);
				accept_string("\n Enter String2: ",text2);
				strlwr(text1);
				strlwr(text2);
				strcmpi(text1,text2,print_message);
				break;
		}
	}
	return 0;
}