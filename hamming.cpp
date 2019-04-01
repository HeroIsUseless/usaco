/*
ID:22920179
PROB:hamming
LANG:C++
*/
#include "iostream"
#include "set"
#include "cstring"
#include "cstdio"
using namespace std;
int n, b, d;
void parse(int ci, int* cBArr){ // 解析拆成二进制
    int arn=0;
    memset(cBArr, 0, sizeof(int)*b);
    while(ci!=0 && arn<=b){
        cBArr[arn++] = ci%2;
        ci /= 2;
    }
}
bool IsDifferent(set<int>& cres, int ci){
    int res = true;
    int* ar = new int[b];
    int* br = new int[b];
    parse(ci, br);
    for(auto var:cres){
        parse(var, ar);
        int dif=0;
        for(int i=0; i<b; i++){
            if(ar[i] != br[i]) dif++;
        }
        if(dif < d) res = false;            
    }
    return res;
}
// 一共n个编码，至多64个，每个编码都是bbit，而且每个编码至少有d个不同
// 那么就是从0开始暴力算就行了，从0开始，进行解码，到n为止，就是这样
// 改一个非常简单的bug，真好

int main(){
    freopen("hamming.in","r", stdin);
    freopen("hamming.out","w", stdout); 
    cin >> n >> b >> d;
    int* bArr = new int[b];
    set<int> res;
    int i=0;
    while(res.size() != n){
        if(IsDifferent(res, i)) 
            res.insert(i);
        i++;
    }
    i=0;
    for(auto var:res){
        i++;
        cout << var << (i%10==0||var==*(--res.end())?"\n":" ");
    }
    return 0;
}