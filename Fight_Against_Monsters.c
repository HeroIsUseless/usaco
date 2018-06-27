#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp,a=0,i,j,k,n,HP_[100000]={0},ATK_[100000]={0};
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&HP_[i],&ATK_[i]);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=1; j<n; j++)
    {
            if(ATK_[i] < ATK_[j])
            {
                temp = ATK_[i];
                ATK_[i] = ATK_[j];
                ATK_[j] = temp;

                temp = HP_[i];
                HP_[i] = HP_[j];
                HP_[j] = temp;
            }
    }
    }

    for(i=0; i<n; i++)
    {
        j=1;
        while(HP_[i]>0)
        {
            for(k=i; k<n; k++)
                a += ATK_[k];
            HP_[i]-=j;
            j+=1;
        }
    }


    printf("%d",a);
    return 0;
}
