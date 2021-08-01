#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;

    while (T--) {
        string s; cin >> s;
        vector<vector<int>> alphabets(26);
        vector<int> checkIdx(26);
        int maxCnt = 0;
        for (int idx = 0; idx < s.length(); idx++) {
            int charIdx = s[idx] - 'a';
            alphabets[charIdx].push_back(idx);
            int size = alphabets[charIdx].size();
            maxCnt = max(maxCnt, size);
        }
        
        int K; cin >> K;

        if (maxCnt < K) {
            cout << -1 << '\n';
            continue;
        }

        int minLength = s.length();
        int maxLength = 0;

        for (int idx = 0; idx < s.length(); idx++) {
            char target = s[idx];
            int targetIdx = target - 'a';
            int& curCheckIdx = checkIdx[targetIdx];

            if (K + curCheckIdx - 1 < alphabets[targetIdx].size()) {
                int windowSub = alphabets[targetIdx][K + curCheckIdx - 1] - alphabets[targetIdx][curCheckIdx] + 1;
                minLength = min(minLength, windowSub);
                maxLength = max(maxLength, windowSub);
            }
            curCheckIdx++;
        }

        cout << minLength << " " << maxLength << '\n';
    }

    return 0;
}
