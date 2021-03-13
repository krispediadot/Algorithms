#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find_set(vector<int>& parents, int target) {
    if (parents[target] == target) return target;
    return parents[target] = find_set(parents, parents[target]);
};

void union_set(vector<int>& parents, int t1, int t2) {
    int p1 = find_set(parents, t1);
    int p2 = find_set(parents, t2);
    
    parents[p1] = p2;
};

int solution(int n, vector<vector<int>> computers) {
    vector<int> parents(n);
    for (int i = 0; i < n; i++) parents[i] = i;
    
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j++) {
            if (computers[i][j] == 1) {
                if (find_set(parents, i) != find_set(parents, j))
                    union_set(parents, i, j);
            }
        }
    }
    
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        parents[i] = find_set(parents, i);
        s.insert(parents[i]);
    }
    return s.size();
}

int main() {
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl;
    cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;
}
