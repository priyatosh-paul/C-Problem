/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<math.h>
//#include<iostream>

// void printFirstNDigitsOfFibonacciSeries(int n)
// {
// //code here

// 	int first=0, second=1, third=0;
	
// 	if (n >0)
// 	{
// 		for(int i =0; i <=n; ++i)
// 	//	while(third )
// 		{
// 			first=second;
// 			second=third;
// 			third= second+ first;
			    
// 			// third= third+second;       
// 			printf("%d\t,", third);
// 		}
// 	}
// 	else
// 	printf("Give valid input\n");


// }

// void reverseNumber(int num)
// {
//     int rem;
//     while(num != 0)
//     {
//     //    num=num/10;
//         rem=num%10;
//          num=num/10;
//         printf ( "%d",rem);
//     }
// }

int NoOfSetBitOfNumber(int num)
{
    int cnt =0;
    
  //  int size= sizeof(num);
    int num1 =0;
    if (num > 0)
    {
        for(int i =0; i < 32; ++i)
        {
           if( num&(1<<i))
            
            {
                     num1=+pow(2,i);
                     

                
                
                
                ++cnt;
                if(num==num1)
                    break;
            }
        }
         return cnt;
    }
    else
        printf("Provide a valied input\n");
    return 1;
}

int main()
{
    
    //printFirstNDigitsOfFibonacciSeries(5);
  //  reverseNumb11;;
  //  NoOfSetBitOfNumber(11);
    printf("No. of bit set is %d\n", NoOfSetBitOfNumber(-6));
    return 0;
}
