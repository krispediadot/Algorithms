// 2412KB, 8ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int answer = 0;
    int l = 0, r = n-1;

    while (l < r) {
        answer = max(answer, (r-l-1)*min(arr[l], arr[r]));
        if (arr[l] < arr[r]) l++;
        else r--;
    }

    cout << answer << '\n';

    return 0;
}
