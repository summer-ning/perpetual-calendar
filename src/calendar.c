#include <stdio.h>

#include "calendar.h"
#include "mytypes.h"


int leap_days[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int commond_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};


int Is_Leap_Year(int year)
{
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
      return true;
   else 
      return false;
}

int Is_Valid_Date(int year, int month, int day)
{
   if (year <= 0 || month > 12 || month <= 0 || day <= 0)
   {
      return false;
   }
   
   if (true == Is_Leap_Year(year))
   {
      if(leap_days[month-1] < day)
         return false;
   }
   else
   {
      if(commond_days[month-1] < day)
         return false;
   }
   
   return true;
}

int Get_Days_InMonth(int year, int month)
{
   if (year <= 0 || month > 12 || month <= 0)
   {
      return false;
   }
   if (true == Is_Leap_Year(year))
      return leap_days[month-1];
   else
      return commond_days[month-1];
}

/**
  * @brief  Calculation Week 
  * @note   算法：基姆拉尔森计算公式
  * @param  
  * @retval 0-6; 0 is Monday,6 is Sunday
  */
int Calculation_Week(int year, int month, int day)
{
   int ret;
   int week;
   ret = Is_Valid_Date(year, month, day);
   if (-1 == ret)
   {
      return -1;
   }
   
   if(month <= 2)
   {
      month += 12;
      year--;
   }
   
   week = (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400) % 7;
   
   return week;
}

int Achieve_Calendar(int date[6][7], int year, int month)
{
   int week,days_in_month;
   int i,j;
   int day = 1;
   
   week = Calculation_Week(year, month, 1);
   if (-1 == week)
      return false;
   week = (week + 1) % 7;
   days_in_month = Get_Days_InMonth(year,month);
   if (false == days_in_month)
      return false;
      
   for(i = 0; i < week; i++)
   {
      date[0][i] = 0;
   }
   for(; i < 7; i++)
   {
      date[0][i] = day++;
   }
   
   for(i = 1; i < 6; i++)
   {
      for(j = 0; j < 7; j++)
      {
         if (day <= days_in_month)
            date[i][j] = day++;
         else
            date[i][j] = 0;
      }
   }
   
   return true;
}

void Print_Calendar(int date[6][7], int year, int month)
{
   int i,j;
   
   printf("   %d/%d\n",month,year);
   printf("SUN  MON  TUE  WEN  THU  FRI  STA\n");
   
   for(i = 0; i < 6; i++)
   {
      for(j = 0; j < 7; j++)
      {
         if (0 != date[i][j])
            printf("%2d   ",date[i][j]);
         else
            printf("     ");
      }
      printf("\n");
   }
}