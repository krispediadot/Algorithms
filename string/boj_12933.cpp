// 2024KB, 0ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string DUCK = "quack";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    vector<int> cnts(DUCK.length(), 0);

    int answer = 0;
    bool possible = true;

    for (auto c : s) {
        if (!possible) break;

        if (c == 'k') {
            if (cnts[0] > 0 && cnts[1] > 0 && cnts[2] > 0 && cnts[3] > 0) {
                answer = max(answer, cnts[0]);

                cnts[0]--;
                cnts[1]--;
                cnts[2]--;
                cnts[3]--;
            }
            else {
                possible = false;
                answer = 0;
            }
        }
        else if (c == 'q') cnts[0]++;
        else {
            int idx = DUCK.find(c);
            for (int i = 0; i < idx; i++) {
                if (cnts[i] < cnts[idx]+1) {
                    possible = false;
                    answer = 0;
                    break;
                }
            }
            if (possible) cnts[idx]++;
        }
    }

    for (auto c : cnts) {
        if (c != 0) {
            answer = 0;
            break;
        }
    }

    if (answer == 0) cout << -1;
    else cout << answer;

    return 0;
}
