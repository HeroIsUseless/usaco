
/*
ID:22920179
LANG:C++
TASK:ariprog
*/
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
/*ifstream fin("ariprog.in");
ofstream fout("ariprog.out");*/
 
int n, m;
bool exist[126000];
int num[126000];
 
bool check(int a, int b)
{
        for (int i = 0; i < n; ++i){
                if (!exist[a]) return 0;
                a += b;
        }//一直进行累加，判断它是否在二项式里，如果都存在才行
        return 1;
}
 
int main()
{
        freopen("ariprog.in","r",stdin);
        freopen("ariprog.out","w",stdout);
        //while (scanf("%d%d", &n, &m) != EOF){
        //cin >> n >> m;
        scanf("%d%d", &n, &m);
        int numCnt = 0;//这个是计数
        for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j) {
                if (!exist[i * i + j * j]){//存在判定，一个平方的作用
                //这个是如果为0，堆分配会为0
                        num[numCnt++] = i * i + j * j;//并且进行计数
                        exist[i * i + j * j] = 1;//这个是flag
                }
        }
    //现在是把m的从i到j的所有的平方存进去了
        sort(num, num + numCnt);//现在进行排序，从头到尾进行 排序
        //下面才开始真正的计算
        int b, pos;
        int cnt = 0;//对，就是这样
        int bigB = (num[numCnt - 1] - num[0]) / (n - 1);//最大的减去最小的，得出的数在整除
        //n-1，这个n是等差数列的值减去一个1
        //不知道这个数字是什么
        for (b = 1; b <= bigB; ++b){//对b进行计算，b代表的是一个，额，距离之类的东西
                for (int j = 0; j < numCnt; ++j){//又进行一次遍历
                        if (check(num[j], b)) ++cnt, printf("%d %d\n", num[j], b);
                        if (num[j] + (n - 1) * b > num[numCnt - 1]) break;
                }
        }
        if (cnt == 0) puts("NONE");
        //}//fout << "NONE" << endl;//fout << "NONE" << endl;
        /*fin.close();
        fout.close();*/
 
        return 0;
}
