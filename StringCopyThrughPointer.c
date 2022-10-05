#include <stdio.h>

// char * reverse(char *str)

// {
//     char *str1;
// 	int l=0;
// 	int end;
// 	int begin;
// 	while( str[l] != '\0')
// 	{
// 	    ++l;
	   
// 	}
	
// 	end = l -1;
    	
//     for (begin=0; begin <= l; ++begin)
//     {
//         str1[begin]= str[end];
        
//         --end;
//     }
    
//     str1[begin] = '\0';
    
//     //printf("%s", str1);
//     return str1;
// }

char* string_copy(char * str)
{
    int l=0,i=0;
    char *str1=NULL;
    while(*(str+l) != '\0')
    {
        
        *(str1+i)=*(str+l);
        printf("%c\n", *(str+l));
        
        ++l;
        ++i;
    }
    
    //for(i=0; i)
    *(str1+i) = '\0';
    printf("%s\n", str1);
    return str1;
}

int main() {
	//code
	
	char str[100]="Priyatosh Paul";
	//char str1[100];
//	reverse(str);
	printf("The new string is %s\n",string_copy(str));
	return 0;
}
