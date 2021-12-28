// 2028KB, 0ms
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string a, b; cin >> a >> b;

    unordered_map<char, int> dict;

    int r = 0, s = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) r++;
        else {
            if (dict[a[i]] < 0) s++;
            if (dict[b[i]] > 0) s++;

            dict[a[i]]++;
            dict[b[i]]--;
        }
    }

    cout << r << ' ' << s << '\n';

    return 0;
}
