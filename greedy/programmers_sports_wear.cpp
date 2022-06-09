/*

-- const int --

테스트 1 〉	통과 (0.01ms, 4.09MB)
테스트 2 〉	통과 (0.01ms, 3.59MB)
테스트 3 〉	통과 (0.01ms, 4.17MB)
테스트 4 〉	통과 (0.01ms, 3.66MB)
테스트 5 〉	통과 (0.01ms, 4.16MB)
테스트 6 〉	통과 (0.01ms, 4.18MB)
테스트 7 〉	통과 (0.01ms, 4.18MB)
테스트 8 〉	통과 (0.01ms, 4.16MB)
테스트 9 〉	통과 (0.01ms, 4.09MB)
테스트 10 〉	통과 (0.01ms, 4.08MB)
테스트 11 〉	통과 (0.01ms, 4.23MB)
테스트 12 〉	통과 (0.01ms, 4.17MB)
테스트 13 〉	통과 (0.01ms, 3.6MB)
테스트 14 〉	통과 (0.01ms, 4.16MB)
테스트 15 〉	통과 (0.01ms, 4.17MB)
테스트 16 〉	통과 (0.01ms, 4.23MB)
테스트 17 〉	통과 (0.01ms, 4.17MB)
테스트 18 〉	통과 (0.01ms, 4.17MB)
테스트 19 〉	통과 (0.01ms, 4.16MB)
테스트 20 〉	통과 (0.01ms, 3.64MB)
*/

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    const int LOST = -1;
    const int EXTRA = 1;
    
    vector<int> students(n+1, 0);
    
    for (auto idx : lost) students[idx]--;
    for (auto idx : reserve) students[idx]++;
    
    int answer = n;
    
    for (int idx = 1 ; idx <= n; idx++) {
        if (students[idx] == LOST) {
            if (students[idx-1] == EXTRA) continue;
            
            if (students[idx+1] == EXTRA) students[idx+1]--;
            else answer--;
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;

	// 1. 전체 학생의 체육복 개수 
	vector<int> students(n + 2, 1);

	for (auto target : reserve) students[target]++;
	for (auto target : lost) students[target]--;

	// 2. 0을 채우지 못하면 answer--;
	for (int i = 1; i <= n; i++) {
		if (students[i] == 0){
			if (students[i - 1] == 2) continue;
			else if (students[i + 1] == 2) students[i + 1]--;
			else answer--;
		}
	}

	return answer;
}

int main()
{
	cout << solution(5, {2, 4}, {1, 3, 5}) << endl; // 5
	cout << solution(5, {2, 4}, {3}) << endl; // 4
	cout << solution(3, {3}, {1}) << endl; // 2
	cout << solution(5, {1, 3}, {3, 5}) << endl; // 4
}
