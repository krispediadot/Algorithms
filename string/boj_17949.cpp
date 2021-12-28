// 6804KB, 48ms

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, int> dict = {{"char", 2},
                                       {"int", 8},
                                       {"long_long", 16}
                                      };

    string s; cin >> s;
    int n; cin >> n;
    vector<string> info(n);
    for (int i = 0; i < n; i++) cin >> info[i];

    int idx = 0;
    for (int i = 0; i < n; i++) {
        string num = s.substr(idx, dict[info[i]]);

        long long mul = 1;
        long long result = 0;
        for (int p = num.length() - 1; p >= 0; p--) {
            char c = num[p];
            int carry = 0;

            if (c >= 'A') carry = -39;

            result += (mul * (c-'0'+carry));
            mul *= 16;
        }

        cout << result << ' ';

        idx += dict[info[i]];
    }

    return 0;
}
