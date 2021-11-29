#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 서류심사, 면접심사 중 적어도 하나가 다른 지워자보다 떨어지지 않는 자만 선발
// 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수

bool cmp (pair<int,int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >>t;

    while (t--) {
        
        int n; cin >> n;
        int cnt = 1;

        vector<pair<int, int>> info(n);

        for (int i = 0; i < n; i++) {
            cin >> info[i].first >> info[i].second;
        }

        sort(info.begin(), info.end(), cmp);

        int limit = info[0].second;

        for (int i = 1; i < n; i++) {
            if (info[i].second < limit) {
                cnt++;
                limit = info[i].second;
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}
