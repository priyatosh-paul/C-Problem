#include <stdio.h>

int main()
{
		unsigned int b=0x1234;

/*		num = ((num >> 8 ) & 0x00ff) | ((num << 8 ) & 0xff00 );
		num = ((num >> 4 ) & 0x0f) | ((num << 4 ) & 0xf0 );
		num = ((num >> 2 )  & 0x50) | ((num << 2 ) & 0x05 ) ;
		num = (num >> 1 ) | (num << 1 ) ;
*/
		b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
		b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
		b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
		printf ("reverse is %4x\n", b);


		
		return 0;
}
