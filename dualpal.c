/*
ID:22920179
LANG:C
TASK:dualpal
*/
#include <stdio.h>

int isPalindromes(int  ca)
{

    int i,j, k=0, t;
    int  a[100],n=0;
    for(i=2; i<=10; i++)
    {
        n=0; t=ca;
        while(t > 0)
        {
            a[n++] = t%i;
            t /= i;
        }

        if(a[n-1] != 0)
        {
            t = 1;//此时作为布尔变量
            for(j=0; j<n/2; j++)
            {
                if(a[j] != a[n-1-j])
                    t = 0;
            }
            k += t;
        }
    }
    if(k >= 2)
        return 1;
    else
        return 0;
}
int main()
{
    int i=0, n, s;
    FILE *pFile1 = fopen("dualpal.in", "r");
    FILE *pFile2 = fopen("dualpal.out", "w");
    fscanf(pFile1,"%d %d", &n, &s);
    while(i != n)
    {
        if(isPalindromes(++s))
        {
            fprintf(pFile2,"%d\n", s);
            i++;
        }
    }
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

