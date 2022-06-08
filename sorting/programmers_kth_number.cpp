/*
테스트 1 〉	통과 (0.01ms, 4.16MB)
테스트 2 〉	통과 (0.01ms, 4.17MB)
테스트 3 〉	통과 (0.01ms, 4.17MB)
테스트 4 〉	통과 (0.01ms, 4.09MB)
테스트 5 〉	통과 (0.01ms, 4.08MB)
테스트 6 〉	통과 (0.01ms, 4.13MB)
테스트 7 〉	통과 (0.01ms, 4.1MB)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int>& cmd : commands) {
    
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int from = cmd[0] - 1;
        int to = cmd[1] - 1;
        int k = cmd[2] - 1;
        
        for (int i = from; i <= to; i++) pq.push(array[i]);
        
        while (k--) pq.pop();
        
        answer.push_back(pq.top());
    }
    
    return answer;
}
