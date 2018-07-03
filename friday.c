/*
TASK:friday
PROB:22920179
LANG:C
*/
#include <stdio.h>
int get13WeekDay(int m)
{
     int n;
     if(m%12 != 0)
         n = getYearDay(m/12) + getMonthDay(m%12, 1990+m/12);
     else
        if(m/12 != 0)
            n = getYearDay(m/12-1) + getMonthDay(12, 1990+m/12);
        else
            n = getMonthDay(12, 1990);
     n = n%7 + 1;
    return n;
 }
int getYearDay(int n)
 {
     int i,a=0;
     for(i=0; i<n; i++)
        if(((1990+i)%100!=0&&(1990+i)/4==0)||((1990+i)%400==0))
            a+=366;
        else
            a+=365;
     return a;
 }
 int getMonthDay(int m, int n)
 {
     int i,day=0,month[20];
     month[1]=31;
     month[2]=29;
     month[3]=31;
     month[4]=30;
     month[5]=31;
     month[6]=30;
     month[7]=31;
     month[8]=31;
     month[9]=30;
     month[10]=31;
     month[11]=30;
     month[12]=31;
     if((n%100!=0&&n/4==0)||(n%400==0))
            month[2] = 29;
        else
            month[2] = 28;
     for(i=1; i<m; i++)
        day += month[i];
     day += 13;
     return day;
 }
int main()
{
    int m,n,i,j,weekday[10] = {0};
     FILE* pFile1 = fopen("friday.in","r");
     FILE* pFile2 = fopen("friday.out","w");
     fscanf(pFile1,"%d",&n);
     m = 12*n;
     for(i=1; i<=m; i++)
     {
         for(j=1; j<=7; j++)
         {
             if(j == get13WeekDay(i))
                weekday[j]++;
         }
     }
     for(i=1; i<=6; i++)
     {
         fprintf(pFile2,"%d ",weekday[i]);
     }
    fprintf(pFile2,"%d\n",weekday[7]);
    fclose(pFile1);fclose(pFile2);
    return 0;
}
