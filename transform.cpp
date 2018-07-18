/*
PROB:transform
LANG:C++
NAME:22920179

*/


#include <stdio.h>

int ln = 0;
char ch1[100][100]={{0}},ch2[100][100]={{0}},ch3[100][100],ch4[100][100];
FILE *pFile1=fopen("transform.in","r");
FILE *pFile2=fopen("transform.out","w");

bool comp();
void fun1();
void fun2();
void fun3();
void fun4();
void fun51();
void fun52();
void fun53();
void fun6();

int main()
{
    fscanf(pFile1,"%d\n",&ln);
    for(int i=0; i<ln; i++)
    {
        for(int j=0; j<ln; j++)
        {
            fscanf(pFile1,"%c",&ch1[i][j]);
        }
        fscanf(pFile1,"\n");
    }
    for(int i=0; i<ln; i++)
    {
        for(int j=0; j<ln; j++)
        {
            fscanf(pFile1,"%c",&ch2[i][j]);
        }
        fscanf(pFile1,"\n");
    }

    fun1();
    if(comp())
    {
        fprintf(pFile2,"1\n");
        return 0;
    }

    fun2();
    if(comp())
    {
        fprintf(pFile2,"2\n");
        return 0;
    }

    fun3();
    if(comp())
    {
        fprintf(pFile2,"3\n");
        return 0;
    }

    fun4();
    if(comp())
    {
        fprintf(pFile2,"4\n");
        return 0;
    }

    fun51();
    if(comp())
    {
        fprintf(pFile2,"5\n");
        return 0;
    }
    fun52();
    if(comp())
    {
        fprintf(pFile2,"5\n");
        return 0;
    }
    fun53();
    if(comp())
    {
        fprintf(pFile2,"5\n");
        return 0;
    }

    fun6();
    if(comp())
    {
        fprintf(pFile2,"6\n");
        return 0;
    }

    fprintf(pFile2,"7\n");
    fclose(pFile1);fclose(pFile2);
    return 0;
}

bool comp()
{
    bool bol = true;;
    for(int i=0; i<ln; i++)
    {
        for(int j=0; j<ln; j++)
        {
            if(ch3[i][j]!=ch2[i][j])
            {
                bol=false;
            }
        }
    }
    return bol;
}
void fun1()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[j][ln-i-1] = ch1[i][j];
}
void fun2()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[ln-i-1][ln-j-1] = ch1[i][j];
}
void fun3()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[ln-j-1][i] = ch1[i][j];
}
void fun4()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[i][ln-j-1] = ch1[i][j];
}
void fun51()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch4[i][ln-j-1] = ch1[i][j];

    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[j][ln-i-1] = ch4[i][j];
}
void fun52()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch4[i][ln-j-1] = ch1[i][j];

    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[ln-i-1][ln-j-1] = ch4[i][j];
}
void fun53()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch4[i][ln-j-1] = ch1[i][j];

    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[ln-j-1][i] = ch4[i][j];
}
void fun6()
{
    for(int i=0; i<ln; i++)
        for(int j=0; j<ln; j++)
            ch3[i][j] = ch1[i][j];
}

































