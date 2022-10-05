#include<stdio.h>
//#include<conio.h>
#include<string.h>

void del(char *p, char ch);

int main() {
   char str[10];
   char ch;

   printf("\nEnter the string : ");
   scanf("%s", &str);

   printf("\nEnter character which you want to delete : ");
   scanf("%ch", &ch);

   del(str, ch);
 //  getch();
 	return 0;
}

/*void del(char str[], char ch) {
   int i, j = 0;
   int size;
   char ch1;
   char str1[10];

   size = strlen(str);

   for (i = 0; i < size; i++) {
      if (str[i] == ch) 
		continue;
	  
		//i=i+1;
			ch1 = str[i];
			str1[j] = ch1;
		
         j++;
      }
  // }
   str1[j] = '\0';

   printf("\ncorrected string is : %s", str1);
}
*/

void del(char *p, char ch) 
{
	if (p== NULL)
	return ;
	char *pDest = p;
	while (*p)
	{
		if (*p != ch)
			*pDest ++ = *p;
		p++;
	}
	*pDest = '\0';	
	 printf("\ncorrected string is : %s", pDest);		
}




