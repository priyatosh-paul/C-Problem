#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
	char* ptr=(char*)malloc(sizeof(char)*10);
	ptr=malloc(20);
	memcpy(ptr,ptr,30);
	printf("size of ptr=%d\n",sizeof(ptr));

	return 0;
}





