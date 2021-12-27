// 2424 KB, 20ms
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> dp(n+1);

    for (int i = 1; i <= n; i++) dp[i] = i;

    for (int i = 2; i <= sqrt(n); i++) {
        int powed = i*i;
        dp[powed] = 1;
        for (int j = powed+1; j <= n; j++) {
            dp[j] = min(dp[j], dp[j-powed] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
