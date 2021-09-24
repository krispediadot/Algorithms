// 2024 KB, 0ms
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int limit; cin >> limit;
	string s; cin >> s;

	stack<char> st;
	
	int idx = 0;
	while (idx < s.length()) {
		if (st.size() > limit && s[idx] == st.top()) break;
	
		if (st.empty()) st.push(s[idx]);
		else if (st.top() != s[idx]) st.pop();
		else st.push(s[idx]);

		idx++;
	}
	if (st.size() > limit) idx--;

	cout << idx  << '\n';

	return 0;
}
