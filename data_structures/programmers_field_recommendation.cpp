/*

주석 있는 버전

테스트 1 〉	통과 (0.03ms, 4.34MB)
테스트 2 〉	통과 (0.02ms, 4.34MB)
테스트 3 〉	통과 (0.03ms, 3.67MB)
테스트 4 〉	통과 (0.03ms, 3.73MB)
테스트 5 〉	통과 (0.03ms, 3.66MB)
테스트 6 〉	통과 (0.03ms, 4.34MB)
테스트 7 〉	통과 (0.03ms, 4.27MB)
테스트 8 〉	통과 (0.03ms, 4.28MB)
테스트 9 〉	통과 (0.03ms, 4.34MB)
테스트 10 〉	통과 (0.03ms, 4.27MB)
*/

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {

	// 1. 선호도 정보 연결 
	unordered_map<string, int> prefers; // {언어명, 선호도 점수}
	for (int i = 0; i < languages.size(); i++) prefers[languages[i]] = preference[i];

  vector<string> fields(table.size()); // 직업군 이름 저장
	int maxIdx = 0, maxScore = 0;

	// 2. 직업군 정보 확인하면서 직업군 언어 점수 계산
	for (int i = 0; i < table.size(); i++) {
		
		// 2-1. 문자열 파싱 준비
		stringstream ss(table[i]);
		string s;
	
		int score = 0; // 해당 직업군의 점수
		int cnt = 0; // 파싱 개수 (최대 5)

		// 2-2. 문자열 파싱
		while (ss >> s) {

			// 첫번째 아이템은 직업군 이름
			if (cnt == 0) fields[i] = s;

			// 나머진 점수별 언어 이름 (5 ~ 1점)
			else {

				// 선호하는 언어관련 정보이면 직업군 언어 점수 계산 (언어 선호도 x 직업군 언어 점수)
				if (prefers.find(s) != prefers.end()) score += (prefers[s] * (6 - cnt));
			}
			cnt++; cnt %= 6;
		}

		// 2-3. 가장 큰 점수만 저장
		if (score == maxScore && fields[i] < fields[maxIdx]) maxIdx = i;
		if (score > maxScore) { maxIdx = i; maxScore = score; }
	}
	
	// 3. 가장 큰 점수의 직업군 출력
    return fields[maxIdx];
}

/*

주석 없는 버전

테스트 1 〉	통과 (0.03ms, 4.34MB)
테스트 2 〉	통과 (0.02ms, 4.34MB)
테스트 3 〉	통과 (0.03ms, 3.67MB)
테스트 4 〉	통과 (0.03ms, 3.73MB)
테스트 5 〉	통과 (0.03ms, 3.66MB)
테스트 6 〉	통과 (0.03ms, 4.34MB)
테스트 7 〉	통과 (0.03ms, 4.27MB)
테스트 8 〉	통과 (0.03ms, 4.28MB)
테스트 9 〉	통과 (0.03ms, 4.34MB)
테스트 10 〉	통과 (0.03ms, 4.27MB)
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	unordered_map<string, int> prefers;
	for (int i = 0; i < languages.size(); i++) prefers[languages[i]] = preference[i];

   vector<string> fields(table.size());
	int maxIdx = 0, maxScore = 0;

	for (int i = 0; i < table.size(); i++) {
		stringstream ss(table[i]);
		string s;
	
		int score = 0;
		int cnt = 0;
		while (ss >> s) {
			if (cnt == 0) fields[i] = s;
			else {
				if (prefers.find(s) != prefers.end()) score += (prefers[s] * (6 - cnt));
			}
			cnt++; cnt %= 6;
		}
		if (score == maxScore && fields[i] < fields[maxIdx]) maxIdx = i;
		if (score > maxScore) { maxIdx = i; maxScore = score; }
	}
	
    return fields[maxIdx];
}
