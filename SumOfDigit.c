#include<stdio.h>



int main()
{int a = 12345;

//sum of all digit;


	int num=a, sum=0;
	
	while (num != 0)
	{
		
		sum+=num % 10;
		num=num /10;	
	}
	printf("The sum of all digit  is %d\n", sum);
	
	return 0;
}
