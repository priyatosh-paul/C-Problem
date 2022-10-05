/*#include<stdio.h>
  swap()

  int main(void)
  {
  unsigned int a;
  printf("Please Enter the number \n");
  scanf("%d",&a);
  swap(a);
  return 0;
  }

*/
#include <stdio.h>

int main()
{
	unsigned int  data=0x1234;

	// swaping 1st bit to 2nd bit (bit counting 7-0).
	// 	    // binary of 0x0A is : 0000 1010
	//
//	data^=(1<<1);
	//data^=(1<<2);
	data = ((data  << 8 ) & 0xFF00)  | (( data  >> 8 )& 0x00FF ) ;
//	data = ((data & 0xFF00 ) << 8 )  | (( data & 0x00FF )  >> 8 ) ;
	// data will be : 0000 1100 (0x0C)
	printf("\ndata after swap bits : %X",data);
	//
	return 0;
}







