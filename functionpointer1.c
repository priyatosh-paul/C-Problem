#include<stdio.h>

int fun(int a, int b)
{
	printf("Hello World\n");

	return a*b;
}


int main()
{
	int (*functionptr)(int, int)=&fun;
	int result=(*functionptr)(10,20);
	printf("%d",result);
//	functionptr=&fun;

	return 0;
}































