// 330184KB, 4408ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(4));
    vector<long long> a, b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.push_back(arr[i][0] + arr[j][1]);
            b.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long cnt = 0;

    for (int i = 0; i < a.size(); i++) {
        int begin = lower_bound(b.begin(), b.end(), -a[i]) - b.begin();
        int end = upper_bound(b.begin(), b.end(), -a[i]) - b.begin();
        cnt += (end - begin);
    }

    cout << cnt << '\n';

    return 0;
}
