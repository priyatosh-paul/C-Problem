#include<stdio.h>
#ifndef GREATER
#define GREATER(a,b) ((a > b)? a : b )
#endif
int main()
{
    int a, b, max;
    printf("Please enter two number :   \n");
    scanf("%d", &a);

    scanf("%d", &b);
    max=GREATER(a,b);
    printf("The greater number is   :  %d ",max);
   // max=GREATER(a,b);

    return 0;
}
