/*
PROB:namenum
NAME:22920179
LANG:C++
*/

#include <stdio.h>
FILE *pFile1 = fopen("namenum.in","r");
FILE *pFile15 = fopen("dict.txt","r");
FILE *pFile2 = fopen("namenum.out","w");
int main()
{
    char num[20]={0};
    char names[5000][15] = {{0}};
    fscanf(pFile1,"%s",num);
    for(int i=0; i<; i++)
    fscanf(pFile15,"%s\n",names[i]);

    fclose(pFile1);fclose(pFile2);
    return 0;
}
