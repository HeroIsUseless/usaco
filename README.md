# helloWorld
全局变量用l前缀
参数变量用_前缀
/*
TASK:beads
PROB:22920179
LANG:C++
*/
#include <stdio.h>
#include <iostream>
//从第一个字符开始



char ch[1000] = 0;
int n;
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
int getN(int i)
{
    int b=1,j=1,k=i,a=ch[i],c;
    while(ch[++k] == a)
        j++;
    if()



}
