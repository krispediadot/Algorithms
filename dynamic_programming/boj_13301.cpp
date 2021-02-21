// https://www.acmicpc.net/problem/13301
// 13301. 타일 장식물
//
// input
// 5
// output
// 26
//
// input
// 6
// output
// 42
//

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long a = 1;
    long long b = 1;
    long long c = 2;
    int idx = 3;
    while (idx < n) {
        long long newc = c + b;
        a = b;
        b = c;
        c = newc;
        idx++;
    }
    if (n == 1) cout << a * 4;
    else if (n == 2) cout << a * 2 + (a + b) * 2;
    else cout << (a + b) * 2 + (b + c) * 2;
}
