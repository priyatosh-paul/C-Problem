#include<stdio.h>
#include<string.h>

 
int main() {
   char s1[100], s2[100];
   int i, j;
 
   printf("\nEnter the string :");
  gets(s1);
  gets(s2);
 
   i = 0; j=0;
   while (s1[i] != '\0'/* && s2[j] != NULL*/) {
      //s2[i] = s1[i];
      i++;
      
   }
   while(s2[j] != NULL)
   {
	  s1[i]=s2[j];
	  
	  i++;j++; 
   }
 
   s1[i] = '\0';
   printf("\nCopied String is %s \n", s1);
 
   return (0);
}

