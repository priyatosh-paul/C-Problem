#include <stdio.h>

union test1
{
	int x;
	int y;
};

union test2
{
	int x;
	char y;
};

union test3
{
	//int arr[10];
//	int arr[0];
	char arr[0];
	char y;
};

int main()
{
	union test1 t1;
	union test2 t2;
	union test3 t3;

	printf ("sizeof(test1) = %d, sizeof(test2) = %d,"
			"sizeof(test3) =  %d", sizeof(t1),
			sizeof(t2), sizeof(t3));
	return 0;
}




