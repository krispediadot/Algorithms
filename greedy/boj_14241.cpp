// 2020 KB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int score = 0;

    sort(nums.begin(), nums.end());

    int pe = 1;
    int size = 0;

    while (pe < n) {
        if (size == 0) {
            size += nums[0];
        }
        score += (size*nums[pe]);
        size += nums[pe];

        pe++;
    }

    cout << score << '\n';

    return 0;
}
