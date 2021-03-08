#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>

using namespace std;

// bitset 사용X
int solution1(vector<vector<int>> board, vector<int> nums) {
    int answer = 0;
    const int N = board.size();
    
    unordered_set<int> targets(nums.begin(), nums.end());
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (targets.find(board[i][j]) != targets.end()) {
                board[i][j] = 0;
            }
        }
    }
    // 가로, 세로
    for (int i = 0; i < N; i++) {
        bool horizental = true, vertical = true;
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) horizental = false;
            if (board[j][i] != 0) vertical = false;
            if (!horizental && !vertical) break;
        }
        if (horizental) answer++;
        if (vertical) answer++;
    }
    
    // 대각선
    bool left = true, right = true;
    for (int i = 0; i < board.size(); i++) {
        if (board[i][i] != 0) left = false;
        if (board[i][board.size() - 1 - i] != 0) right = false;
        if (!left && !right) break;
    }
    if (left) answer++;
    if (right) answer++;

    return answer;
}
// bitset 사용O
int solution2(vector<vector<int>> board, vector<int> nums) {
    int answer = 0;
    const int N = board.size();

    unordered_set<int> targets(nums.begin(), nums.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (targets.find(board[i][j]) != targets.end()) {
                board[i][j] = 0;
            }
        }
    }
    // 가로, 세로
    for (int i = 0; i < N; i++) {
        bitset<1> horizental = true, vertical = true;
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) horizental = false;
            if (board[j][i] != 0) vertical = false;
            if (horizental.none() && vertical.none()) break;
        }
        if (horizental.all()) answer++;
        if (vertical.all()) answer++;
    }

    // 대각선
    bitset<1> left = true, right = true;
    for (int i = 0; i < board.size(); i++) {
        if (board[i][i] != 0) left = false;
        if (board[i][board.size() - 1 - i] != 0) right = false;
        if (left.none() && right.none()) break;
    }
    if (left.all()) answer++;
    if (right.all()) answer++;

    return answer;
}

int main() {
    vector<vector<int>> board {
        {11,13,15,16},
        {12,1,4,3},
        {10,2,7,8},
        {5,14,6,9}
    };
    vector<int> nums {14,3,2,4,13,1,16,11,5,15};
    
    cout << solution1(board, nums) << endl; // 3
	cout << solution2(board, nums) << endl; // 3
}



