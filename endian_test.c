#include <stdio.h>
int main()
{
unsigned int i = 1;
char *c = (char*)&i;
printf("Address of i %u\n",&i);
printf("*c is =%u\n",*c);
if (*c)
printf("Little endian\n");
else
printf("Big endian\n");
//getchar();
return 0;
}



