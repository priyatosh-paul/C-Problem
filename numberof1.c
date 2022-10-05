/*C program to count number of 1's in a number */
 
#include <stdio.h>
 
int count1s(unsigned int num)
{
    unsigned char totalBits=sizeof(num)*8;
    int count=0;
 
    for(i=0;i< totalBits;i++)
    {
        if( num & (1<< i) )
            count++;
    }
 
    return count;
}
int main()
{
    unsigned int data=0x58;
    printf("\nTotal number of 1's are : %d\n",count1s(data));
 
    return 0;
}
