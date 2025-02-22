    #include <stdio.h>
     void ReverseString(char *s)
     {
         char r[1000];
       int begin, end, count = 0;
     
      
     
       // Calculating string length
     
       while (s[count] != '\0')
          count++;
     
       end = count - 1;
     
       for (begin = 0; begin < count; begin++) {
          r[begin] = s[end];
          end--;
       }
     
       r[begin] = '\0';
     
       printf("%s\n", r);
     
     }
    int main()
    {
        char s[1000];
        printf("Input a string\n");
       gets(s);
       ReverseString(s);
       return 0;
    }


