// 7568KB, 112ms
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> info(n);
    for (int i = 0; i < n; i++) {
        int a, s; cin >> a >> s;
        info[i] = {a, s};
    }

    sort(info.begin(), info.end());

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> workstation;

    for (auto& target : info) {

        bool unlock = false;

        while (!workstation.empty()) {
            if (target.first < workstation.top()) break;

            if (target.first > workstation.top() + m) {
                workstation.pop();
            }
            else {
                unlock = true;
                workstation.pop();
                break;
            }
        } 

        workstation.push(target.first + target.second);
        answer += unlock;
    }

    cout << answer << '\n';

    return 0;
}
