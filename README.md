# helloWorld
全局变量用l前缀
参数变量用_前缀
a变量的附属变量
/*
TASK:beads
PROB:22920179
LANG:C++
*/
#include <stdio.h>
#include <iostream>
//从第一个字符开始



char lch[1000] = 0;
int ln;
int main()
{
    int i,a[1000]=0;
    FILE* pFile1 = fopen("beads.in","r");
    FILE* pFile2 = fopen("beads.out","w");
    scanf(pFile1,"%d\n",&n);
    scanf(pFile1,"%s",ch);
    for(i=0; i<n; i++)
    {
        a[i] = getN(i);
    }
    fprintf(pFile2,"%d",maxN(a));
    fclose(pFile1);fclose(pFile2);
    return 0;
}
int getN(int _i)
{
    int i=_i,j,a=0,b=0,an,bn;
    if(_i=0) j=ln-1; else j=i-1;
    while(ch[++i] == a)
        a++;
        
        
    if()



}
