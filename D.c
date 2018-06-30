#include <stdio.h>
#include <stdlib.h>
int n,m,a[250]={0},b[250]={0};
float goal = 0.0;

int main()
{
    int i;
    scanf("%d %d",&n ,&m);
    for(i=0; i<n-1; i++) scanf("%d ",&a[i]);
    scanf("%d",&a[n-1]);
    for(i=0; i<n; i++)
        goal+=a[i]*1.0/n;
    printf("%.2f",goal);
    return 0;
}
