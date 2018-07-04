/*
TASK:friday
PROB:22920179
LANG:C++
*/
#include <stdio.h>

int lmonth[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};//记住从1开始
int get13WeekDay(int m);
     FILE* pFile1 = fopen("friday.in","r");
     FILE* pFile2 = fopen("friday.out","w");

int main()
{
    int m,n,weekday[8] = {0};//记住从1开始
     fscanf(pFile1,"%d",&n);
     m = 12*n;
     for(int i=1; i<=m; i++)
     {
         for(int j=1; j<=7; j++)
         {
             if(j == get13WeekDay(i))
                weekday[j]++;
         }
     }
     for(int i=1; i<=6; i++)
     {
         fprintf(pFile2,"%d ",weekday[i]);
     }
    fprintf(pFile2,"%d\n",weekday[7]);
    fclose(pFile1);fclose(pFile2);
    return 0;
}
int get13WeekDay(int m)
{
    int year = m/12, month = m%12, day=0;
    for(int i=0; i<year; i++)
    {
        if(((1990+i)%100!=0&&(1990+i)/4==0)||((1990+i)%400==0))
            day += 366;
        else
            day += 365;
    }

    if(((1990+year)%100!=0&&(1990+year)/4==0)||((1990+year)%400==0))
        lmonth[2] = 29;
    else
        lmonth[2] = 28;
     for(int i=1; i<month; i++)
        day += lmonth[i];
     day += 13;

    if(month==0)
    {
        day -= (31-13);
    }
    //fprintf(pFile2,"%d\n",day);
    day = day%7 +1;
    return day;
 }

