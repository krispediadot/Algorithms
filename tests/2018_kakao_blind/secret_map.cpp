// solution1
#include <string>
#include <vector>

using namespace std;

string binaryConvertor(int target, int n) {
	string result = "";

	while (target > 0) {
		result = to_string(target % 2) + result;
		target /= 2;
	}

	while (result.length() < n) result = '0' + result;

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) answer.push_back("");

	for (int i = 0; i < n; i++) {
		string r1 = binaryConvertor(arr1[i], n);
		string r2 = binaryConvertor(arr2[i], n);

		for (int j = 0; j < n; j++) {
			if (r1[j] == '1' || r2[j] == '1') answer[i] += '#';
			else answer[i] += ' ';
		}
	}

	return answer;
}

// solution2
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
