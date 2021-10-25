// 2618 KB, 0ms

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            for (int j = i-k; j <= i+k; j++) {
                if (j >= 0 && j < n && s[j] == 'H') {
                    s[j] = 'N';
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt << '\n';
    
    return 0;
}
