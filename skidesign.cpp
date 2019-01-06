/*
ID:22920179
PROB:skidesign
LANG:C++
*/
//1000个而已，暴力求出最小值
//给定一组数据，要求最大值与最小值之间小于17
//通过削比较高的山头，填比较低的山头
//但是怎么削能使总削数最低呢？
//暴力求解的方法，就非常明显了
//首先寻求一个最低点，
//然后比它低的都往上填，比它大于17的都往下降，就是这样

#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cmath"
using namespace std;

int main(){
    int maxHill = 0;
    int minHill = 1000;
    FILE* in = fopen("skidesign.in","r");
    FILE* out= fopen("skidesign.out","w");
    int n; fscanf(in,"%d",&n);
    int hills[1005];
    for(int i=0; i<n; i++){
        fscanf(in,"%d",&hills[i]);
        cout << hills[i] <<endl;
        if(maxHill < hills[i]) maxHill = hills[i];
        if(minHill > hills[i]) minHill = hills[i];
    }
    cout << "max:" << maxHill <<endl;
    cout << "min:" << minHill <<endl;
    int res = 1000000;
    int pos;
    for(int minest=minHill; minest<=maxHill; minest++){
        int t = 0;
        for(int j=0; j<n; j++){
            if(hills[j] < minest){
                t += pow(abs(minest-hills[j]),2);
                if(minest==4)cout << "t:" <<t<<endl;
            }
            else if(hills[j]-minest > 17){
                t += pow((abs(hills[j]-(minest+17))),2);
            }
        }
        if(res > t){
            res = t;
            pos = minest;
        } 
    }
    fprintf(out,"%d\n",res);
    cout<< res <<endl;
    cout << pos <<endl;
    fclose(in);fclose(out);
    return 0;
}