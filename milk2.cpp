/*
TASK:
PROB:22920179
LANG:C++
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

int ln;
FILE *pFile1 = fopen(".in","r");
FILE *pFile2 = fopen(".out","w");

int main()
{
    int time[1000000]={0},beginTime[5500]={0},endTime[5500]={0};
    fscanf(pFile1,"%d\n",&ln);
    for(int i=1; i<=ln; i++)
        fscanf(pFile1,"%d %d\n",beginTime[i],endTime[i]);
    for(int i=1; i<=ln; i++)
        for(int j=beginTime[i]; j<=endTime[i]; j++)
        {
            time[j] += 1;
        }
    fclose(pFile1);fclose(pFile2);
    return 0;
}
