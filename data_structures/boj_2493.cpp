#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    stack<pair<int, int>> st; // {height, idx}

    for (int idx = 1; idx <= n; idx++) {
        int height; cin >> height;

        while (!st.empty() && st.top().first < height) st.pop();

        if (st.empty()) cout << 0 << ' ';
        else cout << st.top().second << ' ';

        st.push({height, idx});
    }

    return 0;
}
