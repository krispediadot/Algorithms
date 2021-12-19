// 2020 KB, 0ms
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long long n, m; cin >> n >> m;

        while (n > 0) {
            m++;
            n /= 2;
        }
        
        cout << m << '\n';
    }

    return 0;
}
