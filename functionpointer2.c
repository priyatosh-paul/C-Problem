#include<stdio.h>

int fun(void)
{
	printf("Hello World\n");

//	return a*b;
	return 1;
}


int main()
{
	int (*functionptr)(void)=&fun;
//	int result=(*functionptr)(10,20);
	printf("%d",functionptr);
//	functionptr=&fun;

	return 0;
}































