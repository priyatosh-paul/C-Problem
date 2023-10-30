#include<stdio.h>
int main(void)
{
	int i,j,rows;
	printf("\n Enter the number of rows: ");
	scanf_s("%d",&rows);

	for(i=0;i<rows;++i)
	{
		printf("\n");
		for(j=0;j<=i;++j)
		{
			printf(" ");
		}
		for(j=i;j<rows;++j)
		{
			printf(" * ");
		}
	}
	printf("\n\n");
	return 0;
}