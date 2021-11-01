// 2024 KB, 36ms
#include <iostream>
#include <vector>

using namespace std;

void generator(vector<int>& answer, int& N, vector<bool> used, int cnt) {
    if (cnt == 0) {
        for (auto a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (used[i] == false) {
            answer.push_back(i);
            used[i] = true;
            generator(answer, N, used, cnt-1);
            used[i] = false;
            answer.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;

    vector<int> answer;
    vector<bool> used(N+1, false);
    generator(answer, N, used, M);

    return 0;
}
