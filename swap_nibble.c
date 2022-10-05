#include <stdio.h> 

unsigned char swapNibbles(unsigned char x) 
{ 
//	return ( (x & 0x0F)<<4 | (x & 0xF0)>>4 ); 
	return ( (x <<4)& 0xF0 | (x >>4 )& 0X0F); 
} 

int main() 
{ 
	unsigned char x = 100; 
	printf("%u", swapNibbles(x)); 
	return 0; 
}




