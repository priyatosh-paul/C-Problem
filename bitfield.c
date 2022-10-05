#include <stdio.h>

// A structure without forced alignment
struct test1
{
unsigned int x: 5;
unsigned int y: 8;
};

// A structure with forced alignment
struct test2
{
unsigned int x: 5;
unsigned int: 0;
unsigned int y: 8;
};

struct test3
{
	int x;
	int y :1;
	char z;
};

int main()
{
printf("Size of test1 is %ld bytes\n", sizeof(struct test1));
printf("Size of test2 is %ld bytes\n", sizeof(struct test2));
printf("Size of test3 is %ld bytes\n", sizeof(struct test3));   
printf("Size of int is %ld bytes\n", sizeof(int));   
getchar();
return 0;
}

//Size of test1 is 4 bytes, the size of unsigneed int is 4 byte, here 4 byte is suufecient
//Size of test2 is 8 bytes, 0 force the size into 4+4=8 byte

