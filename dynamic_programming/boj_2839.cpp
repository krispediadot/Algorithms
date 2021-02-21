// https://www.acmicpc.net/problem/2839
// 2839. 설탕 배달
//
// input
// 18
//
// output
// 4
//

#include <iostream>
#define MAX 5001

using namespace std;

int weight[MAX];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) weight[i] = MAX;

    for (int i = 0; i <= n; i += 5) weight[i] = min(i / 5, weight[i]);
    for (int i = 0; i <= n; i += 3) weight[i] = min(i / 3, weight[i]);
    for (int i = 0; i <= n; i += 5) {
        for (int j = 0; i + j <= n; j += 3) {
            weight[i + j] = min(weight[i] + weight[j], weight[i + j]);
        }
    }
    if (weight[n] == 0 || weight[n] == MAX) cout << -1;
    else cout << weight[n];
}
