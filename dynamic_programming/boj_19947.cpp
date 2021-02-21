// https://www.acmicpc.net/problem/19947
// 19947. 투자의 귀재 배주형
//
// input
// 95229 3
// output
// 114274
//
// input
// 25542 10
// output
// 46549
//

#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int dp[11];

int main() {
    memset(dp, 0, sizeof(dp));
    int h, y; cin >> h >> y;
    float interests[6] = {0, 0.05, 0, 0.2, 0, 0.35};

    dp[0] = h;
    for (int i = 1; i <= y; i++) {
        dp[i] = max(dp[i], dp[i - 1] + dp[i - 1] * interests[1]);
        if (i >= 3) dp[i] = max(dp[i], dp[i - 3] + dp[i - 3] * interests[3]);
        if (i >= 5) dp[i] = max(dp[i], dp[i - 5] + dp[i - 5] * interests[5]);
    }
    cout << dp[y];
}
