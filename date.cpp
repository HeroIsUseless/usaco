//main是把预装好的月数打印出来

#include <stdio.h>
#include <string.h>
#define BTIME 1900;
#define ETIME 2016;
//1900年1月1日是星期一
//二维数组从0*0开始的，如果从1开始
FILE *pFile = fopen("date.out","w");
int lmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month[12][40] = {{0}};
void compMonth(int y);
int getFD(int y);
void printDate();
void printZ();

int main()//先开始一年的打印
{
    int y = ETIME;
    compMonth(y);
    printDate();
    fclose(pFile);
    return 0;
}

void compMonth(int y)
{
    if( (y%100 != 0) && (y%4==0) || (y%400 == 0))
    {
        lmonth[1] = 29;
    }
    else
    {
        lmonth[1] = 28;
    }
    int a = getFD(y);
    for(int m=1; m<=12; m++)
    {
        memset(month[m-1],0,sizeof(month[m-1]));
        for(int i=0; (i<lmonth[m-1] && (a%7+i)<35); i++)
        {
            month[m-1][a%7 + i] = i+1;//在这里也是从0开始的
        }
        a+=lmonth[m-1];
    }
}

int getFD(int y)
{
    int d = 0;
    for(int i=1990; i<y; i++)
    {
        if( (y%100 != 0) && (y%4 == 0) || (y%400 == 0))
        {
            d+=366;
        }
        else
        {
            d+=365;
        }
    }
    return (d+1)%7;
}
void printDate()
{
    for(int ym=1; ym<=3; ym++)//到这里是12个月的输出
    {
        printZ();
        for(int yd=1; yd<=5; yd++)//到这里是每个月的具体输出
        {
            for(int xm=1; xm<=4; xm++)//月份的输出与日期的输出应该是互不相关的
            {
                 for(int xd=1; xd<=7; xd++)
                {
                    printf( "%4d", month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]);
                    fprintf(pFile, "%4d", month[(ym-1)*4 + xm][(yd-1)*7 + xd]);//这样就是从1到12定位好了,也可以从1到35的输出ok,貌似这样定位也没错
                }
                if(xm==4)
                {
                    printf("\n");
                    fprintf(pFile,"\n");//没输出7天空格一下，到最后回车一下
                }
                else
                {
                    printf("   ");
                    fprintf(pFile,"    ");//没输出7天空格一下，到最后回车一下
                }
            }
        }
    }


    for(int i=0; i<12; i++)
    {
        printf("%d ",month[i][35]);
    }

}

void printZ()
{
    printf("\n");
    for(int i=1; i<=4; i++)
    {
        for(int j=0; j<=6; j++)
        {
            switch(j)
            {
            case 0:
                printf("  日");
                break;

            case 1:
                printf("  一");
                break;

            case 2:
                printf("  二");
                break;

            case 3:
                printf("  三");
                break;

            case 4:
                printf("  四");
                break;

            case 5:
                printf("  五");
                break;

            case 6:
                printf("  六   ");
                break;
            }
        }
        if(i==4) printf("\n");
    }
}






















