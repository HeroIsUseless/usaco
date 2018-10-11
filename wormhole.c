/*
ID:22920179
LANG:C
TASK:wormhole
*/
#include <stdio.h>
#include <stdlib.h>
struct Pos
{
    int x,y;
    int next;
    int partner;
};
int n;
struct Pos pos[100];
int isCycle()
{
    int i, j, p;
    for(i=1; i<=n; i++)
    {
        p = i;
        for(j=1; j<=n; j++)
        {
            p = pos[pos[p].partner].next;
        }
        if (p != 0) return 1;
    }
    return 0;
}
int process()
{
    int i, j, total=0;
    for(i=1; i<=n; i++)
    {
        if(pos[i].partner == 0)
            break;
    }

    if(i > n)
        if(isCycle()) return 1;
        else return 0;

    for(j=i+1; j<=n; j++)
    {
        if(pos[j].partner == 0)
        {
            pos[i].partner = j;
            pos[j].partner = i;
            total += process();
            pos[i].partner = 0;
            pos[j].partner = 0;

        }
    }
    return total;
}
int main()
{
    int i, j;
    FILE *pFile1 = fopen("wormhole.in", "r");
    FILE *pFile2 = fopen("wormhole.out", "w");
    fscanf(pFile1,"%d",&n);
    printf("%d\n",n);
    for(i=1; i<=n; i++)
    {
        fscanf(pFile1,"%d %d",&pos[i].x,&pos[i].y);
        pos[i].partner = 0;
        pos[i].next = 0;
        printf("%d %d\n",pos[i].x,pos[i].y);
    }
    for(i=1; i<=n; i++)//½øÐÐnextÅä¶Ô
    {
        for(j=1; j<=n; j++)
        {
            if(pos[i].y == pos[j].y && pos[i].x < pos[j].x)
            {
                if(pos[i].next == 0)
                    pos[i].next = j;
                else
                {
                    if(pos[pos[i].next].x-pos[i].x > pos[j].x-pos[i].x)
                        pos[i].next = j;
                }
            }
        }
    }
    i = process();
    fprintf(pFile2,"%d\n",i);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

