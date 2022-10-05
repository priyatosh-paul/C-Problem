#include<stdio.h>
//#define PRINT(x) ("x")
//#define PRINT(x) ("x")
//#define PRINT(x) ("x") if I write like this x will come as string
#define PRINT(x) (#x)// if I write like this the string will come
int main()
{ 
	  printf("%s",PRINT(x));
	  printf("%s",PRINT(Y));
	  printf("%s",PRINT(Zabc));
	    return 0;
}


