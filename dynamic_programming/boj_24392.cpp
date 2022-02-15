// 13852KB, 72ms
#include <iostream>
#include <vector>

using namespace std;

const int HARD = 1;
const int MOD = 1000000007;
const int dirC[] = {-1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> bridge(n, vector<int>(m));
    vector<vector<long long>> dp(n, vector<long long>(m)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> bridge[i][j];
        }
    }

    for (int j = 0; j < m; j++) dp[0][j] = bridge[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bridge[i][j] == HARD) {
                for (int dir = 0; dir < 3; dir++) {
                    int nextC = j + dirC[dir];
                    if (nextC >= 0 && nextC < m)
                        dp[i][j] += (dp[i-1][j+dirC[dir]] % MOD);
                }
            }
        }
    }

    long long answer = 0;
    for (int j = 0; j < m; j++) answer += (dp[n-1][j] % MOD);
    cout << answer % MOD << '\n';

    return 0;
}
