#include <iostream>
#define SIZE 50
#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
using namespace std;

int map[SIZE][SIZE], dp[SIZE][SIZE], visited[SIZE][SIZE];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int N, M;

int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] == -1) return 0;
    if (visited[x][y]) { cout << -1 << endl; exit(0); }
    if (dp[x][y]) return dp[x][y];
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
        dp[x][y] = MAX(dp[x][y], dfs(x + map[x][y] * dx[i], y + map[x][y] * dy[i]) + 1);
    visited[x][y] = 0;
    return dp[x][y];
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c <= '9') map[i][j] = c - '0';
            else if(c == 'H') map[i][j] = -1;
        }

    cout << dfs(0, 0) << endl;

    return 0;
}
