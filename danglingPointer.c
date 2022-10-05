#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr=NULL,i;
 	for(i=0; i<=10;++i)
	{
		ptr=(int*)malloc(sizeof(int)*1);
//	free(ptr);
	printf("%u\n",ptr);
	}
//	for(i=0; i<=10;++i)

//	free(ptr);

	return 0;
}
