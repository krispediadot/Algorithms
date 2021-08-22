// 2024 KB, 0ms

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

bool checker(string s, string t) {
	if (s.length() == t.length()) {
		return s == t;
	}

	bool answer = false;

	if (t.back() == 'A') {
		string tpop = t;
		tpop.pop_back();
		answer |= checker(s, tpop);
	}
	
	if (t.front() == 'B') {
		string treverse = t;
		reverse(treverse.begin(), treverse.end());
		treverse.pop_back();
		answer |= checker(s, treverse);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, T; cin >> S >> T;
	
	cout << checker(S, T);

	return 0;
}
