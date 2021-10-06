// 19600 KB, 224ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<pair<int, int>> info(N);
    for (int i = 0; i < N; i++) cin >> info[i].first >> info[i].second;

    vector<int> answer(N+1);
    for (int i = 0; i < N; i++) {
        if (i + info[i].first <= N) 
            answer[i + info[i].first] = max(answer[i + info[i].first], answer[i] + info[i].second);    
        
        answer[i + 1] = max(answer[i + 1], answer[i]);
    }

    cout << answer[N];

    return 0;
}
