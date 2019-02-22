# f**k you USACO

模板：
```
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
//函数作用写在这里-函数思路写在这里
int main()//函数参数声明写在这里
{//函数返回值声明写在这里
    fclose(pFile1);fclose(pFile2);
    return 0;
}
```
# 求解回文数字
采用将数字倒转过来然后进行判断就可以了，或者转成字符串然后判断，这个更麻烦
求一定范围内的回文数字的话，用下面的这段代码，是最简单的了。
从1-10000，先进行数字倒转，然后偶数实现，然后奇数实现，就是这样。

