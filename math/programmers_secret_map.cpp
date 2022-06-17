/*
테스트 1 〉	통과 (0.02ms, 3.61MB)
테스트 2 〉	통과 (0.02ms, 4.25MB)
테스트 3 〉	통과 (0.01ms, 4.26MB)
테스트 4 〉	통과 (0.02ms, 4.23MB)
테스트 5 〉	통과 (0.01ms, 4.25MB)
테스트 6 〉	통과 (0.03ms, 4.25MB)
테스트 7 〉	통과 (0.02ms, 3.69MB)
테스트 8 〉	통과 (0.01ms, 4.2MB)
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
        string ans = "";
        arr1[i] = arr1[i]|arr2[i];
        
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0) ans = ' ' + ans;
            else ans = '#' + ans;
            
            arr1[i] = arr1[i] >> 1;
        }
        
		answer.push_back(ans);
	}

	return answer;
}
