#include<stdio.h>
#include "Calender_Header.h"
void print_msg(char* message)
{
	printf(" %s ",message);
}

int main(void)
{
	int month;
	int year;
	int flag;
	
	printf("\n Enter year (eg. 1996): ");
	scanf_s("%d",&year);
	printf("\n Enter month number (eg. 3): ");
	scanf_s("%d",&month);

	flag=find_leap_year(year,print_msg);	
	get_days(month,flag,print_msg);
	
	printf("\n\n");
	return 0;
}