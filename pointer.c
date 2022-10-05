#include<stdio.h>
int main(void)
{
const int a = 10;
const int* ptr = &a;
printf("\n value at ptr is : [%d]\n",*ptr);
printf("\n Address pointed by ptr : [%p]\n",(unsigned int*)ptr);
//*ptr = 11;
++ptr;
printf("\n value at ptr is: [%d]\n",*ptr);
printf("\n value at a is: [%d]\n",a);
printf("Size of pointer %d\n",sizeof(ptr));
return 0;
}









