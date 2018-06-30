#include <stdio.h>

int main()
{
    int i,j,temp,t[3];
    scanf("%d %d %d",&t[0],&t[1],&t[2]);
    for(i=0; i<3; i++)
    {
            temp = t[i]/3;
        for(j=0; j<3; j++)
        {
            if(i == j)
                t[j] = temp;
            else
                t[j] += temp;
        }
    }
    printf("%d %d %d",t[0],t[1],t[2]);
    return 0;
}
