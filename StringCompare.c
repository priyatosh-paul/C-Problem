#include <stdio.h>  
int stringcompare(char*,char*);  
int main()  
{  
  char str1[20]; // declaration of char array  
  char str2[20]; // declaration of char array  
  printf("Enter the first string : ");  
  scanf("%s",str1);  
  printf("\nEnter the second string : ");  
  scanf("%s",str2);  
  int compare=stringcompare(str1,str2); // calling stringcompare() function.  
  if(compare==0)  
  printf("strings are equal");  
 else  
 printf("strings are not equal");  
return 0;  
}  
// Comparing both the strings using pointers  
int stringcompare(char *a,char *b)  
{  
   int flag=0;  
    while(*a!='\0' && *b!='\0')  // while loop  
    {  
        if(*a!=*b)  
        {  
            flag=1;  
        }  
        a++;  
        b++;  
    }  
      
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  
