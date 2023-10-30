#include"Program11_Header.h";

int strlen(const char* text)
{
		int result;
	 result=0;
	while(text[result]!='\0')
		result++;
	return result;
}

void strcpy(char* text1,const char* text2, MSG message)
{
	int count=0;
	while(text2[count]!='\0')
	{
		text1[count]=text2[count];
		count++;
	}
	text1[count]='\0';
}

void strcat(char* text1,const char* text2, MSG message)
{
	int length;
	int count=0; 
	length=strlen(text1);

	while(text2[count]!='\0')
	{
		text1[length]=text2[count];
		count++;
		length++;
	}
	text1[length]='\0';	
}

void strcmp(const char* text1,const char* text2, MSG message)
{
	int l1=strlen(text1);
	int l2=strlen(text2);
	if(l1==l2)
	{
		int count=0;
		int sum1=0;
		int sum2=0;
		int sum3=0;
		while(text1[count]!=0)
		{
			if(text1[count]>text2[count])
			{
				sum1++;
			}
			else if(text1[count]<text2[count])
			{
				sum2++;
			}
			count++;
		}		
		if(sum1>sum2)
		{
			message("\n String1 has higher value than string2..");
			message("\n Hence Return = -1 \n");
			return;
		}
		else if(sum2>sum1)
		{
			message("\n String2 has higher value than string1..");
			message("\n Hence Return = 1 \n");
			return;
		}
		else
		{
			message("\n String1 and String2 are Exactly SAME..\n");
			message("\n Hence return = 0 \n");
			return;
		}				
	}
	else
		message("\n Enter String of SAME length..\n");
}

void strlwr(char* text)
{
	int count=0;
	while(text[count]!=0)
	{
		if(text[count]<91 && text[count]>65)
			text[count]=text[count]+32;
		count++;
	}
}

void strcmpi(const char* text1,const char* text2, MSG message)
{
	int l1=strlen(text1);
	int l2=strlen(text2);
	if(l1==l2)
	{
		int count=0;
		int flag=0;
		while(text1[count]!=0)
		{
			if(text1[count]==text2[count])			
				flag=1;
			else
				flag=0;
			count++;
		}
		if(flag==1)		
			message("\n String1 and String2 are SAME but not exactly..\n");
		else
			message("\n String1 and String2 are NOT SAME..\n");	
	}
	else
		message("\n Enter String of SAME length..\n");
}
