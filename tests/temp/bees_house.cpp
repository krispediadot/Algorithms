// 벌집 출력 문제
// 공간 효율이 낮은 코드 

#include <iostream>
#include <vector>

using namespace std;

void fillNumber(vector<vector<int>>& house, int n, pair<int, int> pos, int num) {
    if (n == 1) {
        house[pos.first][pos.second] = num;
        return;
    }
    
    for (int i = 0; i < n-1; i++) house[pos.first++][pos.second++] = num++;
    for (int i = 0; i < n-1; i++) {
        house[pos.first][pos.second] = num++;
        pos.first += 2;
    }
    for (int i = 0; i < n-1; i++) house[pos.first++][pos.second--] = num++;
    for (int i = 0; i < n-1; i++) house[pos.first--][pos.second--] = num++;
    for (int i = 0; i < n-1; i++) {
        house[pos.first][pos.second] = num++;
        pos.first -= 2;
    }
    for (int i = 0; i < n-1; i++) house[pos.first--][pos.second++] = num++;

    fillNumber(house, n-1, {pos.first+2, pos.second}, num);
}

void printHouse(vector<vector<int>>& house, int n) {
    int c = n-1;
    int len = 1;

    for (int r = 0; r < house.size(); r++) {
        int targetc = c;
        for (int i = 0; i < len; i++) {
            cout << house[r][targetc] << ' ';
            targetc+=2;
        }
        cout << endl;

        if (r < n-1) { len++; c--; }
        else if (house.size() - r < n) { len--; c++; }
        else {
            if (r % 2 != n % 2) { len = n-1; c = 1; }
            else { len = n; c = 0; }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> house((4*n - 3), vector<int> (2*n - 1));

    fillNumber(house, n, {0, n-1}, 1);
    printHouse(house, n);

    return 0;
}
