#include<stdio.h>

static int a =4;

int main()
{
    static int a = 10;
    printf("%d\n", a);
    return 0;
}
