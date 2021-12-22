// 13748 KB, 332ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int order = 0;

    for (int i = 0; i < n; i++) {
        int& target_idx = arr[i].second;

        if (i > 0 && arr[i].first > arr[i-1].first) order++;
        answer[target_idx] = order;
    }

    for (auto a : answer) cout << a << ' ';
    cout << '\n';

    return 0;
}
