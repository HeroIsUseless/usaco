/*
ID:22920179
PROB:frac1
LANG:C++
*/
#include "iostream"
#include "cstdio"
using namespace std;
long n;
FILE *pFile1, *pFile2;
void dfs(long x1,long y1,long x2,long y2){
    if(y1+y2<=n){
        dfs(x1,y1,x1+x2,y1+y2);
        fprintf(pFile2, "%d/%d\n",x1+x2,y1+y2); // 通过顺序直接输出
        dfs(x1+x2,y1+y2,x2,y2);
    }
}

int main(){
    pFile1 = fopen("frac1.in","r");
    pFile2 = fopen("frac1.out", "w");
    fscanf(pFile1, "%d", &n);
    fprintf(pFile2, "0/1\n");
    dfs(0, 1, 1, 1);
    fprintf(pFile2, "1/1\n");
    return 0;
}
