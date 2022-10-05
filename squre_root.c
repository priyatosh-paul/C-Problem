#include<stdio.h>
int squre_root(int num)
{
	int i;
	double d,x;
	if (num>1)
	{
		for(i=1;i*i <=num; ++i);
		printf("I am after first for loop\n");
	//	{
			i--;
			printf("The value of i %d\n", i);
			for( d=0.001; d<1.0; d+=0.001)
			{
				printf("I am after second for loop %ld\n",d);
				x=(double)i+d;
				if(x*x > (double)num)
				{
					x = x - 0.001;
					printf("The value of x %d\n", x);
					break;
				}
			}
			printf("The square root of %d is %.3lf\n",num,x);
	//	}
	}
	else
		printf("%d is a -ve number",num);
	return 1;
}
int main()
{

	int a;
	printf("Please enter the nummber");
	scanf("%d",&a);
//	printf("The sure root of %d is %.3lf\n",a,squre_root(a));
	squre_root(a);
	return 0;
}




