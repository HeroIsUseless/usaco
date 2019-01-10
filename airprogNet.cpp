
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
        }
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
 
        sort(num, num + numCnt);
        int a = num[0], b, pos;
        int cnt = 0;
        int bigB = (num[numCnt - 1] - num[0]) / (n - 1);
        for (b = 1; b <= bigB; ++b){
                for (int j = 0; j < numCnt; ++j){
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
