/*
ID:22920179
LANG:C++
TASK:milk2


*/

#include <iostream>
#include <stdio.h>
using namespace std;
FILE *pFile1 = fopen("milk2.in","r");
FILE *pFile2 = fopen("milk2.out","w");

int main()
{
    int i, j, n, temp,bT[5500],eT[5500];
    fscanf(pFile1,"%d\n",&n);
    for(i=0; i<n; i++)
    {
        fscanf(pFile1,"%d %d\n",&bT[i], &eT[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if(bT[i]>bT[j])
            {
                temp = bT[i]; bT[i] = bT[j]; bT[j] = temp;
                temp = eT[i]; eT[i] = eT[j]; eT[j] = temp;
            }
        }
    }
//     for(i=0; i<n; i++)
//    {
//        fprintf(pFile2,"%d %d\n",bT[i], eT[i]);
//    }
    for(i=0; i<n-1; i++)
    {
        if(eT[i]>=bT[i+1])
        {
            bT[i+1] = bT[i];
            eT[i] = eT[i]>eT[i+1]?eT[i]:eT[i+1];
            eT[i+1] = eT[i];
        }
    }

//    for(i=0; i<n; i++)
//    {
//        fprintf(pFile2,"->%d %d\n",bT[i], eT[i]);
//    }

    int a=0, b=0;
    for(i=0; i<n; i++)
    {
        if(a<eT[i]-bT[i])
        {
            a=eT[i]-bT[i];
        }
    }
    for(i=0; i<n-1; i++)
    {
        if(b<bT[i+1]-eT[i])
        {
            b=bT[i+1]-eT[i];
        }
    }

    fprintf(pFile2,"%d %d\n",a, b);
    fclose(pFile1);fclose(pFile2);
    return 0;
}
