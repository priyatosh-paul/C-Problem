#include<stdio.h>
#include "math.h"
//153 = 1^//3 + 5^3 + 3^3 = 153
int main()
{
	int num,n=0,reminder,result,originalnumber;
	printf("Please Enter the number\n");
	scanf("%d", &num);
	
	originalnumber=num;
	
	while(originalnumber!=0)
	{
		originalnumber=originalnumber/10;
		n++;
	}
	printf("The no of digit is %d",n);
	
	originalnumber=num;

	while(originalnumber != 0)
	{
		reminder=originalnumber%10;
		result += pow(reminder,n);
	}
	printf("The result is %d",result);
	
	

	if(result==num)
		printf("%d is an amstromg number",num);
	else
		printf("%d is not an amstromg number",num);
	return 0;
}



