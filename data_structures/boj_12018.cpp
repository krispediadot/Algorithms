//2024 KB,	0ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;

    vector<int> minM(n, 1);

    for (int i = 0; i < n; i++) {
        vector<int> betInfo;
        int p, l; cin >> p >> l;

        for (int j = 0; j < p; j++) {
            int mi; cin >> mi;
            betInfo.push_back(mi);
        }

        sort(betInfo.begin(), betInfo.end(), greater<int>());

        if (p >= l) minM[i] = betInfo[l-1];
    }

    sort(minM.begin(), minM.end());

    int cnt = 0;
    int minMIdx = 0;
    while (minMIdx < minM.size()) {
        m -= minM[minMIdx++];
        if (m < 0) break;

        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
