/*
ID:22920179
LANG:C++
TASK:ariprog
*/
#include "iostream"
#include "set"
#include "cstdio"
#include "cstdlib"
using namespace std;
//输入n， m
//然后对m进行计算，把符合要求的数字填入数组
//然后进行匹配，一个等差数列中的所有元素都在这个数组里面才行
//然后输出初值和步长，按要求排列即可
//也就是说，将数据进行排列后，根据数组中的每一个元素，
//让b进行从1到最大值的一个爆破检查，就是这样
//程序没有错，但是超时了
std::set<int> pqSqr;
bool isMakeProgression(int ca, int cb, int cn){
    int result = true;
    for(int i=0; i<cn; i++){
        if(pqSqr.count(ca) == 0){
            result = false;
            break;
        }
        ca += cb;
    }
    return result;
}
int main(){
    FILE *pFile1 = fopen("ariprog.in", "r");
    FILE *pFile2 = fopen("ariprog.out", "w");
    int n, m;//p, q都选自m
    fscanf(pFile1, "%d %d", &n, &m);
    for(int p=0; p<=m; p++){
        for(int q=0; q<=m; q++){
            pqSqr.insert(p*p + q*q);
        }
    }
    int maxB = (*(--pqSqr.end()) - *pqSqr.begin())/(n-1);
    int count = 0;
    for(int b=1; b<=maxB; b++){
        for(const auto a : pqSqr){
            if(isMakeProgression(a, b, n)){
                fprintf(pFile2, "%d %d\n", a, b);
                count++;
            }
        }
    }
    //它为什么可以这么选取，是因为num0 + (n-1)b < num-1
    if(count == 0) fprintf(pFile2, "NONE\n");
    return 0;
}