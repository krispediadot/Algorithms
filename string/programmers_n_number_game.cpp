/*
테스트 1 〉	통과 (0.01ms, 4.23MB)
테스트 2 〉	통과 (0.01ms, 4.29MB)
테스트 3 〉	통과 (0.01ms, 4.22MB)
테스트 4 〉	통과 (0.01ms, 4.23MB)
테스트 5 〉	통과 (0.02ms, 4.23MB)
테스트 6 〉	통과 (0.02ms, 3.61MB)
테스트 7 〉	통과 (0.02ms, 4.24MB)
테스트 8 〉	통과 (0.04ms, 3.61MB)
테스트 9 〉	통과 (0.02ms, 4.24MB)
테스트 10 〉	통과 (0.02ms, 4.24MB)
테스트 11 〉	통과 (0.02ms, 4.22MB)
테스트 12 〉	통과 (0.03ms, 4.23MB)
테스트 13 〉	통과 (0.02ms, 4.29MB)
테스트 14 〉	통과 (2.79ms, 4.23MB)
테스트 15 〉	통과 (2.64ms, 4.29MB)
테스트 16 〉	통과 (2.78ms, 4.24MB)
테스트 17 〉	통과 (0.11ms, 4.23MB)
테스트 18 〉	통과 (0.16ms, 4.24MB)
테스트 19 〉	통과 (0.04ms, 3.66MB)
테스트 20 〉	통과 (0.15ms, 4.18MB)
테스트 21 〉	통과 (1.29ms, 3.66MB)
테스트 22 〉	통과 (0.28ms, 4.29MB)
테스트 23 〉	통과 (0.90ms, 3.67MB)
테스트 24 〉	통과 (1.23ms, 4.26MB)
테스트 25 〉	통과 (1.09ms, 4.24MB)
테스트 26 〉	통과 (0.38ms, 4.29MB)
*/

#include <string>
#include <vector>

using namespace std;

string convertor(int target, int n) {
    vector<char> charset = {'0', '1', '2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string result = "";

	if (target == 0) result += charset[0];
	else {
		while (target > 0) {
			result = charset[target % n] + result;
			target /= n;
		}
	}
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string total = "";
    
    int target = 0;
    while (total.length() < t*m) {
        total += convertor(target, n);
        target++;
    }
    
    int turn = p-1;
    while (answer.length() < t) {
        answer += total[turn];
        turn += m;
    }
    
    return answer;
}
