#include<stdio.h>
#include <stdlib.h>
int main()
{
	char *ptr= (char*)malloc(sizeof(char)*10);
	// *ptr= (char*)malloc(sizeof(char)*20);
	

	 printf("%d\n",(*ptr+1)-*ptr);



	return 0;
}
