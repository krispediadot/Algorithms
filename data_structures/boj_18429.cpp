// 2024 KB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K; cin >> N >> K;
    vector<pair<int, int>> weights(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i].first;
        weights[i].second = i;
    }

    sort(weights.begin(), weights.end());

    int answer = 0;

    do {
        int muscles = 0;
        for (int i = 0; i < N; i++) {
            muscles += (weights[i].first - K);
            if (muscles < 0) break;
        }
        
        if (muscles > 0) answer++;
    } while (next_permutation(weights.begin(), weights.end()));

    cout << answer;

    return 0;
}
