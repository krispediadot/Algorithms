// 2056 KB, 8ms

#include <iostream>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) { 
    if (a <= 0 || b <= 0 || c <= 0) return dp[0][0][0] = 1;
    if (a > 20 || b > 20 || c > 20) return dp[20][20][20] = w(20,20,20);
    
    if (dp[a][b][c]) return dp[a][b][c];
    
    if (a < b && b < c)
        return dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);

    return dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        int result = w(a,b,c);

        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
    }

    return 0;
}
