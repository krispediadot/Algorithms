// 29124 KB, 180ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& cntChar, vector<int>& word) {

    for (int i = 0; i < 26; i++) {
        if (cntChar[i] < word[i]) return false;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> alphabets;

    while (1) {
        string s; cin >> s;

        if (s == "-") break;

        vector<int> sub(26);

        for (char c : s) sub[c-'A']++;

        alphabets.push_back(sub);
    }

    while (1) {
        string s; cin >> s;

        if (s == "#") break;

        // 알파벳 순으로 정렬
        sort(s.begin(), s.end());

        vector<int> cntChar(26);
        for (auto c : s) cntChar[c-'A']++;

        string minChar = "", maxChar = "";
        int minAnswer = alphabets.size() + 1, maxAnswer = 0;

        bool checked[26] = {false,};

        for (char target : s) {
            
            int target_idx = target - 'A';

            // min, max 업데이트
            if (checked[target_idx] == false) {

                checked[target_idx] = true;
                
                // target을 필수로 사용해서 생성할 수 있는 단어 수 세기
                int cnt = 0;

                for (auto& word : alphabets) {
                    if (word[target_idx] > 0 && possible(cntChar, word)) 
                        cnt++;
                }

                if (cnt == minAnswer) minChar += target;
                if (cnt < minAnswer) {
                    minChar = "";
                    minChar += target;
                    minAnswer = cnt;
                }

                if (cnt == maxAnswer) maxChar += target;
                if (cnt > maxAnswer) {
                    maxChar = "";
                    maxChar += target;
                    maxAnswer = cnt;
                }
            }
        }

        // 가장 적은 정답 개수를 만드는 문자들, 가장 적은 정답 개수
        cout << minChar << ' ' << minAnswer << ' ';

        // 가장 많은 정답 개수를 만드는 문자들, 가장 많은 정답 개수
        cout << maxChar << ' ' << maxAnswer << '\n';
    }

    return 0;
}
