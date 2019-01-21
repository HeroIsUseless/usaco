/*
ID:22920179
LANG:C++
TASK:milk3
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c;
bool vis[25][25],  s[25];//代表的是结果
void dfs(int aa,int cc)//这个是一个深搜
{//第一个是a，第二个是c
    if(vis[aa][cc]==1)//这个是什么？
    return ;//说明是一个截断，表明已经判断过了
    vis[aa][cc]=1;//这个是一个flag，的确没有什么好的
    //表示方法

    if(aa==0)
        s[cc]=1;//这个是res的数组
    //说是把所有的aa为0的时候存储的，非常好了
    //深搜也只是把所有情况遍历一遍
    //下面也只是每一步了
    int bb=c-aa-cc;
    if(aa!=0&&bb!=b)
    dfs(aa-min(aa,b-bb),cc);//a->b
    if(aa!=0&&cc!=c)
    dfs(aa-min(aa,c-cc),cc+min(aa,c-cc));//a->c
    if(bb!=0&&aa!=a)
    dfs(aa+min(bb,a-aa),cc);//b->a
    if(bb!=0&&cc!=c)
    dfs(aa,cc+min(bb,c-cc));//b->c
    if(cc!=0&&aa!=a)
    dfs(aa+min(cc,a-aa),cc-min(cc,a-aa));//c->a
    if(cc!=0&&bb!=b)
    dfs(aa,cc-min(cc,b-bb));//c->b 
}
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    dfs(0,c); //就这么一个函数
    for(int i=0;i<=c;i++)
    if(s[i]==1)//这个是最后的输出了，看来是输出
    printf("%d ",i);
    return 0;
} 
