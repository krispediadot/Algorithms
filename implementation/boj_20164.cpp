// 2028 KB, 0ms
#include <iostream>
#include <string>
#include <climits>

using namespace std;

void solution(string s, int& minAnswer, int& maxAnswer, int cntOdd) {
    
    if (s.length() == 1) {
        minAnswer = min(minAnswer, cntOdd);
        maxAnswer = max(maxAnswer, cntOdd);
        return;
    }
    if (s.length() == 2) {
        int res = (s[0]-'0') + (s[1]-'0');
        string res_s = to_string(res);
        for (auto& n : res_s) {
            if ((n-'0') % 2 != 0) cntOdd++;
        }

        solution(res_s, minAnswer, maxAnswer, cntOdd);
        return;
    }

    // split into three part
    for (int split1 = 1; split1 < s.length() - 1; split1++) {
        for (int split2 = split1+1; split2 < s.length(); split2++) {
            int a = stoi(s.substr(0,split1));
            int b = stoi(s.substr(split1, split2-split1));
            int c = stoi(s.substr(split2));
            int res = stoi(s.substr(0,split1)) + stoi(s.substr(split1, split2-split1)) + stoi(s.substr(split2));
            string res_s = to_string(res);
            int cnt = 0;
            for (auto& n : res_s) {
                if ((n-'0') % 2 != 0) cnt++;
            }

            solution(res_s, minAnswer, maxAnswer, cntOdd+cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int minAnswer = INT_MAX, maxAnswer = 0;
    string s; cin >> s;
    int cnt = 0;
    for (auto& n : s) {
        if ((n-'0') % 2 != 0) cnt++;
    }

    solution(s, minAnswer, maxAnswer, cnt);

    cout << minAnswer << ' ' << maxAnswer << '\n';

    return 0;
}
