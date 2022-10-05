#include<stdio.h>
int no_of_digit(int num)
{
	int cnt=0;
	while(num!=0)
	{
		num/=10;
		cnt++;

	}
	return cnt;
}

int main(void)
{
	int a;
	printf("Please take the number");
	scanf("%d",&a);
	printf("No of digit in %d is %d",a,no_of_digit(a));
	return 0;
}


