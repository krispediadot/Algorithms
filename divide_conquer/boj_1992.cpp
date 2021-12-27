// 2156 KB, 0ms
#include <iostream>
#include <vector>

using namespace std;

bool isSamePixcel(vector<vector<int>>& image, int r_s, int c_s, int size) {
    int num = image[r_s][c_s];

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (image[r_s + r][c_s + c] != num) return false;
        }
    }
    return true;
}

void solution(vector<vector<int>>& image, int r_s, int c_s, int size, string& answer) {
    if (size == 1 || isSamePixcel(image, r_s, c_s, size)){
        answer += (image[r_s][c_s] + '0');
        return;
    }

    answer += '(';
    int len = size / 2;

    for (int r = r_s; r < r_s+size; r+=len) {
        for (int c = c_s; c < c_s+size; c+=len) {
            solution(image, r, c, len, answer);
        }
    }
    answer += ')';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> image(n, vector<int>(n));

    for (int r = 0; r < n; r++) {
        string s; cin >> s;
        for (int c = 0; c < n; c++) {
            image[r][c] = s[c]-'0';
        }
    }

    string answer = "";

    solution(image, 0, 0, n, answer);

    cout << answer << '\n';

    return 0;
}
