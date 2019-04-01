/*
ID:22920179
PROB:preface
LANG:C++
*/
#include "iostream"
#include "cstdio"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;
int main(){
    freopen("preface.in","r", stdin);
    freopen("preface.out","w", stdout);
    string str[4][10] = {{"","I","II","III","IV","V","VI","VII", "VIII","IX"},
                         {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                         {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                         {"","M","MM","MMM","","","","","",""}};
    int n; cin >> n;
    string res;
    do{
        int i = 0, t, k=n; 
        while(k != 0){
            t = k%10;
            res += str[i][t];
            i += 1;
            k /= 10;
        }
    }while(0 <-- n);
    char s[] = {'I','V','X','L','C','D','M'};
    for(auto var : s){
        if(count(res.begin(),res.end(), var) != 0){
            cout <<var<<" "<<count(res.begin(),res.end(), var)<<endl;
        }
    }
    return 0;
}