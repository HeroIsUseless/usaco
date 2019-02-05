/*
ID:22920179
LANG:C++
TASK:milk3
*/
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
    if(flag[ca][cc] == 1) return;//标志已经探测过了
    else flag[ca][cc] = 1;

    if(ca == 0) res.insert(cc);
    int cb = c - cc - ca;
    //a->b
    if(ca>0 && cb<b) dfs(ca-min(ca, b-cb), cc);
    //a->c
    if(ca>0 && cc<c) dfs(ca-min(ca, c-cc), cc+min(ca, c-cc)); 
    //b->a
    if(cb>0 && ca<a) dfs(ca+min(cb, a-ca), cc);
    //b->c
    if(cb>0 && cc<c) dfs(ca, cc+min(cb, c-cc));
    //c->a
    if(cc>0 && ca<a) dfs(ca+min(cc, a-ca), cc-min(cc, a-ca));
    //c->b
    if(cc>0 && cb<b) dfs(ca, cc-min(cc, b-cb));
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
    dfs(0, c);
    for(auto var : res){
        cout << var <<" ";
    }
    for(auto it=res.begin(); it!=res.end(); it++){
        fprintf(pFile2, "%d%s", *it, 
            it==--res.end()?"\n":" ");
    }
    fclose(pFile1); fclose(pFile2);
    return 0;
}