#include<stdio.h>



int main()
{
	int a = 0x1234;

	a= ((a& 0XFF00)>>8) | ((a & 0x00FF) << 8);

	
	printf("The reverse of string is %x\n", a);
	
	return 0;
}
