#include <stdio.h>
//输入的是n年，输出的是13日在每个星期的次数，
/*通过多少年，就可以知道有多少个13日了
从第一个13日开始，判断这是第几天
用第几天判断是星期几，存入数组中
完成

 */
int get13DayWeek(int m);
int getYearDay(int n);
int getMonthDay(int n);
 int main()
 {
     int n,i,j,weekday[7] = 0;
     FILE* pFile1 = fopen("friday.in","r");
     FILE* pFile2 = fopen("friday.out","w");

     fscanf(pFile1,"%d",&n);
     m = 12*n;
     for(i=0; i<m; i++)
     {
         for(j=0; j<7; j++)
         {
             if(j+1 == get13DayWeek(i))
                weekday[i]++;
         }
     }
     for(i=0; i<7; i++)
     {
         fprintf(pFile2,"%d ",weekday[i]);
     }
     fclose(pFile1);fclose(pFile2);
     return 0;
 }
int get13DayWeek(int m)//输入第几个13日，返回星期几
 {//裁出年数与月数，单独计算相加
     int n;
     if(m%12 != 0)
         n = getYearDay(m/12) + getMonthDay(m%12, m/12+1);
     else
         n = getYearDay(m/12-1) + getMonthDay(12, m/12);
     n = n%7 + 1;
    return n;
 }
 int getYearDay(int n)
 {
     int i,a=0;
     for(i=0; i<n; i++)
        if(((1990+n)%100!=0&&(1990+n)/4==0)||((1990+n)%400==0))
            a+=366;
        else
            a+=365;
     return a;
 }
 int getMonthDay(int m, int n)
 {
     int month[20];
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
     if(((1990+n)%100!=0&&(1990+n)/4==0)||((1990+n)%400==0))

        else

     return 0;
 }






