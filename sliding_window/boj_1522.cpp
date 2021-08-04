// 2024 KB, 0ms
#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	int windowSize = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'b') windowSize++;
	}

	s += s;

	int answer = windowSize;
	int cntB = 0;
	for (int idx = 0; idx < s.length() + windowSize; idx++) {
		if (s[idx] == 'b') cntB++;
		answer = min(answer, windowSize - cntB);

		int firstItemIdx = idx - windowSize + 1;
		if (firstItemIdx >= 0 && s[firstItemIdx] == 'b')
			cntB--;
	}

	cout << answer;

	return 0;
}
