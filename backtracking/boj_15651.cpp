// 2020 KB, 348ms
#include <iostream>
#include <vector>

using namespace std;

void generator(vector<int>& answer, int& N, int cnt) {
    if (cnt == 0) {
        for (auto a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        answer.push_back(i);
        generator(answer, N, cnt-1);
        answer.pop_back(); 
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;

    vector<int> answer;
    generator(answer, N, M);

    return 0;
}
