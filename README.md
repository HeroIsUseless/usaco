# helloWorld
全局变量用l前缀
参数变量用_前缀
a变量的附属变量以a开头
要有勤于注释调试的习惯
多用printf调试，后面加///////////////////////////
在输出用//???????????????????????????????/结尾
模板：///////////////////////////////////////////
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
    fclose(pFile1);fclose(pFile2);
    return 0;
}
//////////////////////////////////////////////////
