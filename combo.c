/*
ID:22920179
LANG:C
TASK:combo
*/
#include <stdio.h>
#include <stdlib.h>
//定义一个数组，把结果放在这里面
//因为是圆环形状的，所以能直接到最后
//根据数据要考虑其极端
int a[1000][3],na=0;
int n;
int k1[3],k2[3];
void KeyBreak(int ck[])//密码破解
{//设置三重循环
    int i,j,k;
    for(i=-2;i<=2;i++)
    {
        while(ck[0]+i < 1)
            ck[0] += n;
        while(ck[0]+i > n)
            ck[0] -= n;
        for(j=-2;j<=2;j++)
        {
            while(ck[1]+j < 1)
                ck[1] += n;
            while(ck[1]+j > n)
                ck[1] -= n;
            for(k=-2;k<=2;k++)
            {
                while(ck[2]+k < 1)
                    ck[2] += n;
                while(ck[2]+k > n)
                    ck[2] -= n;
                a[na][0] = ck[0]+i;
                a[na][1] = ck[1]+j;
                a[na][2] = ck[2]+k;
                na++;
            }
        }
    }

}

int CheckRepeat()//查重
{
    int i,j,b;
    b=na;
    printf("b:%d\n",b);
    for(i=0; i<na; i++)
    {
        for(j=i; j<na; j++)
        {
            if(j==i) continue;
            if(a[i][0]==a[j][0] && a[i][1]==a[j][1] && a[i][2]==a[j][2])
            {
                if(a[j][0]!=0 && a[j][1]!=0 && a[j][2]!=0)
                {
                    a[j][0] = 0;
                    a[j][1] = 0;
                    a[j][2] = 0;
                    b--;
                }

            }
        }
    }
    return b;
}
int main()
{
    int i;
    FILE *pFile1 = fopen("combo.in", "r");
    FILE *pFile2 = fopen("combo.out", "w");
    fscanf(pFile1,"%d",&n);
    for(i=0; i<3; i++)
        fscanf(pFile1,"%d",&k1[i]);
    for(i=0; i<3; i++)
        fscanf(pFile1,"%d",&k2[i]);
    KeyBreak(k1);
    KeyBreak(k2);
    i = CheckRepeat();
    fprintf(pFile2,"%d\n",i);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

