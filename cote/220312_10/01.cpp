#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int money, vector<int> costs) {

    vector<int> costs_real = {1, 5, 10, 50, 100, 500};
    vector<int> dp(money+1, INT_MAX);
    dp[0] = 0;

    for (int idx = 0; idx < costs.size(); idx++) {
        for (int i = costs_real[idx]; i <= money; i++) {
            dp[i] = min(dp[i], dp[i-costs_real[idx]] + costs[idx]);
        }
    }

    return dp[money];
}
