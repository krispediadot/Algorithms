// 2416KB, 28ms
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int h, w, x, y; cin >> h >> w >> x >> y;
    vector<vector<int>> a(h, vector<int>(w));

    for (int r = 0; r < h+x; r++) {
        for (int c = 0; c < w+y; c++) {
            int n; cin >> n;
            
            if (r < h && c < w) {
                if (r < x || c < y) a[r][c] = n;
                else a[r][c] = (n - a[r-x][c-y]);
            }
        }
    }

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++)
            cout << a[r][c] << ' ';
        cout << '\n';
    }

    return 0;
}
