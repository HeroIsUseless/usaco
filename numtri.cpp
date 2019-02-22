/*
ID: 22920179
PROB: numtri
LANG: C++
*/
#include "iostream"
#include "cstdio"
using namespace std;
int dp[2][1000], input[1001];
int main(){
    FILE *pFile1 = fopen("numtri.in", "r");
    FILE *pFile2 = fopen("numtri.out", "w");
    int n; 
    fscanf(pFile1, "%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            fscanf(pFile1, "%d", &input[j]);
            if(j==0)
                dp[(i+1)%2][j]=dp[i%2][j]+input[j];
            else
                dp[(i+1)%2][j]=max(dp[i%2][j]+input[j],dp[i%2][j-1]+input[j]);
        }
    }
    int ans=0; 
    for(int i=0; i<n; i++){
        ans=max(ans, max(dp[0][i], dp[1][i]));
    }
    fprintf(pFile2, "%d\n", ans);
    cout << ans;
    fclose(pFile1); fclose(pFile2);
    return 0;
}