// 2020 KB, 0ms

#include <iostream>
#include <vector>

using namespace std;

bool hansu(int i) {
    string i_s = to_string(i);

    int sub = i_s[1] - i_s[0];

    int last = i%10;
    i/=10;

    while (i) {
        if (last - (i%10) != sub) return false;
        last = i%10;
        i/=10;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<bool> nums(n+1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        if (hansu(i)) cnt++;
    }

    cout << cnt;

    return 0;
}
