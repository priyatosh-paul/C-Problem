#include<stdio.h>
#include"GlobalStatic.h"

extern int a;
extern int b;

//a++;
//b++;

int main()
{
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", ++a+(++b));
	return 0;
}
