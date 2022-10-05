#include<iostream.h>

char* string_reverse(char str[], int l)
{
	int i,j;
	char temp, str1[100];
	for(i=0; i<l-1; ++i)
	{
		for(j=l-1; j >=0; --j)
		{
			str1[j]=str[i];
		}
/*		temp=str[l-1];
		str[l-1]=str[i];
		str[i]=temp;
		--l;

*/	}
		str1[l]='\0';

	return str1;
}
