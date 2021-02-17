//https://www.acmicpc.net/problem/9251
// 9251.LCS
//
// input
// ACAYKP
// CAPCAK
// output
// 4
//

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int dp[1001][1001] = {0,};

    string a,b; cin>>a>>b;
    for(int i=0; i<=a.length(); i++){ // i -> a[i-1] 
        for(int j=0; j<=b.length(); j++){ // j-> b[j-1]
            if(i==0 || j==0) dp[i][j] = 0;
            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    }
    cout<<dp[a.length()][b.length()];
}