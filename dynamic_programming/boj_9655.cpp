// https://www.acmicpc.net/problem/9625
// 9655. 돌 게임
//
// input
// 5
// output
// SK
//

#include <iostream>
#define SK 1
#define CY 0
using namespace std;

int main() {
    int n; cin >> n;

    if (n % 2 == SK) cout << "SK";
    else cout << "CY";
}
