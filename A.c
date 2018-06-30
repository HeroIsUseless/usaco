#include <stdio.h>
int getN2(int n)
{
    int a=0;
    while(n%2 == 0)
    {
        a++;
        n/=2;
    }
    return a;
}
int getN5(int n)
{
    int a=0;
    while(n%5 == 0)
    {
        a++;
        n/=5;
    }
    return a;
}
int main()
{
    int i, j, n, n2=0, n5=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        n2 += getN2(i);
        n5 += getN5(i);
    }
    if(n2 >n5) printf("%d",n5);
    else printf("%d", n2);
    return 0;
}
