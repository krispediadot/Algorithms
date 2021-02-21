//https://www.acmicpc.net/problem/1958
// 1958.LCS3
//
// input
// abcdefghijklmn
// bdefg
// efg
// output
// 3
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int dp[101][101][101] = {0};

    string a, b, c; cin >> a >> b >> c;
    for (int i = 0; i <= a.length(); i++) { // i -> a[i-1] 
        for (int j = 0; j <= b.length(); j++) { // j-> b[j-1]
            for (int k = 0; k <= c.length(); k++) { // k -> c[k-1]
                if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 0;
                else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }
    // string lcs = "";
    // int i = a.length();
    // int j = b.length();
    // int k = c.length();
    // while(i>0 && j>0 && k>0){
    //     if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
    //         lcs.insert(lcs.begin(), a[i-1]);
    //         i--;
    //         j--;
    //         k--;
    //     }
    //     else{
    //         int maxNum = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
    //         if(maxNum==dp[i-1][j][k]) i--;
    //         if(maxNum==dp[i][j-1][k]) j--;
    //         if(maxNum==dp[i][j][k-1]) k--;
    //     }
    // }

    cout << dp[a.length()][b.length()][c.length()] << "\n";
    // cout<<lcs;
}