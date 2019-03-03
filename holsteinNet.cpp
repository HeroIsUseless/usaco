/*
ID:22920179
PROB:holstein
LANG:C++
*/
#include<iostream>
#include<cstdio>
using namespace std;

int v,g,t;
int m=100;
int w[30],s[20][30],f[20],r[20];
void work(int d){
    int i,c=0;
    if(d>g+1) return; // g代表饲料数量，s代表数量
    int b=1; // 然后是一个b，是一个bool变量，代表维他命都大于0？
    for(i=1;i<=v;i++) // w代表vitamin，v代表它的数量
        if(w[i]>0){ // 他们都是从1开始的，它绝对会大于0啊？
            b=0;
            break;
        }

    if(b==1) { // 如果他们都是小于等于0的？
        if(m>t){ // m初始值是100，它代表的是最终的结果
            m=t; // 也对啊
            for(i=1;i<=g;i++) // r是代表结果了
                if(f[i])
                    r[++c]=i;
        }
        return;   // 然后返回
    }

    f[d]=1; // 下面的话就是一些递归，d是一个参数。。。
    t++; // t是一个计数了没错
    for(i=1;i<=v;i++)
        w[i]-=s[d][i]; // 哦，这个比较聪明了，真不错
    work(d+1); // 然后是第二位第三位的

    f[d]=0; // f代表一个标志吧
    t--;
    for(i=1;i<=v;i++)
        w[i]+=s[d][i];
    work(d+1); 

}
int main(){
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    cin>>v;
    for(int i=1;i<=v;i++)
        cin>>w[i];
    cin>>g;
    for(int i=1;i<=g;i++)
        for(int j=1;j<=v;j++)
            cin>>s[i][j];

    work(1); // 最一开始传入的是1，这个是第一位吧

    cout<<m<<" ";
    for(int i=1;i<=m;i++)
        cout<<r[i]<<(i==m?"\n":" ");      
}
