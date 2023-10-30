#include<stdio.h>
int check(int);
void get_number(int *number)
{
	printf("\n Enter 4 digit no: ");
	scanf_s("%d",number);
}

int main(void)
{
	int number;
	get_number(&number);	
	check(number);
}