#include <stdio.h>
#include <math.h>
//  struct A 
// {
//     int a;
//     float b;
//     double c;
//     char d;
// };

void check_armstrong(int number)
{
    int num= number, rem;
    double arm, cnt=0;
    while(num != 0)
    {
        num=num%10;
        cnt++;
    }
    
    num= number;
    while(num != 0)
    {
        
        rem=num%10;
        arm+=pow(rem, cnt);    
        
    }
    
    if (arm == number)
    
    printf(" %d is a Armstrong Number\n", number);
    
    else
    printf(" %d is a Armstrong Number\n", number);
}

int main() {
	//co(nu)de
	//struct A a;
	//printf("Size of Union A is %d\n",sizeof(a));
	int number=153;
	
	
	check_armstrong(number);
	return 0;
}
