#include<stdio.h>
//#include<cstdlib.h>
#include<malloc.h>
#include<cstring>
//#include<free.h>
using namespace std;
int main(void)
{
	char* ptr=(char*)malloc(sizeof(char)*10);
	int  *ptr1 = new(int);
//	ptr=malloc(20);
	memcpy(ptr,ptr1,30);
	printf("size of ptr=%zu\n",sizeof(ptr));
	printf("size of int=%zu\n",sizeof(int));
	delete ptr;//we can delete memory in cpp if it is aloocate using malloc
	delete ptr1; // free an not be used in Cpp
	return 0;
}





