
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cstdlib"
#include "set"
using namespace std;
int a, b, c; 
int flag[25][25];
std::set<int> res;
void dfs(int ca, int cc){
    if(flag[ca][cc] == 1) return;
    else flag[ca][cc] = 1;

    if(ca == 0) res.insert(cc);
    int cb = c - cc - ca;
    //a->b
    if(ca != 0) dfs(ca-min(ca, b-cb), cc);
    //a->c
    if(ca != 0) dfs(ca-(c-cc), );//对呀 
    //b->a
    //b->c

    
    //c->a
    //c->b
}
//输出这么个东西
//当桶A为空的时候，倒的顺序会有不同
//明显会用到递归的方法
//但是怎样才算个头呢？池子里有这个组合说明到头了
//先c->a,b a->b,c c->a,b 这么来一共六次递归呢
//是深度搜索，就是这样，不做了
int main(){
    FILE *pFile1 = fopen("milk3.in", "r");
    FILE *pFile2 = fopen("milk3.out", "w");
    fscanf(pFile1, "%d%d%d", &a, &b, &c);
    m = c;
    dfs();
    for(auto var : res){
        cout << var <<" ";
    }
    fclose(pFile1); fclose(pFile2);
    return 0;
}