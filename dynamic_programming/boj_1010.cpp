// https://www.acmicpc.net/problem/1010
// 1010. 다리 놓기
//
// input
// 3
// 2 2
// 1 5
// 13 29
// output
// 1
// 5
// 67863915
//

#include<iostream>
#include<cstring>
#define MAX 31
using namespace std;

int dp[MAX][MAX];

int sumAll(int r, int c){
    int sum=0;
    for(int j=r; j<=c; j++)
        sum+=dp[r][j];
    return sum;
}

int main(){
    int nTest; cin>>nTest;
    while(nTest--){
        memset(dp, 0, sizeof(dp));
        int n,m; cin>>n>>m;

        for(int j=1; j<=m; j++) dp[1][j] = j;
        for(int i=2; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = sumAll(i-1, j-1);
            }
        }
        cout<<dp[n][m]<<"\n";
    }
}
