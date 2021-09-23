/*
 * 
테스트 1 〉	통과 (0.02ms, 4.3MB)
테스트 2 〉	통과 (0.03ms, 3.65MB)
테스트 3 〉	통과 (0.07ms, 4.25MB)
테스트 4 〉	통과 (0.16ms, 4.24MB)
테스트 5 〉	통과 (0.04ms, 4.31MB)
테스트 6 〉	통과 (0.01ms, 3.66MB)
테스트 7 〉	통과 (0.02ms, 3.66MB)
테스트 8 〉	통과 (0.16ms, 4.32MB)
테스트 9 〉	통과 (0.13ms, 4.32MB)
테스트 10 〉	통과 (0.21ms, 4.32MB)
테스트 11 〉	통과 (0.25ms, 4.31MB)
테스트 12 〉	통과 (0.23ms, 3.86MB)
테스트 13 〉	통과 (0.28ms, 4.26MB)
테스트 14 〉	통과 (0.39ms, 4.32MB)
테스트 15 〉	통과 (0.52ms, 4.31MB)
효율성  테스트
테스트 1 〉	통과 (0.74ms, 3.89MB)
테스트 2 〉	통과 (1.45ms, 4.2MB)
테스트 3 〉	통과 (2.15ms, 4.65MB)
테스트 4 〉	통과 (3.03ms, 5.75MB)
테스트 5 〉	통과 (3.31ms, 5.48MB)
테스트 6 〉	통과 (4.07ms, 5.9MB)
테스트 7 〉	통과 (5.24ms, 6.55MB)
테스트 8 〉	통과 (5.79ms, 7.04MB)
테스트 9 〉	통과 (6.35ms, 7.3MB)
테스트 10 〉	통과 (9.92ms, 7.82MB)
테스트 11 〉	통과 (8.94ms, 8.7MB)
테스트 12 〉	통과 (8.72ms, 10.9MB)
테스트 13 〉	통과 (10.63ms, 12MB)
테스트 14 〉	통과 (13.02ms, 11.7MB)
테스트 15 〉	통과 (15.62ms, 13MB)
 *
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer = { 1, 100001 };
	unordered_map<string, int> unique;
	for (auto& g : gems) unique[g]++;
	int uniqueSize = unique.size();

	unordered_map<string, int> sub;
	int s = 0, e = 0;
	sub[gems[e]]++;
	while (s <= e) {
		if (sub.size() < uniqueSize) {
			if (e < gems.size() - 1) sub[gems[++e]]++;
			else break;
		}
		else {
			if (e - s < answer[1] - answer[0]) {
				answer[0] = s + 1;
				answer[1] = e + 1;
			}
			if (sub[gems[s]] == 1) sub.erase(gems[s]);
			else sub[gems[s]]--;
			s++;
		}
	}

	return answer;
}
