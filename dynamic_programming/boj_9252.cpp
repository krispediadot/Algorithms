//https://www.acmicpc.net/problem/9252
// 9252.LCS2
//
// input
// ACAYKP
// CAPCAK
// output
// 4
// ACAK
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
    string lcs = "";
    int i = a.length();
    int j = b.length();
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            lcs.insert(lcs.begin(),a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    cout<<dp[a.length()][b.length()]<<"\n";
    cout<<lcs;
}