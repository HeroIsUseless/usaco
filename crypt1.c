/*
ID:22920179
LANG:C
TASK:crypt1
*/
#include <stdio.h>
#include <stdlib.h>
int n, a[200];
int isCon(int ca)
{
    int i,k;
    while(ca > 0)
    {
        k=0;
        for(i=0; i<n; i++)
        {
            if(ca%10 == a[i])
            {
                k++;
                break;
            }
        }
        if(k == 0)
            return 0;

        ca /= 10;
    }
    return 1;
}
int main()
{
    int i, j, k=0;
    int m1, m2, m3;
    FILE *pFile1 = fopen("crypt1.in", "r");
    FILE *pFile2 = fopen("crypt1.out", "w");
    fscanf(pFile1,"%d", &n);
    for(i=0; i<n; i++)
    {
        fscanf(pFile1,"%d",&a[i]);
    }
    for(i=100; i<=999; i++)
    {
        for(j=10; j<99; j++)
        {
            if(isCon(i)&&isCon(j))
            {
                m1=i*j; m2=i*(j%10); m3=i*(j/10);
                if((m1>=1000&&m1<=9999)&&(m2>=100&&m2<=999)&&(m3>=100&&m3<=999))
                {
                    if(isCon(m1)&&isCon(m2)&&isCon(m3))
                    {
                        k++;
                    }
                }
            }
        }
    }

    fprintf(pFile2,"%d\n", k);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

