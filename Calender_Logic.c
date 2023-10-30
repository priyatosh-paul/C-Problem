#include "Calender_Header.h"

void get_days(int month,int flag,print message)
{
	if(month<1 || month>12)
		message("\n Enter valid month!!!");
	else if(month==2 && flag==0)
		message("\n Number of days are : 28");		
	else if(month==2 && flag==1)
		message("\n Number of days are : 29");		
	else if((month==4 || month==6 || month==9 || month==11))
		message("\n Number of days are : 30");
	else
		message("\n Number of days are : 31");
	if(flag==1)
		message("\n This year is LEAP year..");
	else
		message("\n This year is NOT LEAP year..");
}

int find_leap_year(int year,print message)	
{
	if(year%4==0 && year%400==0)	
		return 1;
	else if(year%4==0 && year%100==0)
		return 0;
	else if(year%4==0 && year%100!=0)
		return 1;
	else
		return 0;

/*	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
			{
				printf("\n This year is LEAP year..");
				return;
			}
			else
			{
				printf("\n This year is NOT LEAP year..");
				return;
			}
		}
		else
			printf("\n This year is LEAP year..");
	}
	else
		printf("\n This year is NOT LEAP year..");		*/
}
