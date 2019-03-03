/*
ID:22920179
PROB:holstein
LANG:C++
*/
#include "iostream"
#include "cstdio"
using namespace std;
int vitam[30], vi_n; // 维他命
int feed[20][30], fe_n; // 饲料
int test[20], te_n; // 作为中间测试结果
int te_ap[30]; // 用来优化的一个数组，这么点的优化完全不行的
int res[20], re_n = 1000; // 作为最终结果
void Add(int ci){
    for(int i=0; i<vi_n; i++)
        te_ap[i] += feed[ci][i];
}
void Sub(int ci){
    for(int i=0; i<vi_n; i++)
        te_ap[i] -= feed[ci][i];
}
bool Compare(){ 
    bool result = true;
    for(int i=0; i<vi_n; i++)
        if(te_ap[i] < vitam[i]){
            result = false;
            break;
        }
    return result;
}
void dfs(){ 
    if(te_n >= re_n) return;
    if(Compare()){ 
        if(te_n<re_n){
            re_n = te_n;
            for(int i=0; i<re_n; i++)
                res[i] = test[i];
        }
        return; // 既然这里是可以的，那么下面都是大于它的，也没有这个必要了
    } 
    for(int i=0; i<fe_n; i++){
        int j; for(j=0; j<te_n; j++) // 不能重复填入
            if(test[j] == i)
                break;
        if(j == te_n){
            test[te_n++] = i; Add(i);
            dfs();
            te_n--; Sub(i);
        } 
    }
}
// 就是输出首先是最小的数字，然后是最靠近的数列
int main(){
    FILE *pFile1 = fopen("holstein.in", "r");
    FILE *pFile2 = fopen("holstein.out", "w");
    fscanf(pFile1, "%d", &vi_n);
    for(int i=0; i<vi_n; i++)
       fscanf(pFile1, "%d", &vitam[i]); // vi，至多25种

    fscanf(pFile1, "%d", &fe_n); // 饲料，至多15种
    for(int i=0; i<fe_n; i++)
        for(int j=0; j<vi_n; j++)
           fscanf(pFile1, "%d", &feed[i][j]);
    // 处理部分
    for(int i=0; i<fe_n; i++){
        test[te_n++] = i; Add(i);
        dfs();
        te_n--; Sub(i);
    }
    // 输出部分
    fprintf(pFile2, "%d ", re_n);
    for(int i=0; i<re_n; i++){
        fprintf(pFile2, "%d%s", res[i]+1, (i==re_n-1?"\n":" "));
    }
    return 0;
}