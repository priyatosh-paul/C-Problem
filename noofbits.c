/* The procedure given in net is wrong, ttrey to buld own logic
 * ***********************************************************
 #include<stdio.h>
  int count1(int x)
  {
  int cnt=0,s,i;
  s=sizeof(x)*8;
  for(i=0;i<s;++i)
  {
  if(x&(1<<i))
  ++cnt;
  }
  return cnt;
  }
  int main()
  {
  int a;
  printf("Please Enter the number\n");
  scanf("%0x",&a);
  printf("The number of 1 is %d",countq1(a));
//  count1(a);
  return 0;
  }

*/
#include <stdio.h>
int count1s(unsigned int num)
{
	unsigned char totalBits=sizeof(num)*8;
	printf("Tottal bits = %u\n",totalBits);
	int count=0,i;
	for(i=0;i <= totalBits;i++)
	{
		if(num & (1<< i))
			count=i;
	}
	return  count;
	
	/*while(num != 0)
	{
		count ++;
		num >>= 1;
	}
	*/
	//return count;
}

int main()
{
  int a;
  printf("Please Enter the number\n");
  scanf("%d",&a);
//	unsigned int data=0x05;
	printf("\nNumber of bit : %d\n",count1s(a));
	return 0;
}




