#include<iostream>
#define SIZE 100
#define MAX 10001

using namespace std;

int main(void){
    int T;
    cin>>T;

    for(int t=0; t<T; t++) {
        int dp[MAX] = {0};
        int c[SIZE];
        int n, k;

        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> c[i];
        cin>>k;
        // 1을 만들 수 있는 경우의수
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = c[i]; j <= k; ++j) {
                if (j - c[i] >= 0)
                    dp[j] += dp[j - c[i]];
            }
        }
        cout << dp[k] << endl;
    }

    return 0;
}
