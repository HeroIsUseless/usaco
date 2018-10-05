/*
ID:22920179
LANG:C
TASK:barn1
*/
#include <stdio.h>
#include <stdlib.h>
//因为添加木板可能将空房间一并添加
//方法是第一个是房间号，第二是房间后空长度，将空长度排序完毕后，
//因为用m个木板，所以挑m-1个空，即m-1个前置房间，有了这个
//前置房间后，直接减就可以了
int main()
{
    int i, j, k, t, m, s, c;//木板最大的数目，牛棚的总数，牛的数目
    int a[200][2];//牛所在牛棚的编号+一个标记，表示此牛棚后空牛棚长度
    FILE *pFile1 = fopen("barn1.in", "r");
    FILE *pFile2 = fopen("barn1.out", "w");
    fscanf(pFile1,"%d %d %d", &m, &s, &c);
    printf("%d %d %d\n", m, s, c);
    for(i=0; i<c; i++)
    {
        fscanf(pFile1,"%d", &a[i][0]);
    }

    for(i=0; i<c; i++)//牛棚编号从小到大排一次
    {
        k = i;
        for(j=i; j<c; j++)
        {
            if(a[k][0] > a[j][0])
                k = j;
        }
        t=a[i][0]; a[i][0]=a[k][0]; a[k][0]=t;
    }
    for(i=0; i<c-1; i++)
    {
        a[i][1] = a[i+1][0] - a[i][0] -1;
    }
    a[c-1][1] = 0;

    s = s-(a[0][0]-1)-(s-a[c-1][0]-1)-1;

    for(i=0; i<c; i++)//用空房间长度重新排一次
    {
        k = i;
        for(j=i; j<c; j++)
        {
            if(a[k][1] < a[j][1])
                k = j;
        }
        t=a[i][0]; a[i][0]=a[k][0]; a[k][0]=t;
        t=a[i][1]; a[i][1]=a[k][1]; a[k][1]=t;
    }

    if(m>c) m=c;
    for(i=0; i<m-1; i++)
    {
        s -= a[i][1];
    }
    fprintf(pFile2,"%d\n", s);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

