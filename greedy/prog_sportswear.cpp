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
