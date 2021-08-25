
// 12812 KB, 64ms
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	pair<int, int> S, E, Q;
	string s;
	cin >> s; S = { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)) };
	cin >> s; E = { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)) };
	cin >> s; Q = { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)) };
	cin.ignore();

	unordered_set<string> candidates;
	int cnt = 0;
	bool isEnter = false, isExit = false;
	while (getline(cin, s)) {

		if (s == "") break;

		auto itr = s.find(' ');

		// 1. 현재 시간 확인
		pair<int, int> cur = { stoi(s.substr(0, 2)), stoi(s.substr(3,2)) };

		// 1-1. 입장 시간 확인용 flag
		if (!isEnter && ((cur.first < S.first) || (cur.first == S.first && cur.second <= S.second))) isEnter = true;
		if (isEnter && ((cur.first > S.first) || (cur.first == S.first && cur.second > S.second))) isEnter = false;

		// 1-2. 퇴장 시간 확인용 flag
		if (!isExit && ((cur.first > E.first) || (cur.first == E.first && cur.second >= E.second))) isExit = true;
		if (isExit && ((cur.first > Q.first) || (cur.first == Q.first && cur.second > Q.second))) isExit = false;

		// 2. 들어온 사람 확인 
		string name = s.substr(6);

		// 3. 입장 시간이면 set에 추가
		if (isEnter) candidates.insert(name);

		// 4. 퇴장 시간(E ~ Q)이고, set에 있는 사람이면 cnt++
		auto target = candidates.find(name);
		if (isExit && target != candidates.end()) { candidates.erase(target); cnt++; }
	}

	cout << cnt;

	return 0;
}
