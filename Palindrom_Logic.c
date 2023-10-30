#include<stdio.h>
int check(int number)
{
	int number1;
	int reminder;
	int reverse=0;
	number1=number;
	if(number>1000 && number<10000)
	{
		while(number!=0)
		{
			reminder=number%10;
			reverse=reverse*10+reminder;
			number=number/10;
		}
		printf("\n Reverse Number = ",reverse);
		if(number1==reverse)
			printf("\n %d is Palindrome",number1);
		else
			printf("\n %d is Not Palindrome",number1);
	}
	else
		printf("\n Please enter 4 digit number..\n");	
	printf("\n\n");		
}