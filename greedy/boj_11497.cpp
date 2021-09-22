// 2156 KB, 40ms
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_HEIGHT = 100001;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) cin >> heights[i];

        sort(heights.begin(), heights.end());

        int maxGap = max(abs(heights[0] - heights[1]), abs(heights[0] - heights[2]));
        for (int i = 1; i < n-2; i++) {
            maxGap = max(abs(heights[i] - heights[i+2]), maxGap);
        }
        
        cout << maxGap << '\n';
    }

    return 0;
}
