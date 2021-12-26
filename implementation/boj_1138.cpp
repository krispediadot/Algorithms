// 2020 KB, 0ms
#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<int>& info, vector<int>& answer, int n) {
    if (n == 0) return true;

    bool done = false;
    int least = info[n];

    int i = 0;
    while (least > 0 && i < info.size()-1) {
        if (answer[i] > n) least--;
        i++;
    }

    if (i == info.size()-1) return false;

    while (answer[i] == 0) {
        answer[i] = n;
        done |= solution(info, answer, n-1);

        if (done == true) break;

        answer[i] = 0;
        i++;
    }
    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> answer(n);
    vector<int> info(n+1);
    for (int i = 1; i <= n; i++) cin >> info[i];

    solution(info, answer, n);

    for (auto a : answer) cout << a << ' ';

    return 0;
}
