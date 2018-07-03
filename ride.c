/*
{
ID:22920179
PROG:ride
LANG:C
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* pFile;
    FILE* pFile2;
    int i,s1,s2,a1=1,a2=1;
    char string1[100] = {0};
    char string2[100] = {0};
    pFile = fopen("ride.in","r");
    pFile2 = fopen("ride.out","w");
    fgets(string1,90,pFile);
    fgets(string2,90,pFile);
    fclose(pFile);
    s1 = strlen(string1)-1;
    s2 = strlen(string2);
    //fprintf(pFile2,"%d\n%d\n",s1,s2);
    //fprintf(pFile2,"%s\n",string1);
    //fprintf(pFile2,"%s\n",string2);
    for(i=0; i<s1; i++)
    {
        a1*=(string1[i]-64);
    }
    for(i=0; i<s2; i++)
    {
        a2*=(string2[i]-64);
    }
    a1=a1%47;
    a2=a2%47;
    if(a1==a2)
        fputs("GO",pFile2);
    else
        fputs("STAY",pFile2);
    fclose(pFile2);
    return 0;
}
