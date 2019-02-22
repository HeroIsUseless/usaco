/*
ID:22920179
PROB:pprime
LANG:C++
*/
#include "iostream"
#include "cstdio"
#include "math.h"
#include "algorithm"
using namespace std;
bool IsPrimeNum(int a){
    bool res = true;
   for(int i=2; i<=sqrt(a); i++){
       if(a%i == 0){
           res = false;
           break;
       }
   }
   return res;
}

int main(){
    FILE *pFile1 = fopen("pprime.in", "r");
    FILE *pFile2 = fopen("pprime.out", "w");
    int a, b;
    fscanf(pFile1, "%d%d", &a, &b);
    long arr[15005], arn = 0;
    for(int i=1;i<10000;i++) {
        long num=i,re;
        for(re=i;num!=0;num/=10) {
            re=re*10+num%10;
        }
        if(IsPrimeNum(re)) arr[arn++]=re;
        num=i/10; // 因为是单数，所以不会重复        
        for(re=i;num!=0;num/=10){
            re=re*10+num%10;
        }
        if(IsPrimeNum(re)) arr[arn++]=re;
    }
    sort(arr,arr+arn);
    for(int i=0; arr[i]<=b; i++){
        if(arr[i]>=a){
            fprintf(pFile2, "%d\n", arr[i]);
        }
    }
    fclose(pFile1); fclose(pFile2);
    return 0;
}