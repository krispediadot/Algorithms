// https://www.acmicpc.net/problem/10870
// 10870. 피보나치 수 5
//
// input
// 10
//
// output
// 55
//

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int f1 = 0;
    int f2 = 1;
    int f3;
    int idx = 2;
    while (idx <= n) {
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
        idx++;
    }
    if (n == 0) cout << 0;
    else if (n == 1) cout << 1;
    else cout << f3;
}
