// 2024KB, 0ms
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k; cin.ignore();

    int len = 0;
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        if (len + word.length() > k) {
            cout << '\n';
            len = 0;
        }
        if (len > 0) cout << ' ';
        cout << word;
        len += word.length();
    }
    cout << '\n';

    return 0;
}
