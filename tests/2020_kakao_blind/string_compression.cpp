/*
테스트 1 〉	통과 (0.02ms, 4.26MB)
테스트 2 〉	통과 (0.04ms, 4.26MB)
테스트 3 〉	통과 (0.03ms, 3.73MB)
테스트 4 〉	통과 (0.02ms, 4.26MB)
테스트 5 〉	통과 (0.01ms, 4.25MB)
테스트 6 〉	통과 (0.01ms, 4.32MB)
테스트 7 〉	통과 (0.06ms, 3.66MB)
테스트 8 〉	통과 (0.11ms, 4.32MB)
테스트 9 〉	통과 (0.07ms, 4.32MB)
테스트 10 〉	통과 (0.19ms, 4.32MB)
테스트 11 〉	통과 (0.02ms, 4.32MB)
테스트 12 〉	통과 (0.02ms, 4.32MB)
테스트 13 〉	통과 (0.02ms, 4.31MB)
테스트 14 〉	통과 (0.06ms, 3.66MB)
테스트 15 〉	통과 (0.04ms, 4.31MB)
테스트 16 〉	통과 (0.01ms, 4.32MB)
테스트 17 〉	통과 (0.15ms, 4.32MB)
테스트 18 〉	통과 (0.12ms, 4.31MB)
테스트 19 〉	통과 (0.16ms, 3.7MB)
테스트 20 〉	통과 (0.38ms, 4.27MB)
테스트 21 〉	통과 (0.63ms, 4.25MB)
테스트 22 〉	통과 (0.34ms, 4.31MB)
테스트 23 〉	통과 (0.24ms, 4.32MB)
테스트 24 〉	통과 (0.22ms, 3.69MB)
테스트 25 〉	통과 (0.39ms, 4.25MB)
테스트 26 〉	통과 (0.40ms, 4.3MB)
테스트 27 〉	통과 (0.52ms, 4.25MB)
테스트 28 〉	통과 (0.02ms, 4.27MB)
*/

#include <string>
#include <vector>

using namespace std;

// 압축해서 가장 짧은 길이 만들기

int solution(string s) {
	int answer = s.length();

	for (int term = s.length() / 2; term > 0; term--) {

		int totalLen = 0;

		int start = 0;
		while (start + term <= s.length()) {
			string target = s.substr(start, term);
			int repeat = 1;

			while (start + term <= s.length() && s.substr(start + (term*repeat), term) == target) repeat++;

			if (repeat == 1) totalLen += term;
			else totalLen += (term + to_string(repeat).length());
				
			if (totalLen >= answer) break;

			start += (term*repeat);
		}
		if (start < s.length()) totalLen += (s.length() - start);
			
		if (totalLen < answer) answer = totalLen;
		
	}

	return answer;
}
