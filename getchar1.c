#include<stdio.h>
int main()
{
	int ch;  /* May cause problems */ 
	while ((ch = getchar()) != EOF) 
	{
		putchar(ch);
	}
	return 0;
}





