// 6056 KB, 12ms

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, bomb; cin >> s >> bomb;

    string answer = "";

    int idx = 0;
    while (idx < s.length()) {
        answer += s[idx++];

        if (answer.back() == bomb.back() && answer.length() >= bomb.length()) {
            bool isBomb = true;
            
            for (int i = 0; i < bomb.length(); i++) {
                if (answer[answer.length() - (bomb.length() - i)] != bomb[i]) {
                    isBomb = false;
                    break;
                }
            }

            if (isBomb) {
                for (int i = 0; i < bomb.length(); i++) answer.pop_back();
            }
        }
    }

    if (answer.length() > 0) cout << answer << '\n';
    else cout << "FRULA\n";

    return 0;
}
