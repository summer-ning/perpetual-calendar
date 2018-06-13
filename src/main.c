#include <stdio.h>

#include "calendar.h"
#include "mytypes.h"


int main(int argc, char *argv[])
{
   int date[6][7];
   int year, month, day;
   int ret;
// if(argc != 3)
// {
//    printf("parameter error\n");
//    printf("for example:\n");
//    printf("./perpetual_calendar 2018 6\n");
//    return -1;
// }
   printf("please input the year and month:\n");
   scanf("%d %d",&year,&month);
   
   if (month <= 0 || month > 12)
   {
      printf("month is invalid\n");
      return -1;
   }
   
   ret = Achieve_Calendar(date,year,month);
   if(ret == false)
   {
      printf("Achieve_Calendar err\n");
      return -1;
   }
   
   Print_Calendar(date,year,month);
   
   return 0;
}

