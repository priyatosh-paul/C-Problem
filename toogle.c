#include<stdio.h>
int main(void)
{
	int a=3;
	a^=1<<8;
	printf("%d\n",a);
	return 0;
}
