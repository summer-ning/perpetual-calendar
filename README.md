# perpetual-calendar
A simple code about calendar

Source use Kim larsson calculation formula to calculate week.
   Kim larsson calculation formula:
         W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
    W is the week,d is the day,m is the month, y is year.But,if date actually is January and February,the m=13 and 14,as the same time,the year--;
    for example,if date is 2004-1-10,the y=2003,m=13,d=10(2013-13-10)
    ��һ�ºͶ��¿�������һ���ʮ���º�ʮ���£����������2004-1-10����ɣ�2003-13-10�����빫ʽ���㡣
