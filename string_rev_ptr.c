#include<stdio.h>

int main()
{
	char str[50]="priyatosh";

//	char *str;
	char *rev,temp;
	int i;
	rev=str;
	int len=sizeof(str)/sizeof(str[0]);

//	while()
	while (rev != '\0')
	{
		for(i =len-1; i>0; i--)
		{
			temp=str[i];
		//	str[i]=rev;
			rev[i]=temp;




		}
	//	++rev;
	}

	/*	while (rev != '\0')
		{
		++rev;
		}

		str=rev;


*/	

	printf("%s\n",rev);
	return 0;
}

