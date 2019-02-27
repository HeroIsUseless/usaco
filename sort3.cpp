/*
ID:22920179
PROB:sort3
LANG:C++

*/
#include "iostream"
using namespace std;
int arr[1005];
void Swap(int ci, int cj){
    int t = arr[ci];
    arr[ci] = arr[cj];
    arr[cj] = t;
}
int main(){
    FILE *pFile1 = fopen("sort3.in", "r");
    FILE *pFile2 = fopen("sort3.out", "w");
    int res=0;
    int n; fscanf(pFile1, "%d", &n);
    int n1=0, n2=0, n3=0;
    for(int i=0; i<n; i++){
        fscanf(pFile1, "%d", &arr[i]);
        switch (arr[i]) {
            case 1: n1++; break;
            case 2: n2++; break;
            case 3: n3++; break; 
            default: break;
        }
    }
    n2 = n2+n1; n3 = n3+n2;
    // 对1找2找3
    for(int i=0; i<n1; i++){
        if(arr[i] == 2){
            for(int j=n1; j<n2; j++){
                if(arr[j] == 1){
                    Swap(i, j);
                    res++;
                    break;
                }
            }
        }
        if(arr[i] == 3){
            for(int j=n2; j<n3; j++){
                if(arr[j] == 1){
                    Swap(i, j);
                    res++;
                    break;
                }
            }
        }
    }
    // 对2找3
    for(int i=n1; i<n2; i++){
        if(arr[i] == 3){
            for(int j=n2; j<n3; j++){
                if(arr[j] == 2){
                    Swap(i, j);
                    res++;
                    break;
                }
            }
        }
    }
    // 找到有多少个3重叠的
    for(int i=0; i<n1; i++){
        if(arr[i] != 1){
            arr[i] = 0;
            res+=2;
        }
    }
    fprintf(pFile2, "%d\n", res);
    cout << res;
    fclose(pFile1); fclose(pFile2);
    return 0;
}