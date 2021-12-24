// 2024 KB, 0ms
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;

    int n0 = 0, n1 = 0;
    for (auto c : s) {
        if (c == '0') n0++;
        else n1++;
    }

    n0 /= 2;
    n1 /= 2;

    while (n1 > 0) {
        s.erase(s.find('1'), 1);
        n1--;
    }
    
    reverse(s.begin(), s.end());

    while (n0 > 0) {
        s.erase(s.find('0'), 1);
        n0--;
    }

    reverse(s.begin(), s.end());

    cout << s << '\n';

    return 0;
}
