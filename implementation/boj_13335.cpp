// 2020KB, 0ms
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, w, l; cin >> n >> w >> l;
    vector<int> trucks(n);
    for (int i = 0; i < n; i++) cin >> trucks[i];

    queue<pair<int, int>> q; // {weight, in time}
    q.push({trucks[0], 0});

    int t = 1;
    int p = 1;
    int onBridge = trucks[0];

    while (!q.empty()) {
        if (!q.empty() && t - q.front().second == w) {
            onBridge -= q.front().first;
            q.pop();
        }

        if (p < n && onBridge+trucks[p] <= l) {
            q.push({trucks[p], t});
            onBridge += trucks[p++];
        }
        
        t++;
    }

    cout << t << '\n';

    return 0;
}
