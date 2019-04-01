/*
ID:22920179
PROB:subset
LANG:C++
*/
#include "iostream"
#include "cstdio"
using namespace std;
struct Stack
{
    int count = 0;
    bool flag[10000] = {false};   // 代表前进时候的路过变量，从1开始
    bool flag_2[10000] = {false}; // 代表现在是否加上了
    int sum=0;

    Stack(){
        count = 1;
        flag[1] = true;
    }

    void go(int cn){
        while(count < cn){
            flag[count] = true;
            count++;
        }
    }

    void back(){
        while(flag[count] == false){
            if(flag_2[count]){
                sum -= count; flag_2[count] = false;
            } 
            count--;
        }
        flag[count] = false;
        sum += count+1; flag_2[count+1] = true;
    }

    bool isEmpty(){return !count;}
};
int n, euq, res;
void dp(int cn, int sum){
    
    if((cn-1)==0){ // 现在是不加上
        if(sum == euq) res++;
        return;
    }
    else dp(cn-1, sum);

    sum += cn;  // 现在是加上
    if(sum > euq) return;
    if((cn-1)==0){
        if(sum == euq) res++;
        return;
    }
    else dp(cn-1, sum);
}
// 说白了就是排列组合的非递归形式的应用而已
int main(){
    freopen("subset.in","r", stdin);
    freopen("subset.out","w", stdout);
    cin >> n; euq = n*(n+1)/4;
    Stack s;
    if((1+n)*n/2%2 != 0){ // 说明不能拆分成两个
        cout << 0 << endl;
    }
    else{
        while(!s.isEmpty()){
            s.go(n);
            if(s.sum == euq) res++;
            s.back();
        }
        cout << res <<endl;
    }
    return 0;
}