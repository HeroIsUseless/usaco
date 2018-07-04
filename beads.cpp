/*
TASK:beads
PROB:22920179
LANG:C++
*/

#include <stdio.h>
char lbeads[1000];
int ln;
int getBN(int _i);
    FILE *pFile1=fopen("beads.in","r");
    FILE *pFile2=fopen("beads.out","w");
int main()
{
    int a=0;
    fscanf(pFile1,"%d\n",&ln);
    fscanf(pFile1,"%s",lbeads);
    //fprintf(pFile2,"ln:%d\n",ln);///////////////////////////////
    //fprintf(pFile2,"lbeads:%s\n",lbeads);///////////////////////////////
    for(int i=0; i<ln; i++)
    {
        //fprintf(pFile2,"getBN(%d):%d\n",i,getBN(i));/////////////////////
        if(a<getBN(i))
        {
            a=getBN(i);
        }
    }
    fprintf(pFile2,"%d\n",a);//???????????????????????????????????????????????????????????????????/
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}
int getBN(int _i)
{
    int i,bead,n=0;

    bead = lbeads[_i];
    if(_i == ln-1) i=0; else i = _i+1;
    while(lbeads[i] == bead || lbeads[i] == 'w')
    {
        n++;
        //fprintf(pFile2,"char->lbeads[%d]:%c\n",i,lbeads[i]);/////////////////////////////////
        if(i == ln-1) i=0; else i++;
    }

    if(_i == 0) i=ln-1; else i = _i-1;
    bead = lbeads[i];
    if(i == 0) i=ln-1; else i = i-1;
    while(lbeads[i] == bead || lbeads[i] == 'w')
    {
        n++;
        //fprintf(pFile2,"char->lbeads[%d]:%c\n",i,lbeads[i]);/////////////////////////////////
        if(i == 0) i=ln-1; else i--;
    }
    return n+2;
}
