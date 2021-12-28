// 2024KB, 0ms
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;

    bool isOdds = true;

    for (int i = 0; i < s.length(); i++) {
        if (s[i+1] == s[i]) {
            isOdds = false;
        }
    }

    if (!isOdds) cout << "Or not.\n";
    else cout << "Odd.\n";

    return 0;
}
