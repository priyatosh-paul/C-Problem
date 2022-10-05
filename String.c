#include<stdio.h>

int main()
{
	char str1[100],str2[100],str3[100],arr[100];
	printf("Enter first String ::");
	gets(str1);
	sprintf(arr,"%s",str1);
	printf("Enter Second String ::");
	gets(str2);
	sprintf(arr,"%s",str2);
	printf("Enter Third String ::");
	gets(str3);
	sprintf(arr,"%s",str3);
	int i;
	printf("the array is %s\n",arr);
//	for(i=0; arr[i]!='\0';++i)
//		printf("%c",arr[i]);

	return 0;
}



