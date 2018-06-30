#include <stdio.h>
#include <stdlib.h>
int bulb[1500]={0};
int main()
{
    int i,j,n,k;
    scanf("%d %d",&n,&k);
    for(i=1; i<=k; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(j%i == 0)
                if(bulb[j] == 0) bulb[j] = 1;
                    else bulb[j] = 0;
        }
    }
    for(i=1; i<=n; i++)
        if(bulb[i])
            printf("%d ",i);
    return 0;
}
