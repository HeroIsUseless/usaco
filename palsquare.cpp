/*
ID: 22920179
LANG: C++
TASK: palsquare
*/
#include <stdio.h>
#include <string.h>
int IsHuiWen(char ch[])
{
    int n=0;
    for(int i=0; ch[i]!=0; i++) n++;
    for(int i=0; i <= n/2; i++)
    {
        if(ch[i] != ch[n-1-i])
            return 0;
    }
    return 1;
}
void itoa(int a, char* str, int n)//将数字a转换成n进制的数字后放到字符串str中
{//进制是从2到20，a是十进制的，通过除以进制，余下几，就添上什么字母
    int t;//这个函数还要重新到各个
    int strn = 0;
    while(a > 0)
    {
        t = a%n;
        a /= n;
        switch(t)
        {
            case 0: str[strn]='0';strn++;break;
            case 1: str[strn]='1';strn++;break;
            case 2: str[strn]='2';strn++;break;
            case 3: str[strn]='3';strn++;break;
            case 4: str[strn]='4';strn++;break;
            case 5: str[strn]='5';strn++;break;
            case 6: str[strn]='6';strn++;break;
            case 7: str[strn]='7';strn++;break;
            case 8: str[strn]='8';strn++;break;
            case 9: str[strn]='9';strn++;break;
            case 10: str[strn]='A';strn++;break;
            case 11: str[strn]='B';strn++;break;
            case 12: str[strn]='C';strn++;break;
            case 13: str[strn]='D';strn++;break;
            case 14: str[strn]='E';strn++;break;
            case 15: str[strn]='F';strn++;break;
            case 16: str[strn]='G';strn++;break;
            case 17: str[strn]='H';strn++;break;
            case 18: str[strn]='I';strn++;break;
            case 19: str[strn]='J';strn++;break;
        }
    }
    for(int i=0; i<strn/2; i++)
    {
        char temp = str[i];
        str[i] = str[strn-1-i];
        str[strn-1-i] = temp;
    }
    str[strn] = 0;
}
int main()
{
    char ch[500];
    char ch0[500];
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=300; i++)
    {
        itoa(i*i, ch, n);
        itoa(i, ch0, n);
        if(IsHuiWen(ch))
            printf("%s %s\n", ch0, ch);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
