#include<stdio.h>
int main()
{
	int x=8,number=8;
	number &= ~(1 << x);
	printf("%d\n",number);
	return 0;
}

//number &= ~(1 << x);
