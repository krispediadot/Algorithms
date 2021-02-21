//https://www.acmicpc.net/problem/11053
// 11053.가장 긴 증가하는 부분 수열
//
// input
// 6
// 10 20 10 30 20 50
// output
// 4
//

#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
    int arr[2][MAX] = {0,};
    int dp[MAX] = {0};
    int n; cin >> n;

    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[0][i];
        max = arr[0][i] > max ? arr[0][i] : max;
    }
    for (int i = 1; i <= n; i++) dp[i] = max;
    
    max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[0][i] > dp[j] && arr[0][i] <= dp[j + 1]) {
                arr[1][i] = j + 1;
                dp[j + 1] = arr[0][i];
                max = j + 1 > max ? j + 1 : max;
                break;
            }
        }
    }
    cout << max;
}