#include<stdio.h>
int main()
{
    int num;
    printf("Pls Enter the number");
    scanf("%d",&num);
    //if((num != 1) && (num & (num - 1)))
    if (num > 0 && (num & (num - 1)) == 0)
    {   
        printf("%d is power of 2",num);
    }
    else
    {
        printf("%d is not power of 2",num);
    }
    
}




