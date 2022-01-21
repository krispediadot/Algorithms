// 2024KB, 0ms
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int idx = 1;

    while (1) {
        string s; cin >> s;
        if (s[0] == '-') break;

        int cnt = 0;
        int checker = 0;

        stack<char> st;

        for (auto c : s) {
            if (c == '{') st.push(c);
            else {
                if (st.empty()) {
                    cnt++;
                    st.push('{');
                }
                else if (st.top() == '{') st.pop();
                else st.push('}');
            }
        }

        cnt += (st.size()/2);

        cout << idx << ". " << cnt << '\n';
        idx++;
    }

    return 0;
}
