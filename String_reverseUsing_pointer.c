#include <stdio.h>

char * reverse(char *str)

{
    char *str1;
	int l=0;
	int end;
	int begin;
	while( *(str+l) != '\0')
	{
	    //++str;
	    ++l;
	   
	}
	
	end = l -1;
    	
    for (begin=0; begin <= l; ++begin)
    {
        *(str1+begin)= *(str+end);
        
        --end;
    }
    
    *(str1+begin) = '\0';
    
    //printf("%s", str1);
    return str1;
}

int main() {
	//code
	
	char str[100]="Priyatosh";
	
//	reverse(str);
	printf("The reverse string is %s\n",reverse(str));
	return 0;
}
